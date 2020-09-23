#include <stdio.h>
#include <stdlib.h>
#include <magchess/hardware/leds.h>
#include <magchess/hardware/magnet.h>
#include <magchess/hardware/steppers.h>
#include <magchess/logic/gantry.h>
#include <magchess/logic/leds.h>
#include <magchess/logic/logic.h>
#include <magchess/ui/ui.h>

int main(int argc, const char **argv) {
    hw_leds_init();
    hw_magnet_init();
    hw_steppers_init();
    gantry_init();
    leds_init();
    reset_board();
    ui_run();
    return EXIT_SUCCESS;
}
