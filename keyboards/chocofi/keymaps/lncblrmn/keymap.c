#include QMK_KEYBOARD_H

#include "oneshot.h"

#define LR_NAV LT(NAV, KC_ESC)
#define LR_SYM LT(SYM, KC_ESC)
#define LR_MSE TT(MOUSE)
#define LR_FUN TT(FUNC)

#define MT_SPC MT(MOD_LSFT, KC_SPC)
#define MT_ENT MT(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_ENT) 

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
#define MR_WH_L S(KC_WH_U)
#define MR_WH_R S(KC_WH_D)
#define MR_VU C(KC_U)
#define MR_VD C(KC_D)

#define XXXX KC_NO
#define ____ KC_TRNS

enum layers {
    BASE,
    NAV,
    SYM,
    FUNC,
    MOUSE,
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
    CO_JK,
    CO_KL,
    CO_MCOMM,
    CO_COMMDOT,
};

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_BSPC,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   LR_MSE,  LR_NAV,  MT_SPC,           MT_ENT,  LR_SYM,  LR_FUN
    ),

    [NAV] = LAYOUT_split_3x5_3(
        XXXX,    MR_BT,   MR_PRT,  MR_NXT,  MR_W,                               XXXX,    MR_ZO,   XXXX,    MR_ZI,   XXXX,
        OS_CTRL, OS_ALT,  OS_SHFT, OS_CMD,  MR_AT,                              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ____,
        MR_WH_L, KC_WH_D, KC_WH_U, MR_WH_R, MR_SC,                              XXXX,    KC_PGDN, KC_PGUP, XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    [SYM] = LAYOUT_split_3x5_3(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_CIRC,                            KC_PLUS, KC_EXLM, KC_UNDS, KC_DLR,  KC_BSLS,
        KC_0,    KC_4,    KC_5,    KC_6,    KC_AT,                              KC_PIPE, KC_EQL,  KC_LCBR, KC_LBRC, KC_LPRN,
        KC_TILD, KC_7,    KC_8,    KC_9,    XXXX,                               XXXX,    KC_PERC, KC_MINS, KC_HASH, KC_AMPR,
                                   KC_QUOT, KC_COLN, ____,             ____,    ____,    ____
    ),


    // [SYM] = LAYOUT_split_3x5_3(
    //     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_CIRC, KC_EXLM, KC_UNDS, KC_DLR,  KC_TILD,
    //     KC_GRV,  KC_LPRN, KC_LBRC, KC_LCBR, KC_AT,                              KC_PIPE, KC_EQL,  KC_MINS, KC_QUOT, KC_COLN,
    //     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                               KC_PERC, KC_PLUS, KC_AMPR, KC_HASH, KC_BSLS,
    //                                ____,    ____,    ____,             ____,    ____,    ____
    // ),

    // [SYM] = LAYOUT_split_3x5_3(
    //     XXXX,    KC_ASTR, KC_CIRC, KC_EXLM, XXXX,                               XXXX,    KC_UNDS, KC_DLR,  KC_AMPR, XXXX,
    //     KC_QUOT, KC_LPRN, KC_LBRC, KC_LCBR, KC_AT,                              KC_PIPE, KC_EQL,  KC_MINS, KC_COLN, ____,
    //     XXXX,    KC_TILD, KC_PERC, KC_GRV,  XXXX,                               XXXX,    KC_PLUS, KC_HASH, KC_BSLS, XXXX,
    //                                ____,    ____,    ____,             ____,    ____,    ____
    // ),

    [FUNC] = LAYOUT_split_3x5_3(
        XXXX,    KC_F1,   KC_F2,   KC_F3,   XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        XXXX,    KC_F4,   KC_F5,   KC_F6,   XXXX,                               XXXX,    KC_F10,  KC_F11,  KC_F12,  XXXX,
        XXXX,    KC_F7,   KC_F8,   KC_F9,   XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    [MOUSE] = LAYOUT_split_3x5_3(
        XXXX,    MR_BT,   MR_PRT,  MR_NXT,  MR_W,                                XXXX,    MR_ZO,   KC_MS_U, MR_ZI,   XXXX,
        KC_LSFT, KC_LGUI, KC_BTN1, KC_BTN2, MR_AT,                               XXXX,    KC_MS_L, KC_MS_D, KC_MS_R, XXXX,
        MR_WH_L, KC_WH_D, KC_WH_U, MR_WH_R, MR_SC,                               XXXX,    KC_PGDN, KC_PGUP, XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),
};

bool is_alt_tab_active = false;
bool is_ctl_tab_active = false;
uint16_t alt_tab_timer = 0;  

// Combos
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM wr_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM sf_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    [CO_WE] = COMBO(we_combo, MR_Z),
    [CO_ER] = COMBO(er_combo, MR_RZ),
    [CO_WR] = COMBO(wr_combo, MR_AT),
    [CO_SD] = COMBO(sd_combo, KC_TAB),
    [CO_DF] = COMBO(df_combo, QK_REP),
    [CO_SF] = COMBO(sf_combo, KC_LGUI),
    [CO_XC] = COMBO(xc_combo, KC_ENT),
    [CO_CV] = COMBO(cv_combo, KC_BSPC),

    [CO_UI] = COMBO(ui_combo, KC_LEFT),
    [CO_IO] = COMBO(io_combo, KC_RIGHT),
    [CO_JK] = COMBO(jk_combo, MR_VD),
    [CO_KL] = COMBO(kl_combo, MR_VU),
    [CO_MCOMM] = COMBO(mcomm_combo, KC_F3),
    [CO_COMMDOT] = COMBO(commdot_combo, KC_F12),
};

// OSK
oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case KC_CLEAR:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LR_NAV:
    case LR_SYM:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

// Auto Shift
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_LPRN:
        case KC_LBRC:
        case KC_LCBR:
        case KC_COLN:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_LPRN:
            register_code16((!shifted) ? KC_LPRN : KC_RPRN);
            break;
        case KC_LBRC:
            register_code16((!shifted) ? KC_LBRC : KC_RBRC);
            break;
        case KC_LCBR:
            register_code16((!shifted) ? KC_LCBR : KC_RCBR);
            break;
        case KC_COLN:
            register_code16((!shifted) ? KC_COLN : KC_SCLN);
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_LPRN:
            unregister_code16((!shifted) ? KC_LPRN : KC_RPRN);
            break;
        case KC_LBRC:
            unregister_code16((!shifted) ? KC_LBRC : KC_RBRC);
            break;
        case KC_LCBR:
            unregister_code16((!shifted) ? KC_LCBR : KC_RCBR);
            break;
        case KC_COLN:
            unregister_code16((!shifted) ? KC_COLN : KC_SCLN);
            break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

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
      case LR_NAV:
          if (record->event.pressed && record->tap.count > 0) {
                if (get_mods()) {
                    update_oneshot(
                        &os_shft_state, KC_LSFT, OS_SHFT,
                        KC_CLEAR, record
                    );
                    update_oneshot(
                        &os_ctrl_state, KC_LCTL, OS_CTRL,
                        KC_CLEAR, record
                    );
                    update_oneshot(
                        &os_alt_state, KC_LALT, OS_ALT,
                        KC_CLEAR, record
                    );
                    update_oneshot(
                        &os_cmd_state, KC_LCMD, OS_CMD,
                        KC_CLEAR, record
                    );
                    return false;
                }
                return true;
            }
            return true;
    }

    return true;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LGUI);
      is_alt_tab_active = false;
    }
  }

  if (is_ctl_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LCTL);
      is_ctl_tab_active = false;
    }
  }
}