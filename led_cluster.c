#include "led_cluster.h"
#include "ws2812.h"

static uint8_t base_led_indices[4] = {};
static uint8_t caps_lock_led_index = 2;
static uint8_t num_lock_led_index = 3;
static cRGB led[RGBLED_NUM] = {
    {33, 33, 33},
    {33, 33, 33},
    {33, 33, 33},
    {33, 33, 33},
    {33, 33, 33},
    {33, 33, 33},
};

// Colors
static const cRGB indicator = { 0, 33, 0 };
static const cRGB white = { 33, 33, 33 };
static const cRGB off = { 0, 0, 0 };

static led_t led_state;
//static uint8_t layer;

static void _update_leds(LED_TYPE *ledarray) {
    ws2812_setleds(ledarray, RGBLED_NUM);
}

static void _led_update_rgb(void) {
    led[caps_lock_led_index] = led_state.caps_lock ? indicator : white;
    led[num_lock_led_index] = led_state.num_lock ? indicator : white;
    
    for (uint8_t i = 0; i < sizeof(base_led_indices); i++) {
        uint8_t led_index = base_led_indices[i];
        led[led_index] = white;
    }

    _update_leds(led);
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

void keyboard_pre_init_kb(void) {
    _set_base_led_indices();
    _update_leds(led);
}

bool led_update_kb(led_t state) {
    led_state = state;
    _led_update_rgb();
    
    return true;
}

