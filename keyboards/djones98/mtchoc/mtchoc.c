#include "qp.h"
#include "gfx/cat240x240.qgf.h"
#include "config.h"

painter_device_t lcd;

void keyboard_post_init_kb(void) {
    // Display timeout
    wait_ms(LCD_WAIT_TIME);

    lcd = qp_gc9a01_make_spi_device(LCD_HEIGHT, LCD_WIDTH, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);

    qp_init(lcd, LCD_ROTATION);
    qp_set_viewport_offsets(lcd, LCD_OFFSET_X, LCD_OFFSET_Y);
    qp_power(lcd, 1);

    painter_image_handle_t logo_image = qp_load_image_mem(gfx_cat);
    qp_drawimage(lcd, 0, 0, logo_image);
    qp_flush(lcd);
    keyboard_post_init_user();
}


//MODIFIED FROM CODE FOUND ON REDDIT
// Backlight timeout feature
static uint16_t idle_timer          = 0;
static bool     lcd_on              = true;
static uint8_t  old_backlight_level = -1;

void matrix_scan_user(void) {
    // idle_timer needs to be set one time
    if (idle_timer == 0) {
        idle_timer = timer_read();
    }

    if (lcd_on && timer_elapsed(idle_timer) > QUANTUM_PAINTER_DISPLAY_TIMEOUT) {
        old_backlight_level = get_backlight_level();
        backlight_set(0);
        qp_power(lcd, false);
        lcd_on = false;
        qp_flush(lcd);
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (lcd_on == false || old_backlight_level == -1) {
            if (old_backlight_level == -1) old_backlight_level = get_backlight_level();
            backlight_set(old_backlight_level);
            lcd_on = true;
            qp_power(lcd, true);
        }
        idle_timer = timer_read();
    }
    return true;
}
