/* Copyright 2021 Andrzej Ressel (andrzej.ressel@gmail.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

const rgblight_segment_t PROGMEM layer1_segment[] = RGBLIGHT_LAYER_SEGMENTS(
    {16, 1, HSV_WHITE} // Turn LED 16 on
);
const rgblight_segment_t PROGMEM layer2_segment[] = RGBLIGHT_LAYER_SEGMENTS(
    {12, 1, HSV_WHITE} // Turn LED 12 on
);

enum rgb_layer_index {
    RGB_LAYER_1,
    RGB_LAYER_2,
};

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    [RGB_LAYER_1] = layer1_segment,
    [RGB_LAYER_2] = layer2_segment
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(RGB_LAYER_1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(RGB_LAYER_2, layer_state_cmp(state, 2));
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_F1,      KC_PSCR,        KC_HOME,        KC_PGUP,        KC_F2,
        KC_F3,      KC_DEL,         KC_END,         KC_PGDN,        KC_F4,
        KC_F5,      KC_F6,          KC_GRV,         KC_F7,          KC_F8,
        KC_F9,      KC_F10,         KC_UP,          KC_F11,         KC_F12,
        TG(1),      KC_LEFT,        KC_DOWN,        KC_RGHT,        TG(2)
    ),
    [1] = LAYOUT(
        KC_NO,      KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,      KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,      KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,      RM_PREV,        KC_VOLU,        RM_NEXT,        KC_NO,
        TO(0),      RM_VALD,        KC_VOLD,        RM_VALU,        TO(0)
    ),
    [2] = LAYOUT(
        KC_NO,      KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,      KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,      KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,      RM_PREV,        KC_VOLU,        RM_NEXT,        KC_NO,
        TO(0),      RM_VALD,        KC_VOLD,        RM_VALU,        TO(0)
    ),
};
