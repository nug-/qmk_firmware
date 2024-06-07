#include QMK_KEYBOARD_H // Layout for M6-A

#define MACRO0 LCTL(LALT(LSFT(KC_Z))) /* Discord deafen toggle, ctrl+alt+shift+z */
#define MACRO1 LCTL(LALT(LSFT(KC_X))) /* Discord mute toggle, ctrl+alt+shift+x */
#define MACRO2 LGUI(KC_E) /* Open Directory Opus, win+e */
#define MACRO3 LCTL(LALT(LSFT(KC_C))) /* Show/hide foobar, ctrl+alt+shift+c */

enum layers {
  _L0 = 0,
  _L1,
  _L2,
  _L3,
};

typedef struct {
    bool is_press_action;
    int state;
} tap;

enum {
  SINGLE_TAP = 1, /* tap open calculator */
  DOUBLE_TAP,
  TRIPLE_TAP,
  QUAD_TAP,
};

//Tap dance enums
enum {
  TDAN = 0,
};

int cur_dance (tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void x_finished (tap_dance_state_t *state, void *user_data);
void x_reset (tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_L0] = LAYOUT(
  TD(TDAN), MACRO3,  MACRO0, 
  MACRO2,   KC_MPLY, MACRO1),

[_L1] = LAYOUT(
  _______,  KC_W,    QK_LOCK, 
  KC_A,     KC_S,    KC_D),

[_L2] = LAYOUT(
  _______,  KC_UP,   QK_LOCK, 
  KC_LEFT,  KC_DOWN, KC_RGHT),

[_L3] = LAYOUT(
  _______,  KC_NO,   KC_NO, 
  KC_NO,    KC_NO,   QK_BOOT),
};

int cur_dance (tap_dance_state_t *state) {
  if (state->count == 1) {
    return SINGLE_TAP;
  }
  else if (state->count == 2) {
    return DOUBLE_TAP;
  }
  else if (state->count == 3) {
    return TRIPLE_TAP;
  }
  else if (state->count == 4) {
    return QUAD_TAP;
  }
  else return 5; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'TDAN' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void x_finished (tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: 
      register_code(KC_CALC);unregister_code(KC_CALC);
      break;
    case DOUBLE_TAP: 
      layer_invert(_L1); 
      break;
    case TRIPLE_TAP: 
      layer_invert(_L2); 
      break;
    case QUAD_TAP: 
      layer_invert(_L3); 
      break;
  }
}

void x_reset (tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:
      break;
    case DOUBLE_TAP:  
      break;
    case TRIPLE_TAP: 
      break;
    case QUAD_TAP: 
      break;
  }
  xtap_state.state = 0;
}

tap_dance_action_t tap_dance_actions[] = {
  [TDAN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
};
