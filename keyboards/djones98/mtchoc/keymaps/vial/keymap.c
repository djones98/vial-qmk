// Copyright 2020 QMK / James Young (@noroadsleft)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [0] = LAYOUT(
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,           KC_MINS,    KC_EQL,     KC_DEL,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,           KC_LBRC,    KC_RBRC,    KC_NUBS,
        KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,        KC_QUOT,    KC_ENT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,        KC_RSFT,    KC_UP,
        KC_LCTL,    KC_LGUI,    KC_LALT,                    MO(1),     KC_SPC,     KC_BSPC,                     KC_RALT,    KC_RCTL,    KC_NUHS,  KC_LEFT,    KC_DOWN,    KC_RGHT
    ),

    [1] = LAYOUT(
        KC_GRV,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,         KC_F11,      KC_F12,     KC_INS,
        _______,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,        KC_UNDS,     KC_PLUS,    _______,
        _______,    KC_HOME,    KC_PGUP,    _______,    _______,    _______,    _______,    KC_LCBR,    KC_RCBR,    KC_LABK,    KC_RABK,        _______,     _______,
        _______,    KC_END,     KC_PGDN,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,     KC_VOLU,
        _______,    _______,    MO(2),                      _______,    _______,    _______,                    _______,    _______,    KC_MPLY,  KC_MPRV,   KC_VOLD,    KC_MNXT
    ),

    [2] = LAYOUT(
        _______,    _______,   _______,     _______,   _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    QK_BOOT,
        _______,    _______,   _______,     _______,   _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,   _______,     _______,   _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,   _______,     _______,   _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,   _______,                    _______,     _______,    _______,                    _______,    _______,    _______,   _______,    _______,    _______
    )
};
// clang-format on

/* void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
} */


