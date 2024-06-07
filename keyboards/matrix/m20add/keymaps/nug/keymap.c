#include QMK_KEYBOARD_H // Layout for Matrix Add 2.0

#define LT_L1SP LT(_L1, KC_SPC) /* SPACE on tap, LAYER ONE on hold */
#define LT_L1DE LT(_L1, KC_DEL) /* DELETE on tap, LAYER ONE on hold */
#define RCTL_RA RCTL_T(KC_RGHT) /* Right arrow on tap, CTRL on hold */
#define RSFT_UA RSFT_T(KC_UP)   /* Up arrow on tap, SHIFT on hold */
#define RALT_LA RALT_T(KC_LEFT) /* Left arrow on tap, ALT on hold */
#define RGUI_DA RGUI_T(KC_DOWN) /* Down arrow on tap, GUI on hold */
#define MACRO0 LCTL(LALT(LSFT(KC_Z))) /* Discord deafen toggle, ctrl+alt+shift+z */
#define MACRO1 LCTL(LALT(LSFT(KC_X))) /* Discord mute toggle, ctrl+alt+shift+x */

enum layers {
  _L0 = 0,
  _L1,
  _L2, /* Gaming layer */
  _L3, /* RESET layer */
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_HOLD,
  TRIPLE_TAP,
};

//Tap dance enums
enum {
  TCAP = 0,
};

int cur_dance (tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void x_finished (tap_dance_state_t *state, void *user_data);
void x_reset (tap_dance_state_t *state, void *user_data);

/* 
 * ┌───┬──┬───┬───┬───┬───┬─┬───┬───┬───┬───┬──┬───┬───┬───┬───┐ ┌───┬───┬───┐
 * │ESC│  │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │ F8│  │F9 │F10│F11│F12│ │PRS│SCR│PAU│
 * └───┴──┴───┴───┴───┴───┴─┴───┴───┴───┴───┴──┴───┴───┴───┴───┘ └───┴───┴───┘
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
 * │ ~ │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ( │ ) │ BKSPC │ │INS│HOM│PGU│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
 * │ TAB │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │DEL│END│PGD│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
 * │ FUNC │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ ENTER  │ 
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐
 * │ SHIFT  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │   SHIFT  │     │UP │ 
 * ├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─────┤ ┌───┼───┼───┐
 * │CTRL │GUI│ ALT │         SPACE (6.25u)     │ ALT │GUI│CTRL │ │LFT│DWN│RGT│
 * └─────┴───┴─────┴───────────────────────────┴─────┴───┴─────┘ └───┴───┴───┘
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_L0]=LAYOUT_tkl_ansi_tsangan(
		KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SCRL, KC_PAUS,
		QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,
		KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN,
		TD(TCAP), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_UA,                            KC_UP,
		KC_LCTL,  KC_LGUI, KC_LALT,                            LT_L1SP,                            RALT_LA, RGUI_DA, RCTL_RA,          KC_LEFT, KC_DOWN, KC_RGHT),

	[_L1]=LAYOUT_tkl_ansi_tsangan(
		_______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
		KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______, _______, _______,
		KC_CAPS,  KC_PGUP, KC_UP,   KC_PGDN, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, KC_INS,  _______, _______, _______,
		_______,  KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_HOME, KC_PGDN, KC_END,  _______, _______, KC_PSCR,
		_______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP,                            KC_PGUP,
		_______,  _______, _______,                            _______,                            KC_HOME, KC_PGDN, KC_END,           KC_HOME, KC_PGDN, KC_END),

	[_L2]=LAYOUT_tkl_ansi_tsangan(
		KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           MACRO0,  MACRO1,  KC_PAUS,
		QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,
		KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN,
		_______,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                            KC_UP,
		KC_LCTL,  KC_NO,   KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT),

	[_L3]=LAYOUT_tkl_ansi_tsangan(
		QK_BOOT,  KC_F13,  KC_F14,  KC_F15,  KC_F18,  KC_F16,  KC_F19,  KC_F17,  KC_F20,  KC_F21,  KC_F22,  KC_NO,   KC_NO,            KC_F24,  RGB_TOG, RGB_MOD,
		KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_HUI, RGB_SAI, RGB_VAI,
		KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_HUD, RGB_SAD, RGB_VAD,
		_______,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,
		KC_NO,    KC_NO,   KC_NO,                              KC_NO,                              KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO),
};

int cur_dance (tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->interrupted || !state->pressed) return DOUBLE_TAP;
    else return DOUBLE_HOLD;
  }
  else if (state->count == 3) {
    return TRIPLE_TAP;
  }
  else return 5; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void x_finished (tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: 
      layer_on(_L1);
      break;
    case SINGLE_HOLD: 
      layer_on(_L1); 
      break;
    case DOUBLE_TAP: /*gaming layer*/
      layer_invert(_L2); 
      break;
    case DOUBLE_HOLD: 
      register_code(KC_LGUI); 
      break;
    case TRIPLE_TAP: /*reset layer*/
      layer_invert(_L3); 
      break;
  }
}

void x_reset (tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:
      layer_off(_L1); 
      break;
    case SINGLE_HOLD: 
      layer_off(_L1); 
      break;
    case DOUBLE_TAP: 
      break;
    case DOUBLE_HOLD: 
      unregister_code(KC_LGUI); 
      break;
    case TRIPLE_TAP: 
      break;
  }
  xtap_state.state = 0;
}

tap_dance_action_t tap_dance_actions[] = {
  [TCAP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _L1:
      rgblight_sethsv_noeeprom(0, 0, 255); /*white*/
      break;
    case _L2:
//      rgblight_sethsv_noeeprom(180, 255, 255); /*violet*/
      break;
    case _L3:
      rgblight_sethsv_noeeprom(0, 255, 255); /*red*/
      break;
    default:
      rgblight_sethsv_noeeprom(0, 0, 0);
      break;
  }
  return state;
}

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); /*enables RGB, without saving settings*/
  rgblight_sethsv_noeeprom(0, 0, 0); /*sets the color without saving*/
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); /*sets mode to solid without saving*/
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RCTL_RA:
            // Immediately select the hold action when another key is pressed.
            return true;
        case RSFT_UA:
            // Immediately select the hold action when another key is pressed.
            return true;
        case RGUI_DA:
            // Immediately select the hold action when another key is pressed.
            return true;
        case RALT_LA:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}