#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  COPY,
  PSTE,
  VIM_S_ALL,
  VIM_CWH,
  VIM_CWJ,
  VIM_CWK,
  VIM_CWL,
  VIM_EM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | TT(2)  |   1  |   2  |   3  |   4  |   5  |      |           |OSL(2)|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Rclk |           |  =   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | TT(1)  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L1|' / Cmd |
 * |--------+------+------+------+------+------| Lclk |           |  $   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/Ct|'"/Al | CMD  | Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L2  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | ViEM |S_ALL |       | Alt  |  Tab   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | COPY |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Esc   |Enter |
 *                                 |      |ace   | PSTE |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,             KC_2,     KC_3,     KC_4,   KC_5,   RESET,
        KC_TAB,         KC_Q,             KC_W,     KC_E,     KC_R,   KC_T,   KC_BTN2,
        KC_NO,       KC_A,             KC_S,     KC_D,     KC_F,   KC_G,
        KC_LSFT,        KC_Z,             KC_X,     KC_C,     KC_V,   KC_B,   KC_BTN1,
        CTL_T(KC_GRV),  ALT_T(KC_QUOT),   KC_LGUI,  KC_LEFT,  KC_RGHT,

                                                  VIM_EM,     VIM_S_ALL,
                                                              COPY,
                                        KC_SPC,   KC_BSPC,    PSTE,


        // right hand
             KC_NO,   KC_6,   KC_7,  KC_8,      KC_9,     KC_0,               KC_MINS,
             KC_EQL,      KC_Y,   KC_U,  KC_I,      KC_O,     KC_P,        KC_BSLS,
                          KC_H,   KC_J,  KC_K,      KC_L,     KC_SCLN,     KC_QUOT,
             KC_DLR,      KC_N,   KC_M,  KC_COMM,   KC_DOT,   KC_SLSH,     KC_RSFT,
                                  KC_UP, KC_DOWN,   KC_LBRC,  KC_RBRC,            KC_FN1,
             KC_LALT,  GUI_T(KC_TAB),
             KC_PGUP,
             KC_PGDN,  KC_ESC,   KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | TO(0)   |  n   |  n   |  n   |   n  |   n  |  n   |           |   n  |   n  | n    |   n  |  n   |  n   |   n    |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |    n    |  n   |  n   | MsUp |   n  |   n  |TG(1) |           |  n   |   n  |   n  |   n  |  n   |  n   |   n    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  lock   |  n   |MsLeft|MsDown|MsRigt|   n  |------|           |------|VI_CWH|VI_CWJ|VI_CWk|VI_CWL|  n   |   n    |
 * |---------+------+------+------+------+------|  n   |           |      |------+------+------+------+------+--------|
 * |    n    |   n  |  n   | MwUP | MwDU |   n  |      |           |  n   |   n  |   n  |   n  |  n   |  n   |   n    |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | FLASH |   n  |  n   |  n   |  n   |                                       |  Ma0 |   n  |  n   |  n   |   n  |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  n   |  n   |       |   n  |  n   |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Lclk  | Rclk |  n   |       |   n  | Ma2  | Ma1  |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |  n   |       |   n  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
// [SYMB] = LAYOUT_ergodox(
//        // left hand
//        TO(BASE),     KC_NO,      KC_NO,        KC_NO,       KC_NO,       KC_NO,       KC_NO,  
//        KC_NO,     KC_NO,      KC_NO,        KC_MS_U,     KC_NO,       KC_NO,       TG(SYMB),  
//        KC_TRNS,   KC_NO,      KC_MS_L,      KC_MS_D,     KC_MS_R,     KC_NO,  
//        KC_NO,     KC_NO,      KC_NO,        KC_WH_U,     KC_WH_D,     KC_NO,       KC_NO,  
//        RESET,     KC_NO,      KC_NO,     KC_NO,       KC_NO,  
//                                                                                KC_NO,    KC_NO,  
//                                                                                          KC_NO,  
//                                                                  KC_BTN1,      KC_BTN2,  KC_NO,  

//        // right hand
//        KC_NO,     KC_NO,      KC_NO,        KC_NO,        KC_NO,       KC_NO,       KC_NO,  
//        KC_NO,     KC_NO,      KC_NO,        KC_NO,        KC_NO,       KC_NO,       KC_NO,  
//                   VIM_CWH,    VIM_CWJ,      VIM_CWK,      VIM_CWL,     KC_NO,       KC_NO,  
//        KC_NO,     KC_NO,      KC_NO,        KC_NO,        KC_NO,       KC_NO,       KC_NO,  
//                               KC_ACL0,      KC_NO,        KC_NO,       KC_NO,       KC_NO,  
//        KC_NO,    KC_NO,  
//        KC_NO,    
//        KC_NO,    KC_ACL2,  KC_ACL1
// ),
/* Keymap 2: Media and mouse keys
 *

 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  TO(0)  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |  n   |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|TG(2) |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
// [MDIA] = LAYOUT_ergodox(
//        TO(BASE),  KC_F1,    KC_F2,    KC_F3,     KC_F4,     KC_F5,    KC_TRNS,
//        KC_TRNS,   KC_EXLM,  KC_AT,    KC_LCBR,   KC_RCBR,   KC_PIPE,  KC_TRNS,
//        KC_TRNS,   KC_HASH,  KC_DLR,   KC_LPRN,   KC_RPRN,   KC_GRV,
//        KC_TRNS,   KC_PERC,  KC_CIRC,  KC_LBRC,   KC_RBRC,   KC_TILD,  KC_TRNS,
//        KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
//                                        RGB_MOD,KC_TRNS,
//                                                KC_TRNS,
//                                RGB_VAD,RGB_VAI,KC_TRNS,
//        // right hand
//        KC_TRNS,   KC_F6,     KC_F7,    KC_F8,   KC_F9,       KC_F10,     KC_F11,
//        KC_TRNS,   KC_UP,     KC_7,     KC_8,    KC_9,        KC_ASTR,    KC_F12,
//                   KC_DOWN,   KC_4,     KC_5,    KC_6,        KC_PLUS,    KC_TRNS,
//        KC_TRNS,   KC_AMPR,   KC_1,     KC_2,    KC_3,        KC_BSLS,    KC_TRNS,
//                              KC_TRNS,  KC_DOT,  KC_0,        KC_EQL,     KC_TRNS,
//        RGB_TOG,  RGB_SLD,
//        KC_TRNS,  
//        KC_TRNS,  RGB_HUD,  RGB_HUI
// ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(MDIA)                // FN1 - Momentary Layer 2 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.

    // case COPY:
    //   if (record->event.pressed) {
    //     SEND_STRING (SS_LGUI("c"));
    //   }
    //   return false;
    //   break;
    // case PSTE:
    //   if (record->event.pressed) {
    //     SEND_STRING (SS_LGUI("v"));
    //   }
    //   return false;
    //   break;
    // case VIM_S_ALL:
    //   if (record->event.pressed) {
    //     SEND_STRING ("ggVG");
    //   }
    //   return false;
    //   break;

    // case VIM_EM:
    //   if (record->event.pressed) {
    //     SEND_STRING ("\\\\s");
    //   }
    //   return false;
    //   break;
      
    // case VIM_CWH:
    //   if (record->event.pressed) {
    //     SEND_STRING (SS_LCTRL("w")"h");
    //   }
    //   return false;
    //   break;

    // case VIM_CWJ:
    //   if (record->event.pressed) {
    //     SEND_STRING (SS_LCTRL("w")"j");
    //   }
    //   return false;
    //   break;

    // case VIM_CWK:
    //   if (record->event.pressed) {
    //     SEND_STRING (SS_LCTRL("w")"k");
    //   }
    //   return false;
    //   break;

    // case VIM_CWL:
    //   if (record->event.pressed) {
    //     SEND_STRING (SS_LCTRL("w")"l");
    //   }
    //   return false;
    //   break;

    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }

};
