#include <stdio.h>
#include <magchess/logic/logic.h>
#include <magchess/ui/mock.h>

static void ui_status_init(void);
static void ui_status_draw(void);
static void ui_status_board_change(color_t turn, state_t state, char board[64], void *context);

ui_component_t ui_status = {
    .init = ui_status_init,
    .draw = ui_status_draw
};

static color_t turn = -1;
static state_t state = -1;

static void ui_status_init(void) {
    void *tmp;
    add_listener(ui_status_board_change, NULL, &tmp);
}

static void ui_status_draw(void) {
    fprintf(frealout, "\033[%d;%dHTurn: ", ui_status.y, ui_status.x);
    switch (turn) {
        case cr_none:
            fprintf(frealout, "\033[33mN/A\033[0m");
            break;
        case cr_white:
            fprintf(frealout, "\033[37mWhite\033[0m");
            break;
        case cr_purple:
            fprintf(frealout, "\033[34mPurple\033[0m");
            break;
        default:
            fprintf(frealout, "\033[31mUnknown\033[0m");
            break;
    }
    fprintf(frealout, "\033[%d;%dHState: ", ui_status.y + 1, ui_status.x);
    switch (state) {
        case st_unknown:
            fprintf(frealout, "\033[36mN/A\033[0m");
            break;
        case st_turn:
            fprintf(frealout, "\033[33mTurn\033[0m");
            break;
        case st_won:
            fprintf(frealout, "\033[32mWon\033[0m");
            break;
        case st_restore:
            fprintf(frealout, "\033[34mWon\033[0m");
            break;
        default:
            fprintf(frealout, "\033[31mUnknown\033[0m");
            break;
    }
}

static void ui_status_board_change(color_t _turn, state_t _state, char board[64], void *context) {
    turn = _turn;
    state = _state;
}
