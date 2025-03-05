#include QMK_KEYBOARD_H

#include "oneshot.h"

#define LY_NAV LT(NAV, KC_ESC)
#define LY_SYM MO(SYM)
#define LY_NUM LT(NUM, KC_ENT)
#define LY_FUNC LT(FUNC, KC_CAPS)

#define MT_A MT(MOD_LCTL, KC_A)
#define MT_S MT(MOD_LALT, KC_S)
#define MT_D MT(MOD_LGUI, KC_D)
#define MT_F MT(MOD_LSFT, KC_F)

#define MT_J MT(MOD_RSFT, KC_J)
#define MT_K MT(MOD_RGUI, KC_K)
#define MT_L MT(MOD_RALT, KC_L)
#define MT_BSPC MT(MOD_RCTL, KC_BSPC)

#define MR_WH_L S(KC_WH_U)
#define MR_WH_R S(KC_WH_D)
#define MR_SW G(KC_GRV)
#define MR_X G(KC_X)
#define MR_C G(KC_C)
#define MR_V G(KC_V)
#define MR_CT G(KC_W)
#define MR_RT LSG(KC_T)
#define MR_F G(KC_F)
#define MR_UN G(KC_Z)
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
    CO_KCOMMA,
    CO_LCBRCIRC,
    CO_EQLLPRN,
    CO_LPRNQUOT,
    CO_LBRCDQT,
};

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        MT_A,    MT_S,    MT_D,    MT_F,    KC_G,                               KC_H,    MT_J,    MT_K,    MT_L,    MT_BSPC,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   KC_TAB,  LY_NAV,  KC_SPC,          LY_NUM,   LY_SYM,  LY_FUNC
    ),

    [NAV] = LAYOUT_split_3x5_3(
        MR_RT,   MR_SW,   MR_PRT,  MR_NXT,  MR_CT,                              XXXX,    MR_ZO,   XXXX,    MR_ZI,   XXXX,
        OS_CTRL, OS_ALT,  OS_CMD,  OS_SHFT, KC_F12,                             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC,
        MR_WH_L, KC_WH_D, KC_WH_U, MR_WH_R, MR_SC,                              XXXX,    KC_PGDN, KC_PGUP, XXXX,    XXXX,
                                   ____,    ____,    ____,            ____,     ____,    ____
    ),

    [SYM] = LAYOUT_split_3x5_3(
        KC_GRV,  KC_UNDS, KC_DLR,  KC_AMPR, ____,                               ____,    KC_EXLM, KC_LCBR, KC_CIRC, KC_TILD,
        OS_CTRL, OS_ALT,  OS_CMD,  OS_SHFT, KC_AT,                              KC_PLUS, KC_EQL,  KC_LPRN, KC_QUOT, KC_COLN,
        KC_BSLS, KC_HASH, KC_ASTR, KC_PIPE, ____,                               ____,    KC_MINS, KC_LBRC, KC_DQT,  KC_SCLN,
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
        XXXX,    KC_4,    KC_5,    KC_6,    XXXX,                               ____,    ____,    ____,    ____,    ____,
        XXXX,    KC_7,    KC_8,    KC_9,    XXXX,                               XXXX,    XXXX,    KC_EQL,  XXXX,    XXXX,
                                   ____,    KC_0,    ____,             ____,    ____,    ____
    ),

    [FUNC] = LAYOUT_split_3x5_3(
        XXXX,    KC_F1,   KC_F2,   KC_F3,   KC_F4,                              XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        XXXX,    KC_F5,   KC_F6,   KC_F7,   KC_F8,                              XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        XXXX,    KC_F9,   KC_F10,  KC_F11,  KC_F12,                             XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                   ____,    ____,    ____,             ____,    ____,    ____
    ),
};

// Combos
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM wr_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {MT_S, MT_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {MT_D, MT_F, COMBO_END};
const uint16_t PROGMEM sf_combo[] = {MT_S, MT_F, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM xv_combo[] = {KC_X, KC_V, COMBO_END};

const uint16_t PROGMEM jk_combo[] = {MT_J, MT_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {MT_K, MT_L, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};

const uint16_t PROGMEM lcbrcirc_combo[] = {KC_LCBR, KC_CIRC, COMBO_END};
const uint16_t PROGMEM eqllprn_combo[] = {KC_EQL, KC_LPRN, COMBO_END};
const uint16_t PROGMEM lprnquot_combo[] = {KC_LPRN, KC_QUOT, COMBO_END};
const uint16_t PROGMEM lbrcdqt_combo[] = {KC_LBRC, KC_DQT, COMBO_END};

combo_t key_combos[] = {
    [CO_WE] = COMBO(we_combo, MR_UN),
    [CO_ER] = COMBO(er_combo, MR_RD),
    [CO_WR] = COMBO(wr_combo, MR_F),
    [CO_SD] = COMBO(sd_combo, MR_C),
    [CO_DF] = COMBO(df_combo, MR_X),
    [CO_SF] = COMBO(sf_combo, MR_V),
    [CO_XC] = COMBO(xc_combo, KC_ENT),
    [CO_CV] = COMBO(cv_combo, KC_BSPC),
    [CO_XV] = COMBO(xv_combo, KC_F3),

    [CO_JK] = COMBO(jk_combo, KC_LEFT),
    [CO_KL] = COMBO(kl_combo, KC_RGHT),

    [CO_EQLLPRN] = COMBO(eqllprn_combo, KC_GT),
    [CO_LCBRCIRC] = COMBO(lcbrcirc_combo, KC_RCBR),
    [CO_LPRNQUOT] = COMBO(lprnquot_combo, KC_RPRN),
    [CO_LBRCDQT] = COMBO(lbrcdqt_combo, KC_RBRC),
};

// OSK
oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case KC_CLEAR:
    case LY_SYM:
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
      case LY_NAV:
          if (record->event.pressed && get_mods()) {
              keyrecord_t custom_record = {0};
              custom_record.event.pressed = true;

              update_oneshot(
                  &os_shft_state, KC_LSFT, OS_SHFT,
                  KC_CLEAR, &custom_record
              );
              update_oneshot(
                  &os_ctrl_state, KC_LCTL, OS_CTRL,
                  KC_CLEAR, &custom_record
              );
              update_oneshot(
                  &os_alt_state, KC_LALT, OS_ALT,
                  KC_CLEAR, &custom_record
              );
              update_oneshot(
                  &os_cmd_state, KC_LCMD, OS_CMD,
                  KC_CLEAR, &custom_record
              );

            return false;
          }
    }
    return true;
}

// Tap Hold
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LY_NAV:
            return 120;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case LY_NAV:
          return false;
      default:
          return true;
  }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case LY_NAV:
          return true;
      default:
          return false;
  }
}

char chordal_hold_handedness(keypos_t key) {
    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}

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