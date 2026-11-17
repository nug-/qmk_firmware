// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once
#include_next <mcuconf.h>

// Crystal-less STM32F072. PC14/PC15 are matrix signals, not LSE pins.
#undef STM32_HSE_ENABLED
#define STM32_HSE_ENABLED FALSE
#undef STM32_LSE_ENABLED
#define STM32_LSE_ENABLED FALSE
#undef STM32_HSI48_ENABLED
#define STM32_HSI48_ENABLED TRUE
