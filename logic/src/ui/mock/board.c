#include <stdio.h>
#include <string.h>
#include <magchess/logic/logic.h>
#include <magchess/ui/mock.h>

#define MAX_MOVES 32

static void ui_board_init(void);
static void ui_board_draw(void);
static void ui_board_board_change(color_t turn, state_t state, char board[64], void *context);
static void ui_board_selection_change(color_t turn, state_t state, coordinate_t coord, void *context);

ui_component_t ui_board = {
    .init = ui_board_init,
    .draw = ui_board_draw,
    .width = 35,
    .height = 18
};

static char board[64];
static coordinate_t selected = {
    .x = -1
};
static coordinate_t moves[MAX_MOVES];
static int num_moves = 0;

static void ui_board_init(void) {
    void *tmp;
    add_listener(ui_board_board_change, NULL, &tmp);
    add_selection_listener(ui_board_selection_change, NULL, &tmp);
}

static void ui_board_draw(void) {
    int xmin = ui_board.x;
    int xmax = ui_board.x + ui_board.width - 3;
    int ymin = ui_board.y;
    int ymax = ui_board.y + ui_board.height - 2;
    for (int y = ymin; y <= ymax; ++y) {
        fprintf(frealout, "\033[%d;%dH", y, xmin);
        for (int x = xmin; x <= xmax; ++x) {
            if (y == ymin) {
                if (x == xmin) {
                    fprintf(frealout, "\u250F");
                } else if (x == xmax) {
                    fprintf(frealout, "\u2513");
                } else if ((x - xmin) % 4 == 0) {
                    fprintf(frealout, "\u2533");
                } else {
                    fprintf(frealout, "\u2501");
                }
            } else if (y == ymax) {
                if (x == xmin) {
                    fprintf(frealout, "\u2517");
                } else if (x == xmax) {
                    fprintf(frealout, "\u251B");
                } else if ((x - xmin) % 4 == 0) {
                    fprintf(frealout, "\u253B");
                } else {
                    fprintf(frealout, "\u2501");
                }
            } else if ((y - ymin) % 2 == 0) {
                if (x == xmin) {
                    fprintf(frealout, "\u2523");
                } else if (x == xmax) {
                    fprintf(frealout, "\u252B");
                } else if ((x - xmin) % 4 == 0) {
                    fprintf(frealout, "\u254B");
                } else {
                    fprintf(frealout, "\u2501");
                }
            } else {
                int cx = (x - xmin) / 4;
                int cy = 7 - ((y - ymin) / 2);
                char b;
                switch ((x - xmin) % 4) {
                    case 0:
                        fprintf(frealout, "\u2503");
                        break;
                    case 1:
                        if (selected.x == cx && selected.y == cy) {
                            fprintf(frealout, "\033[32m>\033[0m");
                        } else {
                            int found = 0;
                            for (int i = 0; i < num_moves; ++i) {
                                if (moves[i].x == cx && moves[i].y == cy) {
                                    fprintf(frealout, "\033[32m<\033[0m");
                                    found = 1;
                                    break;
                                }
                            }
                            if (!found) {
                                fprintf(frealout, " ");
                            }
                        }
                        break;
                    case 2:
                        b = board[8 * cy + cx];
                        switch (b) {
                            case '_':
                                fprintf(frealout, " ");
                                break;
                            case 'p':
                            case 'r':
                            case 'n':
                            case 'b':
                            case 'k':
                            case 'q':
                                fprintf(frealout, "\033[34m%c\033[0m", b + 'A' - 'a');
                                break;
                            case 'P':
                            case 'R':
                            case 'N':
                            case 'B':
                            case 'K':
                            case 'Q':
                                fprintf(frealout, "\033[37m%c\033[0m", b);
                                break;
                            default:
                                fprintf(frealout, "\033[31m?\033[0m");
                                break;
                        }
                        break;
                    case 3:
                        if (selected.x == cx && selected.y == cy) {
                            fprintf(frealout, "\033[32m<\033[0m");
                        } else {
                            int found = 0;
                            for (int i = 0; i < num_moves; ++i) {
                                if (moves[i].x == cx && moves[i].y == cy) {
                                    fprintf(frealout, "\033[32m>\033[0m");
                                    found = 1;
                                    break;
                                }
                            }
                            if (!found) {
                                fprintf(frealout, " ");
                            }
                        }
                        break;
                }
            }
        }
        if ((y - ymin) % 2 == 1) {
            fprintf(frealout, " %d", 8 - ((y - ymin) / 2));
        }
    }
    fprintf(frealout, "\033[%d;%dH", ymax + 1, xmin);
    for (int x = xmin; x < xmax; ++x) {
        if ((x - xmin) % 4 == 2) {
            fprintf(frealout, "%c", 'A' + ((x - xmin) / 4));
        } else {
            fprintf(frealout, " ");
        }
    }
}

static void ui_board_board_change(color_t turn, state_t state, char _board[64], void *context) {
    memcpy(board, _board, 64);
}

static void ui_board_selection_change(color_t turn, state_t state, coordinate_t coord, void *context) {
    if (coord.x != selected.x || coord.y != selected.y) {
        num_moves = get_moves(coord, moves, MAX_MOVES);
    }
}
