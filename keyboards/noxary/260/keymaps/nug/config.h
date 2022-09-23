#pragma once

// place overrides here
#undef TAPPING_TERM
#undef TAPPING_TOGGLE
#undef USB_POLLING_INTERVAL_MS
#undef LED_CAPS_LOCK_PIN
#undef LED_PIN_ON_STATE

#define TAPPING_TOGGLE 2
#define TAPPING_TERM 175
#define USB_POLLING_INTERVAL_MS 1
#define LED_CAPS_LOCK_PIN B0
#define LED_PIN_ON_STATE 1