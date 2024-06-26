/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2018 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define USE_I2C

#define VIAL_KEYBOARD_UID \
    { 0x49, 0x2B, 0xD0, 0x33, 0xA5, 0x63, 0xEF, 0xD6 }

#define USB_POLLING_INTERVAL_MS 1

#define USB_MAX_POWER_CONSUMPTION 500

#define F_SCL 400000L

#define FORCE_NKRO

#define DYNAMIC_KEYMAP_LAYER_COUNT 3

#define VIAL_TAP_DANCE_ENTRIES 4

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE
