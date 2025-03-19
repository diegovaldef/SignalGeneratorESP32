// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: SignalGenEsp32

#include "ui.h"

void ui_Main_screen_init(void)
{
    ui_Main = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Main, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Main, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Main, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container2 = lv_obj_create(ui_Main);
    lv_obj_remove_style_all(ui_Container2);
    lv_obj_set_width(ui_Container2, lv_pct(55));
    lv_obj_set_height(ui_Container2, lv_pct(98));
    lv_obj_set_x(ui_Container2, lv_pct(3));
    lv_obj_set_y(ui_Container2, lv_pct(2));
    lv_obj_set_flex_flow(ui_Container2, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Container2, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Container2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container9 = lv_obj_create(ui_Container2);
    lv_obj_remove_style_all(ui_Container9);
    lv_obj_set_width(ui_Container9, lv_pct(100));
    lv_obj_set_height(ui_Container9, lv_pct(15));
    lv_obj_set_x(ui_Container9, -13);
    lv_obj_set_y(ui_Container9, 4);
    lv_obj_set_align(ui_Container9, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container9, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container9, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Container9, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label5 = lv_label_create(ui_Container9);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 37
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 34
    lv_obj_set_x(ui_Label5, 68);
    lv_obj_set_y(ui_Label5, 4);
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_Label5, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_Label5, "ARCHIVO");
    lv_obj_set_style_text_font(ui_Label5, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container10 = lv_obj_create(ui_Container2);
    lv_obj_remove_style_all(ui_Container10);
    lv_obj_set_width(ui_Container10, lv_pct(31));
    lv_obj_set_height(ui_Container10, lv_pct(87));
    lv_obj_set_x(ui_Container10, 197);
    lv_obj_set_y(ui_Container10, -209);
    lv_obj_set_align(ui_Container10, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container10, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Container10, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container10, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel1 = lv_obj_create(ui_Container10);
    lv_obj_set_width(ui_Panel1, 70);
    lv_obj_set_height(ui_Panel1, 50);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0x3D70B3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label6 = lv_label_create(ui_Panel1);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "CH1");
    lv_obj_set_style_text_font(ui_Label6, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel2 = lv_obj_create(ui_Container10);
    lv_obj_set_width(ui_Panel2, 70);
    lv_obj_set_height(ui_Panel2, 50);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0x3D70B3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label8 = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_Label8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label8, "CH2");
    lv_obj_set_style_text_font(ui_Label8, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel3 = lv_obj_create(ui_Container10);
    lv_obj_set_width(ui_Panel3, 70);
    lv_obj_set_height(ui_Panel3, 50);
    lv_obj_set_x(ui_Panel3, 31);
    lv_obj_set_y(ui_Panel3, -11);
    lv_obj_set_align(ui_Panel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel3, lv_color_hex(0x3D70B3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label9 = lv_label_create(ui_Panel3);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label9, "CH3");
    lv_obj_set_style_text_font(ui_Label9, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel4 = lv_obj_create(ui_Container10);
    lv_obj_set_width(ui_Panel4, 70);
    lv_obj_set_height(ui_Panel4, 50);
    lv_obj_set_align(ui_Panel4, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel4, lv_color_hex(0x3D70B3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel4, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label10 = lv_label_create(ui_Panel4);
    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label10, "CH4");
    lv_obj_set_style_text_font(ui_Label10, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button8 = lv_btn_create(ui_Main);
    lv_obj_set_width(ui_Button8, 50);
    lv_obj_set_height(ui_Button8, 50);
    lv_obj_set_x(ui_Button8, 196);
    lv_obj_set_y(ui_Button8, -126);
    lv_obj_set_align(ui_Button8, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button8, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button8, lv_color_hex(0xAAAAAA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button8, &ui_img_return_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button5 = lv_btn_create(ui_Main);
    lv_obj_set_width(ui_Button5, 50);
    lv_obj_set_height(ui_Button5, 50);
    lv_obj_set_x(ui_Button5, 138);
    lv_obj_set_y(ui_Button5, -126);
    lv_obj_set_align(ui_Button5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button5, lv_color_hex(0x5A7AB6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button5, &ui_img_restart_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button12 = lv_btn_create(ui_Main);
    lv_obj_set_width(ui_Button12, 50);
    lv_obj_set_height(ui_Button12, 50);
    lv_obj_set_x(ui_Button12, 78);
    lv_obj_set_y(ui_Button12, -126);
    lv_obj_set_align(ui_Button12, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button12, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button12, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button12, lv_color_hex(0xAAAAAA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button12, &ui_img_config_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel5 = lv_obj_create(ui_Main);
    lv_obj_set_width(ui_Panel5, 109);
    lv_obj_set_height(ui_Panel5, 35);
    lv_obj_set_x(ui_Panel5, -69);
    lv_obj_set_y(ui_Panel5, -65);
    lv_obj_set_align(ui_Panel5, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel5, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel5, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel5, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_scrollbar_mode(ui_Panel5, LV_SCROLLBAR_MODE_OFF);

    ui_Spinbox1 = lv_spinbox_create(ui_Panel5);
    lv_obj_set_width(ui_Spinbox1, 70);
    lv_obj_set_height(ui_Spinbox1, 50);
    lv_obj_set_x(ui_Spinbox1, -272);
    lv_obj_set_y(ui_Spinbox1, 59);
    lv_obj_set_align(ui_Spinbox1, LV_ALIGN_CENTER);
    lv_spinbox_set_digit_format(ui_Spinbox1, 4, 2);
    lv_spinbox_set_range(ui_Spinbox1, 0, 2400);
    lv_spinbox_set_cursor_pos(ui_Spinbox1, 1 - 1);
    lv_spinbox_set_value(ui_Spinbox1, 500);
    lv_obj_set_style_pad_left(ui_Spinbox1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Spinbox1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Spinbox1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Spinbox1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Spinbox1, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Spinbox1, lv_color_hex(0xFFFFFF), LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Spinbox1, 0, LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Spinbox1, lv_color_hex(0xFFFFFF), LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Spinbox1, 255, LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Spinbox1, 1, LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Spinbox1, LV_BORDER_SIDE_BOTTOM, LV_PART_CURSOR | LV_STATE_DEFAULT);

    ui_Button11 = lv_btn_create(ui_Main);
    lv_obj_set_width(ui_Button11, 109);
    lv_obj_set_height(ui_Button11, 48);
    lv_obj_set_x(ui_Button11, -71);
    lv_obj_set_y(ui_Button11, 59);
    lv_obj_set_align(ui_Button11, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button11, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button11, lv_color_hex(0x768CF2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button11, &ui_img_1407471917, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Button11, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Button11, 100, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button9 = lv_btn_create(ui_Main);
    lv_obj_set_width(ui_Button9, 109);
    lv_obj_set_height(ui_Button9, 48);
    lv_obj_set_x(ui_Button9, -70);
    lv_obj_set_y(ui_Button9, -4);
    lv_obj_set_align(ui_Button9, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button9, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button9, lv_color_hex(0x768CF2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button9, &ui_img_1486996648, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Button9, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Button9, 100, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel6 = lv_obj_create(ui_Main);
    lv_obj_set_width(ui_Panel6, 109);
    lv_obj_set_height(ui_Panel6, 35);
    lv_obj_set_x(ui_Panel6, 50);
    lv_obj_set_y(ui_Panel6, -66);
    lv_obj_set_align(ui_Panel6, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel6, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel6, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel6, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_scrollbar_mode(ui_Panel6, LV_SCROLLBAR_MODE_OFF);

    ui_Spinbox2 = lv_spinbox_create(ui_Panel6);
    lv_obj_set_width(ui_Spinbox2, 70);
    lv_obj_set_height(ui_Spinbox2, 50);
    lv_obj_set_x(ui_Spinbox2, -473);
    lv_obj_set_y(ui_Spinbox2, 56);
    lv_obj_set_align(ui_Spinbox2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Spinbox2, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE);      /// Flags
    lv_spinbox_set_digit_format(ui_Spinbox2, 4, 2);
    lv_spinbox_set_range(ui_Spinbox2, 0, 9999);
    lv_spinbox_set_cursor_pos(ui_Spinbox2, 1 - 1);
    lv_spinbox_set_value(ui_Spinbox2, 100);
    lv_obj_set_style_pad_left(ui_Spinbox2, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Spinbox2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Spinbox2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Spinbox2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Spinbox2, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Spinbox2, lv_color_hex(0xFFFFFF), LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Spinbox2, 0, LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Spinbox2, lv_color_hex(0xFFFFFF), LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Spinbox2, 255, LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Spinbox2, 1, LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Spinbox2, LV_BORDER_SIDE_BOTTOM, LV_PART_CURSOR | LV_STATE_DEFAULT);

    ui_Button6 = lv_btn_create(ui_Main);
    lv_obj_set_width(ui_Button6, 109);
    lv_obj_set_height(ui_Button6, 48);
    lv_obj_set_x(ui_Button6, 50);
    lv_obj_set_y(ui_Button6, 60);
    lv_obj_set_align(ui_Button6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button6, lv_color_hex(0x768CF2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button6, &ui_img_1407471917, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Button6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Button6, 100, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button7 = lv_btn_create(ui_Main);
    lv_obj_set_width(ui_Button7, 109);
    lv_obj_set_height(ui_Button7, 48);
    lv_obj_set_x(ui_Button7, 49);
    lv_obj_set_y(ui_Button7, -3);
    lv_obj_set_align(ui_Button7, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button7, lv_color_hex(0x768CF2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button7, &ui_img_1486996648, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Button7, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Button7, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Button7, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Button7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button1 = lv_btn_create(ui_Main);
    lv_obj_set_width(ui_Button1, 230);
    lv_obj_set_height(ui_Button1, 47);
    lv_obj_set_x(ui_Button1, -10);
    lv_obj_set_y(ui_Button1, 121);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0x2E5399), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button1, &ui_img_1718651389, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Switch1 = lv_switch_create(ui_Main);
    lv_obj_set_width(ui_Switch1, 50);
    lv_obj_set_height(ui_Switch1, 25);
    lv_obj_set_x(ui_Switch1, 174);
    lv_obj_set_y(ui_Switch1, 2);
    lv_obj_set_align(ui_Switch1, LV_ALIGN_CENTER);


    ui_Switch2 = lv_switch_create(ui_Main);
    lv_obj_set_width(ui_Switch2, 50);
    lv_obj_set_height(ui_Switch2, 25);
    lv_obj_set_x(ui_Switch2, 175);
    lv_obj_set_y(ui_Switch2, 72);
    lv_obj_set_align(ui_Switch2, LV_ALIGN_CENTER);


    ui_Label11 = lv_label_create(ui_Main);
    lv_obj_set_width(ui_Label11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label11, 173);
    lv_obj_set_y(ui_Label11, -24);
    lv_obj_set_align(ui_Label11, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label11, "+/-");
    lv_obj_set_style_text_font(ui_Label11, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label12 = lv_label_create(ui_Main);
    lv_obj_set_width(ui_Label12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label12, 175);
    lv_obj_set_y(ui_Label12, 43);
    lv_obj_set_align(ui_Label12, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label12, "5v/12v");
    lv_obj_set_style_text_font(ui_Label12, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button8, ui_event_Button8, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button5, ui_event_Button5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button11, ui_event_Button11, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button9, ui_event_Button9, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button6, ui_event_Button6, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button7, ui_event_Button7, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);

}
