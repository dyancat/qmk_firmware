#include QMK_KEYBOARD_H

enum custom_keycodes {
  QWERTY = SAFE_RANGE
};

#define _BASE 0
#define _FN1  1

#define MO_FN1 MO(_FN1)

#define MODS_LCTL_MASK  MOD_BIT(KC_LCTL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_GRV  , KC_1    , KC_2    , KC_3     , KC_4   , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_LBRC , KC_RBRC , KC_BSPC ,  KC_BSPC  , \
    KC_TAB  , KC_QUOT , KC_COMM , KC_DOT   , KC_P   , KC_Y    , KC_F    , KC_G    , KC_C    , KC_R    , KC_L    , KC_SLSH , KC_EQL  , KC_BSLS , \
    KC_ESC  , KC_A    , KC_O    , KC_E     , KC_U   , KC_I    , KC_D    , KC_H    , KC_T    , KC_N    , KC_S    , KC_MINS , KC_ENT  , \
    KC_LSFT , KC_SCLN , KC_Q    , KC_J     , KC_K   , KC_X    , KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    , KC_RSFT , KC_UP   , \
    KC_LCTL , KC_LGUI , KC_LALT , KC_SPC   , MO_FN1 ,           MO_FN1  , KC_SPC  , KC_RALT , KC_RGUI , KC_MENU , KC_RCTL , KC_RCTL
  ),

  [_FN1] = LAYOUT(
    KC_GESC , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_DEL  ,  KC_DEL   , \
    _______ , _______ , _______ , _______ , KC_UP   , _______ , _______ , _______ , KC_UP   , _______ , _______ , _______ , _______ , _______ , \
    _______ , _______ , _______ , KC_LEFT , KC_DOWN , KC_RGHT , KC_HOME , KC_LEFT , KC_DOWN , KC_RGHT , _______ , _______ , _______ , \
    _______ , _______ , _______ , _______ , _______ , _______ , KC_END  , _______ , _______ , _______ , _______ , _______ , _______ , \
    _______ , _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ , _______ , _______ , _______
  )
};

