#include QMK_KEYBOARD_H

#include "oneshot.h"

#define LA_NAV MO(NAV)
#define LA_WM  LT(WM, KC_ESC)
#define LA_SYM MO(SYM)
#define LA_MACRO MO(MACRO)

#define MR_SA G(KC_TAB)
#define MR_S G(KC_S)

#define WM_A A(KC_A)
#define WM_S A(KC_S)
#define WM_D A(KC_D)
#define WM_F A(KC_F)
#define WM_AA LSA(KC_A)
#define WM_AS LSA(KC_S)
#define WM_AD LSA(KC_D)
#define WM_AF LSA(KC_F)
#define WM_SM LSA(KC_SCLN)
#define WM_LT A(KC_SLSH)
#define WM_LA A(KC_COMM)
#define WM_FU A(KC_I)
#define WM_FD A(KC_K)
#define WM_FL A(KC_J)
#define WM_FR A(KC_L)
// #define WM_MU LSA(KC_I)
// #define WM_MD LSA(KC_K)
// #define WM_ML LSA(KC_J)
// #define WM_MR LSA(KC_L)
#define WM_RM LSA(KC_MINS)
#define WM_RP LSA(KC_EQL)
#define WM_FS LSA(KC_H)

#define CK_LANG S(KC_COMM)
#define CK_RANG S(KC_DOT)
#define CK_RANG S(KC_DOT)

#define MT_SPC LCTL_T(KC_SPC)
#define MT_ENT LCTL_T(KC_ENT)

#define XXXX KC_NO
#define ____ KC_TRNS

enum layers {
    BASE,
    NAV,
    SYM,
    FUN,
    WM,
    NUM,
    MACRO
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
    CO_SD,
    CO_DF
};

const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};

combo_t key_combos[] = {
    [CO_SD] = COMBO(sd_combo, KC_ESC),
    [CO_DF] = COMBO(df_combo, MR_S),
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
                                   LA_WM,   LA_NAV,  KC_SPC,           MT_ENT,  LA_SYM,  LA_MACRO
    ),
        
    [NAV] = LAYOUT_split_3x5_3(
        XXXX,    XXXX,    MR_PRT,  MR_NXT,  XXXX,                               XXXX,    XXXX,    KC_UP,   XXXX,    XXXX,
        KC_TAB,  OS_ALT,  OS_SHFT, OS_CMD,  XXXX,                               XXXX,    KC_LEFT, KC_DOWN, KC_RGHT, ____,
        XXXX,    QK_REP,  MR_SW,   MR_SA,   XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    [WM] = LAYOUT_split_3x5_3(
        WM_AA,   WM_AS,   WM_AD,   WM_AF,   XXXX,                               XXXX,    XXXX,    WM_FU,   XXXX,    XXXX,
        WM_RM,   WM_RP,   WM_LA,   WM_LT,   WM_SM,                              XXXX,    WM_FL,   WM_FD,   WM_FR,   ____,
        WM_A,    WM_S,    WM_D,    WM_F,    WM_FS,                              XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    [SYM] = LAYOUT_split_3x5_3(
        KC_TILD, KC_CIRC, KC_DLR,  KC_EXLM, KC_PLUS,                            XXXX,    KC_UNDS, KC_GRV,  KC_HASH, KC_BSLS,
        KC_LBRC, KC_LPRN, KC_LCBR, KC_EQL,  KC_AT,                              KC_PERC, KC_QUOT, KC_DQT,  KC_COLN, KC_SCLN,
        KC_RBRC, KC_RPRN, KC_RCBR, KC_AMPR, KC_ASTR,                            KC_PIPE, KC_MINS, KC_LT,   KC_GT,   KC_QUES,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    [NUM] = LAYOUT_split_3x5_3(
        XXXX,    KC_F1,   KC_F2,   KC_F3,   XXXX,                               XXXX,    KC_F4,   KC_F5,   KC_F6,   XXXX,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        XXXX,    KC_F7,   KC_F8,   KC_F9,   XXXX,                               XXXX,    KC_F10,  KC_F11,  KC_F12,  XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    // [MOUSE] = LAYOUT_split_3x5_3(
    //     MR_WF,   XXXX,    MR_ZO,   MR_ZI,   XXXX,                               XXXX,    XXXX,    KC_MS_U, XXXX,    XXXX,
    //     KC_ACL2, KC_ACL0, KC_BTN1, KC_BTN2, MR_SW,                              MR_CL,   KC_MS_L, KC_MS_D, KC_MS_R, XXXX,
    //     XXXX,    XXXX,    XXXX,    KC_CAPS, XXXX,                               XXXX,    KC_WH_U, KC_WH_D, XXXX,    XXXX,
    //                                ____,    ____,    ____,             ____,    ____,    ____
    // ),

    // [FUN] = LAYOUT_split_3x5_3(
    //     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    //     XXXX,    XXXX,    XXXX,    KC_F11,  XXXX,                               XXXX,    KC_F12,  XXXX,    XXXX,    XXXX,
    //     XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
    //                                ____,    ____,    ____,             ____,    ____,    ____
    // ),

    [MACRO] = LAYOUT_split_3x5_3(
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        KC_CAPS, MR_WF,   MR_ZO,   MR_ZI,   MR_SC,                              XXXX,    MR_CL,   MR_SC,   XXXX,    XXXX,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),
};

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
  return update_tri_layer_state(state, NAV, SYM, NUM);
}