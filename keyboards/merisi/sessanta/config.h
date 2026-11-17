// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// STM32F072RBT6: the last 8 KiB of flash (0x0801E000-0x0801FFFF) hold the emulated EEPROM.
// The linker script in ld/ keeps program code out of it.
#define FEE_MCU_FLASH_SIZE 128
#define FEE_PAGE_SIZE 0x800
#define FEE_PAGE_COUNT 4
#define FEE_DENSITY_BYTES 4096
#define FEE_PAGE_BASE_ADDRESS 0x0801E000

// Stock settings defaults.
#define NKRO_DEFAULT_ON true
#define TAPPING_TERM 200
#define COMBO_TERM 50
#define AUTO_SHIFT_TIMEOUT 175
#define ONESHOT_TAP_TOGGLE 5
#define ONESHOT_TIMEOUT 5000
#define TAP_CODE_DELAY 0
#define TAP_HOLD_CAPS_DELAY 80
#define TAPPING_TOGGLE 5
#define MOUSEKEY_DELAY 10
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_MOVE_DELTA 8
#define MOUSEKEY_MAX_SPEED 10
#define MOUSEKEY_TIME_TO_MAX 30
#define MOUSEKEY_WHEEL_DELAY 10
#define MOUSEKEY_WHEEL_INTERVAL 80
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

// Debounce: QMK default (global deferred, 5 ms), the same as the stock firmware.
