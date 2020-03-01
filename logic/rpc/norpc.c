#include <stdio.h>
#include <string.h>
#include "../logic.h"
#include "norpc.h"

#define MOVES_BUFFER_SIZE 16

void norpc_board_update(color_t turn, state_t state, char board[64], void *context);

void norpc_init(void) {
    puts("Running without RPC!");
    void *tmp;
    add_listener(norpc_board_update, NULL, &tmp);
    char command[64];
    char line[256];
    int args[4];
    while (1) {
        printf("> ");
        scanf("%*[\n]%[^\n]", line);
        int parsed = sscanf(line, "%s %d %d %d %d", command, args, args + 1, args + 2, args + 3);
        if (!strcmp(command, "reset_board")) {
            if (parsed == 1) {
                reset_board();
            } else {
                puts("Error: reset_board takes no arguments.");
            }
        } else if (!strcmp(command, "get_moves")) {
            if (parsed == 3) {
                coordinate_t tos[MOVES_BUFFER_SIZE];
                coordinate_t from = {
                    .x = args[0],
                    .y = args[1]
                };
                int count = get_moves(from, tos, MOVES_BUFFER_SIZE);
                for (int i = 0; i < count; ++i) {
                    printf("Valid move: (%d, %d) -> (%d, %d)\n", args[0], args[1], tos[i].x, tos[i].y);
                }
            } else {
                puts("Error: get_moves takes two arguments.");
            }
        } else if (!strcmp(command, "move")) {
            if (parsed == 5) {
                coordinate_t from = {
                    .x = args[0],
                    .y = args[1]
                };
                coordinate_t to = {
                    .x = args[2],
                    .y = args[3]
                };
                move_error_t err = move(from, to);
                static const char *move_errors[] = {
                    "me_none",
                    "me_not_valid",
                    "me_in_check"
                };
                const char *err_str;
                if (err >= 0 && err < 3) {
                    err_str = move_errors[err];
                } else {
                    err_str = "unknown";
                }
                printf("move: %s\n", err_str);
            } else {
                puts("Error: move takes four arguments.");
            }
        } else if (!strcmp(command, "restore")) {
            if (parsed == 2) {
                restore_error_t err = restore((piece_type_t) args[0]);
                static const char *restore_errors[] = {
                    "re_none",
                    "re_none_gone",
                    "re_invalid_state"
                };
                const char *err_str;
                if (err >= 0 && err < 3) {
                    err_str = restore_errors[err];
                } else {
                    err_str = "unknown";
                }
                printf("restore: %s\n", err_str);
            } else {
                puts("Error: restore takes one argument.");
            }
        } else if (!strcmp(command, "help")) {
            if (parsed == 1) {
                puts("Commands:\n"
                     "reset_board\n"
                     "get_moves [x] [y]\n"
                     "move [from_x] [from_y] [to_x] [to_y]\n"
                     "restore [piece]\n"
                     "help\n"
                     "exit");
            } else {
                puts("Error: help takes no arguments.");
            }
        } else if (!strcmp(command, "exit")) {
            if (parsed == 1) {
                return;
            } else {
                puts("Error: exit takes no arguments.");
            }
        } else {
            printf("Unknown command '%s'.  Try help for a list of commands.\n", command);
        }
    }
}

void norpc_board_update(color_t turn, state_t state, char board[64], void *context) {
    static const char *colors[] = {
        "cr_none",
        "cr_white",
        "cr_purple"
    };
    static const char *states[] = {
        "st_unknown",
        "st_turn",
        "unknown",
        "st_won",
        "unknown",
        "st_restore"
    };
    const char *turn_str;
    if (turn >= 0 && turn < 3) {
        turn_str = colors[turn];
    } else {
        turn_str = "unknown";
    }
    const char *state_str;
    if (state >= 0 && state < 5) {
        state_str = states[state];
    } else {
        state_str = "unknown";
    }
    printf("Board update (turn = %s, state = %s):\n", turn_str, state_str);
    int valid = 1;
    for (int i = 0; i < 64; ++i) {
        if (board[i] < ' ' || board[i] > '~') {
            valid = 0;
            break;
        }
    }
    if (valid) {
        char buf[9];
        buf[8] = 0;
        for (int i = 0; i < 8; ++i) {
            memcpy(buf, board + i * 8, 8);
            printf("%s\n", buf);
        }
    } else {
        puts("(Invalid board string)");
    }
}
