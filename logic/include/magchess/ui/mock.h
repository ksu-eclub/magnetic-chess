#ifndef MAGCHESS_UI_MOCK_H
#define MAGCHESS_UI_MOCK_H

#include <stdio.h>

/*
 * +---------------------------------------------------------------------------+
 * |     Magnetic Chess Mock UI  | Output log (oldest)                         |
 * | +-------------------------+ | ...                                         |
 * | | Chess Board             | |                                             |
 * | |                         | |                                             |
 * | |                         | |                                             |
 * | |                         | |                                             |
 * | |                         | |                                             |
 * | +-------------------------+ |                                             |
 * | Current turn: _____         |                                             |
 * | Other status data           |                                             |
 * | ...                         |                                             |
 * |                             |                                             |
 * |                             | ...                                         |
 * | > (command input)           | Output log (most recent)                    |
 * +---------------------------------------------------------------------------+
 */

typedef struct {
    int x;
    int y;
    int width;
    int height;
    void (*init)(void);
    void (*draw)(void);
    void (*run)(void);
    void (*cleanup)(void);
} ui_component_t;

extern FILE *frealout;

extern ui_component_t ui_title;
extern ui_component_t ui_board;
extern ui_component_t ui_status;
extern ui_component_t ui_input;
extern ui_component_t ui_log;

#endif
