/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

#include QMK_KEYBOARD_H

// clang-format off

// flash with
//  qmk flash -kb keychron/q8/ansi_encoder -km dyancat

enum layers{
    MAC_BASE, // QWERTY
    WIN_BASE, // DVORAK
    _FN1,
    _FN2,
    _FN3
};

#define KC_CESC MT(MOD_LCTL, KC_ESC) // ESC or Ctrl
#define KC_SFN1 LT(_FN1, KC_SPC) // Space or Layer 1
#define KC_SLFT C(S(KC_LEFT)) // Ctrl+Shift+Left
#define KC_SRGT C(S(KC_RGHT)) // Ctrl+Shift+Right
#define TD_F189 TD(TD_F18_F19)

//Tap Dance Declarations
enum {
  TD_F18_F19 = 0
};

//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  [TD_F18_F19]  = ACTION_TAP_DANCE_DOUBLE(KC_F18, KC_F19)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_69(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          TD_F189,
        KC_CESC, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,           KC_MPLY,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_DEL,  KC_UP,
        KC_LCTL, KC_LGUI,  KC_LALT,           KC_SFN1,          MO(_FN1), MO(_FN1),         KC_SPC,            MO(_FN2),           KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_69(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_LBRC,  KC_RBRC,  KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_QUOT,  KC_COMM,  KC_DOT,  KC_P,    KC_Y,    KC_F,     KC_G,    KC_C,    KC_R,    KC_L,     KC_SLSH,  KC_EQL,   KC_BSLS,          TD_F189,
        KC_CESC, KC_A,     KC_O,     KC_E,    KC_U,    KC_I,              KC_D,    KC_H,    KC_T,    KC_N,     KC_S,     KC_MINS,  KC_ENT,           KC_MPLY,
        KC_LSFT,           KC_SCLN,  KC_Q,    KC_J,    KC_K,    KC_X,     KC_X,    KC_B,    KC_M,    KC_W,     KC_V,     KC_Z,     KC_DEL,  KC_UP,
        KC_LCTL, KC_LGUI,  KC_LALT,           KC_SFN1,          MO(_FN1), MO(_FN1),         KC_SPC,            MO(_FN2),           KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN1] = LAYOUT_ansi_69(
        _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,           _______,
        _______, _______,  KC_HOME,  KC_UP,   KC_END,  _______, _______,  _______, KC_HOME, KC_UP,   KC_END,   _______,  _______,  _______,          _______,
        _______, KC_SLFT,  KC_LEFT,  KC_DOWN, KC_RGHT, KC_SRGT,           _______, KC_LEFT, KC_DOWN, KC_RGHT,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_FN2] = LAYOUT_ansi_69(
        KC_PWR,  KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,           _______,
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, KC_HOME, KC_UP,    KC_END,   _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______,           _______, _______, _______, KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  QK_BOOT, _______, _______, _______,  _______,  _______,  _______, RGB_MOD,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            RGB_VAD, RGB_TOG, RGB_VAI),

    [_FN3] = LAYOUT_ansi_69(
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN1]   = {ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [_FN2]   = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D)},
    [_FN3]   = {ENCODER_CCW_CW(_______, _______)}
};
#endif // ENCODER_MAP_ENABLE


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CESC:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SFN1:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}