#include "logic.h"
#include <stdlib.h>

// TODO Define a list of {board_listener_t, context}

struct _other_board_t;
typedef struct _other_board_t other_board_t;
struct _other_board_t {
    board_listener_t listener;
    void *context;
    other_board_t *next;
};

struct _select_board_t;
typedef struct _select_board_t select_board_t;
struct _select_board_t {
    selection_listener_t listener;
    void *context;
    select_board_t *next;
};

other_board_t *limbo;
select_board_t *limbo2;

void on_change(color_t turn, state_t state, char board[64]) {
    // TODO For each listener in the list, call it.
    //      The first three arguments to the listener are the three arguments to this function (turn, state, board)
    //      The last argument to the listener is it's {context}
    for(other_board_t *it = limbo; it; it = it->next) {
        it->listener(turn,state,board, it->context);
    }
}

void add_listener(board_listener_t listener, void *context, void **ref) {
    // TODO Add {listener, context} to the list and set {*ref} to the node in the list that was just added
    other_board_t *temp = (other_board_t *)malloc(sizeof(other_board_t));
    temp->listener = listener;
    temp->context = context;
    temp->next = limbo;
    limbo = temp;
    *ref = temp;
}

void remove_listener(void *ref) {
    // TODO Remove the node {ref} from the list
    other_board_t *remove = (other_board_t *)ref;
    for(other_board_t *it = limbo; it; it = it->next) {
        if(it->next == remove) {
            it->next = remove->next;
            free(remove);
            break;
        }
    }
    if(remove == limbo) {
        limbo = remove->next;
        free(remove);
    }
}

/* These are the same as above, but with different variables */

void on_selection(color_t turn, state_t state, coordinate_t coord) {
    // TODO
    for(select_board_t *it = limbo2; it; it = it->next) {
        it->listener(turn,state,coord, it->context);
    }
}

void add_selection_listener(selection_listener_t listener, void *context, void **ref) {
    // TODO
    select_board_t *temp = (select_board_t *)malloc(sizeof(select_board_t));
    temp->listener = listener;
    temp->context = context;
    temp->next = limbo2;
    limbo2 = temp;
    *ref = temp;
}

void remove_selection_listener(void *ref) {
    // TODO
    select_board_t *remove = (select_board_t *)ref;
    for(select_board_t *it = limbo2; it; it = it->next) {
        if(it->next == remove) {
            it->next = remove->next;
            free(remove);
            break;
        }
    }
    if(remove == limbo2) {
        limbo2 = remove->next;
        free(remove);
    }
}
