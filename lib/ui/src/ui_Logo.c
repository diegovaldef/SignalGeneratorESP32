// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.11
// Project name: SignalGenEsp32

#include "ui.h"

void ui_Logo_screen_init(void)
{
    ui_Logo = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Logo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_Logo, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Logo, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_event_cb(ui_Logo, scr_unloaded_delete_cb, LV_EVENT_SCREEN_UNLOADED, &ui_Logo);

    ui_Image2 = lv_img_create(ui_Logo);
    lv_img_set_src(ui_Image2, &ui_img_423428936);
    lv_obj_set_width(ui_Image2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image2, 4);
    lv_obj_set_y(ui_Image2, -21);
    lv_obj_set_align(ui_Image2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_Image2, 150);

    lv_obj_add_event_cb(ui_Logo, ui_event_Logo, LV_EVENT_ALL, NULL);

}
