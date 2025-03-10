#pragma once

#define LY_NAV LT(NAV, KC_ESC)
#define LY_SYM LT(SYM, KC_CAPS)
#define LY_NUM LT(NUM, KC_ENT)
#define LY_FCT MO(FUNC)
#define LY_MSE TT(MOUSE)

#define MT_A MT(MOD_LSFT, KC_A)
#define MT_S MT(MOD_LCTL, KC_S)
#define MT_D MT(MOD_LALT, KC_D)
#define MT_F MT(MOD_LGUI, KC_F)
#define MT_J MT(MOD_RGUI, KC_J)
#define MT_K MT(MOD_RALT, KC_K)
#define MT_L MT(MOD_RCTL, KC_L)
#define MT_BSPC MT(MOD_RSFT, KC_BSPC)

#define TM_MINS TD(CT_MINS)
#define TM_UNDS TD(CT_UNDS)
#define TM_DLR TD(CT_DLR)
#define TM_COLN TD(CT_COLN)
#define TM_EQL TD(CT_EQL)
#define TM_LPRN TD(CT_LPRN)
#define TM_RPRN TD(CT_RPRN)
#define TM_QUOT TD(CT_QUOT)
#define TM_LEFT TD(CT_LEFT)
#define TM_DOWN TD(CT_DOWN)
#define TM_RGHT TD(CT_RGHT)

#define MR_WH_L S(KC_WH_U)
#define MR_WH_R S(KC_WH_D)
#define MR_SW G(KC_GRV)
#define MR_X G(KC_X)
#define MR_C G(KC_C)
#define MR_V G(KC_V)
#define MR_CT G(KC_W)
#define MR_RT LSG(KC_T)
#define MR_UN G(KC_Z)
#define MR_SEN S(KC_ENT)
#define MR_RD LSG(KC_Z)

#define XXXX KC_NO
#define ____ KC_TRNS

enum layers {
    BASE,
    NAV,
    SYM,
    NUM,
    FUNC,
    MOUSE
};

enum keycodes {
    // Macros
    MR_NXT = SAFE_RANGE,
    MR_PRT,
    MR_ZI,
    MR_ZO,
    MR_SC,
    MR_RCA,

    // One Shot Keys
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

enum {
    CO_WE,
    CO_ER,
    CO_WR,
    CO_SD,
    CO_DF,
    CO_SF,
    CO_XC,
    CO_CV,
    CO_XV,
    CO_JK,
    CO_KL,
    CO_IK,
    
    CT_MINS,
    CT_UNDS,
    CT_DLR,
    CT_COLN,
    CT_EQL,
    CT_LPRN,
    CT_RPRN,
    CT_QUOT,
    CT_LEFT,
    CT_DOWN,
    CT_RGHT,
};