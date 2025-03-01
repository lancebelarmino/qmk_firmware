  #include QMK_KEYBOARD_H

  #include "oneshot.h"

  #define LR_NAV TD(TD_WM_NAV)
  #define LR_SYM MO(SYM)
  #define LR_NUM MO(NUM)
  #define LR_MOUS TT(MOUSE)
  #define LR_FUNC MO(FUNC)

  #define MT_SPC MT(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_SPC)
  #define MT_ENT MT(MOD_LSFT, KC_ENT)

  #define MR_AT G(KC_TAB)
  #define MR_ST C(KC_TAB)
  #define MR_W G(KC_W)
  #define MR_Z G(KC_Z)
  #define MR_RZ LSG(KC_Z)
  #define MR_WH_L S(KC_WH_U)
  #define MR_WH_R S(KC_WH_D)
  #define MR_VU C(KC_U)
  #define MR_VD C(KC_D)

  #define XXXX KC_NO
  #define ____ KC_TRNS

  enum layers {
      BASE,
      NAV,
      SYM,
      NUM,
      FUNC,
      MOUSE,
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
      MR_SC,
      MR_HAT,
      MR_AS,
      MR_BT,

      // Custom Shifted Values
      CM_CAG,
      CM_HYPR,

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
      TD_SYM_FUNC,
  };

  td_state_t cur_dance(tap_dance_state_t *state);

  void b_finished(tap_dance_state_t *state, void *user_data);
  void b_reset(tap_dance_state_t *state, void *user_data);

  // void d_finished(tap_dance_state_t *state, void *user_data);
  // void d_reset(tap_dance_state_t *state, void *user_data);

  // Keymap
  const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [BASE] = LAYOUT_split_3x5_3(
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_BSPC,
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                     LR_MOUS, LR_NAV,  MT_SPC,          MT_ENT,   LR_SYM,  LR_FUNC
      ),

      [MOUSE] = LAYOUT_split_3x5_3(
          MR_BT,   MR_ST,   MR_PRT,  MR_NXT,  MR_W,                                XXXX,    MR_ZO,   KC_MS_U, MR_ZI,   XXXX,
          KC_LSFT, KC_LGUI, KC_BTN1, KC_BTN2, XXXX,                                XXXX,    KC_MS_L, KC_MS_D, KC_MS_R, XXXX,
          MR_WH_L, KC_WH_D, KC_WH_U, MR_WH_R, MR_SC,                               XXXX,    KC_PGDN, KC_PGUP, XXXX,    XXXX,
                                    ____,    ____,    ____,             ____,    ____,    ____
      ),

      [NAV] = LAYOUT_split_3x5_3(
          MR_BT,   MR_ST,   MR_PRT,  MR_NXT,  MR_W,                               XXXX,    MR_ZO,   XXXX,    MR_ZI,   XXXX,
          OS_CTRL, OS_ALT,  OS_SHFT, OS_CMD,  XXXX,                               KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ____,
          MR_WH_L, KC_WH_D, KC_WH_U, MR_WH_R, MR_SC,                              XXXX,    KC_PGDN, KC_PGUP, XXXX,    XXXX,
                                     ____,    ____,    ____,            ____,     ____,    ____
      ),

      [SYM] = LAYOUT_split_3x5_3(
          KC_GRV,  KC_ASTR, KC_CIRC, KC_AMPR, KC_PERC,                            KC_PLUS, KC_EXLM, KC_UNDS, KC_DLR,  KC_BSLS,
          KC_QUOT, KC_LBRC, KC_LPRN, KC_LCBR, KC_AT,                              KC_PIPE, KC_EQL,  KC_MINS, KC_COLN, ____,
          KC_DQT,  KC_RBRC, KC_RPRN, KC_RCBR, XXXX,                               XXXX,    KC_HASH, KC_AMPR, KC_SCLN, KC_TILD,
                                     ____,    ____,    ____,             ____,    ____,    ____
      ),

      [FUNC] = LAYOUT_split_3x5_3(
          KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
          KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXX,                               XXXX,    KC_RCMD, KC_RSFT, KC_RALT, KC_RCTL,
          KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                     ____,    ____,    ____,             ____,    ____,    ____
      ),

      [NUM] = LAYOUT_split_3x5_3(
          XXXX,    KC_1,    KC_2,    KC_3,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
          KC_0,    KC_4,    KC_5,    KC_6,    XXXX,                               XXXX,    KC_RCMD, KC_RSFT, CM_CAG,  CM_HYPR,
          XXXX,    KC_7,    KC_8,    KC_9,    XXXX,                               XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                     ____,    ____,    ____,             ____,    ____,    ____
      ),

      // [NUM] = LAYOUT_split_3x5_3(
      //     XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    KC_1,    KC_2,    KC_3,    XXXX,
      //     CM_HYPR, CM_CAG,  KC_LSFT, KC_LCMD, XXXX,                               XXXX,    KC_4,    KC_5,    KC_6,    ____,
      //     XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                               XXXX,    KC_7,    KC_8,    KC_9,    XXXX,
      //                               ____,    ____,    ____,             ____,    KC_0,    ____
      // ),
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
      [CO_WR] = COMBO(wr_combo, MR_HAT),
      [CO_SD] = COMBO(sd_combo, KC_TAB),
      [CO_DF] = COMBO(df_combo, KC_CAPS),
      [CO_SF] = COMBO(sf_combo, MR_AT),
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
      case LR_NAV:
      case LR_SYM:
      case OS_SHFT:
      case OS_CTRL:
      case OS_ALT:
      case OS_CMD:
          return true;
      default:
          return false;
      }
  }

  // Auto Shift
  bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
      switch(keycode) {
          case KC_COMM:
          case KC_DOT: 
          case KC_SLSH:
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
        case CM_CAG:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
            }
            break;
        
        case CM_HYPR:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_LSFT);
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
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
  td_state_t cur_dance(tap_dance_state_t *state) {
      if (state->count == 1) {
          if (state->pressed) return TD_SINGLE_HOLD;
          else return TD_SINGLE_TAP;
      } else if (state->count == 2) {
          if (state->pressed) return TD_DOUBLE_HOLD;
          else return TD_DOUBLE_TAP;
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

  // D
  // static td_tap_t dtap_state = {
  //     .is_press_action = true,
  //     .state = TD_NONE
  // };

  // void d_finished(tap_dance_state_t *state, void *user_data) {
  //     dtap_state.state = cur_dance(state);
  //     switch (dtap_state.state) {
  //         case TD_SINGLE_TAP: {
  //           if (get_mods()) {
  //             keyrecord_t custom_record = {0};
  //             custom_record.event.pressed = true;

  //             update_oneshot(
  //                 &os_shft_state, KC_LSFT, OS_SHFT,
  //                 KC_CLEAR, &custom_record
  //             );
  //             update_oneshot(
  //                 &os_ctrl_state, KC_LCTL, OS_CTRL,
  //                 KC_CLEAR, &custom_record
  //             );
  //             update_oneshot(
  //                 &os_alt_state, KC_LALT, OS_ALT,
  //                 KC_CLEAR, &custom_record
  //             );
  //             update_oneshot(
  //                 &os_cmd_state, KC_LCMD, OS_CMD,
  //                 KC_CLEAR, &custom_record
  //             );
  //           } else {
  //             tap_code(KC_CAPS);
  //           }
  //           break;
  //         }
  //         case TD_SINGLE_HOLD: layer_on(SYM);  break;
  //         default: break;
  //     }
  // }

  // void d_reset(tap_dance_state_t *state, void *user_data) {
  //     switch (dtap_state.state) {
  //         case TD_SINGLE_HOLD: layer_off(SYM); break;
  //         default: break;
  //     }
  //     dtap_state.state = TD_NONE;
  // }

  tap_dance_action_t tap_dance_actions[] = {
      [TD_WM_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, b_finished, b_reset),
      // [TD_SYM_FUNC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, d_finished, d_reset)
  };

  layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, NAV, SYM, NUM);
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