#include QMK_KEYBOARD_H

/*
   How to flash
   ------------

   Open QMK MSYS
   > cd /d/Projects/qmk_firmware
   > qmk flash (assumes config has been setup)
   > qmk flash -kb keebio/quefrency -km dyancat

   If QMK has been updated, may need to flash both sides of the keyboard separately

   https://docs.qmk.fm/#/newbs_flashing
*/


#define LAYOUT_kcq( \
    LA1, LA2, LA3, LA4, LA5, LA6, LA7, RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, \
    LB1, LB2, LB3, LB4, LB5, LB6,      RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, \
    LC1, LC2, LC3, LC4, LC5, LC6,      RC1, RC2, RC3, RC4, RC5, RC6, RC7, \
    LD1, LD2, LD3, LD4, LD5, LD6,      RD1, RD2, RD3, RD4, RD5, RD6, RD7, \
    LE1, LE2, LE3, LE4, LE5,           RE1, RE2, RE3, RE4, RE5, RE6, RE7 \
    ) \
    LAYOUT( \
        KC_##LA1, KC_##LA2, KC_##LA3, KC_##LA4, KC_##LA5, KC_##LA6, KC_##LA7, KC_##RA1, KC_##RA2, KC_##RA3, KC_##RA4, KC_##RA5, KC_##RA6, KC_##RA7, KC_##RA8, \
        KC_##LB1, KC_##LB2, KC_##LB3, KC_##LB4, KC_##LB5, KC_##LB6,           KC_##RB1, KC_##RB2, KC_##RB3, KC_##RB4, KC_##RB5, KC_##RB6, KC_##RB7, KC_##RB8, \
        KC_##LC1, KC_##LC2, KC_##LC3, KC_##LC4, KC_##LC5, KC_##LC6,           KC_##RC1, KC_##RC2, KC_##RC3, KC_##RC4, KC_##RC5, KC_##RC6, KC_##RC7, \
        KC_##LD1, KC_##LD2, KC_##LD3, KC_##LD4, KC_##LD5, KC_##LD6,           KC_##RD1, KC_##RD2, KC_##RD3, KC_##RD4, KC_##RD5, KC_##RD6, KC_##RD7, \
        KC_##LE1, KC_##LE2, KC_##LE3, KC_##LE4, KC_##LE5,                     KC_##RE1, KC_##RE2, KC_##RE3, KC_##RE4, KC_##RE5, KC_##RE6, KC_##RE7 \
    )

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

#define _BASE   0
#define _FN1    1
#define _FN2    2

#define KC_ KC_TRNS
#define KC_FN1 MO(_FN1)
#define KC_FN2 MO(_FN2)
#define KC_FRMT A(S(KC_F))              // Format document
#define KC_LCTE A(S(KC_L))              // Locate file
#define KC_SAVE C(KC_S)                 // Save
#define KC_BULD C(KC_F5)                // Build without debugging
#define KC_AUD1 KC_F18                  // Audio device 1
#define KC_AUD2 KC_F19                  // Audio device 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kcq(
  //|----+----+----+----+----+----+----+              +----+----+----+----+----+----+---------|
     GRV , 1  , 2  , 3  , 4  , 5  , 6  ,                7  , 8  , 9  , 0  ,LBRC,RBRC,, BSPC   ,
  //|----+----+----+----+----+----+----+              +----+----+----+----+----+----+---------|
  //|------+----+----+----+----+----+              +----+----+----+----+----+----+----+-------|
      TAB  ,QUOT,COMM,DOT , P  , Y  ,                F  , G  , C  , R  , L  ,SLSH,EQL ,  BSLS ,
  //|------+----+----+----+----+----+              +----+----+----+----+----+----+----+-------|
  //|-------+----+----+----+----+----+              +----+----+----+----+----+----+-----------|
       ESC  , A  , O  , E  , U  , I  ,                D  , H  , T  , N  , S  ,MINS,    ENT    ,
  //|-------+----+----+----+----+----+              +----+----+----+----+----+----+-----------|
  //|---------+----+----+----+----+----+              +----+----+----+----+----+--------------|
       LSFT   ,SCLN, Q  , J  , K  , X  ,                B  , M  , W  , V  , Z  ,     RSFT    ,,
  //|---------+----+----+----+----+----+              +----+----+----+----+----+--------------|
  //|-----+-----+-----+----------+-----+              +-----+-------+-----+-----+-----+-------|
     LCTL ,LGUI ,LALT ,   SPC    , FN1 ,                FN1 ,  SPC  ,RALT ,RGUI,,RCTL , FN2
  //|-----+-----+-----+----------+-----+              +-----+-------+-----+-----+-----+-------|
  ),

  [_FN1] = LAYOUT_kcq(
  //|----+----+----+----+----+----+----+              +----+----+----+----+----+----+---------|
     GESC, F1 , F2 , F3 , F4 , F5 , F6 ,                F7 , F8 , F9 ,F10 ,F11 ,F12 ,,  DEL   ,
  //|----+----+----+----+----+----+----+              +----+----+----+----+----+----+---------|
  //|------+----+----+----+----+----+              +----+----+----+----+----+----+----+-------|
           ,    ,    , UP ,    ,    ,                   ,PGUP, UP ,PGDN,    ,    ,    ,       ,
  //|------+----+----+----+----+----+              +----+----+----+----+----+----+----+-------|
  //|-------+----+----+----+----+----+              +----+----+----+----+----+----+-----------|
     F13    ,    ,LEFT,DOWN,RGHT,    ,               HOME,LEFT,DOWN,RGHT,SAVE,    ,           ,
  //|-------+----+----+----+----+----+              +----+----+----+----+----+----+-----------|
  //|---------+----+----+----+----+----+              +----+----+----+----+----+--------------|
              ,    ,    ,    ,FRMT,LCTE,               END ,    ,    ,    ,    ,             ,,
  //|---------+----+----+----+----+----+              +----+----+----+----+----+--------------|
  //|-----+-----+-----+----------+-----+              +-----+-------+-----+-----+-----+-------|
          ,     ,     ,          ,     ,                    ,       ,     ,    ,,     ,
  //|-----+-----+-----+----------+-----+              +-----+-------+-----+-----+-----+-------|
  ),

  [_FN2] = LAYOUT_kcq(
  //|----+----+----+----+----+----+----+              +----+----+----+----+----+----+---------|
         ,    ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,PSCR,,  BULD  ,
  //|----+----+----+----+----+----+----+              +----+----+----+----+----+----+---------|
  //|------+----+----+----+----+----+              +----+----+----+----+----+----+----+-------|
           ,    ,    ,    ,    ,    ,               BTN2,BTN1,MS_U,BTN3,    ,    ,    ,       ,
  //|------+----+----+----+----+----+              +----+----+----+----+----+----+----+-------|
  //|-------+----+----+----+----+----+              +----+----+----+----+----+----+-----------|
            ,    ,    ,    ,    ,    ,                   ,MS_L,MS_D,MS_R,    ,    ,           ,
  //|-------+----+----+----+----+----+              +----+----+----+----+----+----+-----------|
  //|---------+----+----+----+----+----+              +----+----+----+----+----+--------------|
              ,    ,    ,    ,    ,    ,                   ,    ,    ,AUD1,AUD2,             ,,
  //|---------+----+----+----+----+----+              +----+----+----+----+----+--------------|
  //|-----+-----+-----+----------+-----+              +-----+-------+-----+-----+-----+-------|
          ,     ,     ,          ,     ,                    ,       ,MUTE ,VOLD,,VOLU ,
  //|-----+-----+-----+----------+-----+              +-----+-------+-----+-----+-----+-------|
  )
};

// If QWERTY is ever needed
/*

  [_QWERTY] = LAYOUT_kcq(
  //|----+----+----+----+----+----+----+              +----+----+----+----+----+----+---------|
     GRV , 1  , 2  , 3  , 4  , 5  , 6  ,                7  , 8  , 9  , 0  ,MINS,EQL ,, BSPC   ,
  //|----+----+----+----+----+----+----+              +----+----+----+----+----+----+---------|
  //|------+----+----+----+----+----+              +----+----+----+----+----+----+----+-------|
      TAB  , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,LBRC,RBRC ,  BSLS ,
  //|------+----+----+----+----+----+              +----+----+----+----+----+----+----+-------|
  //|-------+----+----+----+----+----+              +----+----+----+----+----+----+-----------|
       ESC  , A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,    ENT    ,
  //|-------+----+----+----+----+----+              +----+----+----+----+----+----+-----------|
  //|---------+----+----+----+----+----+              +----+----+----+----+----+--------------|
       LSFT   , Z  , X  , C  , V  , B  ,                N  , M  ,COMM,DOT ,SLSH,     RSFT    ,,
  //|---------+----+----+----+----+----+              +----+----+----+----+----+--------------|
  //|-----+-----+-----+----------+-----+              +-----+-------+-----+-----+-----+-------|
     LCTL ,LGUI ,LALT ,   SPC    , FN1 ,                FN1 ,  SPC  ,RALT ,VOLD,,VOLU , MUTE
  //|-----+-----+-----+----------+-----+              +-----+-------+-----+-----+-----+-------|
  ),

*/