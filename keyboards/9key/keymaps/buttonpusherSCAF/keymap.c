#include "9key.h"

//revised by Ben Howard - Feb. 2018

// Tap Dance Declarations
enum {
  ENT_5 = 0,
  ZERO_1
};

// Macro Declarations
enum {
  DBL_0 = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,-----------------------.
 * |   7   |   8   |   9   |
 * |-------+-------+-------|
 * |   4   | 5/ENT |   6   | Dbl Tap 5 for Enter
 * |-------+-------+-------|
 * |  1/0  |   2   | 3/FN  | 1/0 = Dbl Tap 1 for 0  -  3/FN = Hold 3 for FN
 * `-----------------------'
 */
[0] = KEYMAP( \
  KC_7,       KC_8,      KC_9,       \
  KC_4,       TD(ENT_5), KC_6,       \
  TD(ZERO_1), KC_2,      LT(1, KC_3) \
),

/* LAYER 1
 * ,-----------------------.
 * |  ESC  |   +   |   -   |
 * |-------+-------+-------|
 * |  BSPC |   *   |   /   |
 * |-------+-------+-------|
 * |  00   |   .   |       |
 * `-----------------------'
 */
[1] = KEYMAP( \
  KC_ESC,   KC_PLUS, KC_MINS, \
  KC_BSPC,  KC_ASTR, KC_SLSH, \
  M(DBL_0), KC_DOT,  KC_TRNS  \
)

};

qk_tap_dance_action_t tap_dance_actions[] = {
  [ENT_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_ENT),
  [ZERO_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_0)
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
