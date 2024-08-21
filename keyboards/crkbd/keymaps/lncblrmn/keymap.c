/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "oneshot.h"

#define LA_NAV LT(NAV, KC_SPC)
#define LA_SYM LT(SYM, KC_ENT)
#define LA_MOU TT(MOUSE)

#define MT_TC CMD_T(KC_TAB)
#define MT_ES SFT_T(KC_ESC)
#define MT_CO OPT_T(KC_CAPS)

#define MR_SP LGUI(KC_SPC)
#define MR_QS LGUI(KC_TAB)

#define XXXXXXX KC_NO
#define _______ KC_TRNS

enum layers {
    BASE,
    NAV,
    SYM,
    FUN,
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
    MR_ND,
    MR_PD,
    MR_MC,
    MR_SC,
    MR_AT,
    MR_AS,

    // One Shot Keys
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_CMD
};

enum {
    // Combo
    CO_WE,
    CO_ER,
    CO_AS,
    CO_SD,
    CO_DF,
    CO_XC,
    CO_CV,
};

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};

combo_t key_combos[] = {
    [CO_WE] = COMBO(we_combo, MR_QS),
    [CO_ER] = COMBO(er_combo, MR_AT),
    [CO_AS] = COMBO(as_combo, KC_BSPC),
    [CO_SD] = COMBO(sd_combo, QK_REP),
    [CO_DF] = COMBO(df_combo, KC_SPC),
    [CO_XC] = COMBO(xc_combo, MR_SP),
    [CO_CV] = COMBO(cv_combo, KC_LALT),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MR_WF,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       MR_AT,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       MT_CO,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_F3,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MT_ES,  LA_NAV,   MT_TC,     LA_MOU,  LA_SYM,   MR_SP
                                      //`--------------------------'  `--------------------------'
  ),

    [NAV] = LAYOUT_split_3x6_3( 
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX,   MR_MC,  MR_PRT,  MR_NXT, XXXXXXX,                      XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, OS_CTRL,  OS_ALT,  OS_SHFT, OS_CMD,   MR_SW,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX,   MR_PD,   MR_ND, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_BSLS,  KC_GRV,  KC_DLR, KC_EXLM, KC_CIRC,                      KC_ASTR,    KC_1,    KC_2,    KC_3, KC_HASH, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LBRC, KC_LPRN, KC_LCBR,  KC_EQL, KC_QUOT,                         KC_0,    KC_4,    KC_5,    KC_6, KC_MINS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_RBRC, KC_RPRN, KC_RCBR, KC_AMPR,   KC_AT,                      _______,    KC_7,    KC_8,    KC_9, KC_PERC, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   MR_PD,   MR_ND,  MR_PRT,  MR_NXT,   MR_MC,                      XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_ACL2, KC_ACL0, KC_BTN1, KC_BTN2,   MR_SW,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX,   MR_PD,   MR_PD, XXXXXXX,                      XXXXXXX, KC_WH_U, KC_WH_D, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX,   MR_ZO,   MR_ZI, XXXXXXX,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, OS_CTRL,  OS_ALT,  OS_SHFT, OS_CMD,   MR_SC,                        MR_CL,   KC_F4,   KC_F5,   KC_F6,  KC_F11, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F12, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
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