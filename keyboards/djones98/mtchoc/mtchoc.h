#pragma once
#include "qp.h"

extern painter_device_t      mtchoc_display;
extern painter_font_handle_t roboto_font;

enum layers { _QWERTY = 0, _MEDIA = 1, _NAV = 2, _MOUSE = 3 };

void display_task_kb(void);
