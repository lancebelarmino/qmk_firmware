// Copyright 2022 Pavel Glushkov (@pashutk)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_ROWS  8
#define MATRIX_COLS  6

#define USE_SERIAL
#define SOFT_SERIAL_PIN D2

#define TAPPING_TERM 165
#define TAPPING_TOGGLE 1

#define AUTO_SHIFT_TIMEOUT 165
#define NO_AUTO_SHIFT_NUMERIC

#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
#define MK_C_OFFSET_UNMOD 12
#define MK_C_OFFSET_0 4
#define MK_C_OFFSET_1 6
#define MK_C_OFFSET_2 26

#define COMBO_TERM 30
#define COMBO_STRICT_TIMER
#define COMBO_MUST_HOLD_MODS
#define COMBO_HOLD_TERM 165