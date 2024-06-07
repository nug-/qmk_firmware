/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x63, 0x1B, 0xDF, 0x64, 0x4E, 0xA8, 0x6A, 0x97}

#define VIAL_UNLOCK_COMBO_ROWS {0, 2}
#define VIAL_UNLOCK_COMBO_COLS {0, 0}

// place overrides here
#undef TAPPING_TERM
#undef TAPPING_TOGGLE
#undef USB_POLLING_INTERVAL_MS
#undef HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define TAPPING_TOGGLE 2
#define TAPPING_TERM 175
#define USB_POLLING_INTERVAL_MS 1
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY