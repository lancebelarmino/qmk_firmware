#include QMK_KEYBOARD_H

#include "oneshot.h"

#define LY_NAV MO(NAV)
#define LY_SYM MO(SYM)
#define LY_NUM LT(NUM, KC_ENT)
#define LY_FUNC MO(FUNC)

#define TM_MINS TD(CT_MINS)
#define TM_UNDS TD(CT_UNDS)
#define TM_DLR TD(CT_DLR)
#define TM_COLN TD(CT_COLN)
#define TM_EQL TD(CT_EQL)
#define TM_LPRN TD(CT_LPRN)
#define TM_RPRN TD(CT_RPRN)
#define TM_QUOT TD(CT_QUOT)

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
};

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case LY_NAV:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LY_NAV:
    case LY_SYM:
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
                                   QK_REP,  LY_NAV,  KC_SPC,          LY_NUM,   LY_SYM,  LY_FUNC
    ),

    [NAV] = LAYOUT_split_3x5_3(
        MR_RT,   MR_SW,   MR_PRT,  MR_NXT,  MR_CT,                              XXXX,    MR_ZO,   XXXX,    MR_ZI,   XXXX,
        OS_CTRL, OS_ALT,  OS_SHFT, OS_CMD,  MR_SC,                              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC,
        MR_WH_L, KC_WH_D, KC_WH_U, MR_WH_R, KC_F3,                              XXXX,    KC_PGDN, KC_PGUP, XXXX,    XXXX,
                                   ____,    ____,    ____,            MR_SEN,   ____,    ____
    ),

    [SYM] = LAYOUT_split_3x5_3(
        KC_GRV,  KC_PERC, KC_PIPE, KC_AMPR, ____,                               ____,    KC_EXLM, KC_LCBR, KC_RCBR, KC_TILD,
        TM_MINS, TM_UNDS, TM_DLR,  TM_COLN, KC_AT,                              KC_CIRC, TM_EQL,  TM_LPRN, TM_RPRN, TM_QUOT,
        KC_BSLS, KC_HASH, KC_ASTR, KC_SCLN,  ____,                              ____,    KC_PLUS, KC_LBRC, KC_RBRC, KC_DQT,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    [MOUSE] = LAYOUT_split_3x5_3(
        XXXX,    XXXX,    MR_PRT,  MR_NXT,  XXXX,                               XXXX,    MR_ZO,   KC_MS_U, MR_ZI,   XXXX,
        KC_LSFT, KC_LGUI, KC_BTN1, KC_BTN2, XXXX,                               XXXX,    KC_MS_L, KC_MS_D, KC_MS_R, XXXX,
        MR_WH_L, KC_WH_D, KC_WH_U, MR_WH_R, XXXX,                               XXXX,    KC_PGDN, KC_PGUP, XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    [NUM] = LAYOUT_split_3x5_3(
        XXXX,    KC_1,    KC_2,    KC_3,    XXXX,                               XXXX,    KC_PLUS, KC_MINS, KC_ASTR, XXXX,
        XXXX,    KC_4,    KC_5,    KC_6,    XXXX,                               XXXX,    OS_CMD,  OS_SHFT, OS_ALT,  OS_CTRL,
        XXXX,    KC_7,    KC_8,    KC_9,    XXXX,                               XXXX,    KC_EQL,  XXXX,    XXXX,    XXXX,
                                   ____,    KC_0,    ____,             ____,    ____,    ____
    ),

    [FUNC] = LAYOUT_split_3x5_3(
        XXXX,    KC_F1,   KC_F2,   KC_F3,   KC_F4,                              XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        XXXX,    KC_F5,   KC_F6,   KC_F7,   KC_F8,                              XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        XXXX,    KC_F9,   KC_F10,  KC_F11,  KC_F12,                             XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),
};

typedef struct {
    uint16_t tap;
    uint16_t hold_modifier;
    bool held;
} tap_dance_tap_mod_t;

void tap_dance_tap_mod_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_mod_t *tap_mod = (tap_dance_tap_mod_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            // On hold, register the modifier
            register_code16(tap_mod->hold_modifier);
            tap_mod->held = true;
        } else {
            // Multiple taps, just send the tap key
            register_code16(tap_mod->tap);
            tap_mod->held = true;
        }
    }
}

void tap_dance_tap_mod_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_mod_t *tap_mod = (tap_dance_tap_mod_t *)user_data;

    if (tap_mod->held) {
        if (state->count == 1) {
            unregister_code16(tap_mod->hold_modifier);
        } else {
            unregister_code16(tap_mod->tap);
        }
        tap_mod->held = false;
    }
}

#define ACTION_TAP_DANCE_TAP_MOD(tap, modifier) \
    { .fn = {NULL, tap_dance_tap_mod_finished, tap_dance_tap_mod_reset}, .user_data = (void *)&((tap_dance_tap_mod_t){tap, modifier, false}), }

tap_dance_action_t tap_dance_actions[] = {
    [CT_MINS] = ACTION_TAP_DANCE_TAP_MOD(KC_MINS, KC_LCTL),
    [CT_UNDS] = ACTION_TAP_DANCE_TAP_MOD(KC_UNDS, KC_LALT),
    [CT_DLR] = ACTION_TAP_DANCE_TAP_MOD(KC_DLR, KC_LSFT),
    [CT_COLN] = ACTION_TAP_DANCE_TAP_MOD(KC_COLN, KC_LGUI),
    [CT_EQL] = ACTION_TAP_DANCE_TAP_MOD(KC_EQL, KC_RGUI),
    [CT_LPRN] = ACTION_TAP_DANCE_TAP_MOD(KC_LPRN, KC_RSFT),
    [CT_RPRN] = ACTION_TAP_DANCE_TAP_MOD(KC_RPRN, KC_RALT),
    [CT_QUOT] = ACTION_TAP_DANCE_TAP_MOD(KC_QUOT, KC_RCTL),
};

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

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
        case MR_RCA:
            if (record->event.pressed) {
            register_mods(MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT));
            } else {
            unregister_mods(MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT));
            }
            return false;
        case TM_MINS:
        case TM_UNDS:
        case TM_DLR:
        case TM_COLN:
        case TM_EQL:
        case TM_LPRN:
        case TM_RPRN:
        case TM_QUOT:
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_mod_t *tap_mod = (tap_dance_tap_mod_t *)action->user_data;
                tap_code16(tap_mod->tap);
            }
    }

    return true;
}

// Combos
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM wr_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM sf_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM xv_combo[] = {KC_X, KC_V, COMBO_END};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};

combo_t key_combos[] = {
    [CO_WE] = COMBO(we_combo, MR_UN),
    [CO_ER] = COMBO(er_combo, MR_RD),
    [CO_WR] = COMBO(wr_combo, KC_ENT),
    [CO_SD] = COMBO(sd_combo, KC_ESC),
    [CO_DF] = COMBO(df_combo, KC_TAB),
    [CO_SF] = COMBO(sf_combo, KC_BSPC),
    [CO_XC] = COMBO(xc_combo, MR_C),
    [CO_CV] = COMBO(cv_combo, MR_X),
    [CO_XV] = COMBO(xv_combo, MR_V),

    // [CO_JK] = COMBO(jk_combo, ),
    [CO_KL] = COMBO(kl_combo, KC_CAPS),
};

// Tap Hold
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LY_NAV:
        case LY_SYM:
            return 120;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case LY_NAV:
      case LY_SYM:
          return true;
      default:
          return false;
  }
}

// Tri layer
layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, NAV, SYM, MOUSE);
}

// Display
#ifdef OLED_ENABLE

#include "quantum.h"

static void render_emote(void) {
    oled_clear();  // Clears the previous text
    // Center coordinates (128x32 display)
    uint8_t start_x = (OLED_DISPLAY_WIDTH - 16) / 2;   // 56
    uint8_t start_y = (OLED_DISPLAY_HEIGHT - 16) / 2;  // 8
    
    // Draw 16x16 square
    for (uint8_t x = 0; x < 16; x++) {
        for (uint8_t y = 0; y < 16; y++) {
            oled_write_pixel(start_x + x, start_y + y, true);
        }
    }
}

static void render_default(void) {
    oled_clear();
}

bool oled_task_user(void) {
    if (get_mods() || get_oneshot_mods()) {
        render_emote();
    } else {
        render_default();
    }
    return false;
}

#endif
