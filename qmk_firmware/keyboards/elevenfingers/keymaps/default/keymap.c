//TODO - how to get into nav layer
//TODO - encoder mappings
//TODO - left right oled
#include QMK_KEYBOARD_H

#define _BASE 0
#define _SHIFT 1
#define _NAV 2
#define _NUM 3

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
[_BASE]  =  { ENCODER_CCW_CW(KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },     // volume, todo-scroll though open apps
[_SHIFT] =  { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),                  ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },                       // unused (left thumb occupied), todo - scroll thorugh browser tabs
[_NAV]   =  { ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT),      ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },             // scroll left/right up/down in nav layer
[_NUM]   =  { ENCODER_CCW_CW(KC_MS_LEFT, KC_MS_RIGHT),            ENCODER_CCW_CW(KC_MS_UP, KC_MS_DOWN) }                    // tbd
};
#endif

/* Implementing as "_Shift" layer
const key_override_t colon_key_override = ko_make_basic(KC_LSFT, KC_COLN, KC_SEMICOLON);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &colon_key_override,
    NULL // Null terminate the array of overrides!
};
*/

//Tap dance defs
enum {
        TD_QUOT,
        TD_TLDA,
        TD_LPRN,
        TD_RPRN,
};

void dance_quot_finished(qk_tap_dance_state_t *state, void *user_data){
        switch(state->count){
                case 1:
                        register_code16(KC_QUOTE);
                        break;
                case 2:
                        register_code(KC_GRAVE);
                        break;
        }
}

void dance_quot_reset(qk_tap_dance_state_t *state, void *user_data){
        switch(state->count){
                case 1:
                        unregister_code16(KC_QUOTE);
                        break;
                case 2:
                        unregister_code(KC_GRAVE);
                        break;
        }
}

void dance_tilda_finished(qk_tap_dance_state_t *state, void *user_data){
        switch(state->count){
                case 1:
                        register_code16(KC_MINUS);
                        break;
                case 2:
                        register_code16(KC_TILDE);
                        break;
        }
}

void dance_tilda_reset(qk_tap_dance_state_t *state, void *user_data){
        switch(state->count){
                case 1:
                        unregister_code16(KC_MINUS);
                        break;
                case 2:
                        unregister_code16(KC_TILDE);
                        break;
        }
}

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
        [TD_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_quot_finished, dance_quot_reset),
        [TD_TLDA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_tilda_finished, dance_tilda_reset),
        [TD_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_left_paren_finished, dance_left_paren_reset),
        [TD_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_right_paren_finished, dance_right_paren_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT( \
  RGB_TOG,  KC_0,     KC_1,     KC_2,  KC_UNDS,   TD(TD_QUOT),                                           TD(TD_LPRN), TD(TD_RPRN),  KC_MINS,  KC_PLUS,   KC_EQL, KC_BSPC, \
  _______,  KC_Q,     KC_W,     KC_F,     KC_P,          KC_B,                                                  KC_J,        KC_L,     KC_U,     KC_Y,  KC_COLN,  KC_DEL, \
  KC_LEAD,  KC_A,     KC_R,     KC_S,     KC_T,          KC_G,                                                  KC_M,        KC_N,     KC_E,     KC_I,     KC_O,  KC_ENT, \
  KC_LGUI,  KC_Z,     KC_X,     KC_C,     KC_D,          KC_V,                                                  KC_K,        KC_H,  KC_COMM,   KC_DOT,  KC_SLSH, KC_BSLS, \
                  TO(_NAV), TO(_NUM),  KC_LALT,    MO(_SHIFT),  KC_LCTL,  MO(_NUM),      MO(_NAV),  KC_TAB,   KC_SPC,      KC_INS,  _______,  _______ \
),

[_SHIFT] = LAYOUT( \
  _______,  S(KC_0),  S(KC_1),  S(KC_2),   KC_MINS, S(KC_QUOT),                                                     KC_LCBR,  KC_RCBR,    KC_TILD,   _______,     _______, S(KC_BSPC), \
  _______,  S(KC_Q),  S(KC_W),  S(KC_F),   S(KC_P),    S(KC_B),                                                     S(KC_J),  S(KC_L),    S(KC_U),   S(KC_Y),     KC_SCLN,  S(KC_DEL), \
  _______,  S(KC_A),  S(KC_R),  S(KC_S),   S(KC_T),    S(KC_G),                                                     S(KC_M),  S(KC_N),    S(KC_E),   S(KC_I),     S(KC_O),  S(KC_ENT), \
  _______,  S(KC_Z),  S(KC_X),  S(KC_C),   S(KC_D),    S(KC_V),                                                     S(KC_K),  S(KC_H), S(KC_COMM), S(KC_DOT),  S(KC_SLSH), S(KC_BSLS), \
                     TO(_NAV), TO(_NUM),S(KC_LALT),    _______,  S(KC_LCTL),  MO(_NUM),      MO(_NAV), S(KC_TAB), S(KC_SPC), S(KC_INS),  _______,  _______ \
),

[_NAV] = LAYOUT( \
  _______,  _______,  _______,  _______,  _______,  _______,                                                 _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  KC_PSCR,  _______,                                                 _______,  _______,    KC_UP,  KC_PGUP,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,                                                 _______,  KC_LEFT,  KC_DOWN, KC_RIGHT,  _______,  _______, \
  _______,  _______,   KC_ESC,  _______,  _______,  _______,                                                 _______,  KC_HOME,  KC_PGDN,   KC_END,  _______,  _______, \
                      _______,  _______,  _______,  KC_LSFT,  _______,  _______,         _______,  _______,  _______,  _______,  _______,  _______  \
),

[_NUM] = LAYOUT( \
  _______,  _______,   KC_F10,   KC_F11,    KC_F12,  _______,                                                 _______,   _______, KC_MINS,  KC_PLUS,   KC_EQL, _______,  \
  _______,  _______,    KC_F7,    KC_F8,     KC_F9,  _______,                                                 _______,      KC_7,    KC_8,     KC_9,  KC_COLN, _______,  \
  _______,  _______,    KC_F4,    KC_F5,     KC_F6,  _______,                                                 _______,      KC_4,    KC_5,     KC_6,  KC_PAST, _______,  \
  _______,  _______,    KC_F1,    KC_F2,     KC_F3,  _______,                                                 _______,      KC_1,    KC_2,     KC_3,  KC_PSLS, _______,  \
                      _______,  _______,   _______,  KC_LSFT,  _______,  _______,         _______,  _______,  _______,      KC_0, KC_COMM,   KC_DOT \
)

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



#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation){
    if(is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_180;
}
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);
}
//Setup some mask which can be or'd with bytes to turn off pixels
const uint8_t single_bit_masks[8] = {127, 191, 223, 239, 247, 251, 253, 254};

static void fade_display(void) {
    //Define the reader structure
    oled_buffer_reader_t reader;
    uint8_t buff_char;
    if (random() % 30 == 0) {
        srand(timer_read());
        // Fetch a pointer for the buffer byte at index 0. The return structure
        // will have the pointer and the number of bytes remaining from this
        // index position if we want to perform a sequential read by
        // incrementing the buffer pointer
        reader = oled_read_raw(0);
        //Loop over the remaining buffer and erase pixels as we go
        for (uint16_t i = 0; i < reader.remaining_element_count; i++) {
            //Get the actual byte in the buffer by dereferencing the pointer
            buff_char = *reader.current_element;
            if (buff_char != 0) {
                oled_write_raw_byte(buff_char & single_bit_masks[rand() % 8], i);
            }
            //increment the pointer to fetch a new byte during the next loop
            reader.current_element++;
        }
    }
}

bool oled_task_user(void) {
    if(is_keyboard_master()) {
            switch (get_highest_layer(layer_state)) {
                    case _NUM:
                            oled_write_P(PSTR(">Num\n"), false);
                            oled_write_P(PSTR(" Nav\n"), false);
                            oled_write_P(PSTR(" Shft"), false);
                            oled_write_P(PSTR(" Base\n"), false);
                            break;
                    case _NAV:
                            oled_write_P(PSTR(" Num\n"), false);
                            oled_write_P(PSTR(">Nav\n"), false);
                            oled_write_P(PSTR(" Shft"), false);
                            oled_write_P(PSTR(" Base\n"), false);
                            break;
                    case _SHIFT:
                            oled_write_P(PSTR(" Num\n"), false);
                            oled_write_P(PSTR(" Nav\n"), false);
                            oled_write_P(PSTR(">Shft"), false);
                            oled_write_P(PSTR(" Base\n"), false);
                            break;
                    case _BASE:
                            oled_write_P(PSTR(" Num\n"), false);
                            oled_write_P(PSTR(" Nav\n"), false);
                            oled_write_P(PSTR(" Shft"), false);
                            oled_write_P(PSTR(">Base\n"), false);
                            break;
                    default:
                            oled_write_P(PSTR("XXXXX"), false);
                            oled_write_P(PSTR(" Unk "), false);
                            oled_write_P(PSTR("Layer"), false);
                            oled_write_P(PSTR("XXXXX"), false);
                            break;
            }

            // Host Keyboard LED Status
            oled_write_P(PSTR("Locks"), false);
            led_t led_state = host_keyboard_led_state();
            oled_write_P(led_state.num_lock ? PSTR("\n") : PSTR("!NUM\n"), false);
            oled_write_P(led_state.caps_lock ? PSTR("CAP\n") : PSTR("\n"), false);
            oled_write_P(led_state.scroll_lock ? PSTR("SCR\n") : PSTR("\n"), false);
    }
    else {
            render_logo();
            fade_display();
    }

    return false;

    
}
#endif

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
            case _NUM:
                if (index == 0) {
                    if (clockwise) {
                        tap_code(KC_VOLU);
                    } else {
                        tap_code(KC_VOLD);
                    }
                }
                else {
                    if (clockwise) {
                        tap_code(RGB_VAD);
                    } else {
                        tap_code(RGB_VAI);
                    }
                }
                break;
            case _NAV:
                if (index == 0) {
                    if (clockwise) {
                        tap_code(KC_VOLU);
                    } else {
                        tap_code(KC_VOLD);
                    }
                }
                else {
                    if (clockwise) {
                        tap_code(RGB_VAD);
                    } else {
                        tap_code(RGB_VAI);
                    }
                }
                break;
            case _SHIFT:
                if (index == 0) {
                    if (clockwise) {
                        tap_code(KC_VOLU);
                    } else {
                        tap_code(KC_VOLD);
                    }
                }
                else {
                    if (clockwise) {
                        tap_code(RGB_VAD);
                    } else {
                        tap_code(RGB_VAI);
                    }
                }
                break;
            case _BASE:
                if (index == 0) {
                    if (clockwise) {
                        tap_code(KC_VOLU);
                    } else {
                        tap_code(KC_VOLD);
                    }
                }
                else {
                    if (clockwise) {
                        tap_code(RGB_VAD);
                    } else {
                        tap_code(RGB_VAI);
                    }
                }
                break;
            default:
                    break;
    }
    return true;
}

#endif
