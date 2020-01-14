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

 * 13x7 BLANK LAYOUT for building layouts for the RIGHT HAND side - 8 spaces for each key - 2 lines for each row

 * +--------------------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * +--------------------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * +--------------------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |        |        |        |                 |        |        |        |
 * |        |        |        |        |        |        |        |        |                 |        |        |        |
 * |        |        |        |        |        |        |        |        |                 |        |        |        |
 * +--------------------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * +--------------------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |        |        |                 |        |        |        |        |
 * |        |        |        |        |        |        |        |                 |        |        |        |        |
 * +--------------------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |        |                 |        |        |        |        |        |
 * |        |        |        |        |        |        |                 |        |        |        |        |        |
 * +--------------------------------------------+--------+-----------------------------------------------------|        |
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * +--------------------------------------------------------------------------------------------------------------------+

 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE
};

enum keycodes {
    BASE = SAFE_RANGE,
    LOWER,
    RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base
    * +--------------------------------------------------------------------------------------------------------------------+
    * | CTRL+  | CTRL+  | F19    | F20    | F21    | F22    | F23    | F24    |        | PRTSRC | SCROLL | PAUSE  | VOL    |
    * | SHIFT+ | ALT+   |        |        |        |        |        |        |        |        | LOCK   |        | UP     |
    * | ESC    | DEL    |        |        |        |        |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * | WIN+   |        | F7     | F8     | F9     | F10    | F11    | F12    | ESC    | DELETE | INSERT | MUTE   | VOL    |
    * | L      |        |        |        |        |        |        |        |        |        |        |        | DOWN   |
    * | (LOCK) |        |        |        |        |        |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * | CTRL+  | 6      | 7      | 8      | 9      | 0      | -      | =      | BKSP            | /      | *      | -      |
    * | ALT+   |        |        |        |        |        |        |        |                 |        |        |        |
    * | SHIFT  |        |        |        |        |        |        |        |                 |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * | CTRL+  | Y      | U      | I      | O      | P      | [      | ]      | \      | HOME   | ALT+   | PAGE   | +      |
    * | ALT    |        |        |        |        |        |        |        |        |        | UP     | UP     |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * | CTRL+  | H      | J      | K      | L      | ;      | '      | ENTER           | ALT+   |        | ALT+   | ;      |
    * | SHIFT  |        |        |        |        |        |        |                 | LEFT   |        | RIGHT  |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * | ALT+   | N      | M      | ,      | .      | /      | SHIFT           | UP     | END    | ALT+   | PAGE   | ENTER  |
    * | SHIFT  |        |        |        |        |        |                 |        |        | DOWN   | DOWN   |        |
    * +--------------------------------------------+--------+------------------------------------------------------        |
    * | RAISE  | SPACE  | SPACE  | SPACE  | ALT    | OS     | CTRL   | LEFT   | DOWN   | RIGHT  | 0      | .      |        |
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    */
    [_BASE] = LAYOUT( \
      LCTL(LSFT(KC_ESC)), LCTL(LSFT(KC_DEL)), KC_F19, KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_NO,   KC_PSCR,       KC_SLCK,        KC_PAUSE,       KC_VOLU, \
      LGUI(KC_L),         LGUI(KC_D),         KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_ESC,  KC_DEL,        KC_INS,         KC_MUTE,        KC_VOLD, \
      KC_MEH,             KC_6,               KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,       KC_PSLS,        KC_PAST,        KC_PMNS, \
      LCTL(KC_LALT),      KC_Y,               KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME,       LALT(KC_UP),    KC_PGUP,        KC_PPLS, \
      LCTL(KC_LSFT),      KC_H,               KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_NO,   LALT(KC_LEFT), KC_NO,          LALT(KC_RIGHT), KC_SCLN, \
      LALT(KC_LSFT),      KC_N,               KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   KC_END,        LALT(KC_DOWN),  KC_PGDN,        KC_ENTER, \
      RAISE,              KC_SPC,             KC_SPC, KC_SPC,  KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT,       KC_INS,         KC_DEL,         KC_NO \
    ),
    /* Lower
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |        |        |        |                 |        |        |        |
    * |        |        |        |        |        |        |        |        |                 |        |        |        |
    * |        |        |        |        |        |        |        |        |                 |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |        |        |                 |        |        |        |        |
    * |        |        |        |        |        |        |        |                 |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |        |                 |        |        |        |        |        |
    * |        |        |        |        |        |        |                 |        |        |        |        |        |
    * +--------------------------------------------+--------+-----------------------------------------------------|        |
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    */
    [_LOWER] = LAYOUT( \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),
    /* Raise
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |        |        |        |                 |        |        |        |
    * |        |        |        |        |        |        |        |        |                 |        |        |        |
    * |        |        |        |        |        |        |        |        |                 |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |        |        |                 |        |        |        |        |
    * |        |        |        |        |        |        |        |                 |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    * |        |        |        |        |        |        |                 |        |        |        |        |        |
    * |        |        |        |        |        |        |                 |        |        |        |        |        |
    * +--------------------------------------------+--------+-----------------------------------------------------|        |
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * +--------------------------------------------------------------------------------------------------------------------+
    */
    [_RAISE] = LAYOUT( \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, RESET, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, BL_INC,  _______, _______,  _______, _______, \
      _______, KC_DEL,  KC_NO,   KC_NO,   _______, _______, _______, BL_STEP, BL_DEC,  BL_TOGG, _______,  _______, _______ \
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
