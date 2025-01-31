/* Copyright 2023 yushakobo
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
#include "process_combo.h"

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;


#define OS_LSFT OSM(MOD_LSFT)

enum LAYER{
    CODE,
    GAME,
    NUM,
    NAV,
    SYM1,
    SYM2,
};

enum custom_keycodes {
    CK_AROW = SAFE_RANGE,   // ->
    CK_DARW,                // =>
};


enum combos {
    JK_RALT,
    KL_BSLS,
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};

combo_t key_combos[] = {
    [JK_RALT] = COMBO(jk_combo, KC_RALT),
    [KL_BSLS] = COMBO(kl_combo, KC_BSLS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [CODE] = LAYOUT(
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_8,     KC_9,    KC_0,     KC_PLUS,  KC_MINS,  KC_NO,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_6,     KC_7,     KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,
        MO(SYM1),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME,  KC_TRNS,  KC_H,     KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        MO(SYM2),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    MO(NAV),  KC_BSLS,  KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_NO,
        KC_LCTL,   KC_LGUI, KC_LALT, KC_NO,   KC_SPC,  KC_UNDS, KC_LCTL,  MO(NAV),  OS_LSFT,  KC_ENT,  MO(NUM),  KC_RALT,  KC_RGUI,  KC_LCTL
    ),
    [GAME] = LAYOUT(
        QK_GESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_Z,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_7,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_C,    KC_TRNS, KC_X,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(NUM), KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [SYM1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, CK_AROW, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_EXLM, KC_PLUS, KC_LPRN, KC_RPRN, KC_EQL,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TILD, KC_MINS, KC_LABK, KC_RABK, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, C(KC_SPC),KC_TRNS, KC_TRNS, CW_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [SYM2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_PERC, KC_TRNS, KC_TRNS, CK_DARW, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DLR,  KC_HASH, KC_LBRC, KC_RBRC, KC_COLN, KC_DQUO,
        KC_TRNS, KC_DEL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV,  KC_AT,   KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [NUM] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_TRNS, KC_TRNS, S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_TRNS,
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS, KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(NAV), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(GAME)
    ),
    [NAV] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F6,   KC_F7,   KC_TRNS, KC_LBRC, KC_TRNS, KC_RBRC, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_VOLU, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_TRNS, RGB_VAI,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,KC_TRNS, RGB_VAD,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC,  KC_ENT,  KC_SPC,  KC_TRNS, KC_TRNS, KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    bool ret = true;
    switch (keycode) {
    case CK_AROW:
        if (record->event.pressed) {
            send_string("->");
        }
        ret = false;
        break;
    case CK_DARW:
        if (record->event.pressed) {
          send_string("=>");
        }
        ret = false;
        break;
    case MO(SYM2):
        if (record->event.pressed) {
            register_code(KC_LSFT);
        }
        else {
            unregister_code(KC_LSFT);
        }
        break;
    case KC_LBRC:
    case KC_RBRC:
    case KC_GRV:
    case KC_DEL:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_code(KC_LSFT);
            }
        }
        break;
    case C(KC_HOME):
        if (record->event.pressed) {
            tap_code(KC_END);
        }
        ret = false;
        break;
    default:
        break;
    }

    return ret;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    return true;
}

HSV CreateHsv(u8 hue, u8 sat, u8 val) {
    HSV ret = {hue, sat, val};
    return ret;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    HSV hsv;

    switch (get_highest_layer(state)) {
        case GAME:
            hsv = CreateHsv(HSV_TEAL);
            break;
        case NAV:
            hsv = CreateHsv(HSV_GOLDENROD);
            break;
        case CODE:
            hsv = CreateHsv(HSV_CORAL);
            break;
        default:
            hsv = rgb_matrix_get_hsv();
            break;
    }

    hsv.v = rgb_matrix_get_val();

    rgb_matrix_sethsv(hsv.h, hsv.s, hsv.v);

    return state;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
    case KC_A ... KC_Z:
        add_weak_mods(MOD_BIT(KC_LSFT));
        return true;
    case KC_1 ... KC_9:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
        return true;

    default:
        return false;
    }

    return false;
}

void keyboard_post_init_user(void) {
    layer_clear();
}

#ifdef COMBO_TERM_PER_COMBO
uint16_t get_combo_term(u16 combo_index, combo_t* combo)
{
    return 100;
}
#endif
