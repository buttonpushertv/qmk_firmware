//Attempting to create a '2nd Keybaord' out of a Gherkin based on the work here:
//// Taran's github: https://github.com/TaranVH/2nd-keyboard
//
//Taran's project made use of a HASU USB-to-USB converter. I wondered if it was possible to
//flash any QMK-capable keyboard with the same code. It's a default Gherkin layout with the
//F24-wrapping code at the tail end.

#include QMK_KEYBOARD_H

#define FN1_DEL LT(1, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_3x10(
    KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,   KC_J,
    KC_K,    KC_L,    KC_M,    KC_N,    KC_O,    KC_P,    KC_Q,    KC_R,    KC_S,   KC_T,
    KC_U,    KC_V,    KC_W,    FN1_DEL, KC_X,    KC_Y,    KC_Z,    KC_1,    KC_2,   KC_3
  ),

  [1] = LAYOUT_ortho_3x10(
    _______, _______, KC_4,    KC_5,    KC_6,   _______, _______, _______, _______, _______,
    _______, _______, KC_7,    KC_8,    KC_9,   _______, _______, _______, _______, BL_INC,
    _______, _______, KC_0,    _______, KC_DOT, _______, RESET,   _______, _______, BL_DEC
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
