#include QMK_KEYBOARD_H // layout for ProjectKB Alice (Tengu)

#define LT_L1SP LT(_L1, KC_SPC) /* SPACE on tap, LAYER ONE on hold */
#define LT_L1DE LT(_L1, KC_DEL) /* DELETE on tap, LAYER ONE on hold */
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_L0] = LAYOUT_default(
    KC_ESC,  QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
    KC_PGUP, KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_PGDN, TD(TCAP), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
             KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, LT_L1DE,
             KC_LCTL,           KC_LALT, LT_L1SP, KC_LGUI,                 LT_L1SP,          KC_RALT,          KC_RCTL),

  [_L1] = LAYOUT_default(
    _______, KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_DEL,
    KC_HOME, KC_CAPS,  KC_PGUP, KC_UP,   KC_PGDN, _______, _______,        _______, _______, KC_PGUP, _______, _______, _______, _______, KC_INS,
    KC_END,  _______,  KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,        _______, KC_HOME, KC_PGDN, KC_END,  _______, KC_UP,            KC_PSCR,
             _______,  _______, _______, _______, _______, _______,        _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
             _______,           _______, _______, _______,                 _______,          _______,          _______),

  [_L2] = LAYOUT_default(
    KC_ESC,  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
    MACRO0,  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    MACRO1,  _______,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
             KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_DEL,
             KC_LCTL,           KC_LALT, KC_SPC,  KC_SPC,                  KC_SPC,           KC_RALT,          KC_RCTL),

  [_L3] = LAYOUT_default(
    KC_NO,   QK_BOOT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   _______,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,
             KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
             KC_NO,             KC_NO,   KC_NO,   KC_NO,                   KC_NO,            KC_NO,            KC_NO),
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
  [TCAP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset),
};

void keyboard_pre_init_user(void) {
  setPinOutput(INDICATOR_PIN_0);
  setPinOutput(INDICATOR_PIN_1);
  setPinOutput(INDICATOR_PIN_2);
}

static uint8_t top = 0;
static uint8_t middle = 0;
static uint8_t bottom = 1;

layer_state_t layer_state_set_user(layer_state_t state) {
  top = middle = bottom = 0;
  switch (get_highest_layer(state)) {
    case _L1:
      writePinLow(INDICATOR_PIN_0);
      writePinHigh(INDICATOR_PIN_1);
      writePinHigh(INDICATOR_PIN_2);
      top = 1;
      break;
    case _L2:
      writePinLow(INDICATOR_PIN_1);
      writePinHigh(INDICATOR_PIN_0);
      writePinHigh(INDICATOR_PIN_2);
      middle = 1;
      break;
    case _L3:
      writePinLow(INDICATOR_PIN_2);
      writePinHigh(INDICATOR_PIN_0);
      writePinHigh(INDICATOR_PIN_1);
      bottom = 1;
      break;
    default:
      writePinHigh(INDICATOR_PIN_0);
      writePinHigh(INDICATOR_PIN_1);
      writePinHigh(INDICATOR_PIN_2);
      break;
  }
  return state;
}

bool led_update_user(led_t usb_led) {
  writePin(INDICATOR_PIN_0, !top);
  writePin(INDICATOR_PIN_1, !middle);
  writePin(INDICATOR_PIN_2, !bottom);
  return false;
}