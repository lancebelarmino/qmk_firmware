#include QMK_KEYBOARD_H
#include <stdio.h>

// Layer declarations
enum {
  COLEMAK = 0,
  MOD_ARR,
  FUN_NUM,
  SYMBOLS,
  COMPOSE,

  NUM_LAYERS
};


// Custom keycodes
#define ____ KC_TRNS
#define XXXX KC_NO
//   Left
//     Home row mods
#define KC_A_ LALT_T(KC_A)
#define KC_R_ LGUI_T(KC_R)
#define KC_S_ LCTL_T(KC_S)
#define KC_T_ LSFT_T(KC_T)
//     Layer toggles
#define KC_BSP_ LT(MOD_ARR, KC_BSPC)
#define KC_ESC_ LT(FUN_NUM, KC_ESC)
#define KC_D_   LT(SYMBOLS, KC_D)
//   Right
//     Home-row mods
#define KC_N_ RSFT_T(KC_N)
#define KC_E_ RCTL_T(KC_E)
#define KC_I_ RGUI_T(KC_I)
#define KC_O_ LALT_T(KC_O)
//     Layer toggles
#define KC_SPC_ LT(MOD_ARR, KC_SPC)
#define KC_ENT_ LT(FUN_NUM, KC_ENT)
#define KC_H_   LT(SYMBOLS, KC_H)
#define KC_TAB_ LT(COMPOSE, KC_TAB)
//  Compose
#define KC_AE RALT(KC_Q)
#define KC_SZ RALT(KC_S)
#define KC_EE RALT(KC_E)
#define KC_IE RALT(KC_I)
#define KC_UE RALT(KC_Y)
#define KC_OE RALT(KC_P)


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
    [COLEMAK] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        KC_A_,   KC_R_,   KC_S_,   KC_T_,   KC_G,                               KC_M,    KC_N_,   KC_E_,   KC_I_,   KC_O_,
        KC_Z,    KC_X,    KC_C,    KC_D_,   KC_V,                               KC_K,    KC_H_,   KC_COMM, KC_DOT,  KC_SLSH,
                                   KC_LGUI, KC_BSP_, KC_ESC_,          KC_ENT_, KC_SPC_, KC_TAB_
    ),

    [MOD_ARR] = LAYOUT_split_3x5_3(
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        XXXX,    XXXX,    XXXX,    KC_CAPS, XXXX,                               KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,XXXX,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                   XXXX,    KC_DEL,  XXXX,             XXXX,    XXXX,    XXXX
    ),
    [FUN_NUM] = LAYOUT_split_3x5_3(
        XXXX,    KC_F4,   KC_F3,   KC_F2,   KC_F1,                              XXXX,    KC_7,    KC_8,    KC_9,    KC_MINS,
        XXXX,    KC_F8,   KC_F7,   KC_F6,   KC_F5,                              KC_QUOT, KC_4,    KC_5,    KC_6,    KC_EQL,
        XXXX,    KC_F12,  KC_F11,  KC_F10,  KC_F9,                              KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,
                                   XXXX,    XXXX,    XXXX,             KC_0,    KC_0,    KC_DOT
    ),
    [SYMBOLS] = LAYOUT_split_3x5_3(
        KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,                            KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
        KC_EXLM, XXXX,    XXXX,    XXXX,    XXXX,                               KC_DQUO, XXXX,    KC_LBRC, KC_RBRC, KC_PLUS,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               KC_TILD, XXXX,    KC_LCBR, KC_RCBR, KC_PIPE,
                                   XXXX,    XXXX,    XXXX,             XXXX,    XXXX,    XXXX
    ),
    [COMPOSE] = LAYOUT_split_3x5_3(
       KC_AE,   XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    KC_UE,   KC_OE,
       XXXX,    XXXX,    KC_SZ,   XXXX,    XXXX,                               XXXX,    XXXX,    KC_EE,   KC_IE,    XXXX,
       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                  XXXX,    XXXX,    XXXX,             XXXX,    XXXX,    XXXX
    )
    /*[<TMPL>] = LAYOUT_split_3x5_3(
     *   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
     *   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
     *   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
     *                              XXXX,    XXXX,    XXXX,             XXXX,    XXXX,    XXXX
     *)
     */
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_T):
        case RSFT_T(KC_N):
        case LT(COMPOSE, KC_TAB):
            return TAPPING_TERM_SFT;
        default:
            return TAPPING_TERM;
    }
}
