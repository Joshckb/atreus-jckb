#include QMK_KEYBOARD_H

#include "joshckb/joshckb.h"

#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    HOME_A,  HOME_S, HOME_D, HOME_F, KC_G,                      KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN,
    KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_GESC, KC_NO,  KC_NO,  KC_TAB, MO(_RS),  KC_SPC, KC_ENT,  MO(_LW), KC_BSPC, KC_MINS, KC_QUOT, KC_TAB
  ),

  [_DV] = LAYOUT( /* Dvorak */
    KC_SCLN, KC_COMM, KC_DOT, KC_P,   KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_BSLS,
    HOME_A,  HOME_O,  HOME_E, HOME_U, KC_I,                      KC_D,    HOME_H,  HOME_T,  HOME_N,  HOME_SS,
    KC_QUOT, KC_Q,    KC_J,   KC_K,   KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
    KC_GESC, KC_NO,   KC_NO,  KC_TAB, MO(_RS),  KC_SPC, KC_ENT,  MO(_LW), KC_BSPC, KC_MINS, KC_SLSH, KC_NO
  ),

  [_RS] = LAYOUT( /* Raise */
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    KC_EQL,  CUT,   KC_LPRN, KC_RPRN, KC_GRV,
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                    KC_BSLS, COPY,  KC_LCBR, KC_RCBR, KC_DQUO,
    KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,   PASTE, KC_LBRC, KC_RBRC, KC_RSFT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_NO, KC_NO,  MO(_NV), KC_NO, KC_UNDS, TO(_AD), KC_DEL
  ),

  [_LW] = LAYOUT( /* Lower */
    KC_CAPS, KC_MPRV, KC_MPLY, KC_MNXT, ALT_TAB,                 KC_PGUP, KC_F1, KC_F2,   KC_F3,  KC_F4,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CTL_TAB,                 KC_PGDN, KC_F5, KC_F6,   KC_F7,  KC_F8,
    KC_LSFT, KC_MUTE, KC_VOLD, KC_VOLU, KC_HOME,                 KC_END,  KC_F9, KC_F10,  KC_F11, KC_F12,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_NV),  KC_NO, KC_NO,  KC_TRNS, KC_NO, KC_TRNS, KC_NO,  KC_NO
  ),

  [_NV] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    NAV_1, NAV_2, NAV_3, NAV_4, KC_NO,                 KC_NO, NAV_5, NAV_6, NAV_7, NAV_8,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),

  [_AD] = LAYOUT( /* Adjust */
    KC_RESET, KC_NO, KC_NO, OS_MAC, OS_PC,                  KC_NLCK,  KC_P7,   KC_P8,   KC_P9, KC_PPLS,
    KC_NO,    KC_NO, KC_NO, DVORAK, QWERTY,                 KC_PAST,  KC_P4,   KC_P5,   KC_P6, KC_PMNS,
    KC_NO,    KC_NO, KC_NO, KC_NO,  KC_NO,                  KC_PSLS,  KC_P1,   KC_P2,   KC_P3, KC_PEQL,
    KC_NO,    KC_NO, KC_NO, KC_NO,  KC_NO,   KC_NO, KC_NO,  KC_ENTER, KC_RALT, KC_MINS, KC_P0, KC_BSPC
  ),

};

