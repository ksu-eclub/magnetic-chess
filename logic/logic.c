#include <stdio.h>
#include "logic.h"

board_t board;

void reset_board(void) {
    puts("reset_board");
    // TODO
}

int get_moves(coordinate_t from, coordinate_t *tos, int tos_count) {
    puts("get_moves");
    int count = 0;
    // TODO
    if (count + 1 < tos_count) {
        tos[count].x = 0;
        tos[count].y = 0;
        ++count;
    }
    if (count + 1 < tos_count) {
        tos[count].x = 4;
        tos[count].y = 7;
        ++count;
    }
    return count;
}

move_error_t move(coordinate_t from, coordinate_t to) {
    puts("move");
    // TODO
    return me_none;
}

restore_error_t restore(piece_type_t type) {
    puts("restore");
    // TODO
    return re_none;
}
