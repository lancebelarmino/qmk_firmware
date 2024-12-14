#include QMK_KEYBOARD_H

#include "oneshot.h"

#define TO_BASE TO(BASE)
#define TO_NAV TO(NAV)
#define LA_NAV LT(NAV, KC_ESC)
#define LA_MS  TT(MOUSE)
#define LA_SYM MO(SYM)
#define LA_NUM MO(NUM)

// #define OS_MEH OSM(MOD_MASK_CSA)

#define LM_BASE LM(BASE, MOD_LCTL | MOD_LSFT | MOD_LALT)

#define MR_ST G(KC_TAB)
#define MR_S G(KC_S)
#define MR_R G(KC_R)
#define MR_SA G(KC_A)
#define MR_X G(KC_X)
#define MR_C G(KC_C)
#define MR_V G(KC_V)
#define MR_Q G(KC_Q)
#define MR_W G(KC_W)
#define MR_Z G(KC_Z)
#define MR_RZ LSG(KC_Z)

#define MT_SPC LSFT_T(KC_SPC)
#define MT_ENT LCTL_T(KC_ENT)
#define MT_A MEH_T(KC_A)

#define XXXX KC_NO
#define ____ KC_TRNS

enum layers {
    BASE,
    NAV,
    S_NAV,
    SYM,
    FUN,
    WM,
    NUM,
    MACRO,
    MOUSE
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
    MR_BT,

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
    CO_XV,

    CO_JK,
    CO_KL,
};

const uint16_t PROGMEM wr_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM xv_combo[] = {KC_X, KC_V, COMBO_END};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};


combo_t key_combos[] = {
    [CO_WE] = COMBO(wr_combo, MR_Z),
    [CO_ER] = COMBO(er_combo, MR_RZ),
    [CO_SD] = COMBO(sd_combo, MR_SW),
    [CO_DF] = COMBO(df_combo, MR_ST),
    [CO_XC] = COMBO(xc_combo, MR_C),
    [CO_CV] = COMBO(cv_combo, MR_V),
    [CO_XV] = COMBO(xv_combo, MR_SA),

    [CO_JK] = COMBO(jk_combo, KC_CAPS),
    // [CO_KL] = COMBO(kl_combo, KC_CAPS),
};

// OSK
oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_NAV:
    case LA_SYM:
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

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_BSPC,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   LM_BASE, LA_NAV,  MT_SPC,           MT_ENT,  LA_SYM,  LA_NUM
    ),
        
    [NAV] = LAYOUT_split_3x5_3(
        TO_NAV,  MR_AT,   MR_PRT,  MR_NXT,  MR_BT,                              XXXX,    KC_PGDN, KC_PGUP, XXXX,    XXXX,
        KC_TAB,  OS_ALT,  OS_SHFT, OS_CMD,  QK_REP,                             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ____,
        MR_Q,    MR_W,    XXXX,    XXXX,    XXXX,                               XXXX,    KC_WH_D, KC_WH_U, XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    [S_NAV] = LAYOUT_split_3x5_3(
        ____,    MR_AT,   MR_PRT,  MR_NXT,  MR_BT,                              XXXX,    KC_PGDN, KC_PGUP, XXXX,    XXXX,
        KC_TAB,  OS_ALT,  OS_SHFT, OS_CMD,  QK_REP,                             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ____,
        MR_Q,    MR_W,    MR_AT,   XXXX,    QK_REP,                             XXXX,    KC_WH_D, KC_WH_U, XXXX,    XXXX,
                                   ____,    TO_BASE, ____,             ____,    ____,    ____
    ),

    [SYM] = LAYOUT_split_3x5_3(
        KC_TILD, KC_CIRC, KC_HASH, KC_EXLM, XXXX,                               XXXX,    KC_UNDS, KC_DLR,  KC_GRV,  KC_BSLS,
        KC_LBRC, KC_LPRN, KC_LCBR, KC_EQL,  KC_AT,                              KC_PLUS, KC_QUOT, KC_MINS, KC_SCLN, KC_COLN,
        KC_RBRC, KC_RPRN, KC_RCBR, KC_AMPR, XXXX,                               XXXX,    KC_DQT,  KC_PIPE, KC_ASTR, KC_PERC,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    [NUM] = LAYOUT_split_3x5_3(
        XXXX,    KC_1,    KC_2,    KC_3,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        KC_0,    KC_4,    KC_5,    KC_6,    XXXX,                               KC_H,    KC_J,    KC_K,    KC_L,    ____,
        XXXX,    KC_7,    KC_8,    KC_9,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    [MOUSE] = LAYOUT_split_3x5_3(
        MR_WF,   XXXX,    MR_ZO,   MR_ZI,   XXXX,                               XXXX,    XXXX,    KC_MS_U, XXXX,    XXXX,
        KC_ACL2, KC_ACL0, KC_BTN1, KC_BTN2, MR_SW,                              KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2,
        XXXX,    XXXX,    KC_LSFT, KC_LGUI, XXXX,                               XXXX,    KC_WH_D, KC_WH_U, XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    [MACRO] = LAYOUT_split_3x5_3(
        XXXX,    KC_F1,   KC_F2,   KC_F3,   XXXX,                               XXXX,    KC_F4,   KC_F5,   KC_F6,   XXXX,
        KC_CAPS, MR_WF,   MR_ZO,   MR_ZI,   MR_SC,                              XXXX,    MR_SC,   XXXX,    XXXX,    XXXX,
        XXXX,    KC_F7,   KC_F8,   KC_F9,   XXXX,                               XXXX,    KC_F10,  KC_F11,  KC_F12,  XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),
};

bool is_alt_tab_active = false;
bool is_ctl_tab_active = false;
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

      case MR_BT:
          if (record->event.pressed) {
            if (!is_ctl_tab_active) {
              is_ctl_tab_active = true;
              register_code(KC_LCTL);
            }
            alt_tab_timer = timer_read();
            register_code(KC_TAB);
          } else {
            unregister_code(KC_TAB);
          }
          break;
      case KC_LEFT:
      case KC_RIGHT:
          if (record->event.pressed) {
              alt_tab_timer = timer_read();
          }
          break;
    }

    return true;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 800) {
      unregister_code(KC_LGUI);
      is_alt_tab_active = false;
    }
  }

  if (is_ctl_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 800) {
      unregister_code(KC_LCTL);
      is_ctl_tab_active = false;
    }
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, NAV, SYM, MACRO);
}