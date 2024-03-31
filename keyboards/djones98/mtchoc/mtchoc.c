#include "qp.h"
#include "gfx/cat240x240.qgf.h"
#include "config.h"

painter_device_t lcd;

void keyboard_post_init_kb(void) {
    // Display timeout
    wait_ms(LCD_WAIT_TIME);

    lcd = qp_gc9a01_make_spi_device(LCD_HEIGHT, LCD_WIDTH, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);

    qp_init(lcd, LCD_ROTATION);

    // Display offset
    qp_set_viewport_offsets(lcd, LCD_OFFSET_X, LCD_OFFSET_Y);

    // Power on display,
    qp_power(lcd, 1);
    // Paint catpaste/Katten Paste
    painter_image_handle_t logo_image = qp_load_image_mem(gfx_cat);
    qp_drawimage(lcd, 0, 0, logo_image);

    keyboard_post_init_user();
}
