#include QMK_KEYBOARD_H // Layout for Jubi

#define LT_L1SP LT(_L1, KC_SPC) /* SPACE on tap, LAYER ONE on hold */
#define LT_L1DE LT(_L1, KC_DEL) /* DELETE on tap, LAYER ONE on hold */
#define RCTL_RA RCTL_T(KC_RGHT) /* Right arrow on tap, CTRL on hold */
#define RSFT_UA RSFT_T(KC_UP)   /* Up arrow on tap, SHIFT on hold */
#define RALT_LA RALT_T(KC_LEFT) /* Left arrow on tap, ALT on hold */
#define RGUI_DA RGUI_T(KC_DOWN) /* Down arrow on tap, GUI on hold */
#define MACRO0 LCTL(LALT(LSFT(KC_Z))) /* Discord deafen toggle, ctrl+alt+shift+z */
#define MACRO1 LCTL(LALT(LSFT(KC_X))) /* Discord mute toggle, ctrl+alt+shift+x */
#define MACRO2 LCTL(LALT(LSFT(KC_C))) /* Show/hide foobar, ctrl+alt+shift+c */

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
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │MC0│MC1│ESC│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ( │ ) │ BKSPC │
 * ├───┼───┼───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │MC2│MC3│ TAB │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
 * ├───┼───┼─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │MC4│MC5│ FUNC │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ ENTER  │
 * ├───┼───┼──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 * │MC6│MC7│ SHIFT  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │SHIFT │FN │
 * ├───┼───┼─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─┴───┤
 * │MC8│MC9│CTRL │GUI│ ALT │         SPACE (7u)        │ ALT │GUI│CTRL │
 * └───┴───┴─────┴───┴─────┴───────────────────────────┴─────┴───┴─────┘
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_L0] = LAYOUT_all(
	AU_TOG,  KC_HOME, QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
	CK_TOGG, KC_PGUP, KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
	MACRO2,  KC_PGDN, TD(TCAP), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
	KC_MPLY, KC_END,  KC_LSFT,  KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_UA, LT_L1DE,
	MACRO0,  MACRO1,  KC_LCTL,  KC_LGUI, KC_LALT,                            LT_L1SP,                            RALT_LA, RALT_LA, RGUI_DA, RCTL_RA),

[_L1] = LAYOUT_all(
	_______, _______, KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_DEL,
	_______, _______, KC_CAPS,  KC_PGUP, KC_UP,   KC_PGDN, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, KC_INS,
	_______, _______, _______,  KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_HOME, KC_PGDN, KC_END,  _______, _______, KC_PSCR,
	_______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______,
	_______, _______, _______,  _______, _______,                            _______,                            KC_HOME, KC_HOME, KC_PGDN, KC_END),

[_L2] = LAYOUT_all(
	KC_F1,   KC_HOME, QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
	KC_F2,   KC_PGUP, KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
	MACRO2,  KC_PGDN, _______,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
	KC_MPLY, KC_END,  KC_LSFT,  KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_DEL,
	MACRO0,  MACRO1,  KC_LCTL,  KC_NO,   KC_LALT,                            KC_SPC,                             KC_LEFT, KC_LEFT, KC_DOWN, KC_RGHT),

[_L3] = LAYOUT_all(
	KC_NO,   KC_NO,   QK_BOOT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
	KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
	KC_NO,   KC_NO,   _______,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
	KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,                              KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO),
};

#ifdef AUDIO_ENABLE
#include "audio.h"
#include "song_list.h"
float tone_capsoff[][2]   = SONG(CAPS_LOCK_OFF_SOUND);
float tone_capson[][2]    = SONG(CAPS_LOCK_ON_SOUND);
float tone_numlkoff[][2]  = SONG(NUM_LOCK_OFF_SOUND);
float tone_numlkon[][2]   = SONG(NUM_LOCK_ON_SOUND);
float tone_scrolloff[][2] = SONG(SCROLL_LOCK_OFF_SOUND);
float tone_scrollon[][2]  = SONG(SCROLL_LOCK_ON_SOUND);
//float s1[][2]              = SONG(CAMPANELLA);
//float s2[][2]              = SONG(FANTASIE_IMPROMPTU);
//float s3[][2]              = SONG(NOCTURNE_OP_9_NO_1);
#endif

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
      //#ifdef AUDIO_ENABLE
        //PLAY_SONG(tone_capson);
      //#endif //AUDIO_ENABLE
      break;
    case SINGLE_HOLD: 
    	layer_on(_L1);
      //#ifdef AUDIO_ENABLE
        //PLAY_SONG(tone_capson);
      //#endif //AUDIO_ENABLE
      break;
    case DOUBLE_TAP: 
    	layer_invert(_L2); 
      #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_numlkon);
      #endif //AUDIO_ENABLE
    	break;
    case TRIPLE_TAP: 
    	layer_invert(_L3); 
      #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_scrollon);
      #endif //AUDIO_ENABLE
    	break;
  }
}

void x_reset (tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:
      layer_off(_L1);
      //#ifdef AUDIO_ENABLE
        //PLAY_SONG(tone_capsoff);
      //#endif //AUDIO_ENABLE
    	break;
    case SINGLE_HOLD:
    	layer_off(_L1);
      //#ifdef AUDIO_ENABLE
        //PLAY_SONG(tone_capsoff);
      //#endif //AUDIO_ENABLE
      break;
    case DOUBLE_TAP: 
      #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_numlkoff);
      #endif //AUDIO_ENABLE
    	break;
    case TRIPLE_TAP: 
      #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_scrolloff);
      #endif //AUDIO_ENABLE
    	break;
  }
  xtap_state.state = 0;
}

tap_dance_action_t tap_dance_actions[] = {
  [TCAP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset),
};

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