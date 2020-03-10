#ifndef LOGIC_H
#define LOGIC_H
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int x;
    int y;
} coordinate_t;

typedef enum {
    cr_none = 0,
    cr_white = 1,
    cr_purple = 2
} color_t;

typedef enum {
    pc_rook = 0,
    pc_knight = 1,
    pc_bishop = 2,
    pc_queen = 3,
    pc_pawn = 4,
    pc_king = 5
} piece_type_t;

typedef struct {
    color_t color;
    piece_type_t piece;
    int num_moves;
} piece_t;

typedef enum {
    st_unknown = 0,
    st_turn = 1,
    st_won = 3,
    st_restore = 5
} state_t;

typedef struct {
    piece_t pieces[8][8];
    color_t turn;
    state_t state;
} board_t;

typedef enum {
    me_none = 0,
    me_not_valid = 1,
    me_in_check = 2
} move_error_t;

typedef enum {
    re_none = 0,
    re_none_gone = 1,
    re_invalid_state = 2
} restore_error_t;

typedef void (*board_listener_t)(color_t turn, state_t state, char board[64], void *context);
typedef void (*selection_listener_t)(color_t turn, state_t state, coordinate_t coord, void *context);

void reset_board(void);
int get_moves(coordinate_t from, coordinate_t *tos, int tos_count);
move_error_t move(coordinate_t from, coordinate_t to);
restore_error_t restore(piece_type_t type);
void on_change(color_t turn, state_t state, char board[64]);
void add_listener(board_listener_t listener, void *context, void **ref);
void remove_listener(void *ref);
void on_selection(color_t turn, state_t state, coordinate_t coord);
void add_selection_listener(selection_listener_t listener, void *context, void **ref);
void remove_selection_listener(void *ref);

#ifdef __cplusplus
}
#endif
#endif
