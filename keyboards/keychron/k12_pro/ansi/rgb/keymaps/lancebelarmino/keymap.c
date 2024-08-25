/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// clang-format off
enum layers {
  MAC_BASE,
  WIN_BASE,
  NAV,
  MOUSE,
  FUNC,
  GAMING,
  GAMING_FUNC,
  MENU
};

enum tapdance_keycodes {
    TD_CAPS,
    TD_ESC,
    TD_BSLS,
    TD_DLR,
};

enum custom_keycodes {
    MR_PS = SAFE_RANGE
};

enum {
    OS_UNSURE,
    OS_LINUX,
    OS_WINDOWS,
    OS_MACOS,
    OS_IOS,
} os_variant_t;

tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS),
    [TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_ESC),
    [TD_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_AT),
    [TD_DLR] = ACTION_TAP_DANCE_DOUBLE(KC_DLR, KC_CIRC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // [WIN_BASE] = LAYOUT_61_ansi(
    //     TD(TD_ESC),KC_1,    KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
    //     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
    //     TT(NAV),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     TT(SYM),  LT(MENU, KC_QUOT),  KC_ENT,
    //     TD(TD_CAPS),        KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
    //     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 TO(GAMING),TO(NAV), TO(FUNC), TO(WIN_BASE)),

    [MAC_BASE] = LAYOUT_61_ansi(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        TT(NAV),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            TD(TD_CAPS),
        KC_LCTL,  KC_LOPTN, KC_LGUI,                                KC_SPC,                                 TO(GAMING),OSL(FUNC),TO(FUNC),TO(MAC_BASE)),

    [WIN_BASE] = LAYOUT_61_ansi(
        TD(TD_ESC),KC_1,    KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        TT(NAV),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  LT(MENU,  KC_QUOT), KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            TD(TD_CAPS),
        KC_LCTL,  KC_LGUI, KC_LALT,                                KC_SPC,                                 TO(GAMING),OSL(FUNC),TO(FUNC),TO(WIN_BASE)),

    [NAV] = LAYOUT_61_ansi(
        KC_ESC,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_TAB,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_UP,    _______,  _______,  _______,  _______,  _______,
        TO(WIN_BASE),_______,_______, _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, _______,  _______,            KC_ENT,
        KC_LSFT,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                _______,                                TO(GAMING),OSL(FUNC), TO(FUNC),TO(WIN_BASE)),

    [MENU] = LAYOUT_61_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_TAB,   KC_F1,    KC_F3,    KC_F12,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

    [FUNC] = LAYOUT_61_ansi(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_MOD,
        _______,  _______,  _______,  _______,  MR_PS,    _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,             RGB_TOG, RGB_VAI,  RGB_VAD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_SPI,  RGB_SPD,  RGB_MOD,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

    [GAMING] = LAYOUT_61_ansi(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_EQL,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 TO(GAMING),_______, TO(FUNC),TO(WIN_BASE)),

    [GAMING_FUNC] = LAYOUT_61_ansi(
        TO(GAMING),KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      // Print Screen
      case MR_PS:
          if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_RALT);
            register_code(KC_PSCR);
          } else {
            unregister_code(KC_LCTL);
            unregister_code(KC_RALT);
            unregister_code(KC_PSCR);
          }
          break;
    }
    return true;
};

