#include QMK_KEYBOARD_H

enum layer_number {
  _QW = 0,
  _DV,
  _LW,
  _RS,
  _AD,
};

enum custom_keycode {
    ALT_TAB = SAFE_RANGE,
    CTL_TAB,
    QWERTY,
    DVORAK,
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool is_clt_tab_active = false;
uint16_t clt_tab_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,           KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,           KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    LSFT_T(KC_Z),   KC_X,    KC_C,    KC_V,    KC_B,                              KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
    KC_GESC,        KC_TAB,  KC_LALT, KC_LGUI, MO(_RS),  LCTL_T(KC_SPC), KC_ENT,  MO(_LW), KC_MINS, KC_RALT, KC_QUOT, KC_BSPC
  ),

  [_DV] = LAYOUT( /* Dvorak */
    KC_SCLN,        KC_COMM, KC_DOT,  KC_P,    KC_Y,                                KC_F,    KC_G,    KC_C,    KC_R,    KC_BSLS,
    KC_A,           KC_O,    KC_E,    KC_U,    KC_I,                                KC_D,    KC_H,    KC_T,    KC_N,    KC_S,
    LSFT_T(KC_Z),   KC_Q,    KC_J,    KC_K,    KC_X,                                KC_B,    KC_M,    KC_W,    KC_V,    RSFT_T(KC_Z),
    KC_GESC,        KC_TAB,  KC_LALT, KC_LGUI, MO(_RS),  LCTL_T(KC_SPC), KC_ENT,    MO(_LW), KC_RALT, KC_MINS, KC_SLSH, KC_BSPC
  ),

  [_RS] = LAYOUT( /* Raise */
    KC_1,      KC_2,    KC_3,    KC_4,    KC_5,                      KC_EQL,   KC_PSTE,    KC_LPRN,    KC_RPRN,    KC_DEL,
    KC_6,      KC_7,    KC_8,    KC_9,    KC_0,                      KC_BSLS,  KC_COPY,    KC_LCBR,    KC_RCBR,    KC_DQUO,
    KC_LSFT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_GRV,   KC_CUT,     KC_LBRC,    KC_LBRC,    KC_RSFT,
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,  KC_RCTL,  KC_LGUI,  KC_UNDS,    KC_TRNS,    TO(_AD),    KC_PIPE
  ),

  [_LW] = LAYOUT( /* Lower */
    KC_CAPS,   KC_MPRV,    KC_MPLY,    KC_MNXT,    ALT_TAB,                  KC_HOME,     KC_F1,     KC_F2,    KC_F3,    KC_F4,
    KC_LEFT,   KC_DOWN,    KC_UP,      KC_RGHT,    CTL_TAB,                  KC_END,      KC_F5,     KC_F6,    KC_F7,    KC_F8,
    KC_LSFT,   KC_NO,      KC_VOLD,    KC_VOLU,    KC_MUTE,                  KC_NO,       KC_F9,     KC_F10,   KC_F11,   KC_F12,
    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_LGUI, KC_LCTL, KC_NO,  KC_TRNS,     KC_NO,     KC_TRNS,  KC_NO,    KC_NO
  ),

  [_AD] = LAYOUT( /* Adjust */
    TG(_AD),   KC_NO,    KC_NO,    DVORAK,  QWERTY,                   KC_NLCK,    KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
    KC_NO,     KC_NO,    KC_NO,    KC_NO,   KC_NO,                    KC_PAST,    KC_P4,    KC_P5,    KC_P6,    KC_PMNS,
    KC_NO,     KC_NO,    KC_NO,    KC_NO,   KC_NO,                    KC_PSLS,    KC_P1,    KC_P2,    KC_P3,    KC_PEQL,
    RESET,     KC_NO,    KC_NO,    KC_NO,   KC_NO,  KC_NO, KC_NO,     KC_ENTER,   KC_RALT,  KC_MINS,  KC_P0,    KC_BSPC
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case CTL_TAB:
            if (record->event.pressed) {
                if (!is_clt_tab_active) {
                    is_clt_tab_active = true;
                    register_code(KC_LCTL);
                }
                clt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QW);
            }
        break;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DV);
            }
        break;
    }

    return true;
}

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > TAB_TIMER_TERM) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }

    if (is_clt_tab_active) {
        if (timer_elapsed(clt_tab_timer) > TAB_TIMER_TERM) {
            unregister_code(KC_LCTL);
            is_clt_tab_active = false;
        }
    }
}

