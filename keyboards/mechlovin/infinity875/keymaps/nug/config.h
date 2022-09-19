#pragma once

// place overrides here
#undef TAPPING_TERM
#undef TAPPING_TOGGLE
#undef USB_POLLING_INTERVAL_MS

#define TAPPING_TOGGLE 2
#define TAPPING_TERM 175
#define USB_POLLING_INTERVAL_MS 1

#ifdef RGB_MATRIX_ENABLE

#define VIA_QMK_RGBLIGHT_ENABLE

#endif
