//qmk compile -kb handwired/goldtouch -km default

#include "goldtouch.h"


#define KC_CUT LCTL(KC_X)
#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)
#define KC_UNDO LCTL(KC_Z)
#define LT_0_LY LT(1, KC_0)

// Tap Dance declarations
enum {
    TD_Home_PgUp,
    TD_End_PgDwn
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_Home_PgUp] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_PGUP),
    [TD_End_PgDwn] = ACTION_TAP_DANCE_DOUBLE(KC_END, KC_PGDOWN),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
		KC_ESC,		KC_TAB,		KC_BSPC,	TG(1), 
		KC_CALC,	KC_PSLS,	KC_PAST,	KC_PMNS, 
		KC_7,  		KC_8,		KC_9,		KC_PPLS, 
		KC_4,		KC_5,		KC_6,
		KC_1,		KC_2,		KC_3, 
		LT_0_LY,	KC_DOT,		KC_PENT
		),

	[1] = LAYOUT(
		KC_TRNS,			KC_TRNS,		KC_TRNS,			KC_TRNS, 
		KC_F21,				KC_F22,			KC_F23,				KC_F24, 
		TD(TD_Home_PgUp), 	KC_UP,   		TD(TD_End_PgDwn),	KC_COPY, 
		KC_LEFT,			KC_DOWN,		KC_RGHT, 
		KC_CUT,				OSL(2),			KC_NO,
		KC_TRNS,			KC_UNDO,		KC_PASTE
		), 

	[2] = LAYOUT(
		BL_DEC,		KC_NO,		BL_INC,		KC_NO, 
		KC_DLR,		KC_LT,		KC_GT,		KC_NO, 
		KC_AMPR,	KC_PERC,	KC_EXLM,	KC_NO, 
		KC_LPRN,	KC_RPRN,	KC_BSLS, 
		KC_TILD,	KC_AT,		KC_HASH, 
		KC_NO,		KC_COMM,	KC_EQL
		)
};



//This runs code every time that the layers get changed
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 0:
        backlight_disable();
        break;
    case 1:
        backlight_enable();
        //backlight_level(3);
        breathing_disable();
        break;
    case 2:
        breathing_enable();
        break;
    }
  return state;
}



