#include "utils.h"
#include "drawUtils.h"
#include <pebble.h>

void to_uppercase(char *str) {
  while (*str) {
    *str = toupper((unsigned char)*str);
    str++;
  }
}

struct tm *getCurrentTime() {
  time_t rawTime = time(NULL);
  return localtime(&rawTime);
}

void draw_bt_disconnect_indicator(GContext *ctx, GRect bounds) {
  int cx = bounds.origin.x + bounds.size.w / 2;
  int cy = bounds.origin.y + RING_THICKNESS / 2;

#if defined(PBL_PLATFORM_EMERY) || defined(PBL_PLATFORM_GABBRO)
  int s = 16;
  int r = 4;
  int stem_h = 5;
  int w_r = 4;
  int w_l = 3;
  int d_y = 3;
  int slash_d = 5;
#else
  int s = 14;
  int r = 3;
  int stem_h = 4;
  int w_r = 3;
  int w_l = 2;
  int d_y = 2;
  int slash_d = 4;
#endif

  GRect badge_rect = GRect(cx - s / 2, cy - s / 2, s, s);

  // Black outline (outer squircle)
  graphics_context_set_fill_color(ctx, GColorBlack);
  graphics_fill_rect(ctx, badge_rect, r, GCornersAll);

  // White inner squircle (1px inset)
  GRect inner_rect = grect_inset(badge_rect, GEdgeInsets(1));
  graphics_context_set_fill_color(ctx, GColorWhite);
  graphics_fill_rect(ctx, inner_rect, r > 1 ? r - 1 : 1, GCornersAll);

  // Stylized 'B' Bluetooth icon in black
  graphics_context_set_stroke_color(ctx, GColorBlack);
  graphics_context_set_stroke_width(ctx, 1);

  // Vertical stem
  graphics_draw_line(ctx, GPoint(cx, cy - stem_h), GPoint(cx, cy + stem_h));

  // Upper diagonal and return
  graphics_draw_line(ctx, GPoint(cx - w_l, cy + d_y), GPoint(cx + w_r, cy - d_y));
  graphics_draw_line(ctx, GPoint(cx + w_r, cy - d_y), GPoint(cx, cy - stem_h));

  // Lower diagonal and return
  graphics_draw_line(ctx, GPoint(cx - w_l, cy - d_y), GPoint(cx + w_r, cy + d_y));
  graphics_draw_line(ctx, GPoint(cx + w_r, cy + d_y), GPoint(cx, cy + stem_h));

  // Red diagonal strike-through
  graphics_context_set_stroke_color(ctx, COLOR_FALLBACK(GColorRed, GColorBlack));
  graphics_context_set_stroke_width(ctx, 1);
  graphics_draw_line(ctx, GPoint(cx - slash_d, cy - slash_d),
                          GPoint(cx + slash_d, cy + slash_d));
#if defined(PBL_COLOR)
  graphics_draw_line(ctx, GPoint(cx - slash_d + 1, cy - slash_d),
                          GPoint(cx + slash_d, cy + slash_d - 1));
#endif
}
