/* Copyright 2020 Ben Howard
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.

 * 13x7 BLANK LAYOUT for building layouts for the LEFT HAND side - 8 spaces for each key - 2 lines for each row

 * +--------------------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * +--------------------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * +--------------------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * +--------------------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |                 |        |        |        |        |        |        |
 * |        |        |        |        |        |                 |        |        |        |        |        |        |
 * +--------------------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |                 |        |        |        |        |        |        |
 * |        |        |        |        |        |                 |        |        |        |        |        |        |
 * +--------------------------|        |--------------------------------------------------------------------------------+
 * |        |        |        |        |        |                 |        |        |        |        |        |        |
 * |        |        |        |        |        |                 |        |        |        |        |        |        |
 * +--------------------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * +--------------------------------------------------------------------------------------------------------------------+

 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum left_layers {
    _BASE,
    _LOWER,
    _RAISE
};

enum left_keycodes {
    BASE = SAFE_RANGE,
    LOWER,
    RAISE,
    DBL_0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base
    * +--------------------------------------------------------------------------------------------------------------------+
    * | SCAF   | SCAF   | SCAF   | SCAF   | SCAF   | SCAF   |        | F13    | F14    | F15    | F16    | F17    | F18    |
    * | F1     | F2     | F3     | F4     | F5     | F6     |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * | ,      | /      | *      | -      | HOME   | BKSP   | ESC    | F1     | F2     | F3     | F4     | F5     | F6     |
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * ---------------------------------------------------------------------------------------------------------------------+
    * | 7      | 8      | 9      | +      | END    | DEL    | `      | 1      | 2      | 3      | 4      | 5      | CTRL+  |
    * |        |        |        |        |        |        |        |        |        |        |        |        | ALT+   |
    * |        |        |        |        |        |        |        |        |        |        |        |        | SHIFT  |
    * ---------------------------------------------------------------------------------------------------------------------+
    * | 4      | 5      | 6      | ;      | PG UP  | TAB             | Q      | W      | E      | R      | T      | CTRL+  |
    * |        |        |        |        |        |                 |        |        |        |        |        | ALT    |
    * ---------------------------------------------------------------------------------------------------------------------+
    * | 1      | 2      | 3      | ENTER  | PG DN  | CAPS            | A      | S      | D      | F      | G      | CTRL+  |
    * |        |        |        |        |        |                 |        |        |        |        |        | SHIFT  |
    * ---------------------------|        |-------------------------------------------------------------------------------+
    * | 00     | 0      | .      |        | UP     | SHIFT           | Z      | X      | C      | V      | B      | ALT+   |
    * |        |        |        |        |        |                 |        |        |        |        |        | SHIFT  |
    * ---------------------------+--------+--------------------------------------------------------------------------------+
    * |        | OS     | LOWER  | LEFT   | DOWN   | RIGHT  | CTRL   | ALT    | OS     | SPACE  | SPACE  | SPACE  | RAISE  |
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    */
    [_BASE] = LAYOUT(
      LSFT(LALT(LCTL(KC_F1))),  LSFT(LALT(LCTL(KC_F2))),  LSFT(LALT(LCTL(KC_F3))),  LSFT(LALT(LCTL(KC_F4))),  LSFT(LALT(LCTL(KC_F5))),  LSFT(LALT(LCTL(KC_F6))),  KC_NO,   KC_F13,  KC_F14,  KC_F15, KC_F16, KC_F17, KC_F18,
      KC_NUMLOCK,               KC_PSLS,                  KC_PAST,                  KC_PMNS,                  KC_HOME,                  KC_BSPC,                  KC_ESC,  KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,
      KC_P7,                    KC_P8,                    KC_P9,                    KC_PPLS,                  KC_END,                   KC_DEL,                   KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_MEH,
      KC_P4,                    KC_P5,                    KC_P6,                    KC_NO,                    KC_PGUP,                  KC_TAB,                   KC_TAB,   KC_Q,   KC_W,    KC_E,   KC_R,   KC_T,   LCTL(KC_LALT),
      KC_P1,                    KC_P2,                    KC_P3,                    KC_PENT,                  KC_PGDN,                  KC_CAPS,                  KC_CAPS,   KC_A,  KC_S,    KC_D,   KC_F,   KC_G,   LCTL(KC_LSFT),
      DBL_0,                    KC_P0,                    KC_PDOT,                  KC_PENT,                  KC_UP,                    KC_LSFT,                  KC_LSFT,   KC_Z,  KC_X,    KC_C,   KC_V,   KC_B,   LALT(KC_LSFT),
      KC_COMMA,                 KC_LGUI,                  LOWER,                    KC_LEFT,                  KC_DOWN,                  KC_RIGHT,                 KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, RAISE
    ),
    /* Lower
    * +--------------------------------------------------------------------------------------------------------------------+
    * | SCAF   | SCAF   | SCAF   | SCAF   | SCAF   | SCAF   |        |        |        |        |        |        |        |
    * | F7     | F8     | F9     | F10    | F11    | F12    |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        | mouse  | mouse  | mouse  |        |        |        |        |        |        |        |         |       |
    * |        | acl 0  | acl 1  | acl 2  |        |        |        |        |        |        |        |         |       |
    * ---------------------------------------------------------------------------------------------------------------------+
    * | mouse  | mouse  | mouse  | mouse  |        |        |        |        |        |        |        |        |        |
    * | scrl lt| move up| scrl rt| scrl up|        |        |        |        |        |        |        |        |        |
    * ---------------------------------------------------------------------------------------------------------------------+
    * | mouse  | mouse  | mouse  | mouse  |        |        |        |        |        |        |        |        |        |
    * | move lt| move dn| move rt| scrl dn|        |        |        |        |        |        |        |        |        |
    * ---------------------------------------------------------------------------------------------------------------------+
    * | mouse  | mouse  | mouse  |        |        |                 |        |        |        |        |        |        |
    * | btn 1  | btn 2  | btn 3  |        |        |                 |        |        |        |        |        |        |
    * ---------------------------+--------+--------------------------------------------------------------------------------+
    * | mouse  | mouse  |        |        |        |                 |        |        |        |        |        |        |
      | btn 4  | btn 5  |        |        |        |                 |        |        |        |        |        |        |
    * +--------------------------|        |--------------------------------------------------------------------------------+
    * | mouse  | mouse  |        |        |        |                 |        |        |        |        |        |        |
    * | btn 4  | btn 5  |        |        |        |                 |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |XXXXXXXX|        |        |        |        |        |        |        |        |        |        |
    * |        |        |XXXXXXXX|        |        |        |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    */
    [_LOWER] = LAYOUT(
      LSFT(LALT(LCTL(KC_F7))),  LSFT(LALT(LCTL(KC_F8))),  LSFT(LALT(LCTL(KC_F9))),  LSFT(LALT(LCTL(KC_F10))), LSFT(LALT(LCTL(KC_F11))), LSFT(LALT(LCTL(KC_F12))),  _______, _______, _______, _______, _______, _______, _______,
      KC_NO,                    KC_ACL0,                  KC_ACL1,                  KC_ACL2,                  _______,                  _______,                   _______, _______, _______, _______, _______, _______, _______,
      KC_WH_L,                  KC_MS_U,                  KC_WH_R,                  KC_WH_U,                  _______,                  _______,                   _______, _______, _______, _______, _______, _______, _______,
      KC_MS_L,                  KC_MS_D,                  KC_MS_R,                  KC_WH_D,                  _______,                  _______,                   _______, _______, _______, _______, _______, _______, _______,
      KC_BTN1,                  KC_BTN2,                  KC_BTN3,                  KC_NO,                    _______,                  _______,                   _______, _______, _______, _______, _______, _______, _______,
      KC_BTN4,                  KC_BTN5,                  KC_NO,                    KC_NO,                    _______,                  _______,                   _______, _______, _______, _______, _______, _______, _______,
      KC_NO,                    KC_NO,                    KC_NO,                    KC_NO,                    _______,                  _______,                   _______, _______, _______, _______, _______, _______, _______
    ),
    /* Raise
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |        |        | F19    | F20    | F21    | F22    | F23    | F24    |
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |        |        | F7     | F8     | F9     | F10    | F11    | F12    |
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |                 |        | UP     |        |        |        |        |
    * |        |        |        |        |        |                 |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |                 | LEFT   | DOWN   | RIGHT  |        |        |        |
    * |        |        |        |        |        |                 |        |        |        |        |        |        |
    * +--------------------------|        |--------------------------------------------------------------------------------+
    * |        |        |        |        | BL     |                 |        |        | CALC   |        |        |        |
    * |        |        |        |        | INC    |                 |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * | RESET  |        |        | BL     | BL     | BL     |        |        |        |        |        | BACK   |XXXXXXXX|
    * |        |        |        | STEP   | DEC    | TOGGLE |        |        |        |        |        | SPACE  |XXXXXXXX|
    * +--------------------------------------------------------------------------------------------------------------------+

    */
    [_RAISE] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, KC_F19,  KC_F20,  KC_F21,   KC_F22,  KC_F23,  KC_F24,
      _______, _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,  _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______,
      _______, _______, _______, _______, BL_INC,  _______, _______, _______, _______, KC_CALC,  _______, _______, _______,
      RESET,   _______, _______, BL_STEP, BL_DEC,  BL_TOGG, _______, _______, _______, _______,  _______, KC_BSPC, KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
case LOWER:
  if (record->event.pressed) {
    layer_on(_LOWER);
  } else {
    layer_off(_LOWER);
  }
  return false;
  break;
case RAISE:
  if (record->event.pressed) {
    layer_on(_RAISE);
  } else {
    layer_off(_RAISE);
  }
  return false;
  break;
  case DBL_0:
    SEND_STRING("00");
    return false;
  }
  return true;
};


/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
