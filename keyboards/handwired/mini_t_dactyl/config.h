#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Andy_H
#define PRODUCT         Mini-Thumb-Dactyl
#define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

/* key matrix pins */
#define MATRIX_ROW_PINS { F5, F6, F7, B1, B3}
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }
// #define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

#define SOFT_SERIAL_PIN D0

#define FORCE_NKRO


#define TAPPING_TERM 200

#define COMBO_TERM 50
#define COMBO_COUNT 3


/* How to determine left/right hand. Choose one: */
// #define SPLIT_HAND_PIN D2  // must have 10k resistor connect to RXI pin
#define MASTER_LEFT
// #define MASTER_RIGHT

#endif