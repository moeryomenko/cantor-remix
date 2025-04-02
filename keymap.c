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
        KC_NO,  KC_Q,     KC_W,    KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,    KC_I,     KC_O,      KC_P,     KC_NO,
        KC_NO, LA(KC_A), LC(KC_S), LS(KC_D), LG(KC_F), KC_G,                         KC_H, LG(KC_J),  LS(KC_K), LC(KC_L), LA(KC_SCLN), KC_NO,
        KC_NO,  KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,                         KC_N,     KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,    KC_NO,
                                        KC_LSFT, L(KC_SPC), R(KC_ENT),            R(KC_ESC), L(KC_BSPC), KC_BSLS
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
        KC_NO,  KC_NO,       KC_NO,     KC_NO,    KC_F11,   KC_F12,          KC_GRV,  KC_NO,   KC_NO,    KC_LBRC, KC_RBRC,  KC_NO,
        KC_NO, LA(KC_F10), LC(KC_F9), LS(KC_F8), LG(KC_F7), KC_F6,           KC_1,  LG(KC_2), LS(KC_3), LC(KC_4), LA(KC_5), KC_NO,
        KC_NO,  KC_F5,       KC_F4,     KC_F3,    KC_F2,    KC_F1,           KC_6,    KC_7,    KC_8,      KC_9,    KC_0,    KC_NO,
                                          KC_LSFT, KC_SPC, KC_ENT,           KC_ESC, KC_BSPC, KC_TAB
    ),
     /* Navigation/Media layout
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │PSc│   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │LSh├───┐           ┌───┤RSh│
      *               └───┤Spc├───┐   ┌───┤Bsp├───┘
      *                   └───┤Ent│   │Esc├───┘
      *                       └───┘   └───┘
      */
    [_NAV] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO,   KC_HOME,       KC_END,                KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_PSCR, CTL_T(KC_TAB), CTL_T(SFT_T(KC_TAB)), KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_LEFT, KC_DOWN,       KC_UP,                 KC_RGHT, KC_NO, KC_NO,
                             KC_NO, KC_NO, KC_NO,          KC_NO,   KC_NO,         KC_NO
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
        KC_NO, QK_BOOT, QK_MAKE, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,
        KC_NO,  KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,  KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                 KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO
    )
};
