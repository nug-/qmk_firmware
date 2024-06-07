#pragma once

// place overrides here
#undef TAPPING_TERM
#undef TAPPING_TOGGLE
#undef USB_POLLING_INTERVAL_MS
#undef HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define TAPPING_TOGGLE 2
#define TAPPING_TERM 175
#define USB_POLLING_INTERVAL_MS 1
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define INDICATOR_PIN_0 B2
#define INDICATOR_PIN_1 C15
#define INDICATOR_PIN_2 B9