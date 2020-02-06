#include "chocopad.h"

#define _BASE 0
#define _FN1 1

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = KEYMAP (
  KC_F13, KC_F14,              KC_F15,     KC_F16,
  KC_F17, KC_F18,              KC_F19,     KC_F20,
  KC_F21, KC_F22,              KC_F23,     KC_F24,
  KC_MEH, LSFT(LALT(KC_LCTRL), LGUI(KC_L), FN1

),

[_FN1] = KEYMAP (
RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAI,
BL_TOGG, BL_INC , BL_DEC,  BL_BRTG,
RESET,   _______, _______, _______,
)

};

void matrix_init_user(void) {
}
