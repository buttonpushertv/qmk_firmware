#include "chocopad.h"

#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define _FN4 4

#define _______ KC_TRNS

// Tap Dance Declarations
enum {
  ENT_5 = 0,
  MINS_PLUS,
  ZERO_DBL,
  DEL_BKSP
};

// Macro Declarations
enum {
  DBL_0 = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [ENT_5] = ACTION_TAP_DANCE_DOUBLE(KC_P5, KC_ENT),
  [MINS_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_PMNS, KC_PPLS),
  [ZERO_DBL] = ACTION_TAP_DANCE_DOUBLE(KC_P0, DBL_0),
  [DEL_BKSP] = ACTION_TAP_DANCE_DOUBLE(KC_DEL, KC_BSPC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = KEYMAP (
  LSFT(LALT(LCTL(KC_F7))),   LSFT(LALT(LCTL(KC_F8))),   LSFT(LALT(LCTL(KC_F9))),  TO(_FN1),
  LSFT(LALT(LCTL(KC_F4))),   LSFT(LALT(LCTL(KC_F5))),   LSFT(LALT(LCTL(KC_F6))),  TO(_FN2),
  LSFT(LALT(LCTL(KC_F1))),   LSFT(LALT(LCTL(KC_F2))),   LSFT(LALT(LCTL(KC_F3))),  TO(_FN3),
  LSFT(LALT(LCTL(KC_F10))),  LSFT(LALT(LCTL(KC_F11))),  LSFT(LALT(LCTL(KC_F12))), TO(_FN4)
),

[_FN1] = KEYMAP (
  KC_P7 , KC_P8 ,        KC_P9 , TO(_BASE),
  KC_P4 , TD(ENT_5) ,    KC_P6 , KC_PSLS,
  KC_P1 , KC_P2 ,        KC_P3 , TD(MINS_PLUS),
  TD(DEL_BKSP), TD(ZERO_DBL) , KC_DOT, KC_PAST
),

[_FN2] = KEYMAP (
  KC_HOME , KC_UP ,  KC_PGUP , TO(_BASE),
  KC_LEFT , KC_ESC , KC_RIGHT, _______,
  KC_END,   KC_DOWN, KC_PGDN , _______,
  _______,  _______, _______,  _______
),

[_FN3] = KEYMAP (
RESET,   _______, _______, TO(_BASE),
RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAI,
BL_TOGG, BL_INC , BL_DEC,  BL_BRTG
),

[_FN4] = KEYMAP (
RESET,   _______, _______, TO(_BASE),
RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAI,
BL_TOGG, BL_INC , BL_DEC,  BL_BRTG
)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
      switch(id) {
          case DBL_0:
              SEND_STRING("00");
              return false;
      }
  }
  return MACRO_NONE;
};

void matrix_init_user(void) {
}
