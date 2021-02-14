//qmk compile -kb handwired/mini_t_dactyl -km default


#include "mini_t_dactyl.h"


#define _BASE 0
#define _FN   3
#define _COL  2
#define _GAME 1

#define _____ KC_NO

// Mod-Tap
#define SFT_BSPC LSFT_T(KC_BSPC)
#define CMD_BSPC LCMD_T(KC_BSPC)
#define SFT_A    LSFT_T(KC_A)
#define SFT_Z    LSFT_T(KC_Z)
#define SFT_SCLN LSFT_T(KC_SCLN)
#define SFT_QUOT LSFT_T(KC_QUOT)
#define SFT_DEL  LSFT_T(KC_DEL)
#define CMD_DEL  LCMD_T(KC_DEL)
#define CMD_SPC  RCMD_T(KC_SPC)
#define CMD_ESC  RCMD_T(KC_ESC)
#define ALT_CAPS LALT_T(KC_CAPS)
#define SFT_ENT  RSFT_T(KC_ENT)
#define SFT_SPC  RSFT_T(KC_SPC)
#define CTL_TAB  CTL_T(KC_TAB)
#define ALT_TAB  ALT_T(KC_TAB)
#define FN_DEL   LT(_FN, KC_DEL)

// compose keys
#define CMD_TAB  LCMD(KC_TAB)
#define CMD_RTAB LCMD(KC_GRAVE)
#define CTL_LEFT LCTL(KC_LEFT)
#define CTL_RGHT LCTL(KC_RIGHT)

// mouse keys
#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

// active layers
#define LY_FN  MO(_FN)
#define B_BASE  LT(_BASE, KC_B)

// detect mod status
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

//dynamic macros
#define M_St DYN_REC_START1
#define M_Pl DYN_MACRO_PLAY1


#define KC_CUT LCTL(KC_X)
#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)


// Tap Dance declarations
enum {
    TD_Minus_Plus,
    TD_End_PgDwn,
    J_RPr,
    K_LPr,
    U_Min,
    I_Plus,
    Plus_Eq,
    Grv_LAYR
};

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

// Define a type for as many tap dance states as you need
enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP
};

// Function associated with all tap dances
uint8_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void gv_finished(qk_tap_dance_state_t *state, void *user_data);
void gv_reset(qk_tap_dance_state_t *state, void *user_data);

void JP_finished(qk_tap_dance_state_t *state, void *user_data);
void JP_reset(qk_tap_dance_state_t *state, void *user_data);

void KP_finished(qk_tap_dance_state_t *state, void *user_data);
void KP_reset(qk_tap_dance_state_t *state, void *user_data);

void IP_finished(qk_tap_dance_state_t *state, void *user_data);
void IP_reset(qk_tap_dance_state_t *state, void *user_data);

void RST_finished(qk_tap_dance_state_t *state, void *user_data);
void RST_reset(qk_tap_dance_state_t *state, void *user_data);



enum combos {
  AS_Cut,
  SD_Copy,
  DF_Paste
};

const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [AS_Cut] = COMBO(as_combo, KC_CUT),
  [SD_Copy] = COMBO(sd_combo, KC_COPY),
  [DF_Paste] = COMBO(df_combo, KC_PASTE)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Game
 * ,----------------------------------------,                        ,----------------------------------------,
 * |   ~  |  !  |   @  |   #  |   $  |   %  |                        |   ^  |   &  |   *  |   (  |   )  |     |
 * |   `  |  1  |   2  |   3  |   4  |   5  |                        |   6  |   7  |   8  |   9  |   0  |     |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * |      | Tab |   q  |   w  |   e  |   r  |                        |   y  |   u  |   i  |   o  |   p  | \|  |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * |      |Shift|   a  |   s  |   d  |   f  |                        |   h  |   j  |   k  |   l  |  ;:  | '"  |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * |      | Ctrl|   z  |   x  |   c  |   v  |                        |   n  |   m  |   ,  |   .  |  /?  | ALT |
 * '------+-----+------+------+------+------'------+          +------+------+------+------+------+------+-----'  
 *              |  {   |   }  |   b  |Space | FN   |          | CMD  |  BS  |DEL   |  __  |   +  |
 *              |  [   |   ]  | Base |      | NAV  |          | ESC  |      |FN    |   -  |   =  |
 *              '------+------'------+------'------+          '------'------+------'------+------'
 */

[_GAME] = LAYOUT( \
  TD(Grv_LAYR),  KC_1,      KC_2,  KC_3,    KC_4,  KC_5,                   KC_6,    KC_7,  KC_8,    KC_9,   KC_0,   DF(_COL),  \
  KC_NO,   KC_TAB,    KC_Q,  KC_W,    KC_E,  KC_R,                   KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,   KC_BSLS,\
  KC_NO,   KC_LSHIFT, KC_A,  KC_S,    KC_D,  KC_F,                   KC_H,    KC_J,  KC_K,    KC_L,   KC_SCLN,KC_QUOT,\
  KC_NO,   KC_LCTL,   KC_Z,  KC_X,    KC_C,  KC_V,                   KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,KC_RALT,\
                  KC_LBRC, KC_RBRC,                                            TD(TD_Minus_Plus), KC_EQUAL,                 \
                                   B_BASE, KC_SPC, LY_FN,         CMD_ESC, KC_BSPC, FN_DEL                                 \
),


/* Base (qwerty)
 * ,----------------------------------------,                        ,----------------------------------------,
 * |   ~  |  !  |   @  |   #  |   $  |   %  |                        |   ^  |   &  |   *  |   (  |   )  |     |
 * |   `  |  1  |   2  |   3  |   4  |   5  |                        |   6  |   7  |   8  |   9  |   0  |     |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * | TAB  |  q  |   w  |   e  |   r  |   t  |                        |   y  |   u  |   i  |   o  |   p  | \|  |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * | CAPS |  a  |   s  |   d  |   f  |   g  |                        |   h  |   j  |   k  |   l  |  ;:  | '"  |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * | CTRL |  z  |   x  |   c  |   v  |   b  |                        |   n  |   m  |   ,  |   .  |  /?  | ALT |
 * '------+-----+------+------+------+------'------+          +------+------+------+------+------+------+-----'  
 *              |  {   |   }  |Shift |Space |ENTER |          | CMD  |  BS  |DEL   |  __  |   +  |
 *              |  [   |   ]  |      |      |      |          | ESC  |      |FN    |   -  |   =  |
 *              '------+------'------+------'------+          '------'------+------'------+------'
 */

[_BASE] = LAYOUT( \
  TD(Grv_LAYR),  KC_1,  KC_2,    KC_3,  KC_4,    KC_5,                         KC_6,    KC_7,  KC_8,    KC_9,   KC_0,   DF(_COL),  \
  KC_TAB,  KC_Q,  KC_W,    KC_E,  KC_R,    KC_T,                         KC_Y,   TD(U_Min),  TD(I_Plus),    KC_O,   KC_P,   KC_BSLS,\
  ALT_CAPS, KC_A,  KC_S,    KC_D,  KC_F,    KC_G,                         KC_H,  TD(J_RPr),  TD(K_LPr),    KC_L,   KC_SCLN,KC_QUOT,\
  KC_LCTL, KC_Z,  KC_X,    KC_C,  KC_V,    KC_B,                         KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH,KC_RALT,\
                  KC_LBRC, KC_RBRC,                                            TD(TD_Minus_Plus), KC_EQUAL,                 \
                                KC_LSFT, KC_SPC, KC_ENT,         CMD_ESC, KC_BSPC, FN_DEL                                 \
),


/* Base (colemak-dh)
 * ,----------------------------------------,                        ,----------------------------------------,
 * |   ~  |  !  |   @  |   #  |   $  |   %  |                        |   ^  |   &  |   *  |   (  |   )  |     |
 * |   `  |  1  |   2  |   3  |   4  |   5  |                        |   6  |   7  |   8  |   9  |   0  |     |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * | TAB  |  q  |   w  |   f  |   p  |   b  |                        |   j  |   l  |   u  |   y  |  ;:  | \|  |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * | CAPS |  a  |   r  |   s  |   t  |   g  |                        |   k  |   n  |   e  |   i  |   o  | '"  |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * | CTRL |  z  |   x  |   c  |   d  |   v  |                        |   m  |   h  |   ,  |   .  |  /?  | ALT |
 * '------+-----+------+------+------+------'------+          +------+------+------+------+------+------+-----'  
 *              |  {   |   }  |Shift |Space |ENTER |          | CMD  |  BS  |DEL   |  __  |   +  |
 *              |  [   |   ]  |      |      |      |          | ESC  |      |FN    |   -  |   =  |
 *              '------+------'------+------'------+          '------'------+------'------+------'
 */


[_COL] = LAYOUT( \
  KC_GRV,   KC_1,  KC_2,    KC_3,  KC_4,    KC_5,                         KC_6,    KC_7,  KC_8,    KC_9,   KC_0,    DF(_BASE),  \
  KC_TAB,   KC_Q,  KC_W,    KC_F,  KC_P,    KC_B,                         KC_J,    KC_L,  KC_U,    KC_Y,   KC_SCLN, KC_BSLS,\
  ALT_CAPS, KC_A,  KC_R,    KC_S,  KC_T,    KC_G,                         KC_K,    KC_N,  KC_E,    KC_I,   KC_O,    KC_QUOT,\
  KC_LCTL,  KC_Z,  KC_X,    KC_C,  KC_D,    KC_V,                         KC_M,    KC_H,  KC_COMM, KC_DOT, KC_SLSH, KC_RALT,\
                   KC_LBRC, KC_RBRC,                                                 TD(TD_Minus_Plus), KC_EQUAL,                 \
                                KC_LSFT, KC_SPC, KC_ENT,         CMD_ESC, KC_BSPC, FN_DEL                                 \
),

/* Layer: function + navigation
 * ,----------------------------------------,                        ,----------------------------------------,
 * |      |  F1 |  F2  |  F3  |  F4  |  F5  |                        |  F6  |  F7  |  F8  |  F9  |  F10 | F11 |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * | TAB  |     |      |Play_M|Rec_M |      |                        | Prev | home |   ^  | PgUp | vol+ | F12 |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * |      |     | Prev | Play | Next |      |                        | Play |  <-  |   v  |   -> | mute |     |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * | CTRL |     | Cut  | Copy | Paste|      |                        | Next |  end |      | PgDn | vol- |     |
 * '------+-----+------+------+------+------'------+          +------+------+------+------+------+------+-----'
 *              |      |      | SHIFT|Space |ENTER |          | CMD  |  BS  |DEL   |      |      |
 *              |      |      |      |      |      |          | ESC  |      |FN    |      |      |
 *              '------+------'------+------'------+          '------'------+------'------+------'
 */

[_FN] = LAYOUT( \
  _____,   KC_F1,  KC_F2,  KC_F3,   KC_F4,    KC_F5,                     KC_F6,     KC_F7,      KC_F8,   KC_F9,     KC_F10,  KC_F11,\
  KC_TAB,  _____,  _____,  M_Pl,    M_St,     DM_RSTP,                   KC_MPRV,   KC_HOME,    KC_UP,   KC_PGUP,   KC_VOLU, KC_F12,\
  _____,   _____, KC_MPRV, KC_MPLY, KC_MNXT,  _____,                     KC_MPLY,   KC_LEFT,    KC_DOWN, KC_RIGHT,  KC_MUTE, _____, \
  KC_LCTL, _____, KC_CUT,  KC_COPY, KC_PASTE, _____,                     KC_MNXT,   KC_END,     _____,   KC_PGDOWN, KC_VOLD, _____, \
                   _____,  _____,                                                       _____,   _____,                     \
                                KC_LSFT, KC_SPC, KC_ENT,         CMD_ESC, KC_BSPC, FN_DEL                                 \
),

};





// Determine the current tap dance state
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) return DOUBLE_TAP;
    else return 8;
}



// Initialize tap structure associated with tap dance key
static tap gv_tap_state = {
    .is_press_action = true,
    .state = 0
};

// Functions that control what our tap dance key does
void gv_finished(qk_tap_dance_state_t *state, void *user_data) {
    gv_tap_state.state = cur_dance(state);
    switch (gv_tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_GRV);
            break;
        case SINGLE_HOLD:
            register_code(KC_GRV);
            break;
        case DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_GAME)) {
                // If already set, then switch it off
                layer_off(_GAME);
            } else {
                // If not already set, then switch the layer on
                layer_on(_GAME);
            }
            break;
    }
}

void gv_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (gv_tap_state.state == SINGLE_HOLD) {
        unregister_code(KC_GRV);
    }
    gv_tap_state.state = 0;
}



// Initialize tap structure associated with tap dance key
static tap JP_tap_state = {
    .is_press_action = true,
    .state = 0
};

// Functions that control what our tap dance key does
void JP_finished(qk_tap_dance_state_t *state, void *user_data) {
    JP_tap_state.state = cur_dance(state);
    switch (JP_tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_J);
            break;
        case SINGLE_HOLD:
            register_code16(KC_J);
            break;
        case DOUBLE_TAP:
            register_code16(KC_LPRN);
            break;
    }
}

void JP_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (JP_tap_state.state == SINGLE_HOLD) {
        unregister_code16(KC_J);
    }
    if (JP_tap_state.state == DOUBLE_TAP) {
        unregister_code16(KC_LPRN);
    }
    JP_tap_state.state = 0;
}



// Initialize tap structure associated with tap dance key
static tap KP_tap_state = {
    .is_press_action = true,
    .state = 0
};

// Functions that control what our tap dance key does
void KP_finished(qk_tap_dance_state_t *state, void *user_data) {
    KP_tap_state.state = cur_dance(state);
    switch (KP_tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_K);
            break;
        case SINGLE_HOLD:
            register_code16(KC_K);
            break;
        case DOUBLE_TAP:
            register_code16(KC_RPRN);
            break;
    }
}

void KP_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (KP_tap_state.state == SINGLE_HOLD) {
        unregister_code16(KC_K);
    }
    if (KP_tap_state.state == DOUBLE_TAP) {
        unregister_code16(KC_RPRN);
    }
    KP_tap_state.state = 0;
}



// Initialize tap structure associated with tap dance key
static tap IP_tap_state = {
    .is_press_action = true,
    .state = 0
};

// Functions that control what our tap dance key does
void IP_finished(qk_tap_dance_state_t *state, void *user_data) {
    IP_tap_state.state = cur_dance(state);
    switch (IP_tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_I);
            break;
        case SINGLE_HOLD:
            register_code16(KC_I);
            break;
        case DOUBLE_TAP:
            register_code16(KC_PLUS);
            break;
    }
}

void IP_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (IP_tap_state.state == SINGLE_HOLD) {
        unregister_code16(KC_I);
    }
    if (IP_tap_state.state == DOUBLE_TAP) {
        unregister_code16(KC_PLUS);
    }
    IP_tap_state.state = 0;
}



// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_Minus_Plus] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_KP_PLUS),
    [TD_End_PgDwn] = ACTION_TAP_DANCE_DOUBLE(KC_END, KC_PGDOWN),
    [J_RPr] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, JP_finished, JP_reset, 175),
    [K_LPr] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, KP_finished, KP_reset, 175),
    [U_Min] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_MINS),
    [I_Plus] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, IP_finished, IP_reset, 175),
    [Plus_Eq] = ACTION_TAP_DANCE_DOUBLE(KC_KP_PLUS, KC_EQUAL),
    [Grv_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, gv_finished, gv_reset, 200)
};

