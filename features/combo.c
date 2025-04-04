#include QMK_KEYBOARD_H

const uint16_t PROGMEM cmb_minus[] = {LG(KC_F), RG(KC_J), COMBO_END};
const uint16_t PROGMEM cmb_equals[] = {RG(KC_J), RS(KC_K), COMBO_END};
const uint16_t PROGMEM cmb_quote[] = {LS(KC_D), RS(KC_K), COMBO_END};
const uint16_t PROGMEM cmb_plus[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_tmux[] = {R(KC_ENTER), R(KC_ESC), COMBO_END};
const uint16_t PROGMEM cmb_bkspace[] = {KC_U, KC_I, COMBO_END};

enum combos {
    MINUS,
    EQUALS,
    QUOTE,
    PLUS,
    TMUX,
    BKSCPACE
};

combo_t key_combos[] = {
    [MINUS] = COMBO(cmb_minus, KC_MINUS),     // f j
    [EQUALS] = COMBO(cmb_equals, KC_EQL),     // j k
    [QUOTE] = COMBO(cmb_quote, KC_QUOTE),     // d k
    [PLUS] = COMBO(cmb_plus, KC_KP_PLUS),     // e r
    [TMUX] = COMBO(cmb_tmux, LCTL(KC_B)),     // Ent Spc
    [BKSCPACE] = COMBO(cmb_bkspace, KC_BSPC), // u i
};

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case TMUX:
            return 200;
    }
    return COMBO_TERM;
}
