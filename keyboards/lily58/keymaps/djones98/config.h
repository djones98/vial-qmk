#pragma once

/* VIAL UID for Lily58*/
#define VIAL_KEYBOARD_UID {0x7E, 0xFD, 0xFC, 0x5B, 0x7D, 0x39, 0x48, 0x06}

/* VIAL secure unlock keystroke - currently both big keys (typ. SPACE/ENTER) */
#define VIAL_UNLOCK_COMBO_ROWS {4, 9}
#define VIAL_UNLOCK_COMBO_COLS {4, 4}

#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#define FORCE_NKRO
#define DEBOUNCING_DELAY 2
#define USB_POLLING_INTERVAL_MS 1

#define MASTER_LEFT

#define USE_SERIAL_PD2

#define SPLIT_WPM_ENABLE
#define SPLIT_OLED_ENABLE
#define SPLIT_LED_STATE_ENABLE
