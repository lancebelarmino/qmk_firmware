#include QMK_KEYBOARD_H

#include "oneshot.h"

#define LA_NAV MO(NAV)
#define LA_SYM MO(SYM)
#define MT_TS LSFT_T(KC_TAB)
#define MT_ES RSFT_T(KC_ESC)
#define XXXX KC_NO
#define ____ KC_TRNS

enum layers {
    BASE,
    NAV,
    SYM,
    FUN,
};

enum keycodes {
    // Macros
    MR_SP = SAFE_RANGE,
    MR_NT,
    MR_RT,
    MR_NXT,
    MR_PRT,
    MR_SW,
    MR_X,
    MR_C,
    MR_V,
    MR_F,
    MR_S,
    MR_DS,
    MR_AS,
    MR_ZI,
    MR_ZO,
    MR_WF,
    MR_CO,
    MR_CL,
    MR_AT,
    MR_RO,
    MR_ND,
    MR_PD,
    MR_MC,
    MR_SC,

    // One Shot Keys
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_CMD
};

enum {
    // Tap Dance
    TD_Z,

    // Left Hand Combos
    CO_QW,
    CO_WE,
    CO_ER,
    CO_RT,
    CO_FG,
    CO_AS,
    CO_SD,
    CO_DF,
    CO_ZX,
    CO_XC,
    CO_CV,
    CO_VB,

    // Right Hand Combos
    CO_YU,
    CO_UI,
    CO_IO,
    CO_OP,
    CO_HJ,
    CO_JK,
    CO_KL,
    CO_LBSPC,
    CO_NM,
    CO_MCOMM,

    // Both Hands Combos
    CO_SPCENT
};

void dance_undo_finished(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_LGUI);
            register_code(KC_Z);
            break;
        case 2:
            register_code(KC_LGUI);
            register_code(KC_LSFT);  
            register_code(KC_Z);
            break;
        default:
            break;
    }
}

void dance_undo_reset(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            unregister_code(KC_LGUI);
            unregister_code(KC_Z);
            break;
        case 2:
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);  
            unregister_code(KC_Z);
            break;
        default:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_Z] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_undo_finished, dance_undo_reset),
};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM lbspc_combo[] = {KC_L, KC_BSPC, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM spcent_combo[] = {KC_SPC, KC_ENT, COMBO_END};        

combo_t key_combos[] = {
    // Left Hand
    // [CO_QW] = COMBO(qw_combo, MR_AT),
    [CO_WE] = COMBO(we_combo, MR_AS),
    [CO_ER] = COMBO(er_combo, MR_SW),
    [CO_RT] = COMBO(rt_combo, MR_AT),
    [CO_AS] = COMBO(as_combo, KC_LCTL),
    [CO_SD] = COMBO(sd_combo, KC_LOPT),
    [CO_DF] = COMBO(df_combo, KC_RGUI),
    [CO_FG] = COMBO(fg_combo, KC_BSPC),
    [CO_ZX] = COMBO(zx_combo, MR_NT),
    [CO_XC] = COMBO(xc_combo, MR_SC),
    [CO_CV] = COMBO(cv_combo, MR_CO),
    // [CO_VB] = COMBO(vb_combo, MR_WF),

    // Right Hand
    [CO_YU] = COMBO(yu_combo, MR_DS),
    [CO_UI] = COMBO(ui_combo, MR_PRT),
    [CO_IO] = COMBO(io_combo, MR_NXT),
    // [CO_OP] = COMBO(op_combo, MR_CA),
    [CO_HJ] = COMBO(hj_combo, KC_F12),
    [CO_JK] = COMBO(jk_combo, KC_RGUI),
    [CO_KL] = COMBO(kl_combo, KC_ROPT),
    [CO_LBSPC] = COMBO(lbspc_combo, KC_RCTL),
    [CO_NM] = COMBO(nm_combo, MR_CL),
    [CO_MCOMM] = COMBO(mcomm_combo, MR_RO),

    // Both Hands
    [CO_SPCENT] = COMBO(spcent_combo, MR_SP),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_BSPC,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   MT_TS,   LA_NAV,  KC_SPC,           KC_ENT,  LA_SYM,  MT_ES
    ),

    [NAV] = LAYOUT_split_3x5_3(
        MR_WF,   MR_S,    MR_F,    MR_RT,   XXXX,                               XXXX,    XXXX,    KC_UP,   XXXX,    XXXX,
        OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  XXXX,                               KC_WH_U, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,
        TD(TD_Z),MR_X,    MR_C,    MR_V,    MR_PD,                              KC_WH_D, MR_PD,   MR_ND,   XXXX,    XXXX,
                                   XXXX,    ____,    ____,             ____,    ____,    XXXX
    ),
 
    [SYM] = LAYOUT_split_3x5_3(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_LBRC, KC_LPRN, KC_LCBR, KC_EQL,  KC_AT,                              KC_EXLM, KC_QUOT, KC_MINS, KC_GRV,  KC_SCLN,
        KC_RBRC, KC_RPRN, KC_RCBR, KC_AMPR, KC_ASTR,                            KC_HASH, KC_PERC, KC_BSLS, KC_DLR,  KC_CIRC,
                                   XXXX,    ____,    ____,             ____,    ____,    XXXX
    ),

    [FUN] = LAYOUT_split_3x5_3(
        XXXX,    XXXX,    MR_ZO,   MR_ZI,   XXXX,                               XXXX,    KC_F1,   KC_F2,   KC_F3,   KC_F4,
        KC_CAPS, OS_CTRL, OS_ALT,  OS_CMD,  MR_MC,                              XXXX,    KC_F5,   KC_F6,   KC_F7,   KC_F8,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    KC_F9,   KC_F10,  KC_F11,  KC_F12,
                                   XXXX,    ____,   ____,              ____,    ____,    XXXX
    ),
};

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

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;     

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
      case MR_SP:
          // Spotlight
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_SPC);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_SPC);
          }
          break;
      case MR_NT:
          // New tab
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_T);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_T);
          }
          break;
      case MR_RT:
          // Reload tab
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_R);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_R);
          }
          break;
      case MR_RO:
          // Reopen tab
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_T);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_T);
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
      case MR_ND:
          // Next Desktop
          if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_L);
          } else {
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            unregister_code(KC_L);
          }
          break;
      case MR_PD:
          // Previous Desktop
          if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_J);
          } else {
            unregister_code(KC_LCTL);
            unregister_code(KC_LSFT);
            unregister_code(KC_J);
          }
          break;
      case MR_MC:
          // Open Mission Control
          if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_I);
          } else {
            unregister_code(KC_LCTL);
            unregister_code(KC_I);
          }
          break;
      case MR_DS:
          // Terminal Duplicate Session
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_T);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_T);
          }
          break;
      case MR_X:
          // Cut
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_X);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_X);
          }
          break;
      case MR_C:
          // Copy
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_C);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_C);
          }
          break;
      case MR_V:
          // Paste
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_V);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_V);
          }
          break;
      case MR_F:
          // Find
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_F);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_F);
          }
          break;
      case MR_S:
          // Save
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_S);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_S);
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
      case MR_CO:
          // Comment out
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_SLSH);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_SLSH);
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