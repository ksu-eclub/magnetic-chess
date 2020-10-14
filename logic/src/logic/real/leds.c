#include <stddef.h>
#include <magchess/hardware/leds.h>
#include <magchess/logic/logic.h>
#include <magchess/logic/leds.h>

static void leds_update(color_t turn, state_t state, coordinate_t coord, void *context);

void leds_init(void) {
    void *tmp;
    add_selection_listener(leds_update, NULL, &tmp);
}

static void leds_update(color_t turn, state_t state, coordinate_t coord, void *context) {
    // TODO
}
