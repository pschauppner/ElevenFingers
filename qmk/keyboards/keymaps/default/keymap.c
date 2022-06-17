#include QMK_KEYBOARD_H

#define _BL 0
#define _NL 1


//Tap dance defs
enum {
        TD_LPRN,
        TD_RPRN
};

void dance_left_paren_finished(qk_tap_dance_state_t *state, void *user_data){
        switch(state->count){
                case 1:
                        register_code16(KC_LEFT_PAREN);
                        break;
                case 2:
                        register_code(KC_LBRACKET);
                        break;
                case 3:
                        register_code16(KC_LEFT_CURLY_BRACE);
                        break;
        }
}

void dance_left_paren_reset(qk_tap_dance_state_t *state, void *user_data){
        switch(state->count){
                case 1:
                        unregister_code16(KC_LEFT_PAREN);
                        break;
                case 2:
                        unregister_code(KC_LBRACKET);
                        break;
                case 3:
                        unregister_code16(KC_LEFT_CURLY_BRACE);
                        break;
        }
}

void dance_right_paren_finished(qk_tap_dance_state_t *state, void *user_data){
        switch(state->count){
                case 1:
                        register_code16(KC_RIGHT_PAREN);
                        break;
                case 2:
                        register_code(KC_RBRACKET);
                        break;
                case 3:
                        register_code16(KC_RIGHT_CURLY_BRACE);
                        break;
        }
}

void dance_right_paren_reset(qk_tap_dance_state_t *state, void *user_data){
        switch(state->count){
                case 1:
                        unregister_code16(KC_RIGHT_PAREN);
                        break;
                case 2:
                        unregister_code(KC_RBRACKET);
                        break;
                case 3:
                        unregister_code16(KC_RIGHT_CURLY_BRACE);
                        break;
        }
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [TD_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_left_paren_finished, dance_left_paren_reset),
        [TD_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_right_paren_finished, dance_right_paren_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BL] = LAYOUT( \
  DM_REC1,  KC_0,     KC_1,     KC_2,     KC_UNDS,  KC_QUOT,                                           TD(TD_LPRN), TD(TD_RPRN), KC_MINS,  KC_PLUS,  KC_EQL,  KC_BSPC, \
  KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,                                                    KC_J,     KC_L,     KC_U,     KC_Y,     KC_COLN, KC_DEL,  \
  KC_LEAD,  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,                                                    KC_M,     KC_N,     KC_E,     KC_I,     KC_O,    KC_ENT,  \
  KC_LGUI,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,                                                    KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH, KC_BSLS, \
                      KC_LEFT,  KC_RIGHT, KC_LALT,  KC_LSFT,  KC_LCTL,  MO(_NL),         DM_PLY1,  KC_TAB,   KC_SPC,   KC_ESC,   KC_UP,    KC_DOWN \
),

[_NL] = LAYOUT( \
  _______,  _______,  _______,  OUT_BT,   OUT_USB,  OUT_AUTO,                                                _______,  _______,  KC_PSLS,  KC_PAST,  KC_PMNS, _______,  \
  /*_______,  _______,  _______,  _______,  _______,  _______,                                                _______,  _______,  KC_PSLS,  KC_PAST,  KC_PMNS, _______,  \ */
  _______,  _______,  _______,  _______,LALT(KC_PSCR),  _______,                                                 _______,  KC_7,  KC_8,  KC_9,  KC_PPLS, _______,  \
  _______,  _______,  _______,  _______,      _______,  _______,                                                 _______,  KC_4,  KC_5,  KC_6,  KC_PPLS, _______,  \
  _______,  _______,  _______,  _______,      _______,  _______,                                                 _______,  KC_1,  KC_2,  KC_3,  KC_PENT, _______,  \
                      _______,  _______,      _______,  _______,  _______,  _______,         _______,  _______,  _______,  KC_0,  _______,  KC_DOT \
),

/*
[] = LAYOUT( \
  _______,  _______,  _______,  _______,  _______,  _______,                                                 _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,                                                 _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,                                                 _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,                                                 _______,  _______,  _______,  _______,  _______,  _______, \
                      _______,  _______,  _______,  _______,  _______,  _______,         _______,  _______,  _______,  _______,  _______,  _______  \
),
*/

};


LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_P) {
      // Anything you can do in a macro.
      SEND_STRING("pschauppner");
    }
    SEQ_ONE_KEY(KC_Q) {
      // Anything you can do in a macro.
      SEND_STRING("qmk");
    }
    //SEQ_TWO_KEYS(KC_D, KC_D) {
      //SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    //}
    //SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      //SEND_STRING("https://start.duckduckgo.com\n");
    //}
    //SEQ_TWO_KEYS(KC_A, KC_S) {
      //register_code(KC_LGUI);
      //register_code(KC_S);
      //unregister_code(KC_S);
      //unregister_code(KC_LGUI);
    //}
  }
}



#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation){
    return OLED_ROTATION_0;
}

void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BL:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _NL:
            oled_write_P(PSTR("0123456789\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    oled_write_P(PSTR("Locks: "), false);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("     ") : PSTR("!NUM "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
