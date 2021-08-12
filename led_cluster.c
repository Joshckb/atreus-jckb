#include "led_cluster.h"
#include "ws2812.h"

// Colors
static const cRGB indicator = { 0, 10, 0 };
static const cRGB white = { 10, 10, 10 };
static const cRGB off = { 0, 0, 0 };

// TODO: Handle this better.
//static bool leds_state = false;
static led_t led_state;
static uint8_t layer;

// Breathing
static bool breathing_state = false;
//static uint8_t breathing_step = 1;
//static uint8_t breathing_speed = 1;

static uint8_t base_led_indices[4] = {};
static uint8_t caps_lock_led_index = 5;
static uint8_t num_lock_led_index = 0;
static cRGB leds[RGBLED_NUM] = {
    { 10, 10, 10 },
    { 10, 10, 10 },
    { 10, 10, 10 },
    { 10, 10, 10 },
    { 10, 10, 10 },
    { 10, 10, 10 }
};

static void _update_leds(LED_TYPE *ledarray) {
    ws2812_setleds(ledarray, RGBLED_NUM);
}

static void _led_update_rgb(void) {
    leds[caps_lock_led_index] = led_state.caps_lock ? indicator : white;
    leds[num_lock_led_index] = led_state.num_lock ? indicator : white;
    
    for (uint8_t i = 0; i < sizeof(base_led_indices); i++) {
        uint8_t led_index = base_led_indices[i];
        leds[led_index] = white;
    }

    _update_leds(leds);
}

static void _set_base_led_indices(void) {
    uint8_t index = 0;

    for (uint8_t i = index; i < RGBLED_NUM; i++) {
        if (i == caps_lock_led_index || i == num_lock_led_index) {
            continue;
        }

        base_led_indices[index++] = i;
    }
}

void leds_on() {

}

void leds_off() {

}

void speed_up_breathing() {

}

void speed_down_breathing() {

}

void led_breathing_on() {
    breathing_state = true;
}

void led_breathing_off() {
    breathing_state = false;
}

void keyboard_pre_init_kb(void) {
    _set_base_led_indices();
    _led_update_rgb();

    keyboard_pre_init_user();
}

bool led_update_kb(led_t state) {
    led_state = state;
    _led_update_rgb();
    
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    layer = get_highest_layer(state);
    _led_update_rgb();

    return state;
}
 
