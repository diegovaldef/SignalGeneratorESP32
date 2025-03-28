// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: SignalGenEsp32

#include "ui.h"

void ui_Explorador_screen_init(void)
{
    ui_Explorador = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Explorador, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Explorador, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Explorador, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container1 = lv_obj_create(ui_Explorador);
    lv_obj_remove_style_all(ui_Container1);
    lv_obj_set_width(ui_Container1, lv_pct(95));
    lv_obj_set_height(ui_Container1, lv_pct(20));
    lv_obj_set_x(ui_Container1, lv_pct(0));
    lv_obj_set_y(ui_Container1, lv_pct(5));
    lv_obj_set_align(ui_Container1, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_Container1, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_Container1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Container1, 7, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button3 = lv_btn_create(ui_Container1);
    lv_obj_set_width(ui_Button3, 50);
    lv_obj_set_height(ui_Button3, 50);
    lv_obj_set_x(ui_Button3, -21);
    lv_obj_set_y(ui_Button3, -67);
    lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0x5A7AB6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button3, &ui_img_1162731896, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button2 = lv_btn_create(ui_Container1);
    lv_obj_set_width(ui_Button2, 50);
    lv_obj_set_height(ui_Button2, 50);
    lv_obj_set_x(ui_Button2, -147);
    lv_obj_set_y(ui_Button2, -55);
    lv_obj_set_align(ui_Button2, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button2, lv_color_hex(0x5A7AB6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button2, &ui_img_1760988675, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button4 = lv_btn_create(ui_Container1);
    lv_obj_set_width(ui_Button4, 50);
    lv_obj_set_height(ui_Button4, 50);
    lv_obj_set_x(ui_Button4, -244);
    lv_obj_set_y(ui_Button4, -59);
    lv_obj_set_align(ui_Button4, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_Button4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button4, lv_color_hex(0x5A7AB6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button4, &ui_img_sound_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label1 = lv_label_create(ui_Container1);
    lv_obj_set_height(ui_Label1, 50);
    lv_obj_set_flex_grow(ui_Label1, 1);
    lv_obj_set_x(ui_Label1, 60);
    lv_obj_set_y(ui_Label1, -113);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "Select a File");
    lv_obj_set_style_text_align(ui_Label1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Label1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label1, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container5 = lv_obj_create(ui_Explorador);
    lv_obj_remove_style_all(ui_Container5);
    lv_obj_set_width(ui_Container5, lv_pct(95));
    lv_obj_set_height(ui_Container5, lv_pct(70));
    lv_obj_set_x(ui_Container5, 0);
    lv_obj_set_y(ui_Container5, lv_pct(10));
    lv_obj_set_align(ui_Container5, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container5, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container5, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container5, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Roller3 = lv_roller_create(ui_Container5);
    lv_roller_set_options(ui_Roller3, "Option 1 \nOption 2 \nOption 3\nOption 4 \nOption 5\nOption 6\nOption 7\nOption 8",
                          LV_ROLLER_MODE_NORMAL);
    lv_obj_set_width(ui_Roller3, lv_pct(70));
    lv_obj_set_height(ui_Roller3, lv_pct(95));
    lv_obj_set_x(ui_Roller3, -140);
    lv_obj_set_y(ui_Roller3, 85);
    lv_obj_set_align(ui_Roller3, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_Roller3, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE);      /// Flags
    lv_obj_set_style_text_letter_space(ui_Roller3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_Roller3, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Roller3, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Roller3, lv_color_hex(0x2F71EC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller3, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_Roller3, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Roller3, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller3, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Roller3, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Roller3, 150, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Roller3, 1, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Roller3, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_Container6 = lv_obj_create(ui_Container5);
    lv_obj_remove_style_all(ui_Container6);
    lv_obj_set_width(ui_Container6, lv_pct(30));
    lv_obj_set_height(ui_Container6, lv_pct(95));
    lv_obj_set_align(ui_Container6, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container6, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Container6, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Container6, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container7 = lv_obj_create(ui_Container6);
    lv_obj_remove_style_all(ui_Container7);
    lv_obj_set_width(ui_Container7, lv_pct(90));
    lv_obj_set_height(ui_Container7, lv_pct(85));
    lv_obj_set_align(ui_Container7, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container7, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Container7, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Container7, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button13 = lv_btn_create(ui_Container7);
    lv_obj_set_width(ui_Button13, 51);
    lv_obj_set_height(ui_Button13, 50);
    lv_obj_set_x(ui_Button13, 175);
    lv_obj_set_y(ui_Button13, -47);
    lv_obj_set_align(ui_Button13, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button13, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button13, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button13, lv_color_hex(0x768CF2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button13, &ui_img_1486996648, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button14 = lv_btn_create(ui_Container7);
    lv_obj_set_width(ui_Button14, 51);
    lv_obj_set_height(ui_Button14, 50);
    lv_obj_set_x(ui_Button14, 357);
    lv_obj_set_y(ui_Button14, 25);
    lv_obj_set_align(ui_Button14, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button14, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button14, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button14, lv_color_hex(0x768CF2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button14, &ui_img_1407471917, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button10 = lv_btn_create(ui_Container6);
    lv_obj_set_width(ui_Button10, lv_pct(85));
    lv_obj_set_height(ui_Button10, lv_pct(18));
    lv_obj_set_x(ui_Button10, 178);
    lv_obj_set_y(ui_Button10, 247);
    lv_obj_set_align(ui_Button10, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button10, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button10, lv_color_hex(0x2E5399), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_Button10);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, 1);
    lv_obj_set_y(ui_Label2, 0);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "Open");
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label2, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button3, ui_event_Button3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button4, ui_event_Button4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button13, ui_event_Button13, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button14, ui_event_Button14, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button10, ui_event_Button10, LV_EVENT_ALL, NULL);

}
