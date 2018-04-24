#include "jj40.h"
#include "action_layer.h"

#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  '   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Ctrl |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Esc  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Lower|  Alt |"(GUI)|DE(RA)| Space(Shift)|BS(RA)|?(Alt)|  GUI | Lower|      |
 * `-----------------------------------------------------------------------------------'
 */
  // todo ",? on modifiers?
[_QWERTY] = KEYMAP( \
  KC_TAB,     KC_Q,    KC_W,    KC_E,           KC_R,          KC_T,    KC_Y,           KC_U,               KC_I,           KC_O,    KC_P,      KC_QUOT, \
  KC_LCTL,    KC_A,    KC_S,    KC_D,           KC_F,          KC_G,    KC_H,           KC_J,               KC_K,           KC_L,    KC_SCLN,   KC_RCTL, \
  KC_ESC,     KC_Z,    KC_X,    KC_C,           KC_V,          KC_B,    KC_N,           KC_M,               KC_COMM,        KC_DOT,  KC_SLSH,   KC_ENT , \
  _______, MO(_LOWER), KC_LALT, LGUI_T(KC_DQT), LT(_RAISE, KC_DEL), MT(MOD_LSFT, KC_SPC),  LT(_RAISE, KC_BSPC), RALT_T(KC_QUES), KC_RGUI, MO(_LOWER), _______ \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Bksp(Shift) |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,      KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    S(KC_NUHS),S(KC_NUBS),_______, _______, _______, \
  _______, _______, _______, _______, _______, MT(MOD_LSFT, KC_BSPC), _______, _______,  _______, _______, _______ \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |  -   |  =   |  [   |  ]   |  \   | Left | Down |  Up  | Right|   *  | Ctrl |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Esc  |  !   |  +   |  {   |  }   |   ^  |   $  |   (  |   )  |   %  |   #  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Bksp(Shift) |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,  KC_1,     KC_2,     KC_3,        KC_4,        KC_5,       KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, KC_MINUS, KC_EQUAL, KC_LBRACKET, KC_RBRACKET, KC_BSLASH,  KC_LEFT,   KC_DOWN, KC_UP,  KC_RIGHT, KC_ASTR, _______, \
  _______, KC_EXLM,  KC_PLUS,  KC_LCBR,     KC_RCBR,     KC_CIRC,    KC_DLR,    KC_LPRN, KC_RPRN, KC_PERC, KC_HASH, _______, \
  _______, _______,  _______,  _______,     _______,     MT(MOD_LSFT, KC_BSPC), _______, _______, _______, _______, _______ \
)
};

// Loop
void matrix_scan_user(void) {
  // Empty
};
