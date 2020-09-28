#include <stdio.h>
#include <magchess/ui/mock.h>

static void ui_title_draw(void);

ui_component_t ui_title = {
    .draw = ui_title_draw
};

static void ui_title_draw(void) {
    static const char title[] = "Magnetic Chess Mock UI";
    fprintf(frealout, "\033[%d;%dH%s", ui_title.y, ui_title.x + (ui_title.width - sizeof(title) + 1) / 2, title);
}
