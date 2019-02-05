/* Copyright 2017 Brian Fong
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
#include "gherkin.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define DEF 0
#define NUM 1
#define SCAF 2
#define DIR 3
#define ETC 4

/////////////// TAP DANCE SECTION START ///////////////
//Tap Dance Declarations (list of my tap dance configurations)
enum {
  TD_SFT_CAPS = 0
  ,TD_Q_ESC
  ,ENT_TAP_DANCE
  ,DEL_TAP_DANCE
  ,CTRLA_TAP_DANCE
  ,CTRLB_TAP_DANCE
  ,CTRLC_TAP_DANCE
  ,TD_D_CTRLD
  ,TD_E_CTRLE
  ,TD_F_CTRLF
  ,TD_G_CTRLG
  ,TD_H_CTRLH
  ,TD_I_CTRLI
  ,TD_J_CTRLJ
  ,TD_K_CTRLK
  ,TD_L_CTRLL
  ,CTRLM_TAP_DANCE
  ,CTRLN_TAP_DANCE
  ,TD_O_CTRLO
  ,TD_P_CTRLP
  ,TD_R_CTRLR
  ,TD_S_CTRLS
  ,TD_T_CTRLT
  ,TD_U_CTRLU
  ,CTRLV_TAP_DANCE
  ,TD_W_CTRLW
  ,CTRLX_TAP_DANCE
  ,TD_Y_CTRLY
  ,CTRLZ_TAP_DANCE
  ,TD_F1_F11
  ,TD_F2_F12
};

///// QUAD FUNCTION TAP DANCE GENERAL SETUP SECTION START /////
///// (no need to edit this section) /////
//Enums used to clearly convey the state of the tap dance
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send SINGLE_TAP twice - NOT DOUBLE_TAP
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
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
//instantialize an instance of 'tap' for the 'ENT' tap dance.
static tap ENTtap_state = {
  .is_press_action = true,
  .state = 0
};

void ENT_finished (qk_tap_dance_state_t *state, void *user_data) {
  ENTtap_state.state = cur_dance(state);
  switch (ENTtap_state.state) {
    case SINGLE_TAP: register_code(KC_SPC); break;
    case SINGLE_HOLD: register_code(KC_LSFT); break;
    case DOUBLE_TAP: register_code(KC_ENT); break;
    case DOUBLE_HOLD: register_code(KC_NO); break; // setting double hold to do nothing (change this if you want)
    case DOUBLE_SINGLE_TAP: register_code(KC_SPC); unregister_code(KC_SPC); register_code(KC_SPC);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void ENT_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (ENTtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_SPC); break;
    case SINGLE_HOLD: unregister_code(KC_LSFT); break;
    case DOUBLE_TAP: unregister_code(KC_ENT); break;
    case DOUBLE_HOLD: unregister_code(KC_NO);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_SPC);
  }
  ENTtap_state.state = 0;
}

//instanalize an instance of 'tap' for the 'DEL' tap dance.
static tap DELtap_state = {
  .is_press_action = true,
  .state = 0
};

void DEL_finished (qk_tap_dance_state_t *state, void *user_data) {
  DELtap_state.state = cur_dance(state);
  switch (DELtap_state.state) {
    case SINGLE_TAP: register_code(KC_BSPC); break;
    case SINGLE_HOLD: register_code(KC_LCTL); break;
    case DOUBLE_TAP: register_code(KC_DEL); break;
    case DOUBLE_HOLD: register_code(KC_NO); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_BSPC); unregister_code(KC_BSPC); register_code(KC_BSPC);
  }
}

void DEL_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (DELtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_BSPC); break;
    case SINGLE_HOLD: unregister_code(KC_LCTL); break;
    case DOUBLE_TAP: unregister_code(KC_DEL); break;
    case DOUBLE_HOLD: unregister_code(KC_NO);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_BSPC);
  }
  DELtap_state.state = 0;
}

//instantialize an instance of 'tap' for the 'A-CTRL-A' tap dance.
static tap CTRLAtap_state = {
  .is_press_action = true,
  .state = 0
};

void CTRLA_finished (qk_tap_dance_state_t *state, void *user_data) {
  CTRLAtap_state.state = cur_dance(state);
  switch (CTRLAtap_state.state) {
    case SINGLE_TAP: register_code(KC_A); break;
    case SINGLE_HOLD: register_code(KC_LSFT); break;
    case DOUBLE_TAP: register_code(KC_LCTL); register_code(KC_A); break;
    case DOUBLE_HOLD: register_code(KC_NO); break; // setting double hold to do nothing (change this if you want)
    case DOUBLE_SINGLE_TAP: register_code(KC_A); unregister_code(KC_A); register_code(KC_A);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void CTRLA_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (CTRLAtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_A); break;
    case SINGLE_HOLD: unregister_code(KC_LSFT); break;
    case DOUBLE_TAP: unregister_code(KC_LCTL); unregister_code(KC_A); break;
    case DOUBLE_HOLD: unregister_code(KC_NO);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_A);
  }
  CTRLAtap_state.state = 0;
}

//instantialize an instance of 'tap' for the 'B-CTRL-B' tap dance.
static tap CTRLBtap_state = {
  .is_press_action = true,
  .state = 0
};

void CTRLB_finished (qk_tap_dance_state_t *state, void *user_data) {
  CTRLBtap_state.state = cur_dance(state);
  switch (CTRLBtap_state.state) {
    case SINGLE_TAP: register_code(KC_B); break;
    case SINGLE_HOLD: layer_on(SCAF); break;
    case DOUBLE_TAP: register_code(KC_LCTL); register_code(KC_B); break;
    case DOUBLE_HOLD: register_code(KC_NO); break; // setting double hold to do nothing (change this if you want)
    case DOUBLE_SINGLE_TAP: register_code(KC_B); unregister_code(KC_B); register_code(KC_B);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void CTRLB_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (CTRLBtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_B); break;
    case SINGLE_HOLD: layer_off(SCAF); break;
    case DOUBLE_TAP: unregister_code(KC_LCTL); unregister_code(KC_B); break;
    case DOUBLE_HOLD: unregister_code(KC_NO);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_B);
  }
  CTRLBtap_state.state = 0;
}

//instantialize an instance of 'tap' for the 'C-CTRL-C' tap dance.
static tap CTRLCtap_state = {
  .is_press_action = true,
  .state = 0
};

void CTRLC_finished (qk_tap_dance_state_t *state, void *user_data) {
  CTRLCtap_state.state = cur_dance(state);
  switch (CTRLCtap_state.state) {
    case SINGLE_TAP: register_code(KC_C); break;
    case SINGLE_HOLD: register_code(KC_LGUI); break;
    case DOUBLE_TAP: register_code(KC_LCTL); register_code(KC_C); break;
    case DOUBLE_HOLD: register_code(KC_NO); break; // setting double hold to do nothing (change this if you want)
    case DOUBLE_SINGLE_TAP: register_code(KC_C); unregister_code(KC_C); register_code(KC_C);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void CTRLC_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (CTRLCtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_C); break;
    case SINGLE_HOLD: unregister_code(KC_LGUI); break;
    case DOUBLE_TAP: unregister_code(KC_LCTL); unregister_code(KC_C); break;
    case DOUBLE_HOLD: unregister_code(KC_NO);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_C);
  }
  CTRLCtap_state.state = 0;
}

//instantialize an instance of 'tap' for the 'N-CTRL-N' tap dance.
static tap CTRLNtap_state = {
  .is_press_action = true,
  .state = 0
};

void CTRLN_finished (qk_tap_dance_state_t *state, void *user_data) {
  CTRLNtap_state.state = cur_dance(state);
  switch (CTRLNtap_state.state) {
    case SINGLE_TAP: register_code(KC_N); break;
    case SINGLE_HOLD: layer_on(NUM); break;
    case DOUBLE_TAP: register_code(KC_LCTL); register_code(KC_N); break;
    case DOUBLE_HOLD: register_code(KC_NO); break; // setting double hold to do nothing (change this if you want)
    case DOUBLE_SINGLE_TAP: register_code(KC_N); unregister_code(KC_N); register_code(KC_N);
    case TRIPLE_TAP: register_code(KC_NO);
    case TRIPLE_HOLD: register_code(KC_LSFT); layer_on(NUM); break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void CTRLN_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (CTRLNtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_N); break;
    case SINGLE_HOLD: layer_off(NUM); break;
    case DOUBLE_TAP: unregister_code(KC_LCTL); unregister_code(KC_N); break;
    case DOUBLE_HOLD: unregister_code(KC_NO);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_N);
    case TRIPLE_TAP: unregister_code(KC_NO);
    case TRIPLE_HOLD: unregister_code(KC_LSFT); layer_off(NUM); break;
  }
  CTRLNtap_state.state = 0;
}

//instantialize an instance of 'tap' for the 'M-CTRL-M' tap dance.
static tap CTRLMtap_state = {
  .is_press_action = true,
  .state = 0
};

void CTRLM_finished (qk_tap_dance_state_t *state, void *user_data) {
  CTRLMtap_state.state = cur_dance(state);
  switch (CTRLMtap_state.state) {
    case SINGLE_TAP: register_code(KC_M); break;
    case SINGLE_HOLD: layer_on(ETC); break;
    case DOUBLE_TAP: register_code(KC_LCTL); register_code(KC_M); break;
    case DOUBLE_HOLD: register_code(KC_NO); break; // setting double hold to do nothing (change this if you want)
    case DOUBLE_SINGLE_TAP: register_code(KC_M); unregister_code(KC_M); register_code(KC_M);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void CTRLM_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (CTRLMtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_M); break;
    case SINGLE_HOLD: layer_off(ETC); break;
    case DOUBLE_TAP: unregister_code(KC_LCTL); unregister_code(KC_M); break;
    case DOUBLE_HOLD: unregister_code(KC_NO);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_M);
  }
  CTRLMtap_state.state = 0;
}


//instantialize an instance of 'tap' for the 'V-CTRL-V' tap dance.
static tap CTRLVtap_state = {
  .is_press_action = true,
  .state = 0
};

void CTRLV_finished (qk_tap_dance_state_t *state, void *user_data) {
  CTRLVtap_state.state = cur_dance(state);
  switch (CTRLVtap_state.state) {
    case SINGLE_TAP: register_code(KC_V); break;
    case SINGLE_HOLD: layer_on(DIR); break;
    case DOUBLE_TAP: register_code(KC_LCTL); register_code(KC_V); break;
    case DOUBLE_HOLD: register_code(KC_NO); break; // setting double hold to do nothing (change this if you want)
    case DOUBLE_SINGLE_TAP: register_code(KC_V); unregister_code(KC_V); register_code(KC_V);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void CTRLV_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (CTRLVtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_V); break;
    case SINGLE_HOLD: layer_off(DIR); break;
    case DOUBLE_TAP: unregister_code(KC_LCTL); unregister_code(KC_V); break;
    case DOUBLE_HOLD: unregister_code(KC_NO);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_V);
  }
  CTRLVtap_state.state = 0;
}

//instantialize an instance of 'tap' for the 'Z-CTRL-Z' tap dance.
static tap CTRLXtap_state = {
  .is_press_action = true,
  .state = 0
};

void CTRLX_finished (qk_tap_dance_state_t *state, void *user_data) {
  CTRLXtap_state.state = cur_dance(state);
  switch (CTRLXtap_state.state) {
    case SINGLE_TAP: register_code(KC_X); break;
    case SINGLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_TAP: register_code(KC_LCTL); register_code(KC_X); break;
    case DOUBLE_HOLD: register_code(KC_NO); break; // setting double hold to do nothing (change this if you want)
    case DOUBLE_SINGLE_TAP: register_code(KC_X); unregister_code(KC_X); register_code(KC_X);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void CTRLX_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (CTRLXtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_X); break;
    case SINGLE_HOLD: unregister_code(KC_LALT); break;
    case DOUBLE_TAP: unregister_code(KC_LCTL); unregister_code(KC_X); break;
    case DOUBLE_HOLD: unregister_code(KC_NO);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
  }
  CTRLXtap_state.state = 0;
}

//instantialize an instance of 'tap' for the 'Z-CTRL-Z' tap dance.
static tap CTRLZtap_state = {
  .is_press_action = true,
  .state = 0
};

void CTRLZ_finished (qk_tap_dance_state_t *state, void *user_data) {
  CTRLZtap_state.state = cur_dance(state);
  switch (CTRLZtap_state.state) {
    case SINGLE_TAP: register_code(KC_Z); break;
    case SINGLE_HOLD: register_code(KC_LCTL); break;
    case DOUBLE_TAP: register_code(KC_LCTL); register_code(KC_Z); break;
    case DOUBLE_HOLD: register_code(KC_NO); break; // setting double hold to do nothing (change this if you want)
    case DOUBLE_SINGLE_TAP: register_code(KC_Z); unregister_code(KC_Z); register_code(KC_Z);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void CTRLZ_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (CTRLZtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_Z); break;
    case SINGLE_HOLD: unregister_code(KC_LCTL); break;
    case DOUBLE_TAP: unregister_code(KC_LCTL); unregister_code(KC_Z); break;
    case DOUBLE_HOLD: unregister_code(KC_NO);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_Z);
  }
  CTRLZtap_state.state = 0;
}

///// QUAD FUNCTION TAP DANCE PERSONALIZATION SECTION END /////

//Tap Dance Definitions
//THIS SECTION HAS TO BE AT THE END OF THE TAP DANCE SECTION
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
// Other declarations would go here, separated by commas, if you have them
 ,[ENT_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ENT_finished, ENT_reset)
 ,[DEL_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, DEL_finished, DEL_reset)
 ,[CTRLA_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CTRLA_finished, CTRLA_reset)
 ,[CTRLB_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CTRLB_finished, CTRLB_reset)
 ,[CTRLC_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CTRLC_finished, CTRLC_reset)
 ,[TD_D_CTRLD] = ACTION_TAP_DANCE_DOUBLE(KC_D, LCTL(KC_D))
 ,[TD_E_CTRLE] = ACTION_TAP_DANCE_DOUBLE(KC_E, LCTL(KC_E))
 ,[TD_F_CTRLF] = ACTION_TAP_DANCE_DOUBLE(KC_F, LCTL(KC_F))
 ,[TD_G_CTRLG] = ACTION_TAP_DANCE_DOUBLE(KC_G, LCTL(KC_G))
 ,[TD_H_CTRLH] = ACTION_TAP_DANCE_DOUBLE(KC_H, LCTL(KC_H))
 ,[TD_I_CTRLI] = ACTION_TAP_DANCE_DOUBLE(KC_I, LCTL(KC_I))
 ,[TD_J_CTRLJ] = ACTION_TAP_DANCE_DOUBLE(KC_J, LCTL(KC_J))
 ,[TD_K_CTRLK] = ACTION_TAP_DANCE_DOUBLE(KC_K, LCTL(KC_K))
 ,[TD_L_CTRLL] = ACTION_TAP_DANCE_DOUBLE(KC_L, LCTL(KC_L))
 ,[CTRLM_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CTRLM_finished, CTRLM_reset)
 ,[CTRLN_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CTRLN_finished, CTRLN_reset)
 ,[TD_O_CTRLO] = ACTION_TAP_DANCE_DOUBLE(KC_O, LCTL(KC_O))
 ,[TD_P_CTRLP] = ACTION_TAP_DANCE_DOUBLE(KC_P, LCTL(KC_P))
 ,[TD_Q_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
 ,[TD_R_CTRLR] = ACTION_TAP_DANCE_DOUBLE(KC_R, LCTL(KC_R))
 ,[TD_S_CTRLS] = ACTION_TAP_DANCE_DOUBLE(KC_S, LCTL(KC_S))
 ,[TD_T_CTRLT] = ACTION_TAP_DANCE_DOUBLE(KC_T, LCTL(KC_T))
 ,[TD_U_CTRLU] = ACTION_TAP_DANCE_DOUBLE(KC_U, LCTL(KC_U))
 ,[CTRLV_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CTRLV_finished, CTRLV_reset)
 ,[TD_W_CTRLW] = ACTION_TAP_DANCE_DOUBLE(KC_W, LCTL(KC_W))
 ,[CTRLX_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CTRLX_finished, CTRLX_reset)
 ,[TD_Y_CTRLY] = ACTION_TAP_DANCE_DOUBLE(KC_Y, LCTL(KC_Y))
 ,[CTRLZ_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CTRLZ_finished, CTRLZ_reset)
 ,[TD_F1_F11] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F11)
 ,[TD_F2_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F12)
};

//In Layer declaration, add tap dance item in place of a key code
//TD(TD_SFT_CAPS)

///////////// TAP DANCE SECTION END ///////////////

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// /* Qwerty
// * .--------------------------------------------------------------------------------------------------------------.
// * | Q        | W        | E        | R        | T        | Y         | U        | I        | O        | P        |
// * | //ESC    | //Ctrl-W | //Ctrl-E | //Ctrl-R | //Ctrl-T | //Ctrl-Y  | //Ctrl-U | //Ctrl-I | //Ctrl-O | //Ctrl-P |
// * |          |          |          |          |          |           |          |          |          |          |
// * |----------+----------+----------+----------+----------+-----------+----------+----------+----------+----------|
// * | A        | S        | D        | F        | G        | H         | J        | K        | L        | SPACE    |
// * | //Ctrl-A | //Ctrl-S | //Ctrl-D | //Ctrl-F | //Ctrl-G | //Ctrl-H  | //Ctrl-J | //Ctrl-K | //Ctrl-L | //ENTER  |
// * | (Shift)  |          |          |          |          |           |          |          |          | (Shift)  |
// * |----------+----------+----------+----------+----------+-----------+----------+----------+----------+----------|
// * | Z        | X        | C        | V        | B        | N         | M        | <        | >        | BkSpc    |
// * | //Ctrl-Z | //Ctrl-X | //Ctrl-C | //Ctrl-V | //Ctrl-B | //Ctrl-N  | //Ctrl-M |          | .        | //Del    |
// * | (Ctrl)   | (Alt)    | (Super)  | (3-DIR)  | (2-SCAF) | (1-NUM)   | (4-ETC)  | (Super)  | (Alt)    | (Ctrl)   |
// * |          |          |          |          |          | ///shftNUM|          |          |          |          |
// * '--------------------------------------------------------------------------------------------------------------'
// */

 [DEF] = KEYMAP( /* Qwerty*/
   TD(TD_Q_ESC),        TD(TD_W_CTRLW),      TD(TD_E_CTRLE),      TD(TD_R_CTRLR),      TD(TD_T_CTRLT),      TD(TD_Y_CTRLY),      TD(TD_U_CTRLU),      TD(TD_I_CTRLI), TD(TD_O_CTRLO),  TD(TD_P_CTRLP),
   TD(CTRLA_TAP_DANCE), TD(TD_S_CTRLS),      TD(TD_D_CTRLD),      TD(TD_F_CTRLF),      TD(TD_G_CTRLG),      TD(TD_H_CTRLH),      TD(TD_J_CTRLJ),      TD(TD_K_CTRLK), TD(TD_L_CTRLL),  TD(ENT_TAP_DANCE),
   TD(CTRLZ_TAP_DANCE), TD(CTRLX_TAP_DANCE), TD(CTRLC_TAP_DANCE), TD(CTRLV_TAP_DANCE), TD(CTRLB_TAP_DANCE), TD(CTRLN_TAP_DANCE), TD(CTRLM_TAP_DANCE), GUI_T(KC_COMM), ALT_T(KC_DOT),   TD(DEL_TAP_DANCE)
  ),
//
// /*
// *  1-NUM Layer - Numbers, Function Keys
// * .----------------------------------------------------------------------------------------------------.
// * |          |        |         |         |          |         |         |         |         |         |
// * | F1       | F2     | F3      | F4      | F5       | F6      | F7      | F8      | F9      | F10     |
// * | //F11    | //F12  |         |         |          |         |         |         |         |         |
// * |----------+--------+---------+---------+----------+---------+---------+---------+---------+---------|
// * | !        | @      | #       | $       | %        | ^       | &       | *       | (       | )       |
// * | 1        | 2      | 3       | 4       | 5        | 6       | 7       | 8       | 9       | 0       |
// * | (Shift)  |        |         |         |          |         |         |         |         | (Shift) |
// * |----------+--------+---------+---------+----------+---------+---------+---------+---------+---------|
// * |          |        |         |         |          |#########|         | <       | >       |         |
// * |          |        |         | Space   | RETURN   |#########| Del     | ,       | .       | BkSpc   |
// * | (Ctrl)   | (Alt)  |         |         |          |#########| (Shift) | (Super) | (Alt)   | (Ctrl)  |
// * '----------------------------------------------------------------------------------------------------'
// */
//
  [NUM] = KEYMAP ( /* Numbers */
    TD(TD_F1_F11), TD(TD_F2_F12), KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,         KC_F8,          KC_F9,         KC_F10,
    KC_1,          KC_2,          KC_3,    KC_4,    KC_5,      KC_6,    KC_7,          KC_8,           KC_9,          KC_0,
    KC_RCTL,       KC_LALT,       KC_TRNS, KC_SPC,  KC_ENTER,  KC_TRNS, SFT_T(KC_DEL), GUI_T(KC_COMM), ALT_T(KC_DOT), CTL_T(KC_BSPC)
  ),
//
//*
// *  SCAF Layer (Shift-Contol-Alt-Function Key)
// * .-----------------------------------------------------------------------------------------.
// * | ~      | SCAF   |SCAF    |SCAF    |SCAF    |SCAF    |SCAF    |        | _      | +      |
// * | `      | 1      |2       |3       |4       |5       |6       |        | -      | =      |
// * |        |        |        |        |        |        |        |        |        |        |
// * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
// * |        | SCAF   |SCAF    |SCAF    |SCAF    |SCAF    |SCAF    | {      | }      | |      |
// * |        | 7      |8       |9       |10      |11      |12      | [      | ]      | \      |
// * |(Shift) |        |        |        |        |        |        |        |        |        |
// * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
// * | CAPS   |        |        |        |########|        |        | :      | "      | ?      |
// * |        |        |        | Tab    |########|        |        | ;      | '      | /      |
// * | (Ctrl) | (Alt   |        |        |########|(Shift) |        |        |        |        |
// * '-----------------------------------------------------------------------------------------'
// */
//

[SCAF] = KEYMAP(
  KC_GRV,          LSFT(LALT(LCTL(KC_F1))),  LSFT(LALT(LCTL(KC_F2))),  LSFT(LALT(LCTL(KC_F3))),  LSFT(LALT(LCTL(KC_F4))),   LSFT(LALT(LCTL(KC_F5))),   LSFT(LALT(LCTL(KC_F6))),   KC_TRNS,      KC_MINUS,     KC_EQUAL,
  SFT_T(KC_TAB),   LSFT(LALT(LCTL(KC_F7))),  LSFT(LALT(LCTL(KC_F8))),  LSFT(LALT(LCTL(KC_F9))),  LSFT(LALT(LCTL(KC_F10))),  LSFT(LALT(LCTL(KC_F11))),  LSFT(LALT(LCTL(KC_F12))),  KC_LBRACKET,  KC_RBRACKET,  SFT_T(KC_BSLASH),
  LCTL_T(KC_CAPS), KC_LALT,                  KC_TRNS,                  KC_TAB,                   KC_TRNS,                   KC_RSFT,                   KC_TRNS,                   KC_SCOLON,      ALT_T(KC_QUOTE),    CTL_T(KC_SLASH)
 ),

//
///*
// *  Directional Modifiers
// * .------------------------------------------------------------------------------------------.
// * |        |        |        |        | mouse   | mouse  | mouse  |        |        |        |
// * | Home   | Up     | PgUp   | Ins    | Scroll  | move   | Scroll |        |        |        |
// * |        |        |        |        | Up      | Up     | Down   |        |        |        |
// * |--------+--------+--------+--------+---------+--------+--------+--------+--------+--------|
// * |        |        |        |        | mouse   | mouse  | mouse  |        |        |        |
// * | Left   | Down   | Right  | Ctrl   | move    | move   | move   |        |        |        |
// * |        |        |        |        | Left    | Down   | Right  |        |        |        |
// * |--------+--------+--------+--------+---------+--------+--------+--------+--------+--------|
// * |        |        |        |########|         | mouse  | mouse  |        |        |        |
// * | End    |        | PgDn   |########|         | button | button |        |        |        |
// * |        | (Alt)   |       |########| (Shift) | 1      | 2      |        | (Alt)  | (Ctrl) |
// * '------------------------------------------------------------------------------------------'
// */
//
[DIR] = KEYMAP( /* Directional Modifiers */
  KC_HOME, KC_UP,   KC_PGUP, KC_INS,  KC_WH_U, KC_MS_U, KC_WH_D, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_LEFT, KC_DOWN, KC_RGHT, KC_LCTL, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_END,  KC_LALT, KC_PGDN, KC_TRNS, KC_LSFT, KC_BTN1, KC_BTN2, KC_TRNS, KC_LALT, KC_RCTL
),
//
//
//  /*
//  *  ETC
// * .-------------------------------------------------------------------------------------------.
// * |        |        |        |        |        |        |        |         |        | BL     |
// * |        |        |        |        |        |        |        |         | MUTE   | Toggle |
// * |        |        |        |        |        |        |        |         |        |        |
// * |--------+--------+--------+--------+--------+--------+--------+---------+--------+--------|
// * |        |        |        | Ctrl-  |        |        |        |         |        |        |
// * |        |        |        | Alt-   | Del    | Space  |        |         | VOL +  | BL +   |
// * |        |        |        | Del    |        |        |        |         |        |        |
// * |--------+--------+--------+--------+--------+--------+--------+---------+--------+--------|
// * |        |        |        |        |        |        |########|         |        |        |
// * |        |        |        |        |        | Enter  |########|         | VOL -  | BL -   |
// * |        |        |        |        |        |        |########| (Shift) |        |        |
// * '-----------------------------------------------------------------------------------------'
// */
//
[ETC] = KEYMAP( /* ETC */
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, BL_TOGG,
  KC_TRNS, KC_TRNS, KC_TRNS, LALT(LCTL(KC_DEL)), KC_DEL,  KC_SPC,  KC_TRNS, KC_TRNS, KC_VOLU, BL_INC,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_ENT,  KC_TRNS, KC_LSFT, KC_VOLD, BL_DEC


 ),
};
