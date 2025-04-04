// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _LOWER,
  _NAV,
  _ADJUST
};

#define R(kc) LT(_NAV, kc)
#define L(kc) LT(_LOWER, kc)

#define LA(kc) LALT_T(kc)
#define LC(kc) LCTL_T(kc)
#define LS(kc) LSFT_T(kc)
#define LG(kc) LGUI_T(kc)

#define RA(kc) RALT_T(kc)
#define RC(kc) RCTL_T(kc)
#define RS(kc) RSFT_T(kc)
#define RG(kc) RGUI_T(kc)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /* Base layout
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ : │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │LSh├───┐           ┌───┤ \ │
      *               └───┤Spc├───┐   ┌───┤Bsp├───┘
      *                   └───┤Ent│   │Esc├───┘
      *                       └───┘   └───┘
      */
    [_BASE] = LAYOUT_split_3x6_3(
        KC_T,   KC_R,     KC_E,    KC_W,     KC_Q,    KC_NO,                         KC_Y,     KC_U,    KC_I,     KC_O,      KC_P,     KC_NO,
        KC_G, LG(KC_F), LS(KC_D), LC(KC_S), LA(KC_A), KC_NO,                         KC_H, RG(KC_J),  RS(KC_K), RC(KC_L), RA(KC_SCLN), KC_NO,
        KC_B,   KC_V,     KC_C,    KC_X,     KC_Z,    KC_NO,                         KC_N,     KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,    KC_NO,
                                        R(KC_ENT), L(KC_SPC), KC_LSFT,            R(KC_ESC), L(KC_BSPC), KC_BSLS
    ),
     /* Lower layout
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │F11│F12│       │ ` │   │   │ [ │ ] │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │F10│F9 │F8 │F7 │F6 │       │ 1 │ 2 │ 3 │ 4 │ 5 │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │F5 │F4 │F3 │F2 │F1 │       │ 6 │ 7 │ 8 │ 9 │ 0 │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │LSh├───┐           ┌───┤Tab│
      *               └───┤Spc├───┐   ┌───┤Bsp├───┘
      *                   └───┤Ent│   │Esc├───┘
      *                       └───┘   └───┘
      */
    [_LOWER] = LAYOUT_split_3x6_3(
        KC_F12, KC_F11,   KC_NO,   KC_NO,    KC_NO,   KC_NO,          KC_GRV,  KC_NO,   KC_NO,    KC_LBRC, KC_RBRC,  KC_NO,
        KC_F6, LG(KC_F7), LS(KC_F8), LC(KC_F9), LA(KC_F10), KC_NO,           KC_1,  LG(KC_2), LS(KC_3), LC(KC_4), LA(KC_5), KC_NO,
        KC_F1,   KC_F2,     KC_F3,    KC_F4,     KC_F5,    KC_NO,           KC_6,    KC_7,    KC_8,      KC_9,    KC_0,    KC_NO,
                                          KC_ENT, KC_SPC, KC_LSFT,           KC_ESC, KC_BSPC, KC_TAB
    ),
     /* Navigation/Media layout
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │Bot│Mk │Clr│   │   │       │   │   │   │VUp│   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │PSc│ ^ │ $ │VDn│   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │  │  │  │  │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │LSh├───┐           ┌───┤RSh│
      *               └───┤Spc├───┐   ┌───┤Bsp├───┘
      *                   └───┤Ent│   │Esc├───┘
      *                       └───┘   └───┘
      */
    [_NAV] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, QK_CLEAR_EEPROM, QK_MAKE, QK_BOOT, KC_NO,      KC_NO,   KC_HOME, KC_END,  KC_VOLU, KC_NO,    KC_NO,
        KC_NO, KC_NO,   KC_NO,         KC_NO,     KC_NO, KC_NO,      KC_PSCR, S(KC_6), S(KC_4), KC_VOLD, KC_NO,    KC_NO,
        KC_NO, KC_NO,   KC_NO,         KC_NO,     KC_NO, KC_NO,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,    KC_NO,
                                       KC_NO,     KC_NO, KC_NO,      KC_NO,   KC_NO,   KC_NO
    ),
     /* Adjust layout
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │Bot│Mk │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_ADJUST] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO, QK_MAKE, QK_BOOT,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,
        KC_NO,  KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,  KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                 KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO
    )
};
