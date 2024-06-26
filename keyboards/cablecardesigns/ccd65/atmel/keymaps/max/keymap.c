#include QMK_KEYBOARD_H

#define _MA 0
#define _F1 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MA] = LAYOUT(
    KC_ESC,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS, KC_EQL,KC_GRV, KC_DEL, KC_HOME,\
    KC_TAB,   KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,KC_RBRC,KC_BSPC,         KC_PGUP, \
    KC_LCTRL,  KC_A,  KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,_______,KC_ENT,         KC_PGDN,  \
    KC_LSFT,KC_BSLS, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,KC_UP,         MO(_F1), \
    KC_LGUI,KC_LALT,KC_LALT,                 KC_SPC,                        KC_RGUI,KC_RALT,             KC_LEFT,KC_DOWN,KC_RGHT),

  [_F1] = LAYOUT(
    RESET,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,  KC_F12,_______,KC_PSCR,KC_END, \
    KC_CAPS,RGB_TOG,RGB_MOD,RGB_HUI,RGB_HUD,RGB_SAI,RGB_SAD,RGB_VAI,RGB_VAD,_______,_______,_______,_______,KC_DEL,        _______, \
    _______,KC_VOLD,KC_MUTE,KC_VOLU,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,  \
    _______,_______,KC_MPRV,KC_MNXT,KC_MPLY,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______, \
    _______,_______,_______,                _______,                        _______,_______,_______,_______,                _______)
  };
