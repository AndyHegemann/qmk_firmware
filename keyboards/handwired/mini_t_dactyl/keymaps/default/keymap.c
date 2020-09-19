#include "mini_t_dactyl.h"


#define _BASE 0
#define _FN   1
#define _COL 2

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
#define ALT_CAPS ALT_T(KC_CAPS)
#define SFT_ENT  RSFT_T(KC_ENT)
#define CTL_TAB  CTL_T(KC_TAB)
#define ALT_TAB  ALT_T(KC_TAB)

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

// detect mod status
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

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
 *              |  {   |   }  | ENTER|Space | FN   |          | CMD  |  BS  |DEL   |  __  |   +  |
 *              |  [   |   ]  | SHIFT|      | NAV  |          | ESC  |      |SHIFT |   -  |   =  |
 *              '------+------'------+------'------+          '------'------+------'------+------'
 */

[_BASE] = LAYOUT( \
  KC_GRV,  KC_1,  KC_2,    KC_3,  KC_4,    KC_5,                         KC_6,    KC_7,  KC_8,    KC_9,   KC_0,   DF(_COL),  \
  KC_TAB,  KC_Q,  KC_W,    KC_E,  KC_R,    KC_T,                         KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,   KC_BSLS,\
  KC_CAPS, KC_A,  KC_S,    KC_D,  KC_F,    KC_G,                         KC_H,    KC_J,  KC_K,    KC_L,   KC_SCLN,KC_QUOT,\
  KC_LCTL, KC_Z,  KC_X,    KC_C,  KC_V,    KC_B,                         KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,KC_RALT,\
                  KC_LBRC, KC_RBRC,                                                      KC_MINS, KC_EQL,                 \
                                  SFT_ENT,KC_SPC, LY_FN,       CMD_ESC, KC_BSPC, SFT_DEL                                 \
),

/* Layer: function + navigation
 * ,----------------------------------------,                        ,----------------------------------------,
 * |      |  F1 |  F2  |  F3  |  F4  |  F5  |                        |  F6  |  F7  |  F8  |  F9  |  F10 | F11 |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * | TAB  |     |      |      |      |      |                        |  del | home |   ^  | PgUp | vol+ | F12 |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * |      |     |      |      |      |      |                        |      |  <-  |   v  |   -> | mute |     |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * | CTRL |     |      |      |      |      |                        | home |  end | PgUp | PgDn | vol- |     |
 * '------+-----+------+------+------+------'------+          +------+------+------+------+------+------+-----'
 *              |      |      | ENTER|Space | FN   |          | CMD  |  BS  |DEL   |      |      |
 *              |      |      | SHIFT|      | NAV  |          | ESC  |      |SHIFT |      |      |
 *              '------+------'------+------'------+          '------'------+------'------+------'
 */

[_FN] = LAYOUT( \
  _____,   KC_F1,  KC_F2,  KC_F3, KC_F4, KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10,  KC_F11,\
  KC_TAB,  _____,  _____,  _____, _____, _____,                       KC_DEL,  KC_HOME, KC_UP,   KC_PGUP,   KC_VOLU, KC_F12,\
  _____,   _____,  _____,  _____, _____, _____,                       _____,   KC_LEFT, KC_DOWN, KC_RIGHT,  KC_MUTE, _____, \
  KC_LCTL, _____,  _____,  _____, _____, _____,                       KC_HOME, KC_END,  KC_PGUP, KC_PGDOWN, KC_VOLD, _____, \
                   _____,  _____,                                                       _____,   _____,                     \
                                  SFT_ENT,KC_SPC, _____,     CMD_ESC, KC_BSPC, SFT_DEL                                      \
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
 *              |  {   |   }  | ENTER|Space | FN   |          | CMD  |  BS  |DEL   |  __  |   +  |
 *              |  [   |   ]  | SHIFT|      | NAV  |          | ESC  |      |SHIFT |   -  |   =  |
 *              '------+------'------+------'------+          '------'------+------'------+------'
 */

[_COL] = LAYOUT( \
  KC_GRV,  KC_1,  KC_2,    KC_3,  KC_4,    KC_5,                         KC_6,    KC_7,  KC_8,    KC_9,   KC_0,    DF(_BASE),  \
  KC_TAB,  KC_Q,  KC_W,    KC_F,  KC_P,    KC_B,                         KC_J,    KC_L,  KC_U,    KC_Y,   KC_SCLN, KC_BSLS,\
  KC_CAPS, KC_A,  KC_R,    KC_S,  KC_T,    KC_G,                         KC_K,    KC_N,  KC_E,    KC_I,   KC_O,    KC_QUOT,\
  KC_LCTL, KC_Z,  KC_X,    KC_C,  KC_D,    KC_V,                         KC_M,    KC_H,  KC_COMM, KC_DOT, KC_SLSH, KC_RALT,\
                  KC_LBRC, KC_RBRC,                                                      KC_MINS, KC_EQL,                 \
                                  SFT_ENT,KC_SPC, LY_FN,       CMD_ESC, KC_BSPC, SFT_DEL                                 \
),

};


