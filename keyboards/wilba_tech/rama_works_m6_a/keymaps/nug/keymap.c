#include QMK_KEYBOARD_H

#define MACRO0 LCTL(LALT(LSFT(KC_Z))) /* Discord deafen toggle, ctrl+alt+shift+z */
#define MACRO1 LGUI(KC_E) /* Open Directory Opus, win+e */
#define MACRO2 LCTL(LALT(LSFT(KC_C))) /* Show/hide foobar, ctrl+alt+shift+c */
#define MACRO3 LCTL(LALT(LSFT(KC_X))) /* Discord mute toggle, ctrl+alt+shift+x */

enum layers {
  _L0 = 0,
  _L1,
  _L2, /* Gaming layer */
  _L3, /* RESET layer */
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_L0] = LAYOUT(
   KC_CALC, MACRO2,  MACRO0, 
   MACRO1,  KC_MPLY, MACRO3),

[_L1] = LAYOUT(
  KC_NO,   KC_NO,    KC_NO, 
  KC_NO,   KC_NO,    KC_NO),

[_L2] = LAYOUT(
  KC_NO,   KC_NO,    KC_NO, 
  KC_NO,   KC_NO,    KC_NO),

[_L3] = LAYOUT(
  KC_NO,   KC_NO,    KC_NO, 
  KC_NO,   KC_NO,    KC_NO),
};