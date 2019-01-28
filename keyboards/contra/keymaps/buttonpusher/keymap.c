/* Copyright 2015-2017 Jack Humbert - Modifications by Ben Howard 2018
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
 */

#include "contra.h"
/*#include "action_layer.h"*/

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _QWERTYX2C,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _DIRECTIONAL
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  QWERTYX2C,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  DIRECTIONAL,
  BUTTONPUSHER,
  TD_SFT_CAPS = 0,
  TD_BKSP_DEL,
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
  TD_Z_CTRLZ
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
  [TD_SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
// Other declarations would go here, separated by commas, if you have them
 ,[TD_BKSP_DEL] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_DEL)
 ,[TD_A_CTRLA] = ACTION_TAP_DANCE_DOUBLE(KC_A, LCTL(KC_A))
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
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | ESC  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl | Alt  | GUI  | mouse|Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = {
    {KC_ESC,   KC_Q,    KC_W,    KC_E,        KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
    {KC_TAB,   KC_A,    KC_S,    KC_D,        KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
    {KC_LSFT,  KC_Z,    KC_X,    KC_C,        KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
    {KC_LCTL,  KC_LALT, KC_LGUI, DIRECTIONAL, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT}
  },

/* QwertyX2C
 * All Alphas have a Double Tap Dance that inputs as if you were holding Control and that letter.
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |//CAPS|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | mouse| Lower| Spc  | Spc  |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTYX2C] = {
  {KC_ESC,          TD(TD_Q_CTRLQ), TD(TD_W_CTRLW), TD(TD_E_CTRLE), TD(TD_R_CTRLR), TD(TD_T_CTRLT), TD(TD_Y_CTRLY), TD(TD_U_CTRLU), TD(TD_I_CTRLI), TD(TD_O_CTRLO), TD(TD_P_CTRLP), KC_BSPC},
  {KC_TAB,          TD(TD_A_CTRLA), TD(TD_S_CTRLS), TD(TD_D_CTRLD), TD(TD_F_CTRLF), TD(TD_G_CTRLG), TD(TD_H_CTRLH), TD(TD_J_CTRLJ), TD(TD_K_CTRLK), TD(TD_L_CTRLL), KC_SCLN,        KC_QUOT},
  {TD(TD_SFT_CAPS), TD(TD_Z_CTRLZ), TD(TD_X_CTRLX), TD(TD_C_CTRLC), TD(TD_V_CTRLV), TD(TD_B_CTRLB), TD(TD_N_CTRLN), TD(TD_M_CTRLM), KC_COMM,        KC_DOT,         KC_SLSH,        KC_ENT },
  {KC_LCTL,         KC_LALT,        KC_LGUI,        DIRECTIONAL,    LOWER,          KC_SPC,         KC_SPC,         RAISE,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | `    |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Tab  | Alt  | GUI  |Lower |    Space    |Raise | Left |Right |  Up  |Down  |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_GRV,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_LCTL, KC_A,   KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_ESC,  KC_TAB, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_RGHT, KC_UP,   KC_DOWN}
},

/* Dvorak
 * All Alphas have a Double Tap Dance that inputs as if you were holding Control and that letter.
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |//CAPS|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | mouse|Lower | Spc  | Spc  |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_ESC,          KC_QUOT,        KC_COMM,        KC_DOT,         TD(TD_P_CTRLP), TD(TD_Y_CTRLY), TD(TD_F_CTRLF), TD(TD_G_CTRLG), TD(TD_C_CTRLC), TD(TD_R_CTRLR), TD(TD_L_CTRLL), _______},
  {KC_TAB,          TD(TD_A_CTRLA), TD(TD_O_CTRLO), TD(TD_E_CTRLE), TD(TD_U_CTRLU), TD(TD_I_CTRLI), TD(TD_D_CTRLD), TD(TD_H_CTRLH), TD(TD_T_CTRLT), TD(TD_N_CTRLN), TD(TD_S_CTRLS), KC_SLSH},
  {TD(TD_SFT_CAPS), KC_SCLN,        TD(TD_Q_CTRLQ), TD(TD_J_CTRLJ), TD(TD_K_CTRLK), TD(TD_X_CTRLX), TD(TD_B_CTRLB), TD(TD_M_CTRLM), TD(TD_W_CTRLW), TD(TD_V_CTRLV), TD(TD_Z_CTRLZ), KC_ENT },
  {KC_LCTL,         KC_LALT,        KC_LGUI,        DIRECTIONAL,    LOWER,          KC_SPC,         KC_SPC,         RAISE,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT}
},

/* Lower
 * ,----------------------------------------------------------------------------------------.
 * |   ~    |   !   |   @  |   #  |   $  |   %  |   ^  |   &  |   *    |   (  |   )  |      |
 * |--------+-------+------+------+------+-------------+------+--------+------+------+------|
 * |        |  F1   |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +    |   {  |   }  |  |   |
 * |--------+-------+------+------+------+------|------+------+--------+------+------+------|
 * |        |  F7   |  F8  |  F9  |  F10 |  F11 |  F12 |      |        |      |      |      |
 * |--------+-------+------+------+------+------+------+------+--------+------+------+------|
 * | Ctrl   | button|      |      |######| BkSp | Del  |######| Print  |      |      | Ins  |
 * | Alt-Del| pusher|      |      |######|      |      |######| Screen |      |      |      |
 * `----------------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, KC_BSPC, KC_DEL,  _______, KC_PSCR, _______, _______, KC_INS}
},

/* Raise
 * ,-------------------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |              |
 * |------+------+------+------+------+-------------+------+------+------+------+--------------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \           |
 * |      | SCAF | SCAF | SCAF | SCAF | SCAF | SCAF |      |      |      |      |              |
 * |------+------+------+------+------+------|------+------+------+------+------+--------------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Calc |      |      |      | macro        |
 * |      | SCAF | SCAF | SCAF | SCAF | SCAF | SCAF |      |      |      |      | buttonpusher |
 * |------+------+------+------+------+------+------+------+------+------+------+--------------|
 * |      |      |      |      |######| BkSp | Del  |######|Home  |PgDn  |PgUp  |End           |
 * `-------------------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,                     KC_2,                     KC_3,                     KC_4,                      KC_5,                      KC_6,                      KC_7,    KC_8,     KC_9,    KC_0,   _______},
  {_______, LSFT(LALT(LCTL(KC_F1))),  LSFT(LALT(LCTL(KC_F2))),  LSFT(LALT(LCTL(KC_F3))),  LSFT(LALT(LCTL(KC_F4))),   LSFT(LALT(LCTL(KC_F5))),   LSFT(LALT(LCTL(KC_F6))),   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, LSFT(LALT(LCTL(KC_F7))),  LSFT(LALT(LCTL(KC_F8))),  LSFT(LALT(LCTL(KC_F9))),  LSFT(LALT(LCTL(KC_F10))),  LSFT(LALT(LCTL(KC_F11))),  LSFT(LALT(LCTL(KC_F12))),  KC_CALC, _______, _______, _______, BUTTONPUSHER},
  {_______, _______,                  _______,                  _______,                  _______,                   KC_BSPC,                   KC_DEL,                    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------------.
 * |      | NUM  | NUM   | NUM  | NUM   | NUM   | NUM   | NUM   | NUM   | NUM  | NUM  | NUM  |
 * |      | PAD 1| PAD 2 | PAD 3| PAD 4 | PAD 5 | PAD 6 | PAD 7 | PAD 8 | PAD 9| PAD 0| .    |
 * |------+------+-------+------+-------+-------+-------+-------+-------+------+------+------|
 * |      |Qwerty|Colemak|Dvorak|       |       |       | NUM   | NUM   | NUM  | NUM  | NUM  |
 * |      |      |       |      |       |       |       | *     | /     | +    | -    | =    |
 * |------+------+-------+------+-------+-------+-------+-------+-------+------+------+------|
 * |      |Qwerty|       | RGB  | RGB   | RGB   | RGB   | RGB   | RGB   | RGB  | RGB  | NUM  |
 * |      | X2C  |       | Togg | Hue + | Hue - | Sat + | Sat - | V+    | V-   | Mod  | Enter|
 * |------+------+-------+------+-------+-------+-------+-------+-------+------+------+------|
 * |      |      |       |      |#######| Reset | Ctrl  |#######| Next  | Vol- | Vol+ | Play |
 * |      |      |       |      |#######|       |Alt-Del|#######|       |      |      |      |
 * `----------------------------------------------------------------------------------------'
 */
[_ADJUST] = {

  {_______, KC_P1,     KC_P2,   KC_P3,   KC_P4,   KC_P5, KC_P6,              KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_PDOT},
  {_______, QWERTY,    COLEMAK, DVORAK,  _______, _______, _______,            KC_PAST, KC_PSLS, KC_PPLS, KC_PMNS, KC_PEQL},
  {_______, QWERTYX2C, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,            RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL },
  {_______, _______,   _______, _______, _______, RESET,   LALT(LCTL(KC_DEL)), _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Directional
 * ,---------------------------------------------------------------------------------------------------.
 * |       | mouse   | mouse   | mouse   | mouse   |       | mouse |       |      |      |      |      |
 * |       | scrl lt | move up | scrl rt | scrl up |       | acl 0 |       |      |      |      |      |
 * |-------+---------+---------+---------+---------+-------+-------+-------+------+------+------+------|
 * |       | mouse   | mouse   | mouse   | mouse   |       | mouse |       |      |      |      |      |
 * |       | move lt | move dn | move rt | scrl dn |       | acl 1 |       |      |      |      |      |
 * |-------+---------+---------+---------+---------+-------+-------+-------+------+------+------+------|
 * |       | mouse   | mouse   | mouse   | mouse   | mouse | mouse |       |      |      |      |      |
 * |       | btn 1   | btn 2   | btn 3   | btn 4   | btn 5 | acl 2 |       |      |      |      |      |
 * |-------+---------+---------+---------+---------+-------+-------+-------+------+------+------+------|
 * |       |         |         |         |         |               |       |      |      |      |      |
 * `--=------------------------------------------------------------------------------------------------'
 */
[_DIRECTIONAL] = {
  {_______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______, KC_ACL0, _______, _______, _______, _______, _______},
  {_______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, KC_ACL1, _______, _______, _______, _______, _______},
  {_______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_ACL2, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        SEND_STRING("mode just switched to QWERTY and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
      case QWERTYX2C:
        if (record->event.pressed) {
          SEND_STRING("mode just switched to QWERTYX2C with double-tap Control-letter on each key\n");
          set_single_persistent_default_layer(_QWERTYX2C);
        }
        return false;
        break;

    case COLEMAK:
      if (record->event.pressed) {
        SEND_STRING("mode just switched to COLEMAK and this is a huge string\n");
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        SEND_STRING("mode just switched to DVORAK and this is a huge string\n");
        set_single_persistent_default_layer(_DVORAK);
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
}
