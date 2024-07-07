#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"

#define LA_NUM MO(NUM)
#define LA_NAV MO(NAV)
#define LA_SYM MO(SYM)
#define LA_FUN MO(FUN)
#define XXXX KC_NO

enum layers {
    BASE,
    NAV,
    SYM,
    NUM,
    FUN,
};

enum keycodes {
    // Macros
    MR_SP = SAFE_RANGE,
    MR_NT,
    MR_RT,
    MR_CT,
    MR_NXT,
    MR_PRT,
    MR_CW,
    MR_SW,
    MR_X,
    MR_C,
    MR_V,
    MR_F,
    MR_S,
    MR_DS,
    MR_AS,
    MR_CS,
    MR_ZI,
    MR_ZO,
    MR_DL,
    MR_WF,
    MR_CO,
    MR_CA,
    MR_CL,

    // Swapper
    SW_WIN,

    // One Shot Keys
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_CMD
};

enum {
    // Tap Dance
    TD_Z,
    TD_T,

    // Left Hand Combos
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
    CO_UI,
    CO_IO,
    CO_OP,
    CO_HJ,
    CO_JK,
    CO_KL,
    CO_NM,
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

void dance_tab_finished(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_LGUI);
            register_code(KC_W);
            break;
        case 2:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_T);
            break;
        default:
            break;
    }
}

void dance_tab_reset(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            unregister_code(KC_LGUI);
            unregister_code(KC_W);
            break;
        case 2:
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_T);
            break;
        default:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_Z] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_undo_finished, dance_undo_reset),
    [TD_T] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_tab_finished, dance_tab_reset),
};

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};

combo_t key_combos[] = {
    // Left Hand
    [CO_WE] = COMBO(we_combo, MR_NT),
    [CO_ER] = COMBO(er_combo, MR_RT),
    [CO_RT] = COMBO(rt_combo, MR_DS),
    [CO_AS] = COMBO(as_combo, KC_TAB),
    [CO_SD] = COMBO(sd_combo, MR_AS),
    [CO_DF] = COMBO(df_combo, MR_S),
    [CO_FG] = COMBO(fg_combo, KC_ESC),
    [CO_ZX] = COMBO(zx_combo, MR_F),
    [CO_XC] = COMBO(xc_combo, MR_CO),
    [CO_CV] = COMBO(cv_combo, KC_BSPC),
    [CO_VB] = COMBO(vb_combo, MR_CS),

    // Right Hand
    [CO_UI] = COMBO(ui_combo, MR_CT),
    [CO_IO] = COMBO(io_combo, MR_CW),
    [CO_OP] = COMBO(op_combo, MR_CA),
    [CO_HJ] = COMBO(hj_combo, KC_F12),
    [CO_JK] = COMBO(jk_combo, MR_PRT),
    [CO_KL] = COMBO(kl_combo, MR_NXT),
    [CO_NM] = COMBO(nm_combo, MR_CL),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_BSPC,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   LA_NUM,  LA_NAV,  KC_SPC,           KC_ENT,  LA_SYM,  LA_FUN
    ),

    [NUM] = LAYOUT_split_3x5_3(
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                   XXXX,    XXXX,    KC_SPC,           KC_ENT,  XXXX,    XXXX
    ),

    [NAV] = LAYOUT_split_3x5_3(
        KC_ESC,  SW_WIN,  XXXX,    MR_RT,   MR_SW,                              KC_WH_U, KC_HOME, KC_UP,   KC_END,  KC_DEL,
        OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_TAB,                             KC_WH_D, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,
        TD(TD_Z),MR_X,    MR_C,    MR_V,    XXXX,                               XXXX,    XXXX,    MR_DL,   XXXX,    TD(TD_T),
                                   XXXX,    XXXX,    KC_SPC,           KC_ENT,  MR_SP,   XXXX
    ),
 
    [SYM] = LAYOUT_split_3x5_3(
        KC_BSLS, KC_GRV,  KC_DLR,  KC_EXLM, KC_AT,                              KC_ASTR, KC_PLUS, KC_PERC, KC_CIRC, KC_HASH,
        KC_LBRC, KC_LPRN, KC_LCBR, KC_EQL,  KC_GT,                              KC_LT,   KC_QUOT, KC_MINS, KC_UNDS, KC_SCLN,
        KC_RBRC, KC_RPRN, KC_RCBR, KC_AMPR, XXXX,                               XXXX,    KC_PIPE, KC_COMM, KC_DOT,  KC_SLSH,
                                   XXXX,    XXXX,    KC_SPC,           KC_ENT,  XXXX,    XXXX
    ),

    [FUN] = LAYOUT_split_3x5_3(
        XXXX,    XXXX,    MR_ZO,   MR_ZI,   XXXX,                               XXXX,    KC_F1,   KC_F2,   KC_F3,   KC_F4,
        KC_CAPS, OS_CTRL, OS_ALT,  OS_CMD,  XXXX,                               XXXX,    KC_F5,   KC_F6,   KC_F7,   KC_F8,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    KC_F9,   KC_F10,  KC_F11,  KC_F12,
                                   MR_WF,   XXXX,   KC_SPC,            KC_ENT,  XXXX,    XXXX
    ),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_NUM:
    case LA_NAV:
    case LA_SYM:
    case LA_FUN:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_NUM:
    case LA_NAV:
    case LA_SYM:
    case LA_FUN:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  update_swapper(
        &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
        keycode, record
    );

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
      case MR_CT:
          // Close tab
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_W);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_W);
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
      case MR_CW:
          // Close Window
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_W);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_W);
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
      case MR_CA:
          // Close Application
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_Q);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_Q);
          }
          break;
      case MR_DS:
          // Terminal Duplicate Session
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_GRV);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_GRV);
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
      case MR_CS:
          // Terminal Clear Session
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_K);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_K);
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
      case MR_DL:
          // Vscode Duplicate Line
          if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_DOWN);
          } else {
            unregister_code(KC_LALT);
            unregister_code(KC_LSFT);
            unregister_code(KC_DOWN);
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
    }
    return true;
}