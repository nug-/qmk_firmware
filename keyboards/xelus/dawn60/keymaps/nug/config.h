#pragma once

/* enable/disable LEDs based on layout */
// switch between split backspace (1) or normal backspace(0)
#undef RGB_BACKLIGHT_USE_SPLIT_BACKSPACE
#define RGB_BACKLIGHT_USE_SPLIT_BACKSPACE 0

// switch between Tsangan (1) or Arrows Bottom Row (0)
#undef RGB_BACKLIGHT_USE_7U_SPACEBAR
#define RGB_BACKLIGHT_USE_7U_SPACEBAR 1

// switch between standard split rshift (0) or arrows r shift (1)
// .------------------.           .-------------------.
// | ? |  Shift  | Fn |    vs     |  Shift  | Up | Fn |
// `------------------'           `-------------------'
#undef RGB_BACKLIGHT_USE_SPLIT_RIGHT_SHIFT
#define RGB_BACKLIGHT_USE_SPLIT_RIGHT_SHIFT 0

#undef TAPPING_TERM
#undef TAPPING_TOGGLE
#undef USB_POLLING_INTERVAL_MS
// #undef HOLD_ON_OTHER_KEY_PRESS

#define TAPPING_TOGGLE 2
#define TAPPING_TERM 175
#define USB_POLLING_INTERVAL_MS 1
// #define HOLD_ON_OTHER_KEY_PRESS