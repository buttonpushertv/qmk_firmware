#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN1 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
    KC_F13,  KC_F14, KC_F15,     KC_F16, \
    KC_F17,  KC_F18, KC_F19,     KC_F20, \
    KC_F21,  KC_F22, KC_F23,     KC_F24, \
    KC_HYPR, KC_MEH, LGUI(KC_L), MO(_FN1) \
  ),
  [_FN1] = LAYOUT_ortho_4x4(
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, \
    BL_TOGG, BL_INC,  BL_DEC,  BL_BRTG, \
    BL_STEP, _______, RESET,   _______  \
  )

};

void matrix_init_user(void) {
}
