#include "logic.h"

/*
 * This file implements two isolated listeners.  on_change and on_selection are very similar, as are add_listener and
 * add_selection_listener and remote_listener and remove_selection_listener.  When on_change is called, it will call all
 * the functions given to the add_listener function with the arguments given to the on_change method (turn, state, and
 * board), in addition to the context variable given to that specific call to add_listener.  Inside add_listener, it
 * also sets *ref with some value so that if that value is give to remove_listener, following calls to on_change will no
 * longer call that function.
 */

void on_change(color_t turn, state_t state, char board[64]) {
    // TODO
}

void add_listener(board_listener_t listener, void *context, void **ref) {
    // TODO
}

void remove_listener(void *ref) {
    // TODO
}

void on_selection(color_t turn, state_t state, coordinate_t coord) {
    // TODO
}

void add_selection_listener(selection_listener_t listener, void *context, void **ref) {
    // TODO
}

void remove_selection_listener(void *ref) {
    // TODO
}
