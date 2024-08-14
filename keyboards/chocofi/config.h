// Copyright 2022 Pavel Glushkov (@pashutk)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_ROWS  8
#define MATRIX_COLS  6

#define USE_SERIAL
#define SOFT_SERIAL_PIN D2

#define TAPPING_TERM 165
#define TAPPING_TOGGLE 1

#define AUTO_SHIFT_TIMEOUT 200
#define AUTO_SHIFT_REPEAT
#define NO_AUTO_SHIFT_NUMERIC

#define MK_KINETIC_SPEED
#define MOUSEKEY_INITIAL_SPEED 280 
#define MOUSEKEY_ACCELERATED_SPEED 2500

#define COMBO_TERM 30
#define COMBO_STRICT_TIMER
#define COMBO_MUST_HOLD_MODS
#define COMBO_HOLD_TERM 165