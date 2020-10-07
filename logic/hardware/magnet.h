#ifndef HARDWARE_MAGNET_H
#define HARDWARE_MAGNET_H

typedef enum {
    ms_off,
    ms_low_power,
    ms_high_power
} magnet_state_t;

void hw_magnet_init(void);
void hw_magnet_set_state(magnet_state_t state);

#endif
