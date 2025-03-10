#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "common.h"

///////////////////
// Keymap
//////////////////
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        MT_A,    MT_S,    MT_D,    MT_F,    KC_G,                               KC_H,    MT_J,    MT_K,    MT_L,    MT_BSPC,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   LY_MSE,  LY_NAV,  KC_SPC,           KC_ENT,  LY_SYM,  LY_FCT
    ),

    [NAV] = LAYOUT_split_3x5_3(
        MR_RT,   MR_SW,   MR_PRT,  MR_NXT,  MR_CT,                              XXXX,    MR_ZO,   XXXX,    MR_ZI,   XXXX,
        KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, MR_SC,                              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC,
        MR_WH_L, KC_WH_D, KC_WH_U, MR_WH_R, XXXX,                               XXXX,    KC_PGDN, KC_PGUP, XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),

    [SYM] = LAYOUT_split_3x5_3(
        KC_GRV,  KC_AMPR, KC_LT,   KC_GT,   KC_PERC,                            KC_CIRC, KC_EXLM, KC_LCBR, KC_RCBR, KC_TILD,
        TM_MINS, TM_UNDS, TM_DLR,  TM_COLN, KC_AT,                              KC_PIPE, TM_EQL,  TM_LPRN, TM_RPRN, TM_QUOT,
        KC_BSLS, KC_HASH, KC_ASTR, KC_SCLN, ____,                               ____,    KC_PLUS, KC_LBRC, KC_RBRC, KC_DQT,
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
        KC_0,    KC_4,    KC_5,    KC_6,    XXXX,                               KC_SPC,  MT_J,    MT_K,    MT_L,    MT_BSPC,
        XXXX,    KC_7,    KC_8,    KC_9,    XXXX,                               XXXX,    KC_EQL,  XXXX,    XXXX,    XXXX,
                                   ____,    XXXX,    ____,             ____,    ____,    ____
    ),

    [FUNC] = LAYOUT_split_3x5_3(
        XXXX,    KC_F1,   KC_F2,   KC_F3,   KC_F4,                              XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        XXXX,    KC_F5,   KC_F6,   KC_F7,   KC_F8,                              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXX,
        XXXX,    KC_F9,   KC_F10,  KC_F11,  KC_F12,                             XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),
};



///////////////////
// Tap Dance
//////////////////
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
    [CT_MINS] = ACTION_TAP_DANCE_TAP_MOD(KC_MINS, KC_LSFT),
    [CT_UNDS] = ACTION_TAP_DANCE_TAP_MOD(KC_UNDS, KC_LCTL),
    [CT_DLR] = ACTION_TAP_DANCE_TAP_MOD(KC_DLR, KC_LALT),
    [CT_COLN] = ACTION_TAP_DANCE_TAP_MOD(KC_COLN, KC_LGUI),
    [CT_EQL] = ACTION_TAP_DANCE_TAP_MOD(KC_EQL, KC_RGUI),
    [CT_LPRN] = ACTION_TAP_DANCE_TAP_MOD(KC_LPRN, KC_RALT),
    [CT_RPRN] = ACTION_TAP_DANCE_TAP_MOD(KC_RPRN, KC_RCTL),
    [CT_QUOT] = ACTION_TAP_DANCE_TAP_MOD(KC_QUOT, KC_RSFT),

    [CT_LEFT] = ACTION_TAP_DANCE_TAP_MOD(KC_LEFT, KC_RSFT),
    [CT_DOWN] = ACTION_TAP_DANCE_TAP_MOD(KC_DOWN, KC_RGUI),
    [CT_RGHT] = ACTION_TAP_DANCE_TAP_MOD(KC_RGHT, KC_RALT),
};



///////////////////
// Tap Hold
//////////////////
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LY_NAV:
        case LY_SYM:
            return 120;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LY_NAV:
        case LY_SYM:
            return false;
        default:
            return true;
    }
    return true;
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

char chordal_hold_handedness(keypos_t key) {
    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}


///////////////////
// One Shot Keys
//////////////////
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



///////////////////
// Macros
//////////////////
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



///////////////////
// Combos
//////////////////
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM wr_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {MT_S, MT_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {MT_D, MT_F, COMBO_END};
const uint16_t PROGMEM sf_combo[] = {MT_S, MT_F, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM xv_combo[] = {KC_X, KC_V, COMBO_END};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};

combo_t key_combos[] = {
    [CO_WE] = COMBO(we_combo, MR_UN),
    [CO_ER] = COMBO(er_combo, MR_RD),
    [CO_WR] = COMBO(wr_combo, KC_F3),
    [CO_SD] = COMBO(sd_combo, KC_TAB),
    [CO_DF] = COMBO(df_combo, KC_BSPC),
    [CO_SF] = COMBO(sf_combo, QK_REP),
    [CO_XC] = COMBO(xc_combo, MR_C),
    [CO_CV] = COMBO(cv_combo, MR_X),
    [CO_XV] = COMBO(xv_combo, MR_V),

    // [CO_JK] = COMBO(jk_combo, ),
    // [CO_KL] = COMBO(kl_combo, KC_CAPS),
};



///////////////////
// Tri layer
//////////////////
layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, NAV, SYM, NUM);
}



///////////////////
// Display
//////////////////
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
