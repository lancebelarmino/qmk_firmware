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

#pragma once

#ifdef RGB_MATRIX_ENABLE
/* RGB Matrix driver configuration */
#    define DRIVER_COUNT 1
#    define DRIVER_ADDR_1 0b1110100
#    define RGB_MATRIX_LED_COUNT 61

/* Set to infinit, which is use in USB mode by default */
#    define RGB_MATRIX_TIMEOUT RGB_MATRIX_TIMEOUT_INFINITE

/* Allow shutdown of led driver to save power */
#    define RGB_MATRIX_DRIVER_SHUTDOWN_ENABLE

/* Turn off backlight on low brightness to save power */
#    define RGB_MATRIX_BRIGHTNESS_TURN_OFF_VAL 48

/* Indication led */
#    define DIM_CAPS_LOCK
#    define CAPS_LOCK_INDEX 28
#    define LOW_BAT_IND_INDEX 56

// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS

/* Set LED driver current */
#    define CKLED2001_CURRENT_TUNE \
        { 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50 }
#endif

#define ONESHOT_TAP_TOGGLE 5
#define ONESHOT_TIMEOUT 5000 
#define TAPPING_TERM 500
// #define MK_KINETIC_SPEED
// #define MOUSEKEY_INITIAL_SPEED 760
// #define MOUSEKEY_BASE_SPEED 2000
// #define MOUSEKEY_DECELERATED_SPEED 450
// #define MOUSEKEY_ACCELERATED_SPEED 2000
// #define MOUSEKEY_MOVE_DELTA 4
// #define MOUSEKEY_INTERVAL 6

#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
#define MK_C_OFFSET_UNMOD 12
#define MK_C_OFFSET_0 4
#define MK_C_OFFSET_1 6
#define MK_C_OFFSET_2 26