/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0xEA, 0xE3, 0x29, 0x4F, 0x79, 0xFF, 0x86, 0xC6}
/* #define VIAL_UNLOCK_COMBO_ROWS {0, 1}
#define VIAL_UNLOCK_COMBO_COLS {0, 11} */


#define ANALOG_JOYSTICK_SPEED_MAX 5
#define ANALOG_JOYSTICK_SPEED_REGULATOR 10

#define ANALOG_JOYSTICK_Y_AXIS_PIN B6
#define ANALOG_JOYSTICK_X_AXIS_PIN D7

#define POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_INVERT_Y

#define DEBOUNCE 3
#define FORCE_NKRO
#define USB_POLLING_INTERVAL_MS 1


#define NO_ACTION_ONESHOT
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
