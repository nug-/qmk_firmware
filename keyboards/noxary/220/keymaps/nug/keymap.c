#include QMK_KEYBOARD_H // Layout for Noxary 220

#define LT_L1NL LT(_L1, KC_NLCK) /* Numlock on tap, LAYER ONE on hold */

enum layers {
  _L0 = 0,
  _L1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_L0] = LAYOUT_ortho_6x4(
		KC_ESC,  BL_TOGG, BL_DEC,  BL_INC, 
		LT_L1NL, KC_PSLS, KC_PAST, KC_PEQL, 
		KC_P7,   KC_P8,   KC_P9,   KC_PMNS, 
		KC_P4,   KC_P5,   KC_P6,   KC_PPLS, 
		KC_P1,   KC_P2,   KC_P3,   KC_PENT, 
		KC_P0,   KC_P0,   KC_PDOT, KC_PENT),

  [_L1] = LAYOUT_ortho_6x4(
    RESET,   BL_TOGG, BL_DEC,  BL_INC, 
    _______, KC_NO,   KC_NO,   KC_NO, 
    KC_NO,   KC_NO,   KC_NO,   KC_NO, 
    KC_NO,   KC_NO,   KC_NO,   KC_NO, 
    KC_NO,   KC_NO,   KC_NO,   KC_NO, 
    KC_NO,   KC_NO,   KC_NO,   KC_NO),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		DDRC |= (1 << 6); PORTC |= (1 << 6);
	} else {
		DDRC &= ~(1 << 6); PORTC &= ~(1 << 6);
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}