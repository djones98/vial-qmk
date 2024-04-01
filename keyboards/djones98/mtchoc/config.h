#pragma once

#define FORCE_NKRO

#define BACKLIGHT_PWM_DRIVER PWMD4  //MATCHED IN mcuconf.h.
#define BACKLIGHT_PWM_CHANNEL 2     // no clue where this value comes from but it works

#define SPI_DRIVER SPID1
#define SPI_SCK_PIN GP10
#define SPI_MOSI_PIN GP11
#define SPI_MISO_PIN NO_PIN

/* LCD Configuration */
#define LCD_DC_PIN GP8
#define LCD_CS_PIN GP9
#define LCD_RST_PIN GP12

//#define LCD_BLK_PIN GP25 // USED AS BACKLIGHT PIN IN INFO.JSON
#define LCD_SPI_DIVISOR 4
#define LCD_WAIT_TIME 150
#define LCD_ROTATION QP_ROTATION_180
#define LCD_OFFSET_X 0
#define LCD_OFFSET_Y 0
#define LCD_WIDTH 240
#define LCD_HEIGHT 240
#define SPI_MODE 0

// QP Configuration
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
// Timeout configuration, default 30000 (30 sek). 0 = No timeout. Beware of image retention.
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 30000
