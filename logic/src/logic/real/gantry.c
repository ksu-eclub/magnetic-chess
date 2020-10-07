#include <stddef.h>
#include <magchess/hardware/magnet.h>
#include <magchess/hardware/steppers.h>
#include <magchess/logic/logic.h>
#include <magchess/logic/gantry.h>

static void gantry_update(color_t turn, state_t state, char board[64], void *context);

void gantry_init(void) {
    void *tmp;
    add_listener(gantry_update, NULL, &tmp);
}

static void gantry_update(color_t turn, state_t state, char board[64], void *context) {
    // TODO
}
