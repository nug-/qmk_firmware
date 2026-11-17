// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once
#include_next <board.h>

// The generic STM32F072 board borrows the Nucleo-64 pin table (PA5 an LED output, PA2/PA3 UART).
// PA5 is a matrix row here, so start every pad as an input instead; only SWD (PA13/PA14) keeps
// its alternate function. QMK then sets up the matrix and USB.
#undef VAL_GPIOA_MODER
#define VAL_GPIOA_MODER ((2U << (13U * 2U)) | (2U << (14U * 2U)))
#undef VAL_GPIOB_MODER
#define VAL_GPIOB_MODER 0U
#undef VAL_GPIOC_MODER
#define VAL_GPIOC_MODER 0U
#undef VAL_GPIOD_MODER
#define VAL_GPIOD_MODER 0U
#undef VAL_GPIOE_MODER
#define VAL_GPIOE_MODER 0U
#undef VAL_GPIOF_MODER
#define VAL_GPIOF_MODER 0U

// The pull-up/pull-down table is left as is: SWD keeps its pulls and unused pads are pulled up
// instead of floating.
// matrix_init then sets the pull-ups on the matrix pins.
