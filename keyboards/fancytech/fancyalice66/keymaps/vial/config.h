#pragma once
#define VIAL_KEYBOARD_UID {0x9D, 0x94, 0xC3, 0x86, 0x8B, 0xB2, 0xB7, 0x3A}
#define DYNAMIC_KEYMAP_LAYER_COUNT 3


#define RGB_DEFAULT_MODE DUAL_BEACON
#define RGB_MATRIX_TIMEOUT 300000 // number of milliseconds to wait until rgb automatically turns off
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define VIALRGB_NO_DIRECT

#define DEBOUNCE 1
#define USB_POLLING_INTERVAL_MS 1

#define NO_ACTION_ONESHOT
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

