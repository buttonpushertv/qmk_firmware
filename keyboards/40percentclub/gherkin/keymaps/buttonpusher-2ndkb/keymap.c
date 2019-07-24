//Attempting to create a '2nd Keybaord' out of a Gherkin based on the work here:
//// Taran's github: https://github.com/TaranVH/2nd-keyboard
//
//Taran's project made use of a HASU USB-to-USB converter. I wondered if it was possible to
//flash any QMK-capable keyboard with the same code. It's a customized layout for a specific application with the
//F24-wrapping code at the tail end. The non-standard layout will be heavily altered in AutoHotKey.

#include QMK_KEYBOARD_H

enum gherkin_layers {
  _DEF,
  _LWR,
  _UPR,
  _ADJ
};

enum gherkin_keycodes {
  DEF = SAFE_RANGE,
  LWR,
  UPR,
  ADJ
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEF] = LAYOUT_ortho_3x10(
    KC_A,    KC_B,    KC_C,    KC_D,     KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,
    KC_K,    LWR,     KC_L,    KC_M,     KC_N,    KC_O,    KC_P,    KC_Q,    UPR,     KC_R,
    KC_S,    KC_T,    KC_U,    KC_V,     KC_W,    KC_X,    KC_Y,    KC_Z,    KC_DOT,  KC_COMM
  ),

  [_LWR] = LAYOUT_ortho_3x10(

    KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    _______, _______, _______,
    KC_8,    _______, KC_9,    KC_0,     KC_MINS, KC_EQL,  KC_SCLN, _______, _______, _______,
    KC_LBRC, KC_RBRC, KC_QUOT, KC_GRV,   KC_SLSH, KC_SPC,  KC_BSPC, _______, _______, _______
  ),

  [_UPR] = LAYOUT_ortho_3x10(
     _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,
     _______, _______, _______, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_F13,
     _______, _______, _______, KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20
  ),

  [_ADJ] = LAYOUT_ortho_3x10(
     _______, _______, _______, _______, _______, _______, _______, _______, _______, BL_INC,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, BL_DEC,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET
  ),

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}


void led_set_user(uint8_t usb_led) {

}

//https://docs.qmk.fm/keycode.txt
//shoutout to drashna on the QMK discord for basically writing this for me.... :P

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t f24_tracker;
    switch (keycode) {
      case LWR:
        if (record->event.pressed) {
          layer_on(_LWR);
          update_tri_layer(_LWR, _UPR, _ADJ);
        } else {
          layer_off(_LWR);
          update_tri_layer(_LWR, _UPR, _ADJ);
        }
        return false;
        break;
      case UPR:
        if (record->event.pressed) {
          layer_on(_UPR);
          update_tri_layer(_LWR, _UPR, _ADJ);
        } else {
          layer_off(_UPR);
          update_tri_layer(_LWR, _UPR, _ADJ);
        }
        return false;
        break;
    case KC_A ... KC_F23: //notice how it skips over F24
    //case KC_EXECUTE ... KC_EXSEL: //exsel is the last one before the modifier keys
        if (record->event.pressed) {
            register_code(KC_F24); //this means to send F24 down
            f24_tracker++;
            register_code(keycode);
        } else {
            unregister_code(keycode);
            f24_tracker--;
            if (!f24_tracker) {
                unregister_code(KC_F24); //this means to send F24 up
            }
            //real key is released HERE
        }
        return false;
        break;
    }
    return true;
}
