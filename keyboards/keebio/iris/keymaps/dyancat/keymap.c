#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_ KC_TRNS

#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen
#define KC_TABC MT(MOD_LCTL, KC_TAB)    // Control (hold), Tab (tap)
#define KC_ESCC MT(MOD_LCTL, KC_ESC)    // Control (hold), Escape (tap)
#define KC_BACK LGUI(KC_LEFT)           // Browser Back
#define KC_FORW LGUI(KC_RIGHT)          // Browser Forward
#define KC_LPTS S(KC_9)                 // Left parenthesis
#define KC_RPTS S(KC_0)                 // Right parenthesis
#define KC_LAGB S(KC_COMM)              // Left angle bracket
#define KC_RAGB S(KC_DOT)               // Right angle bracket
#define KC_LCLB S(KC_LBRC)              // Left angle bracket
#define KC_RCLB S(KC_RBRC)              // Right angle bracket
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_ENTS MT(MOD_LSFT, KC_ENT)
#define KC_FRMT A(S(KC_F))              // Format document
#define KC_LCTE A(S(KC_L))              // Locate file
#define KC_CNSL C(KC_GRV)               // Open console

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GRV , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB ,QUOT,COMM,DOT , P  , Y  ,                F  , G  , C  , R  , L  ,SLSH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ESCC, A  , O  , E  , U  , I  ,                D  , H  , T  , N  , S  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT,SCLN, Q  , J  , K  , X  ,SPC ,     LALT, B  , M  , W  , V  , Z  ,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,LALT,RASE,         ENT ,LOWR,SPC
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,LAGB,RAGB,    ,    ,                   ,SPC , UP ,LBRC,RBRC,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,LCLB,RCLB,PIPE,    ,               HOME,LEFT,DOWN,RGHT,PLUS,EQL ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,FRMT,LCTE,    ,    ,     RPRN,END ,    ,    ,    ,MINS,ENT ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       SPC ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     DEL ,MPRV,BACK,FORW,PGUP,UNDS,               EQL ,HOME,    ,    ,    ,BSLS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     MUTE,MSTP,MPLY,VOLD,PGDN,MINS,    ,         ,PLUS,END ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RESET  , DEBUG  , RGB_HUD, RGB_SAD, RGB_VAD, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,                  _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  )

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
