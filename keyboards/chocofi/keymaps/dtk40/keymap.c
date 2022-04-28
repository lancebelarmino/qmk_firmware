#include QMK_KEYBOARD_H
#include <stdio.h>

// Layer declarations
enum {
  COLEMK = 0,
  MOD_ARR,
  FN_NUM,

  NUM_LAYERS
};


// Custom keycodes
#define ____ KC_TRNS
#define XXXX KC_NO
//  Left
//   Home row mods
#define KC_A_ LALT_T(KC_A)
#define KC_R_ LGUI_T(KC_R)
#define KC_S_ LCTL_T(KC_S)
#define KC_T_ LSFT_T(KC_T)
//   Layer toggles
#define KC_BSP_ LT(MOD_ARR, KC_BSPC)
#define KC_ESC_ LT(FN_NUM, KC_ESC)
//  Right
//   Home-row mods
#define KC_N_ RSFT_T(KC_N)
#define KC_E_ RCTL_T(KC_E)
#define KC_I_ RGUI_T(KC_I)
#define KC_O_ LALT_T(KC_O)
//   Layer toggles
#define KC_SPC_ LT(MOD_ARR, KC_SPC)
#define KC_ENT_ LT(FN_NUM, KC_ENT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ F │ P │ B │       │ J │ L │ U │ Y │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ R │ S │ T │ G │       │ M │ N │ E │ I │ O │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ D │ V │       │ K │ H │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │GUI├───┐           ┌───┤Tab│
      *           └───┤Bsp├───┐   ┌───┤   ├───┘
      *               └───┤Esc│   │Ent├───┘
      *                   └───┘   └───┘
      */
    [COLEMK] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        KC_A_,   KC_R_,   KC_S_,   KC_T_,   KC_G,                               KC_M,    KC_N_,   KC_E_,   KC_I_,   KC_O_,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                               KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                   KC_LGUI, KC_BSP_, KC_ESC_,          KC_ENT_, KC_SPC_, KC_TAB
    ),

    [MOD_ARR] = LAYOUT_split_3x5_3(
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        XXXX,    XXXX,    XXXX,    KC_CAPS, XXXX,                               KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,XXXX,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                   XXXX,    KC_DEL,  XXXX,             XXXX,    XXXX,    XXXX
    ),
    [FN_NUM] = LAYOUT_split_3x5_3(
        XXXX,    KC_F4,   KC_F3,   KC_F2,   KC_F1,                              XXXX,    KC_7,    KC_8,    KC_9,    KC_MINS,
        XXXX,    KC_F8,   KC_F7,   KC_F6,   KC_F5,                              KC_QUOT, KC_4,    KC_5,    KC_6,    KC_EQL,
        XXXX,    KC_F12,  KC_F11,  KC_F10,  KC_F9,                              KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,
                                   XXXX,    XXXX,    XXXX,             KC_0,    KC_0,    KC_DOT
    )
    /*[<TMPL>] = LAYOUT_split_3x5_3(
     *   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
     *   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
     *   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
     *                              XXXX,    XXXX,    XXXX,             XXXX,    XXXX,    XXXX
     *)
     */
};
