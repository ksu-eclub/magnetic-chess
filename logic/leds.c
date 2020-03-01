#include <stddef.h>
#include "hardware/leds.h"
#include "logic.h"
#include "leds.h"

void leds_update(color_t turn, state_t state, coordinate_t coord, void *context);

void leds_init(void) {
    void *tmp;
    add_selection_listener(leds_update, NULL, &tmp);
}

void leds_update(color_t turn, state_t state, coordinate_t coord, void *context) {
    // TODO
}
