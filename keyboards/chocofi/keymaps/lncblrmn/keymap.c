#include QMK_KEYBOARD_H

#include "oneshot.h"

#define LA_NAV MO(NAV)
#define LA_SYM MO(SYM)
#define LA_DES LT(DES, KC_ESC)
#define LA_WM  LT(WM, KC_SPC)
#define LA_WM2 MO(WM2)
#define LA_NUM MO(NUM)

#define MR_SP G(KC_SPC)
#define MR_QS G(KC_TAB)
#define MR_CO G(KC_SLSH)
#define MR_Z G(KC_Z)
#define MR_RD LSG(KC_Z)
#define MR_X G(KC_X)
#define MR_C G(KC_C)
#define MR_V G(KC_V)
#define MR_S G(KC_S)
#define MR_R G(KC_R)

#define WM_A A(KC_A)
#define WM_S A(KC_S)
#define WM_D A(KC_D)
#define WM_F A(KC_F)
#define WM_AA LSA(KC_A)
#define WM_AS LSA(KC_S)
#define WM_AD LSA(KC_D)
#define WM_AF LSA(KC_F)
#define WM_SM LSA(KC_SCLN)
#define WM_AT A(KC_TAB)
#define WM_LT A(KC_SLSH)
#define WM_LA A(KC_COMM)
#define WM_FU A(KC_I)
#define WM_FD A(KC_K)
#define WM_FL A(KC_J)
#define WM_FR A(KC_L)
#define WM_MU LSA(KC_I)
#define WM_MD LSA(KC_K)
#define WM_ML LSA(KC_J)
#define WM_MR LSA(KC_L)
#define WM_RM LSA(KC_MINS)
#define WM_RP LSA(KC_EQL)
#define WM_FS LSA(KC_H)

#define XXXX KC_NO
#define ____ KC_TRNS

enum layers {
    BASE,
    NAV,
    SYM,
    FUN,
    DES,
    WM,
    WM2,
    NUM
};

enum keycodes {
    // Macros
    MR_NT = SAFE_RANGE,
    MR_RT,
    MR_NXT,
    MR_PRT,
    MR_SW,
    MR_ZI,
    MR_ZO,
    MR_WF,
    MR_CL,
    MR_SC,
    MR_AT,
    MR_AS,

    // One Shot Keys
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_CMD
};

// Combos
enum {
    CO_WE,
    CO_ER,
    CO_SD,
    CO_DF,
    CO_XC,
    CO_CV,
    CO_MCOMM,
    CO_COMMDOT,
    CO_KL
};

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};

combo_t key_combos[] = {
    [CO_WE] = COMBO(we_combo, WM_FR),
    [CO_ER] = COMBO(er_combo, MR_R),
    [CO_SD] = COMBO(sd_combo, KC_TAB),
    [CO_DF] = COMBO(df_combo, MR_S),
    [CO_XC] = COMBO(xc_combo, MR_SP),
    [CO_CV] = COMBO(cv_combo, QK_REP),
    [CO_MCOMM] = COMBO(mcomm_combo, KC_F12),
    [CO_COMMDOT] = COMBO(commdot_combo, KC_F3),

    [CO_KL] = COMBO(kl_combo, KC_ENT),
};

// Auto Shift
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_LBRC:
            return true;
        case KC_LPRN:
            return true;
        case KC_LCBR:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_LBRC:
            register_code16((!shifted) ? KC_LBRC : KC_RBRC);
            break;
        case KC_LPRN:
            register_code16((!shifted) ? KC_LPRN : KC_RPRN);
            break;
        case KC_LCBR:
            register_code16((!shifted) ? KC_LCBR : KC_RCBR);
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            register_code16(keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_LBRC:
            unregister_code16((!shifted) ? KC_LBRC : KC_RBRC);
            break;
        case KC_LPRN:
            unregister_code16((!shifted) ? KC_LPRN : KC_RPRN);
            break;
        case KC_LCBR:
            unregister_code16((!shifted) ? KC_LCBR : KC_RCBR);
            break;
        default:
            unregister_code16(keycode);
    }
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_BSPC,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   LA_DES,  LA_NAV,  LA_WM,            KC_ENT,  LA_SYM,  LA_NUM
    ),
        
    [NAV] = LAYOUT_split_3x5_3(
        XXXX,    XXXX,    MR_PRT,  MR_NXT,  XXXX,                               XXXX,    XXXX,    KC_UP,   XXXX,    XXXX,
        OS_CTRL, OS_ALT,  OS_SHFT, OS_CMD,  XXXX,                               XXXX,    KC_LEFT, KC_DOWN, KC_RGHT, ____,
        MR_Z,    MR_X,    MR_C,    MR_V,    MR_RD,                              XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    [SYM] = LAYOUT_split_3x5_3(
        KC_BSLS, KC_GRV,  KC_DLR,  KC_EXLM, XXXX,                               XXXX,    KC_ASTR, KC_PERC, KC_CIRC, XXXX,
        KC_QUOT, KC_LBRC, KC_LPRN, KC_LCBR, XXXX,                               XXXX,    KC_EQL,  KC_MINS, KC_SCLN, ____,
        KC_PIPE, XXXX,    KC_AMPR, KC_AT,   XXXX,                               XXXX,    KC_PLUS, KC_UNDS, KC_TILD, KC_HASH,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    [NUM] = LAYOUT_split_3x5_3(
        XXXX,    KC_1,    KC_2,    KC_3,    XXXX,                               XXXX,    KC_ASTR, KC_PERC, KC_CIRC, XXXX,
        XXXX,    KC_4,    KC_5,    KC_6,    XXXX,                               XXXX,    KC_EQL,  KC_MINS, KC_SCLN, ____,
        KC_0,    KC_7,    KC_8,    KC_9,    XXXX,                               XXXX,    KC_PLUS, KC_UNDS, KC_TILD, KC_HASH,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    // [MOUSE] = LAYOUT_split_3x5_3(
    //     MR_WF,   XXXX,    MR_ZO,   MR_ZI,   XXXX,                               XXXX,    XXXX,    KC_MS_U, XXXX,    XXXX,
    //     KC_ACL2, KC_ACL0, KC_BTN1, KC_BTN2, MR_SW,                              MR_CL,   KC_MS_L, KC_MS_D, KC_MS_R, XXXX,
    //     XXXX,    XXXX,    XXXX,    KC_CAPS, XXXX,                               XXXX,    KC_WH_U, KC_WH_D, XXXX,    XXXX,
    //                                ____,    ____,    ____,             ____,    ____,    ____
    // ),

    [FUN] = LAYOUT_split_3x5_3(
        MR_WF,   XXXX,    MR_ZO,   MR_ZI,   XXXX,                               XXXX,    KC_F1,   KC_F2,   KC_F3,   KC_F4,
        KC_CAPS, OS_CTRL, OS_ALT,  OS_CMD,  MR_SC,                              MR_CL,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
        XXXX,    XXXX,    XXXX,    KC_CAPS, XXXX,                               XXXX,    KC_F9,   KC_F10,  KC_F11,  KC_F12,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    [DES] = LAYOUT_split_3x5_3(
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    KC_UP,   XXXX,    XXXX,
        KC_LCTL, KC_LOPT, KC_LSFT, KC_LCMD, XXXX,                               XXXX,    KC_LEFT, KC_DOWN, KC_RGHT, ____,
        KC_SPC,  XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    [WM] = LAYOUT_split_3x5_3(
        XXXX,    XXXX,    WM_RM,   WM_RP,   XXXX,                               XXXX,    XXXX,    WM_FU,   XXXX,    XXXX,
        WM_A,    WM_S,    WM_D,    WM_F,    WM_SM,                              XXXX,    WM_FL,   WM_FD,   WM_FR,   ____,
        WM_FS,   XXXX,    XXXX,    WM_AT,   XXXX,                               XXXX,    WM_LA,   WM_LT,   XXXX,    XXXX,
                                   ____,    ____,    ____,             LA_WM2,  ____,    ____
    ),

    [WM2] = LAYOUT_split_3x5_3(
        XXXX,    XXXX,    ____,    ____,    XXXX,                               XXXX,    XXXX,    WM_MU,   XXXX,    XXXX,
        WM_AA,   WM_AS,   WM_AD,   WM_AF,   WM_SM,                              XXXX,    WM_ML,   WM_MD,   WM_MR,   ____,
        ____,    XXXX,    XXXX,    ____,    XXXX,                               XXXX,    ____,    ____,    XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),
};

// OSK
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_NAV:
    case LA_SYM:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;     

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    switch (keycode) {
      case MR_AS:
          // Switch Application
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_TAB);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_TAB);
          }
          break;
      case MR_NXT:
          // Next tab
          if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_LGUI);
            register_code(KC_RIGHT);
          } else {
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
            unregister_code(KC_RIGHT);
          }
          break;
      case MR_PRT:
          // Previous tab
          if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_LGUI);
            register_code(KC_LEFT);
          } else {
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
            unregister_code(KC_LEFT);
          }
          break;
      case MR_SW:
          // Switch Window
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_GRV);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_GRV);
          }
          break;
      case MR_ZI:
          // Zoom in
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_PPLS);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_PPLS);
          }
          break;
      case MR_ZO:
          // Zoom out
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_MINS);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_MINS);
          }
          break;
      case MR_WF:
          // Full screen
          if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_ENT);
          } else {
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
            unregister_code(KC_ENT);
          }
          break;
      case MR_CL:
          // Clear Line
          if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_E);
            register_code(KC_U);
          } else {
            unregister_code(KC_LCTL);
            unregister_code(KC_E);
            unregister_code(KC_U);
          }
          break;
      case MR_SC:
          // Screen Shot Cropped
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_2);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_2);
          }
          break;
      case MR_AT:
          if (record->event.pressed) {
            if (!is_alt_tab_active) {
              is_alt_tab_active = true;
              register_code(KC_LGUI);
            }
            alt_tab_timer = timer_read();
            register_code(KC_TAB);
          } else {
            unregister_code(KC_TAB);
          }
          break;
    }

    return true;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 600) {
      unregister_code(KC_LGUI);
      is_alt_tab_active = false;
    }
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, NAV, SYM, FUN);
}