#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <magchess/ui/mock.h>

static void ui_log_init(void);
static void ui_log_draw(void);
static void ui_log_cleanup(void);
static void *output_thread(void *ctx);
static void error(const char *str);

ui_component_t ui_log = {
    .init = ui_log_init,
    .draw = ui_log_draw,
    .cleanup = ui_log_cleanup
};

FILE *frealout = NULL;
static int realout;
static int pipes[2];
static pthread_t thread;
static pthread_mutex_t mutex;
static pthread_cond_t cond;
static char buffer[4096];
static int buffer_used = 0;
static int nonce;

static void ui_log_init(void) {
    frealout = stderr;
    if ((realout = dup(STDOUT_FILENO)) < 0) {
        error("ui_log_init: dup(STDOUT)");
    }
    frealout = fdopen(realout, "w");
    if (pipe(pipes) < 0) {
        error("ui_log_init: pipe");
    }
    if (dup2(pipes[1], STDOUT_FILENO) < 0) {
        error("ui_log_init: dup2(STDOUT)");
    }
    if (dup2(pipes[1], STDERR_FILENO) < 0) {
        error("ui_log_init: dup2(STDERR)");
    }
    if (pthread_create(&thread, NULL, output_thread, NULL) < 0) {
        error("ui_log_init: pthread_create");
    }
}

static void ui_log_draw(void) {
    if (pthread_mutex_lock(&mutex) < 0) {
        error("ui_log_draw: pthread_mutex_lock");
    }
    int nonce_copy = nonce;
    if (write(pipes[1], "\x01", 1) < 0) {
        error("ui_run: write");
    }
    while (nonce == nonce_copy) {
        if (pthread_cond_wait(&cond, &mutex) < 0) {
            error("ui_log_init: pthread_cond_wait");
        }
    }
    for (char *line = buffer, *end = buffer + buffer_used; line < end; ) {
        char *it;
        for (it = line; it < end && *it != '\n' && it < line + ui_log.width - 2; ++it);
        fprintf(frealout, "\033[1;%dH\033[1K\033[1000000;1H\n\033[%d;%dH", ui_log.x, ui_log.y + ui_log.height - 1, ui_log.x + 2);
        fwrite(line, 1, it - line, frealout);
        if (*it == '\n') {
            line = it + 1;
        } else {
            line = it;
        }
    }
    buffer_used = 0;
    if (pthread_mutex_unlock(&mutex) < 0) {
        error("ui_log_draw: pthread_mutex_unlock");
    }
    for (int y = ui_log.y; y < ui_log.y + ui_log.height; ++y) {
        fprintf(frealout, "\033[%d;%dH\033[1K\u2503", y, ui_log.x);
    }
}

static void ui_log_cleanup(void) {
    fflush(stderr);
    fflush(stdout);
    if (write(pipes[1], "\x02", 1) < 0) {
        error("ui_run: write");
    }
    if (pthread_join(thread, NULL) < 0) {
        error("ui_run: pthread_join");
    }
    fprintf(frealout, "\033[1000000;1H\n");
    fflush(frealout);
}

static void *output_thread(void *ctx) {
    char lcl_buffer[sizeof(buffer)];
    int run = 1;
    while (run) {
        int n = read(pipes[0], lcl_buffer, sizeof(lcl_buffer));
        if (n < 0) {
            error("output_thread: read");
        }
        if (pthread_mutex_lock(&mutex) < 0) {
            error("output_thread: pthread_mutex_lock");
        }
        for (int i = 0; i < n; ++i) {
            switch (lcl_buffer[i]) {
                case '\x01':
                    ++nonce;
                    pthread_cond_broadcast(&cond);
                    break;
                case '\x02':
                    run = 0;
                    break;
                default:
                    buffer[buffer_used++] = lcl_buffer[i];
                    break;
            }
        }
        if (pthread_mutex_unlock(&mutex) < 0) {
            error("output_thread: pthread_mutex_unlock");
        }
    }
    return NULL;
}

static void error(const char *str) {
    fprintf(frealout, "%s: %s\n", str, strerror(errno));
    fflush(frealout);
    exit(1);
}
