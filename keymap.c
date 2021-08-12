#include QMK_KEYBOARD_H

enum layer_number {
  _QW = 0,
  _LW,
  _RS,
  _AD,
  _DV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,           KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,           KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    LSFT_T(KC_Z),   KC_X,    KC_C,    KC_V,    KC_B,                              KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
    KC_GESC,        KC_TAB,  KC_LGUI, KC_LALT, MO(_RS),  LCTL_T(KC_SPC), KC_ENT,  MO(_LW), KC_RALT, KC_MINS, KC_QUOT, KC_BSPC
  ),

  [_RS] = LAYOUT( /* Raise */
    LALT(KC_TAB),   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,                    KC_EQL,  KC_LPRN,    KC_RPRN,    KC_CUT,  KC_DEL,
    LGUI(KC_TAB),   KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,                   KC_BSLS, KC_LCBR,    KC_RCBR,    KC_COPY, KC_PSTE,
    KC_LSFT,        KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_GRV,  KC_LBRC,    KC_LBRC,    KC_NO,   KC_RSFT,
    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL, TO(_AD), KC_TRNS, KC_TRNS,    KC_NO,      KC_NO,   KC_NO
  ),

  [_LW] = LAYOUT( /* Lower */
    KC_CAPS,        KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_VOLU,                  KC_NO,    KC_F1,     KC_F2,    KC_F3,    KC_F4,
    KC_LEFT,        KC_UP,      KC_DOWN,    KC_RGHT,    KC_VOLD,                  KC_NO,    KC_F5,     KC_F6,    KC_F7,    KC_F8,
    KC_LSFT,        KC_NO,      KC_NO,      KC_NO,      KC_MUTE,                  KC_F9,    KC_F10,    KC_F11,   KC_F12,   KC_RSFT,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_LCTL, KC_NO,  KC_TRNS,  KC_TRNS,   KC_NO,    KC_NO,    KC_DEL
  ),

  [_AD] = LAYOUT( /* Adjust */
    TG(_AD),        KC_NO,    KC_NO,    DF(_DV), DF(_QW),               KC_NLCK,    KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
    KC_NO,          KC_NO,    KC_NO,    KC_NO,   KC_NO,                 KC_PAST,    KC_P4,    KC_P5,    KC_P6,    KC_PMNS,
    KC_NO,          KC_NO,    KC_NO,    KC_NO,   KC_NO,                 KC_PSLS,    KC_P1,    KC_P2,    KC_P3,    KC_PEQL,
    RESET,          KC_NO,    KC_NO,    KC_NO,   KC_NO,  KC_NO, KC_NO,  KC_NO,      KC_RALT,  KC_MINS,  KC_P0,    KC_ENTER
  ),

  [_DV] = LAYOUT( /* Dvorak */
    KC_SCLN,        KC_COMM, KC_DOT,  KC_P,    KC_Y,                                  KC_F,    KC_G,    KC_C,    KC_R,    KC_BSLS,
    KC_A,           KC_O,    KC_E,    KC_U,    KC_I,                                  KC_D,    KC_H,    KC_T,    KC_N,    KC_S,
    LSFT_T(KC_Z),   KC_Q,    KC_J,    KC_K,    KC_X,                                  KC_B,    KC_M,    KC_W,    KC_V,    RSFT_T(KC_Z),
    KC_GESC,        KC_TAB,  KC_LGUI, KC_LALT, MO(_RS),  LCTL_T(KC_SPC), KC_ENT,      MO(_LW), KC_RALT, KC_MINS, KC_SLSH, KC_BSPC
  ),
};

