#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <magchess/ui/ui.h>
#include <magchess/ui/mock.h>

static inline void call(void (*func)(void));
static void signal_handler(int sig);

void ui_init(void) {
    struct termios orig_termios;
    if (tcgetattr(STDIN_FILENO, &orig_termios) < 0) {
        perror("ui_init: tcgetattr");
        exit(1);
    }
    struct termios new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    if (tcsetattr(STDIN_FILENO, TCSANOW, &new_termios) < 0) {
        perror("ui_init: tcsetattr");
        exit(1);
    }
    printf("\033[1000000;1000000H\033[6n;");
    fflush(stdout);
    int screen_width;
    int screen_height;
    scanf("%*[^\033]");
    scanf("\033[%d;%dR", &screen_height, &screen_width);
    if (tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios) < 0) {
        perror("ui_init: tcsetattr(visible_termios)");
        exit(1);
    }
    for (int i = 1; i < screen_height; ++i) {
        printf("\n");
    }
    fflush(stdout);

    ui_title.x = 1;
    ui_title.y = 1;
    ui_title.width = ui_board.width;
    ui_title.height = 1;

    ui_board.x = 1;
    ui_board.y = ui_title.y + ui_title.height + 1;

    ui_status.x = 1;
    ui_status.y = ui_board.y + ui_board.height + 1;
    ui_status.width = ui_board.width;
    ui_status.height = screen_height - ui_board.y - ui_board.height - 3;

    ui_input.x = 1;
    ui_input.y = screen_height - 1;
    ui_input.width = ui_board.width;
    ui_input.height = 1;

    ui_log.x = ui_title.x + ui_title.width + 1;
    ui_log.y = 1;
    ui_log.width = screen_width - ui_log.x + 1;
    ui_log.height = screen_height;

    call(ui_title.init);
    call(ui_board.init);
    call(ui_status.init);
    call(ui_input.init);
    call(ui_log.init);

    signal(SIGINT, signal_handler);
}

void ui_run(void) {
    while (1) {
        call(ui_log.draw);
        call(ui_title.draw);
        call(ui_board.draw);
        call(ui_status.draw);
        call(ui_input.draw);
        fflush(frealout);

        call(ui_title.run);
        call(ui_board.run);
        call(ui_status.run);
        call(ui_input.run);
        call(ui_log.run);
    }
}

static inline void call(void (*func)(void)) {
    if (func) {
        func();
    }
}

static void signal_handler(int sig) {
    call(ui_log.draw);
    call(ui_title.draw);
    call(ui_board.draw);
    call(ui_status.draw);
    call(ui_input.draw);

    call(ui_title.cleanup);
    call(ui_board.cleanup);
    call(ui_status.cleanup);
    call(ui_input.cleanup);
    call(ui_log.cleanup);

    exit(0);
}
