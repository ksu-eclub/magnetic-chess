#include <stddef.h>
#include "hardware/magnet.h"
#include "hardware/steppers.h"
#include "logic.h"
#include "gantry.h"

void gantry_update(color_t turn, state_t state, char board[64], void *context);

void gantry_init(void) {
    void *tmp;
    add_listener(gantry_update, NULL, &tmp);
}

void gantry_update(color_t turn, state_t state, char board[64], void *context) {
    // TODO
}
