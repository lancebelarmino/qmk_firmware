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
};

enum tapdance_keycodes {
    TD_CAPS,
    TD_NAV,
    TD_ESC
};

enum custom_keycodes {
    M_REFRESH = SAFE_RANGE,
    M_QUIT,
};

enum {
    OS_UNSURE,
    OS_LINUX,
    OS_WINDOWS,
    OS_MACOS,
    OS_IOS,
} os_variant_t;

tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_NAV] = ACTION_TAP_DANCE_DOUBLE(MO(NAV), MO(MOUSE)),
    [TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_TILD),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_61_ansi(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        TO(NAV),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        TD(TD_CAPS),        KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL,  KC_LOPTN, KC_LGUI,                               KC_SPC,                                 TO(GAMING),TO(NAV),  OSL(FUNC),TO(MAC_BASE)),

    [WIN_BASE] = LAYOUT_61_ansi(
        TD(TD_ESC),KC_1,    KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        TO(NAV),  KC_A,    KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        TD(TD_CAPS),        KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 TO(GAMING),TO(NAV), OSL(FUNC),TO(WIN_BASE)),

    [GAMING] = LAYOUT_61_ansi(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_EQL,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        TD(TD_CAPS),        KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 TO(GAMING),TO(NAV), OSL(FUNC),TO(WIN_BASE)),

    [NAV] = LAYOUT_61_ansi(
        KC_ESC,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_TAB,   KC_PGUP,  KC_PGDN,  KC_HOME,  KC_END,  _______,   _______,  _______,  KC_UP,    _______,  _______,  _______,  _______,  _______,
        TO(MOUSE),_______,  _______,  _______,  KC_F,     _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, _______,  _______,            KC_ENT,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                _______,                                TO(GAMING),TO(NAV),  TO(FUNC),TO(WIN_BASE)),

    [MOUSE] = LAYOUT_61_ansi(
        KC_ESC,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_TAB,   KC_PGUP,  KC_PGDN,  KC_HOME,  KC_END,   _______,  _______,  _______,  KC_MS_U,  _______,  _______,  _______,  _______,  _______,
        TO(WIN_BASE),KC_ACL2,KC_ACL0, KC_BTN1,  KC_BTN2,  KC_ESC,   KC_WH_U,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,  _______,            KC_ENT,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                _______,                                TO(GAMING),TO(NAV), OSL(FUNC),TO(WIN_BASE)),
    
    [FUNC] = LAYOUT_61_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_BSLS,
        RGB_TOG,  KC_F12,   M_QUIT,   KC_D,     M_REFRESH,KC_G,     KC_H,     KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_SCLN,  KC_QUOT,            KC_ENT,
        _______,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
        _______,  _______,  _______,                                _______,                                TO(GAMING),TO(NAV), OSL(FUNC),TO(WIN_BASE)),
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      // TODO: Fix mac os refresh
      case M_REFRESH:
          if (record->event.pressed) {
            if (OS_MACOS) {
              tap_code(KC_LGUI);
              tap_code(KC_R);
            } else {
              tap_code(KC_F5);
            }
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_F5);
            unregister_code(KC_R);
          }
          break;
      case M_QUIT:
          if (record->event.pressed) {
            if (OS_MACOS) {
              tap_code(KC_LGUI);
              tap_code(KC_Q);
            } else {
              tap_code(KC_LALT);
              tap_code(KC_F4);
            }
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_F4);
            unregister_code(KC_LALT);
            unregister_code(KC_F4);
          }
          break;
    }
    return true;
};

