#include "chocopad.h"

#define _BASE 0

#define _______ KC_TRNS

enum 4x4_keycodes {
  TD_C_CTRLC,
  TD_V_CTRLV,
  TD_X_CTRLX,
  TD_Z_CTRLZ
};

// Tap Dance Declarations
enum {
    TD_C_CTRLC,
    TD_V_CTRLV,
    TD_X_CTRLX,
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
  [TD_C_CTRLC] = ACTION_TAP_DANCE_DOUBLE(KC_C, LCTL(KC_C))
 ,[TD_V_CTRLV] = ACTION_TAP_DANCE_DOUBLE(KC_V, LCTL(KC_V))
 ,[TD_X_CTRLX] = ACTION_TAP_DANCE_DOUBLE(KC_X, LCTL(KC_X))
 ,[TD_Z_CTRLZ] = ACTION_TAP_DANCE_DOUBLE(KC_Z, LCTL(KC_Z))
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = KEYMAP {
  LSFT(LALT(LCTL(KC_F9))), LSFT(LALT(LCTL(KC_F10))), LSFT(LALT(LCTL(KC_F11))), LSFT(LALT(LCTL(KC_F12))),
  LSFT(LALT(LCTL(KC_F4))), LSFT(LALT(LCTL(KC_F5))),  LSFT(LALT(LCTL(KC_F6))),  LSFT(LALT(LCTL(KC_F7))),
  LSFT(LALT(LCTL(KC_F1))), LSFT(LALT(LCTL(KC_F2))),  LSFT(LALT(LCTL(KC_F3))),  LSFT(LALT(LCTL(KC_F4))),
  TD(TD_Z_CTRLZ),          TD(TD_X_CTRLX),           TD(TD_C_CTRLC),           TD(TD_V_CTRLV),
},

};

void matrix_init_user(void) {
}
