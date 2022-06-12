#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xECED
#define PRODUCT_ID 0x3663
#define DEVICE_VER 0x0001
#define MANUFACTURER Fancytech
#define PRODUCT FancyAlice66
#define DESCRIPTION FancyAlice66

#define MATRIX_ROWS 5
#define MATRIX_COLS 16
#define MATRIX_ROW_PINS \
    { F4, F5, F6, F7, C7 }
#define MATRIX_COL_PINS \
    { C6, E6, B5, B4, D7, D6, D4, D5, D3, D2, D1, D0, B7, B3, B2, B1 }

#define DIODE_DIRECTION ROW2COL
#define FORCE_NKRO
#define DEBOUNCING_DELAY 5


#ifdef RGB_MATRIX_ENABLE
// The pin connected to the data pin of the LEDs
#    define RGB_DI_PIN B0
// The number of LEDs connected
#    define DRIVER_LED_TOTAL 82
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_DISABLE_WHEN_USB_SUSPENDED true
#    define RGB_MATRIX_CENTER \
        { 105, 32 }

/* RGB Matrix effect */

#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define ENABLE_RGB_MATRIX_DUAL_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_PIXEL_RAIN
#    define ENABLE_RGB_MATRIX_MULTISPLASH

#endif
