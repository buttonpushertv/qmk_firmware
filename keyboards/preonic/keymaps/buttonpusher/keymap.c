/* Copyright 2015-2017 Jack Humbert
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

 *BLANK LAYOUT for building layouts - 8 spaces for each key - 2 lines for each row

 * +-----------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * +-----------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * +-----------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * +-----------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * +-----------------------------------------------------------------------------------------------------------+
 * |        |        |        |        |        |                 |        |        |        |        |        |
 * |        |        |        |        |        |                 |        |        |        |        |        |
 * +-----------------------------------------------------------------------------------------------------------+

 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _QWERTYX2C,
  _LOWER,
  _RAISE,
  _ADJUST,
  _DIRECTIONAL
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  QWERTYX2C,
  LOWER,
  RAISE,
  DIRECTIONAL,
  BUTTONPUSHER
};

enum tap_dance_codes {
  TD_A_CTRLA,
  TD_B_CTRLB,
  TD_C_CTRLC,
  TD_D_CTRLD,
  TD_E_CTRLE,
  TD_F_CTRLF,
  TD_G_CTRLG,
  TD_H_CTRLH,
  TD_I_CTRLI,
  TD_J_CTRLJ,
  TD_K_CTRLK,
  TD_L_CTRLL,
  TD_M_CTRLM,
  TD_N_CTRLN,
  TD_O_CTRLO,
  TD_P_CTRLP,
  TD_Q_CTRLQ,
  TD_R_CTRLR,
  TD_S_CTRLS,
  TD_T_CTRLT,
  TD_U_CTRLU,
  TD_V_CTRLV,
  TD_W_CTRLW,
  TD_X_CTRLX,
  TD_Y_CTRLY,
  TD_Z_CTRLZ,
  TD_1_CTRL1,
  TD_2_CTRL2,
  TD_3_CTRL3,
  TD_4_CTRL4,
  TD_5_CTRL5,
  TD_6_CTRL6,
  TD_7_CTRL7,
  TD_8_CTRL8,
  TD_9_CTRL9,
  TD_0_CTRL0,
  TD_QUOT_CTRLQUOT,
  TD_SCLN_CTRLSCLN,
  TD_SLSH_CTRLSLSH,
  TD_DOT_CTRLDOT,
  TD_COMM_CTRLCOMM,
  TD_ENT_CTRLENT,
  TD_BSPC_CTRLBSPC,
  TD_BSLS_CTRLBSLS
};

///// QUAD FUNCTION TAP DANCE GENERAL SETUP SECTION START /////
///// (no need to edit this section) /////
//Enums used to clearly convey the state of the tap dance
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5 //send SINGLE_TAP twice - NOT DOUBLE_TAP
  // Add more enums here if you want for triple, quadruple, etc.
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    //If count = 1, and it has been interrupted - it doesn't matter if it is pressed or not: Send SINGLE_TAP
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    if (state->interrupted) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
  //with single tap.
  else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else return 6; //magic number. At some point this method will expand to work for more presses
}
///// QUAD FUNCTION TAP DANCE GENERAL SETUP SECTION END /////

///// QUAD FUNCTION TAP DANCE PERSONALIZATION SECTION START /////

///// QUAD FUNCTION TAP DANCE PERSONALIZATION SECTION END /////

//Tap Dance Definitions
//THIS SECTION HAS TO BE AT THE END OF THE TAP DANCE SECTION
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_A_CTRLA] = ACTION_TAP_DANCE_DOUBLE(KC_A, LCTL(KC_A))
 ,[TD_B_CTRLB] = ACTION_TAP_DANCE_DOUBLE(KC_B, LCTL(KC_B))
 ,[TD_C_CTRLC] = ACTION_TAP_DANCE_DOUBLE(KC_C, LCTL(KC_C))
 ,[TD_D_CTRLD] = ACTION_TAP_DANCE_DOUBLE(KC_D, LCTL(KC_D))
 ,[TD_E_CTRLE] = ACTION_TAP_DANCE_DOUBLE(KC_E, LCTL(KC_E))
 ,[TD_F_CTRLF] = ACTION_TAP_DANCE_DOUBLE(KC_F, LCTL(KC_F))
 ,[TD_G_CTRLG] = ACTION_TAP_DANCE_DOUBLE(KC_G, LCTL(KC_G))
 ,[TD_H_CTRLH] = ACTION_TAP_DANCE_DOUBLE(KC_H, LCTL(KC_H))
 ,[TD_I_CTRLI] = ACTION_TAP_DANCE_DOUBLE(KC_I, LCTL(KC_I))
 ,[TD_J_CTRLJ] = ACTION_TAP_DANCE_DOUBLE(KC_J, LCTL(KC_J))
 ,[TD_K_CTRLK] = ACTION_TAP_DANCE_DOUBLE(KC_K, LCTL(KC_K))
 ,[TD_L_CTRLL] = ACTION_TAP_DANCE_DOUBLE(KC_L, LCTL(KC_L))
 ,[TD_M_CTRLM] = ACTION_TAP_DANCE_DOUBLE(KC_M, LCTL(KC_M))
 ,[TD_N_CTRLN] = ACTION_TAP_DANCE_DOUBLE(KC_N, LCTL(KC_N))
 ,[TD_O_CTRLO] = ACTION_TAP_DANCE_DOUBLE(KC_O, LCTL(KC_O))
 ,[TD_P_CTRLP] = ACTION_TAP_DANCE_DOUBLE(KC_P, LCTL(KC_P))
 ,[TD_Q_CTRLQ] = ACTION_TAP_DANCE_DOUBLE(KC_Q, LCTL(KC_Q))
 ,[TD_R_CTRLR] = ACTION_TAP_DANCE_DOUBLE(KC_R, LCTL(KC_R))
 ,[TD_S_CTRLS] = ACTION_TAP_DANCE_DOUBLE(KC_S, LCTL(KC_S))
 ,[TD_T_CTRLT] = ACTION_TAP_DANCE_DOUBLE(KC_T, LCTL(KC_T))
 ,[TD_U_CTRLU] = ACTION_TAP_DANCE_DOUBLE(KC_U, LCTL(KC_U))
 ,[TD_V_CTRLV] = ACTION_TAP_DANCE_DOUBLE(KC_V, LCTL(KC_V))
 ,[TD_W_CTRLW] = ACTION_TAP_DANCE_DOUBLE(KC_W, LCTL(KC_W))
 ,[TD_X_CTRLX] = ACTION_TAP_DANCE_DOUBLE(KC_X, LCTL(KC_X))
 ,[TD_Y_CTRLY] = ACTION_TAP_DANCE_DOUBLE(KC_Y, LCTL(KC_Y))
 ,[TD_Z_CTRLZ] = ACTION_TAP_DANCE_DOUBLE(KC_Z, LCTL(KC_Z))
 ,[TD_1_CTRL1] = ACTION_TAP_DANCE_DOUBLE(KC_1, LCTL(KC_1))
 ,[TD_2_CTRL2] = ACTION_TAP_DANCE_DOUBLE(KC_2, LCTL(KC_2))
 ,[TD_3_CTRL3] = ACTION_TAP_DANCE_DOUBLE(KC_3, LCTL(KC_3))
 ,[TD_4_CTRL4] = ACTION_TAP_DANCE_DOUBLE(KC_4, LCTL(KC_4))
 ,[TD_5_CTRL5] = ACTION_TAP_DANCE_DOUBLE(KC_5, LCTL(KC_5))
 ,[TD_6_CTRL6] = ACTION_TAP_DANCE_DOUBLE(KC_6, LCTL(KC_6))
 ,[TD_7_CTRL7] = ACTION_TAP_DANCE_DOUBLE(KC_7, LCTL(KC_7))
 ,[TD_8_CTRL8] = ACTION_TAP_DANCE_DOUBLE(KC_8, LCTL(KC_8))
 ,[TD_9_CTRL9] = ACTION_TAP_DANCE_DOUBLE(KC_9, LCTL(KC_9))
 ,[TD_0_CTRL0] = ACTION_TAP_DANCE_DOUBLE(KC_0, LCTL(KC_0))
 ,[TD_QUOT_CTRLQUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, LCTL(KC_QUOT))
 ,[TD_SCLN_CTRLSCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LCTL(KC_SCLN))
 ,[TD_SLSH_CTRLSLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, LCTL(KC_SLSH))
 ,[TD_DOT_CTRLDOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, LCTL(KC_DOT))
 ,[TD_COMM_CTRLCOMM] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, LCTL(KC_COMM))
 ,[TD_ENT_CTRLENT] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, LCTL(KC_ENT))
 ,[TD_DEL_CTRLDEL] = ACTION_TAP_DANCE_DOUBLE(KC_DEL, LCTL(KC_DEL))
 ,[TD_BSPC_CTRLBSPC] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, LCTL(KC_BSPC))
 ,[TD_BSLS_CTRLBSLS] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, LCTL(KC_BSLS))
  // Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |        |        |        |        |        |        |        |        |        | BACK   |
* |  `     | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | SPACE  |
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |        |        |        |        |        |        |        |        |        |        |
* | Tab    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | DEL    |
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |        |        |        |        |        |        |        |        |        |        |
* | ESC    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      |
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |        |        |        |        |        |        |        |        |        |        |
* | Shift  | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | ENTER  |
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |        | Direc- |        |                 |        |        |        |        |        |
* | CONTROL| ALT    | GUI    | tional | Lower  |  SPACE          | Raise  | Left   | Down   | Up     | Right  |
* +-----------------------------------------------------------------------------------------------------------+
*/
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV,        KC_1,          KC_2,          KC_3,        KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,        KC_Q,          KC_W,          KC_E,        KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  \
  KC_ESC,        KC_A,          KC_S,          KC_D,        KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  OSM(MOD_LSFT), KC_Z,          KC_X,          KC_C,        KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
  OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), DIRECTIONAL, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* QwertyX2C
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |        |        |        |        |        |        |        |        |        | BACK   |
* |  `     | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | SPACE  |
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |        |        |        |        |        |        |        |        |        |        |
* | Tab    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | DEL    |
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |        |        |        |        |        |        |        |        |        |        |
* | ESC    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      |
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |        |        |        |        |        |        |        |        |        |        |
* | Shift  | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | ENTER  |
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |        | Direc- |        |                 |        |        |        |        |        |
* | CONTROL| ALT    | GUI    | tional | Lower  |  SPACE          | Raise  | Left   | Down   | Up     | Right  |
* +-----------------------------------------------------------------------------------------------------------+
*/

[_QWERTYX2C] = LAYOUT_preonic_grid( \
  KC_GRV,  TD(TD_1_CTRL1), TD(TD_2_CTRL2), TD(TD_3_CTRL3), TD(TD_4_CTRL4), TD(TD_5_CTRL5), TD(TD_6_CTRL6), TD(TD_7_CTRL7), TD(TD_8_CTRL8),       TD(TD_9_CTRL9),     TD(TD_0_CTRL0),       TD(TD_BSPC_CTRLBSPC), \
  KC_ESC,  TD(TD_Q_CTRLQ), TD(TD_W_CTRLW), TD(TD_E_CTRLE), TD(TD_R_CTRLR), TD(TD_T_CTRLT), TD(TD_Y_CTRLY), TD(TD_U_CTRLU), TD(TD_I_CTRLI),       TD(TD_O_CTRLO),     TD(TD_P_CTRLP),       TD(TD_DEL_CTRLDEL), \
  KC_TAB,  TD(TD_A_CTRLA), TD(TD_S_CTRLS), TD(TD_D_CTRLD), TD(TD_F_CTRLF), TD(TD_G_CTRLG), TD(TD_H_CTRLH), TD(TD_J_CTRLJ), TD(TD_K_CTRLK),       TD(TD_L_CTRLL),     TD(TD_SCLN_CTRLSCLN), TD(TD_QUOT_CTRLQUOT), \
  KC_LSFT, TD(TD_Z_CTRLZ), TD(TD_X_CTRLX), TD(TD_C_CTRLC), TD(TD_V_CTRLV), TD(TD_B_CTRLB), TD(TD_N_CTRLN), TD(TD_M_CTRLM), TD(TD_COMM_CTRLCOMM), TD(TD_DOT_CTRLDOT), TD(TD_SLSH_CTRLSLSH), TD(TD_ENT_CTRLENT),  \
  KC_LCTL, KC_LALT,        KC_LGUI,        DIRECTIONAL,    LOWER,          KC_SPC,         KC_SPC,         RAISE,          KC_LEFT,              KC_DOWN,            KC_UP,                KC_RGHT \
),


/* Lower
* +-----------------------------------------------------------------------------------------------------------+
* | WEB    |        |        |        |        |        |        |        |        |        |        |        |
* | BACK   | F1     | F2     | F3     | F4     | INS    | CAPS   | F17    | F18    | F19    | F20    |        |
* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
* | WEB    |        |        |        |        |        | PRINT  |        |        |        |        |        |
* | HOME   | F5     | F6     | F7     | F8     |        | SCREEN | F21    | F22    | F23    | F24    |        |
* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
* | WEB    |        |        |        |        |        |        | MY     |        |        |        |        |
* | SEARCH | F9     | F10    | F11    | F12    |        | CALC   | COMP   |        |        |        |        |
* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
* |        |        |        |        |        | MACRO  |        |        |        |        |        |        |
* |        | F13    | F14    | F15    | F16    |b'pusher|        |        |        |        |        |        |
* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
* |CTRL-ALT|        |        |        |        |                 |        |        |        |        |        |
* |DEL     |        |        | ENTER  |XXXXXXXX|  DELETE         |        |        |        |        |        |
* +-----------------------------------------------------------------------------------------------------------+
*/
[_LOWER] = LAYOUT_preonic_grid( \
  KC_WBAK,            KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_INS,       KC_CAPS, KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______, \
  KC_WHOM,            KC_F5,   KC_F6,   KC_F7,    KC_F8,   _______,      KC_PSCR, KC_F21,  KC_F22,  KC_F23,  KC_F24,  _______, \
  KC_WSCH,            KC_F9,   KC_F10,  KC_F11,   KC_F12,  _______,      KC_CALC, KC_MYCM, _______, _______, _______, _______, \
  _______,            KC_F13,  KC_F14,  KC_F15,   KC_F16,  BUTTONPUSHER, _______, _______, _______, _______, _______, _______, \
  LALT(LCTL(KC_DEL)), _______, _______, KC_ENTER, _______, KC_DEL,       KC_DEL,  _______, _______, _______, _______, _______  \
),

/* Raise
* +-----------------------------------------------------------------------------------------------------------+
* |        | SCAF   | SCAF   | SCAF   | SCAF   |        |        |        |        |        |        |        |
* |        | F1     | F2     | F3     | F4     | %      | ^      | &      | *      | (      | )      |        |
* +-----------------------------------------------------------------------------------------------------------+
* |        | SCAF   | SCAF   | SCAF   | SCAF   |        |        |        |        |        |        |        |
* |        | F5     | F6     | F7     | F8     | _      | +      | {      | }      | |      |        |        |
* +-----------------------------------------------------------------------------------------------------------+
* |        | SCAF   | SCAF   | SCAF   | SCAF   |        |        |        |        |        |        |        |
* |        | F9     | F10    | F11    | F12    | -      | =      | [      | ]      | \      | :      | "      |
* +-----------------------------------------------------------------------------------------------------------+
* |        | SCAF   | SCAF   | SCAF   | SCAF   |        |        |        |        |        |        |        |
* |        | F13    | F14    | F15    | F16    |        |        |        | <      | >      | ?      |        |
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |        |        |        |                 |XXXXXXXX|        |        |        |        |
* |        |        |        |        |        |  BACKSPACE      |XXXXXXXX| Home   | PgDn   | PgUp   | End    |
* +-----------------------------------------------------------------------------------------------------------+
 */
[_RAISE] = LAYOUT_preonic_grid( \
  _______, LSFT(LALT(LCTL(KC_F1))),  LSFT(LALT(LCTL(KC_F2))),  LSFT(LALT(LCTL(KC_F3))),  LSFT(LALT(LCTL(KC_F4))),   KC_PERCENT,    KC_CIRCUMFLEX, KC_AMPERSAND,        KC_ASTERISK,           KC_LEFT_PAREN,          KC_RIGHT_PAREN, _______, \
  _______, LSFT(LALT(LCTL(KC_F5))),  LSFT(LALT(LCTL(KC_F6))),  LSFT(LALT(LCTL(KC_F7))),  LSFT(LALT(LCTL(KC_F8))),   KC_UNDERSCORE, KC_PLUS,       KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE,  KC_PIPE,                _______,        _______,  \
  _______, LSFT(LALT(LCTL(KC_F9))),  LSFT(LALT(LCTL(KC_F10))), LSFT(LALT(LCTL(KC_F11))), LSFT(LALT(LCTL(KC_F12))),  KC_MINUS,      KC_EQUAL,      KC_LBRACKET,         KC_RBRACKET,           TD(TD_BSLS_CTRLBSLS),   KC_COLON,       KC_DOUBLE_QUOTE,  \
  _______, LSFT(LALT(LCTL(KC_F13))), LSFT(LALT(LCTL(KC_F14))), LSFT(LALT(LCTL(KC_F15))), LSFT(LALT(LCTL(KC_F16))),  _______,       _______,       _______,             KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET, KC_QUESTION,    _______, \
  _______, _______,                  _______,                  _______,                  _______,                   KC_BSPC,       KC_BSPC,       _______,             KC_HOME,               KC_PGDN,                KC_PGUP,        KC_END  \
),

/* Directional
* +-----------------------------------------------------------------------------------------------------------+
* |        | NUM 1  | NUM 2  | NUM 3  | NUM 4  | NUM 5  | NUM 6  | NUM 7  | NUM 8  | NUM 9  | NUM 0  |        |
* |        | +GUI   | +GUI   | +GUI   | +GUI   | +GUI   | +GUI   | +GUI   | +GUI   | +GUI   | +GUI   |        |
* +-----------------------------------------------------------------------------------------------------------+
* |        | mouse  | mouse  | mouse  | mouse  |        | mouse  |        |        |        |        |        |
* |        | scrl lt| move up| scrl rt| scrl up|        | acl 0  |        |        |        |        |        |
* +-----------------------------------------------------------------------------------------------------------+
* |        | mouse  | mouse  | mouse  | mouse  |        | mouse  |        |        |        |        |        |
* |        | move lt| move dn| move rt| scrl dn|        | acl 1  |        |        |        |        |        |
* +-----------------------------------------------------------------------------------------------------------+
* |        | mouse  | mouse  | mouse  | mouse  | mouse  | mouse  |        |        |        |        |        |
* |        | btn 1  | btn 2  | btn 3  | btn 4  | btn 5  | acl 2  |        | Mute   | Play   | Stop   |        |
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |XXXXXXXX|        |        |                 |        |        |        |        |        |
* |        |        |XXXXXXXX|        |        |                 |        | Prev   | Vol Dn | Vol Up | Next   |
* +-----------------------------------------------------------------------------------------------------------+
 */
[_DIRECTIONAL] = LAYOUT_preonic_grid( \
  _______, LGUI(KC_P1), LGUI(KC_P2), LGUI(KC_P3), LGUI(KC_P4), LGUI(KC_P5), LGUI(KC_P6), LGUI(KC_P7), LGUI(KC_P8), LGUI(KC_P9), LGUI(KC_P0), _______, \
  _______, KC_WH_L,     KC_MS_U,     KC_WH_R,     KC_WH_U,     _______,     KC_ACL0,     _______,     _______,     _______,     _______,     _______, \
  _______, KC_MS_L,     KC_MS_D,     KC_MS_R,     KC_WH_D,     _______,     KC_ACL1,     _______,     _______,     _______,     _______,     _______, \
  _______, KC_BTN1,     KC_BTN2,     KC_BTN3,     KC_BTN4,     KC_BTN5,     KC_ACL2,     _______,     KC_MUTE,     KC_MPLY,     KC_MSTP,     _______, \
  _______, _______,     _______,     _______,     _______,     _______,     _______,     _______,     KC_MPRV,     KC_VOLD,     KC_VOLU,     KC_MNXT  \
),

/* Adjust (Lower + Raise)
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |        |        |        |        |        |        |        |        |        |        |
* |        |        |        |        |        |        |        |        |        |        |        |        |
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |        |        |        |        |        |        |        |        |        |        |
* |        | Reset  |        |        |        |        |        |        |        |        |        |        |
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |        |        |        |        |        |        |        |        |        |        |
* |        |        |        | Aud on | AudOff  |AGnorm | AGswap | Qwerty |QwrtyX2C|        |        |        |
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |        |        |        |        |        |        |        |        |        |        |
* |        | Voice- | Voice+ | Mus on | MusOff | MidiOn | MidOff |        |        |        |        |        |
* +-----------------------------------------------------------------------------------------------------------+
* |        |        |        |        |XXXXXXXX|                 |XXXXXXXX|        |        |        |        |
* |        |        |        |        |XXXXXXXX|                 |XXXXXXXX|        |        |        |        |
* +-----------------------------------------------------------------------------------------------------------+
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  QWERTYX2C, _______, _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______,   _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______  \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
          case QWERTYX2C:
            if (record->event.pressed) {
              set_single_persistent_default_layer(_QWERTYX2C);
            }
            return false;
            break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
          case DIRECTIONAL:
            if (record->event.pressed) {
              layer_on(_DIRECTIONAL);
            } else {
              layer_off(_DIRECTIONAL);
            }
            return false;
            break;
        case BUTTONPUSHER:
          if (record->event.pressed) {
              SEND_STRING("buttonpusher"); // this is our macro!
          }
          return false;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
