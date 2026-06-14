/* 
Copyright 2023 NEO

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                             KC_PSCR, KC_SCRL, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC,          KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,                   KC_DEL,  KC_END,  KC_PGDN,
        MO(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,            
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),                              KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, MO(1), KC_RCTL,                     KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [1] = LAYOUT(
        KC_ESC,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,                             KC_PSCR, KC_SCRL, KC_PAUS,
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_DEL,           KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_DEL,  KC_INS,  KC_SCRL, KC_PAUS, KC_NO,   KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_PSCR,                   KC_DEL,  KC_END,  KC_PGDN,
        KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT,KC_PSCR, KC_NO,   KC_NO,   KC_NO,   UG_PREV, UG_NEXT, UG_VALD, UG_VALU,          KC_ENT,            
        KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_CAPS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU, KC_RSFT, KC_NO,                              KC_PGUP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_NO,   KC_RCTL,                   KC_HOME, KC_PGDN, KC_END
    )
};

#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM caps_lock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_WHITE}
);

const rgblight_segment_t PROGMEM scroll_lock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_RED}
);

const rgblight_segment_t PROGMEM caps_and_scroll_lock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_ORANGE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    caps_lock_layer,
    scroll_lock_layer,
    caps_and_scroll_lock_layer
    
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    rgblight_set_layer_state(1, led_state.scroll_lock);
    rgblight_set_layer_state(2, led_state.caps_lock && led_state.scroll_lock);
    return true;
}
#endif
