#include "goldtouch.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
		KC_MPRV, KC_MPLY, KC_MNXT, DF(1), 
		KC_CALC, KC_PSLS, KC_PAST, KC_PMNS, 
		KC_7,    KC_8,    KC_9,    KC_PPLS, 
		KC_4, 	 KC_5, 		KC_6, 
		KC_1, 	 KC_2, 		KC_3, 
		KC_0, 	 KC_DOT, 	KC_PENT),

	[1] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, DF(0), 
		KC_F21, KC_F22,  KC_F23,  KC_F24, 
		KC_HOME, KC_UP,   KC_END,  KC_COPY, 
		KC_LEFT, KC_DOWN, KC_RGHT, 
		KC_CUT,  OSL(2),  KC_NO, 
		KC_LSFT, KC_UNDO, KC_PSTE), 

	[2] = LAYOUT(
		KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_DLR, KC_LT, KC_GT, KC_NO, 
		KC_AMPR, KC_PERC, KC_EXLM, KC_NO, 
		KC_LPRN, KC_RPRN, KC_BSLS, 
		KC_TILD, KC_AT, KC_HASH, 
		KC_NO, KC_PCMM, KC_PEQL)
};



const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	keyevent_t event = record->event;

	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}