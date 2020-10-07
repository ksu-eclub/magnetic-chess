#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <magchess/logic/logic.h>
#include <magchess/ui/mock.h>

static void ui_input_draw(void);
static void ui_input_run(void);

ui_component_t ui_input = {
    .draw = ui_input_draw,
    .run = ui_input_run
};

static coordinate_t selected = {
    .x = -1
};

static void ui_input_draw(void) {
    fprintf(frealout, "\033[%d;%dH>", ui_input.y, ui_input.x);
}

static void ui_input_run(void) {
    fprintf(frealout, "\033[%d;%dH", ui_input.y, ui_input.x + 2);
    fflush(frealout);
    char buffer[256];
    scanf("%*[\n]");
    scanf("%s", buffer);
    char col;
    int row;
    if (!strcmp(buffer, "help")) {
        printf("UI: Known commands:\n");
        printf("  - help\n");
        printf("  - move <COL> <ROW>\n");
        printf("  - quit\n");
        printf("  - reset\n");
        printf("  - restore <PIECE>\n");
        printf("  - select <COL> <ROW>\n");
    } else if (!strcmp(buffer, "move")) {
        if (scanf(" %c %d", &col, &row) == 2) {
            if (col >= 'a' && col <= 'h') {
                col += 'A' - 'a';
            }
            if (col < 'A' || col > 'H' || row < 1 || row > 8) {
                printf("UI: Usage: move <COL> <ROW>\n");
            } else if (selected.x < 0 || selected.y < 0) {
                printf("UI: Please run select before move\n");
            } else {
                coordinate_t to;
                to.x = col - 'A';
                to.y = row - 1;
                switch (move(selected, to)) {
                    case me_none:
                        break;
                    case me_not_valid:
                        printf("UI: Unable to move: not valid.\n");
                        break;
                    case me_in_check:
                        printf("UI: Unable to move: in check.\n");
                        break;
                    default:
                        printf("UI: Unable to move: unknown error.\n");
                        break;
                }
            }
        } else {
            printf("UI: Usage: move <COL> <ROW>\n");
        }
    } else if (!strcmp(buffer, "quit")) {
        raise(SIGINT);
    } else if (!strcmp(buffer, "reset")) {
        reset_board();
        printf("Board reset.\n");
    } else if (!strcmp(buffer, "restore")) {
        scanf(" %s", buffer);
        piece_type_t piece;
        if (!strcmp(buffer, "rook")) {
            piece = pc_rook;
        } else if (!strcmp(buffer, "knight")) {
            piece = pc_knight;
        } else if (!strcmp(buffer, "bishop")) {
            piece = pc_bishop;
        } else if (!strcmp(buffer, "queen")) {
            piece = pc_queen;
        } else if (!strcmp(buffer, "pawn")) {
            piece = pc_pawn;
        } else if (!strcmp(buffer, "king")) {
            piece = pc_king;
        } else {
            printf("UI: Unknown piece '%s'.  Expected rook, knight, bishop, queen, pawn, or king.\n", buffer);
            piece = -1;
        }
        if (piece >= 0) {
            switch (restore(piece)) {
                case re_none:
                    break;
                case re_none_gone:
                    printf("UI: Unable to restore: no pieces gone.\n");
                    break;
                case re_invalid_state:
                    printf("UI: Unable to restore: invalid state.\n");
                    break;
                default:
                    printf("UI: Unable to restore: unknown error.\n");
                    break;
            }
        }
    } else if (!strcmp(buffer, "select")) {
        if (scanf(" %c %d", &col, &row) == 2) {
            if (col >= 'a' && col <= 'h') {
                col += 'A' - 'a';
            }
            if (col < 'A' || col > 'H' || row < 1 || row > 8) {
                printf("UI: Usage: select <COL> <ROW>\n");
            } else {
                selected.x = col - 'A';
                selected.y = row - 1;
                get_moves(selected, NULL, 0);
            }
        } else {
            printf("UI: Usage: move <COL> <ROW>\n");
        }
    } else {
        printf("UI: Unknown command '%s'\n", buffer);
    }
    scanf("%*[^\n]");
}
