  #include QMK_KEYBOARD_H

  #include "oneshot.h"

  #define LY_NAV TD(TD_WM_NAV)
  #define LY_SYM MO(SYM)
  #define LY_NUM LT(NUM, KC_ENT)

  #define MT_A MT(MOD_LCTL, KC_A)
  #define MT_S MT(MOD_LALT, KC_S)
  #define MT_D MT(MOD_LSFT, KC_D)
  #define MT_F MT(MOD_LGUI, KC_F)

  #define MT_J MT(MOD_RGUI, KC_J)
  #define MT_K MT(MOD_RSFT, KC_K)
  #define MT_L MT(MOD_RALT, KC_L)
  #define MT_BSPC MT(MOD_RCTL, KC_BSPC)

  #define MR_AT G(KC_TAB)
  #define MR_ST C(KC_TAB)
  #define MR_W G(KC_W)
  #define MR_Z G(KC_Z)
  #define MR_RZ LSG(KC_Z)
  #define MR_WH_L S(KC_WH_U)
  #define MR_WH_R S(KC_WH_D)
  #define MR_VU C(KC_U)
  #define MR_VD C(KC_D)
  #define MR_SW G(KC_GRV)

  #define XXXX KC_NO
  #define ____ KC_TRNS

  enum layers {
      BASE,
      NAV,
      SYM,
      NUM,
      FUNC,
      MOUSE,
      DES
  };

  enum keycodes {
      // Macros
      MR_NT = SAFE_RANGE,
      MR_RT,
      MR_NXT,
      MR_PRT,
      MR_ZI,
      MR_ZO,
      MR_SC,
      MR_HAT,
      MR_AS,
      MR_BT,
      MR_CM,

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
      CO_UI,
      CO_IO,
      CO_JK,
      CO_KL,
      CO_MCOMM,
      CO_COMMDOT,
  };

  typedef enum {
      TD_NONE,
      TD_UNKNOWN,
      TD_SINGLE_TAP,
      TD_SINGLE_HOLD,
      TD_DOUBLE_TAP,
      TD_DOUBLE_HOLD,
      TD_DOUBLE_SINGLE_TAP
  } td_state_t;

  typedef struct {
      bool is_press_action;
      td_state_t state;
  } td_tap_t;

  // Tap dance enums
  enum {
      TD_WM_NAV,
  };

  td_state_t cur_dance(tap_dance_state_t *state);

  void b_finished(tap_dance_state_t *state, void *user_data);
  void b_reset(tap_dance_state_t *state, void *user_data);

  // Keymap
  const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [BASE] = LAYOUT_split_3x5_3(
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
          MT_A,    MT_S,    MT_D,    MT_F,    KC_G,                               KC_H,    MT_J,    MT_K,    MT_L,    MT_BSPC,
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                     KC_TAB,  LY_NAV,  KC_SPC,          LY_NUM,   LY_SYM,  KC_CAPS
      ),

      [NAV] = LAYOUT_split_3x5_3(
          MR_BT,   MR_ST,   MR_PRT,  MR_NXT,  MR_W,                               XXXX,    MR_ZO,   XXXX,    MR_ZI,   XXXX,
          OS_CTRL, OS_ALT,  OS_SHFT, OS_CMD,  MR_HAT,                             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC,
          MR_WH_L, KC_WH_D, KC_WH_U, MR_WH_R, MR_SC,                              XXXX,    KC_PGDN, KC_PGUP, XXXX,    XXXX,
                                     ____,    ____,    ____,            ____,     ____,    ____
      ),

      [SYM] = LAYOUT_split_3x5_3(
          KC_GRV,  KC_ASTR, KC_CIRC, KC_AMPR, KC_PERC,                            KC_PLUS, KC_EXLM, KC_UNDS, KC_DLR,  KC_BSLS,
          KC_QUOT, KC_LBRC, KC_LPRN, KC_LCBR, KC_AT,                              KC_PIPE, KC_EQL,  KC_MINS, KC_COLN, KC_BSPC,
          KC_DQT,  KC_RBRC, KC_RPRN, KC_RCBR, XXXX,                               XXXX,    KC_HASH, KC_AMPR, KC_SCLN, KC_TILD,
                                     ____,    ____,    ____,             ____,    ____,    ____
      ),

      [MOUSE] = LAYOUT_split_3x5_3(
          MR_BT,   MR_ST,   MR_PRT,  MR_NXT,  MR_W,                                XXXX,    MR_ZO,   KC_MS_U, MR_ZI,   XXXX,
          KC_LSFT, KC_LGUI, KC_BTN1, KC_BTN2, MR_HAT,                              XXXX,    KC_MS_L, KC_MS_D, KC_MS_R, XXXX,
          MR_WH_L, KC_WH_D, KC_WH_U, MR_WH_R, MR_SC,                               XXXX,    KC_PGDN, KC_PGUP, XXXX,    XXXX,
                                     ____,    ____,    ____,             ____,     ____,    ____
      ),

      [FUNC] = LAYOUT_split_3x5_3(
          KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
          KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXX,                               XXXX,    KC_RCMD, KC_RSFT, KC_RALT, KC_RCTL,
          KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                     ____,    ____,    ____,             ____,    ____,    ____
      ),

      [NUM] = LAYOUT_split_3x5_3(
          XXXX,    KC_1,    KC_2,    KC_3,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
          XXXX,    KC_4,    KC_5,    KC_6,    XXXX,                               ____,    ____,    ____,    ____,    ____,
          XXXX,    KC_7,    KC_8,    KC_9,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    ____,
                                     ____,    KC_0,    ____,             ____,    ____,    ____
      ),
  };

  bool is_alt_tab_active = false;
  bool is_ctl_tab_active = false;
  uint16_t alt_tab_timer = 0; 

  // Combos
  const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
  const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
  const uint16_t PROGMEM wr_combo[] = {KC_W, KC_R, COMBO_END};
  const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
  const uint16_t PROGMEM df_combo[] = {KC_F, KC_D, COMBO_END};
  const uint16_t PROGMEM sf_combo[] = {KC_S, KC_F, COMBO_END};
  const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
  const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
  const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
  const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
  const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
  const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
  const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};
  const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};

  combo_t key_combos[] = {
      [CO_WE] = COMBO(we_combo, MR_Z),
      [CO_ER] = COMBO(er_combo, MR_RZ),
      [CO_WR] = COMBO(wr_combo, MR_CM),
      [CO_SD] = COMBO(sd_combo, QK_REP),
      [CO_DF] = COMBO(df_combo, MR_AT),
      [CO_SF] = COMBO(sf_combo, MR_SW),
      [CO_XC] = COMBO(xc_combo, KC_ENT),
      [CO_CV] = COMBO(cv_combo, KC_BSPC),

      [CO_UI] = COMBO(ui_combo, MR_VD),
      [CO_IO] = COMBO(io_combo, MR_VU),
      [CO_JK] = COMBO(jk_combo, KC_LEFT),
      [CO_KL] = COMBO(kl_combo, KC_RIGHT),
      [CO_MCOMM] = COMBO(mcomm_combo, KC_F3),
      [CO_COMMDOT] = COMBO(commdot_combo, KC_F12),
  };

  // OSK
  oneshot_state os_shft_state = os_up_unqueued;
  oneshot_state os_ctrl_state = os_up_unqueued;
  oneshot_state os_alt_state = os_up_unqueued;
  oneshot_state os_cmd_state = os_up_unqueued;

  bool is_oneshot_cancel_key(uint16_t keycode) {
      switch (keycode) {
      case KC_CLEAR:
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
        case MR_HAT:
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

        case MR_BT:
            if (record->event.pressed) {
              if (!is_ctl_tab_active) {
                is_ctl_tab_active = true;
                register_code(KC_LCTL);
              }
              alt_tab_timer = timer_read();
              register_code(KC_TAB);
            } else {
              unregister_code(KC_TAB);
            }
            break;
        case KC_LEFT:
        case KC_RIGHT:
            if (record->event.pressed) {
                alt_tab_timer = timer_read();
            }
            break;
        case MR_CM:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LALT);
                register_code(KC_C);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
                unregister_code(KC_C);
            }
            break;
      }

      return true;
  }

  void matrix_scan_user(void) {
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 1000) {
        unregister_code(KC_LGUI);
        is_alt_tab_active = false;
      }
    }

    if (is_ctl_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 1000) {
        unregister_code(KC_LCTL);
        is_ctl_tab_active = false;
      }
    }
  }

  // Tap Dance (A, B, C | D, E, F)
  uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
      switch (keycode) {
          case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
              return 120;
          default:
              return TAPPING_TERM;
      }
  }

  td_state_t cur_dance(tap_dance_state_t *state) {
      if (state->count == 1) {
          if (state->pressed) return TD_SINGLE_HOLD;
          else return TD_SINGLE_TAP;
      } else return TD_UNKNOWN;
  }

  // B
  static td_tap_t btap_state = {
      .is_press_action = true,
      .state = TD_NONE
  };

  void b_finished(tap_dance_state_t *state, void *user_data) {
      btap_state.state = cur_dance(state);
      switch (btap_state.state) {
          case TD_SINGLE_TAP: {
            if (get_mods()) {
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
            } else {
              register_code(KC_ESC);
            }
            break;
          }
          case TD_SINGLE_HOLD: layer_on(NAV);  break;
          case TD_DOUBLE_TAP: {
            register_code(KC_LSFT);
            register_code(KC_ESC); break;
          }
          default: break;
      }
  }

  void b_reset(tap_dance_state_t *state, void *user_data) {
      switch (btap_state.state) {
          case TD_SINGLE_TAP: {
              if (!get_mods()) {
                unregister_code(KC_ESC);
              }
            break;
          }
          case TD_SINGLE_HOLD: layer_off(NAV); break;
          case TD_DOUBLE_TAP: {
            unregister_code(KC_LSFT);
            unregister_code(KC_ESC); break;
          }
          default: break;
      }
      btap_state.state = TD_NONE;
  }

  tap_dance_action_t tap_dance_actions[] = {
      [TD_WM_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, b_finished, b_reset),
  };

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