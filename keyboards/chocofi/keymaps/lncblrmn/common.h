#pragma once

#define LY_NAV LT(NAV, KC_ESC)
#define LY_SYM LT(SYM, KC_CAPS)
#define LY_NUM LT(NUM, KC_ENT)
#define LY_FCT MO(FUNC)
#define LY_MSE TT(MOUSE)

#define MT_A MT(MOD_LCTL, KC_A)
#define MT_S MT(MOD_LALT, KC_S)
#define MT_D MT(MOD_LSFT, KC_D)
#define MT_F MT(MOD_LGUI, KC_F)
#define MT_J MT(MOD_RGUI, KC_J)
#define MT_K MT(MOD_RSFT, KC_K)
#define MT_L MT(MOD_RALT, KC_L)
#define MT_BSPC MT(MOD_RCTL, KC_BSPC)

#define TM_0 TD(CT_0)
#define TM_4 TD(CT_4)
#define TM_5 TD(CT_5)
#define TM_6 TD(CT_6)
#define TM_EQL TD(CT_EQL)
#define TM_LPRN TD(CT_LPRN)
#define TM_RPRN TD(CT_RPRN)
#define TM_COLN TD(CT_COLN)
#define TM_DOWN TD(CT_DOWN)
#define TM_UP TD(CT_UP)
#define TM_RGHT TD(CT_RGHT)

#define MR_WH_L S(KC_WH_U)
#define MR_WH_R S(KC_WH_D)
#define MR_SW G(KC_GRV)
#define MR_ST G(KC_TAB)
#define MR_X G(KC_X)
#define MR_C G(KC_C)
#define MR_V G(KC_V)
#define MR_CT G(KC_W)
#define MR_RT LSG(KC_T)
#define MR_UN G(KC_Z)
#define MR_SEN S(KC_ENT)
#define MR_RD LSG(KC_Z)
#define MR_F G(KC_F)

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
    MR_AT,
    MR_DIR,

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

    CO_UI,
    CO_IO,
    CO_UO,
    CO_JK,
    CO_KL,
    CO_JL,
    CO_MCOMM,
    CO_COMMDOT,
    CO_MDOT,

    CO_UJ,
    CO_IK,
    CO_OL,
    CO_JM,
    CO_KCOMM,
    CO_LDOT,

    CO_NAVSYM,
    
    CT_0,
    CT_4,
    CT_5,
    CT_6,
    CT_EQL,
    CT_LPRN,
    CT_RPRN,
    CT_COLN,
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;  
