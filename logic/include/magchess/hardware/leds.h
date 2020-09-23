#ifndef MAGCHESS_HARDWARE_LEDS_H
#define MAGCHESS_HARDWARE_LEDS_H

typedef enum {
    led_off,
    led_white,
    led_red,
    led_pink
} led_color_t;

void hw_leds_init(void);
void hw_leds_set_pattern(led_color_t leds[64]);

#endif
