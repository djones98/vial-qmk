#include "qp.h"
#include "gfx/samurai.qgf.h"
#include "gfx/samurai2.qgf.h"
#include "gfx/samurai3.qgf.h"
#include "config.h"
#include "mtchoc.h"
#include "gfx/robotomono20.qff.h"

static deferred_token display_task_token;
painter_font_handle_t roboto_font;
painter_device_t      mtchoc_display;
static deferred_token my_anim;

uint32_t display_task_callback(uint32_t trigger_time, void *cb_arg) {
    display_task_kb();
    return 100;
}

void keyboard_post_init_kb(void) {
    wait_ms(LCD_WAIT_TIME);

    /* Create, initialise, set offsets, power on, clear display, load image and font to memory */
    mtchoc_display = qp_gc9a01_make_spi_device(LCD_HEIGHT, LCD_WIDTH, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);
    qp_init(mtchoc_display, LCD_ROTATION);
    qp_set_viewport_offsets(mtchoc_display, LCD_OFFSET_X, LCD_OFFSET_Y);
    qp_power(mtchoc_display, true);
    qp_clear(mtchoc_display);
    painter_image_handle_t mtchoc_glitch_anim = qp_load_image_mem(gfx_samurai3);
    roboto_font                       = qp_load_font_mem(font_robotomono20);

    /* Blacks out the background */
    static bool first_draw = true;
    if (first_draw) {
        qp_rect(mtchoc_display, 0, 0, 240, 240, 0, 0, 0, true);
        first_draw = false;
    }

    /* Display animation and use callback to call display_task_kb */
    my_anim            = qp_animate(mtchoc_display, 49, 0, mtchoc_glitch_anim);
    display_task_token = defer_exec(10, display_task_callback, NULL);
}

void display_task_kb(void) {
    static uint32_t last_scan_rate      = 0;
    static int      current_layer_state = 99;
    char            buffer[64]          = {0};
    char            layer[10]           = {0};

    if (last_scan_rate != get_matrix_scan_rate()) {
        snprintf(buffer, sizeof(buffer), "Scan Rate %ld", get_matrix_scan_rate());
        int16_t width = qp_textwidth(roboto_font, buffer);
        qp_drawtext(mtchoc_display, (120 - (width / 2)), (183 - roboto_font->line_height), roboto_font, buffer);
        last_scan_rate = get_matrix_scan_rate();
    }

    if (get_highest_layer(layer_state) != current_layer_state) {
        snprintf(buffer, sizeof(buffer), "Layer");
        int16_t width = qp_textwidth(roboto_font, buffer);
        qp_drawtext(mtchoc_display, (120 - (width / 2)), (208 - roboto_font->line_height), roboto_font, buffer);
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                strcpy(layer, "QWERTY");
                break;
            case _MEDIA:
                strcpy(layer, " MEDIA ");
                break;
            case _NAV:
                strcpy(layer, "  NAV  ");
                break;
            case _MOUSE:
                strcpy(layer, " MOUSE ");
                break;
            default:
                strcpy(layer, " UNDEF ");
        }
        snprintf(buffer, sizeof(buffer), "%s", layer);
        width = qp_textwidth(roboto_font, buffer);
        qp_drawtext(mtchoc_display, (120 - (width / 2)), (230 - roboto_font->line_height), roboto_font, buffer);
        current_layer_state = get_highest_layer(layer_state);
    }
}

// MODIFIED FROM CODE FOUND ON REDDIT
//  Backlight timeout feature
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
        qp_power(mtchoc_display, false);
        lcd_on = false;
        qp_flush(mtchoc_display);
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (lcd_on == false || old_backlight_level == -1) {
            if (old_backlight_level == -1) old_backlight_level = get_backlight_level();
            backlight_set(old_backlight_level);
            lcd_on = true;
            qp_power(mtchoc_display, true);
        }
        idle_timer = timer_read();
    }
    return true;
}
