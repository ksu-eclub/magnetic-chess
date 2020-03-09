#include "logic.h"

// TODO Define a list of {board_listener_t, context}

void on_change(color_t turn, state_t state, char board[64]) {
    // TODO For each listener in the list, call it.
    //      The first three arguments to the listener are the three arguments to this function (turn, state, board)
    //      The last argument to the listener is it's {context}
}

void add_listener(board_listener_t listener, void *context, void **ref) {
    // TODO Add {listener, context} to the list and set {*ref} to the node in the list that was just added
}

void remove_listener(void *ref) {
    // TODO Remove the node {ref} from the list
}

/* These are the same as above, but with different variables */

void on_selection(color_t turn, state_t state, coordinate_t coord) {
    // TODO
}

void add_selection_listener(selection_listener_t listener, void *context, void **ref) {
    // TODO
}

void remove_selection_listener(void *ref) {
    // TODO
}
