#include QMK_KEYBOARD_H

#include "oneshot.h"

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

enum macros {
    MR_FW = SAFE_RANGE, // Forward by word
    MR_BW, // Backward by word
    MR_ST, // Spotlight
    MR_NT, // New tab
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT,
                                   LA_NUM,  LA_NAV,  KC_SPC,           KC_ENT,  LA_SYM,  LA_FUN
    ),

    [NUM] = LAYOUT_split_3x5_3(
        XXXX,    XXXX,    KC_LT,   KC_GT,   XXXX,                               KC_EQL,  KC_1,    KC_2,    KC_3,    KC_PLUS,
        OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_TAB,                             KC_ASTR, KC_4,    KC_5,    KC_6,    KC_MINS,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               KC_0,    KC_7,    KC_8,    KC_9,    KC_SLSH,
                                   XXXX,    XXXX,    KC_SPC,           KC_ENT,  XXXX,    XXXX
    ),

    [NAV] = LAYOUT_split_3x5_3(
        KC_ESC,  XXXX,    XXXX,    XXXX,    MR_NT,                              XXXX,    KC_HOME, KC_UP,   KC_END,  KC_DEL,
        OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_TAB,                             KC_WH_U, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,
        XXXX,    XXXX,    XXXX,    XXXX,    KC_CAPS,                            KC_WH_D, MR_FW,   MR_BW,   XXXX,    XXXX,
                                   XXXX,    XXXX,    KC_SPC,           KC_ENT,  MR_ST,   XXXX
    ),

    [SYM] = LAYOUT_split_3x5_3(
        KC_EXLM, KC_AT,   KC_LT,   KC_GT,   KC_HASH,                            KC_EQL,  KC_GRV,  KC_DLR,  KC_PERC, KC_PLUS,
        OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_TAB,                             KC_ASTR, KC_LPRN, KC_LCBR, KC_LBRC, KC_MINS,
        KC_CIRC, KC_UNDS, KC_BSLS, KC_PIPE, KC_AMPR,                            KC_QUES, KC_RPRN, KC_RCBR, KC_RBRC, KC_SLSH,
                                   XXXX,    XXXX,    KC_SPC,           KC_ENT,  XXXX,    XXXX
    ),

    [FUN] = LAYOUT_split_3x5_3(
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    KC_F1,   KC_F2,   KC_F3,   KC_F4,
        OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  XXXX,                               XXXX,    KC_F5,   KC_F6,   KC_F7,   KC_F8,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    KC_F9,   KC_F10,  KC_F11,  KC_F12,
                                   XXXX,    XXXX,   KC_SPC,            KC_ENT,  XXXX,    XXXX
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

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

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

    // switch (keycode) {
    //   case MR_FW:
    //       // Forward by word
    //       if (record->event.pressed) {
    //         register_code(KC_LGUI);
    //         register_code(KC_RIGHT);
    //       } else {
    //         unregister_code(KC_LGUI);
    //         unregister_code(KC_RIGHT);
    //       }
    //       break;
    //   case MR_BW:
    //       // Backward by word
    //       if (record->event.pressed) {
    //         register_code(KC_LGUI);
    //         register_code(KC_LEFT);
    //       } else {
    //         unregister_code(KC_LGUI);
    //         unregister_code(KC_LEFT);
    //       }
    //       break;
    //   case MR_ST:
    //       // Spotlight
    //       if (record->event.pressed) {
    //         register_code(KC_LGUI);
    //         register_code(KC_SPC);
    //       } else {
    //         unregister_code(KC_LGUI);
    //         unregister_code(KC_SPC);
    //       }
    //       break;
    //   case MR_NT:
    //       // New tab
    //       if (record->event.pressed) {
    //         register_code(KC_LGUI);
    //         register_code(KC_T);
    //       } else {
    //         unregister_code(KC_LGUI);
    //         unregister_code(KC_T);
    //       }
    //       break;
    // }
    return true;
}