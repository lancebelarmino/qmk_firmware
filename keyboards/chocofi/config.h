// Copyright 2022 Pavel Glushkov (@pashutk)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_ROWS  8
#define MATRIX_COLS  6

#define USE_SERIAL
#define SOFT_SERIAL_PIN D2

#define NO_ALT_REPEAT_KEY

#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD

#define MOUSEKEY_INERTIA
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 40
#define MOUSEKEY_FRICTION  20
#define MOUSEKEY_MOVE_DELTA 1

#define COMBO_TERM 40
#define COMBO_STRICT_TIMER
#define COMBO_MUST_HOLD_MODS
#define COMBO_HOLD_TERM 165