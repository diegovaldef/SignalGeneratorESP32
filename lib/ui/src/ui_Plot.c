// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: SignalGenEsp32

#include "ui.h"

void ui_Plot_screen_init(void)
{
    ui_Plot = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Plot, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_Plot, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Plot, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    ui_Container4 = lv_obj_create(ui_Plot);
    lv_obj_remove_style_all(ui_Container4);
    lv_obj_set_width(ui_Container4, lv_pct(100));
    lv_obj_set_height(ui_Container4, lv_pct(100));
    lv_obj_set_align(ui_Container4, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container4, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container4, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_Container4, LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_SCROLL_WITH_ARROW |
                    LV_OBJ_FLAG_SCROLL_ONE);     /// Flags
    lv_obj_clear_flag(ui_Container4, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    ui_Chart1 = lv_chart_create(ui_Container4);
    lv_obj_set_width(ui_Chart1, lv_pct(80));
    lv_obj_set_height(ui_Chart1, lv_pct(80));
    lv_obj_set_x(ui_Chart1, -21);
    lv_obj_set_y(ui_Chart1, -75);
    lv_obj_set_align(ui_Chart1, LV_ALIGN_CENTER);
    lv_chart_set_type(ui_Chart1, LV_CHART_TYPE_LINE);
    lv_chart_set_axis_tick(ui_Chart1, LV_CHART_AXIS_PRIMARY_X, 10, 5, 5, 2, true, 50);
    lv_chart_set_axis_tick(ui_Chart1, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 5, 2, true, 50);
    lv_chart_set_axis_tick(ui_Chart1, LV_CHART_AXIS_SECONDARY_Y, 10, 5, 5, 2, false, 25);
    lv_chart_series_t * ui_Chart1_series_1 = lv_chart_add_series(ui_Chart1, lv_color_hex(0x808080),
                                                                 LV_CHART_AXIS_PRIMARY_Y);
    static lv_coord_t ui_Chart1_series_1_array[] = { 0, 10, 20, 40, 80, 80, 40, 20, 10, 0 };
    lv_chart_set_ext_y_array(ui_Chart1, ui_Chart1_series_1, ui_Chart1_series_1_array);





}
