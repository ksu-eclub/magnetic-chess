#include <stdio.h>
#include <stdlib.h>
#include "hardware/leds.h"
#include "hardware/magnet.h"
#include "hardware/steppers.h"
#include "gantry.h"
#include "leds.h"
#include "rpc/rpc.h"

int main(int argc, const char **argv) {
    hw_leds_init();
    hw_magnet_init();
    hw_steppers_init();
    gantry_init();
    leds_init();
    rpc_init();
    return EXIT_SUCCESS;
}
