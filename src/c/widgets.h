#pragma once

#include <pebble.h>

// Maximum length of any widget text string (including null terminator)
#define WIDGET_TEXT_LEN 48

// ---------------------------------------------------------------------------
// widget_get_text
// Parses `format_string` and replaces template tokens like {date}, {steps},
// {dist}, and {batt} with actual values. Writes into `buf`.
// ---------------------------------------------------------------------------
void widget_get_text(const char *format_string, char *buf, int buf_len);

void widget_set_phone_battery_level(int level);
int widget_get_phone_battery_level(void);
bool widgets_contain_token(const char *token);
