// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.11
// Project name: SignalGenEsp32

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_Logo
void ui_Logo_screen_init(void);
void ui_event_Logo(lv_event_t * e);
lv_obj_t * ui_Logo;
lv_obj_t * ui_Label7;


// SCREEN: ui_ErrorSD
void ui_ErrorSD_screen_init(void);
lv_obj_t * ui_ErrorSD;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Label4;


// SCREEN: ui_Explorador
void ui_Explorador_screen_init(void);
lv_obj_t * ui_Explorador;
lv_obj_t * ui_Container1;
void ui_event_Button3(lv_event_t * e);
lv_obj_t * ui_Button3;
void ui_event_Button4(lv_event_t * e);
lv_obj_t * ui_Button4;
void ui_event_Button2(lv_event_t * e);
lv_obj_t * ui_Button2;
lv_obj_t * ui_Label1;
lv_obj_t * ui_Container5;
lv_obj_t * ui_Roller3;
lv_obj_t * ui_Container6;
lv_obj_t * ui_Container7;
void ui_event_Button13(lv_event_t * e);
lv_obj_t * ui_Button13;
void ui_event_Button14(lv_event_t * e);
lv_obj_t * ui_Button14;
void ui_event_Button10(lv_event_t * e);
lv_obj_t * ui_Button10;
lv_obj_t * ui_Label2;


// SCREEN: ui_Main
void ui_Main_screen_init(void);
lv_obj_t * ui_Main;
lv_obj_t * ui_Container2;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Chart1;
lv_obj_t * ui_Chart2;
lv_obj_t * ui_Chart3;
lv_obj_t * ui_Chart4;
void ui_event_Button1(lv_event_t * e);
lv_obj_t * ui_Button1;
void ui_event_Button5(lv_event_t * e);
lv_obj_t * ui_Button5;
lv_obj_t * ui_Button6;
lv_obj_t * ui_Button7;
void ui_event_Button8(lv_event_t * e);
lv_obj_t * ui_Button8;


// SCREEN: ui_Loading
void ui_Loading_screen_init(void);
lv_obj_t * ui_Loading;
lv_obj_t * ui_Spinner2;
lv_obj_t * ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Logo(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        exitLogo(e);
    }
}
void ui_event_Button3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        backDirectory(e);
    }
}
void ui_event_Button4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        nextDirectory(e);
    }
}
void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        refreshRollerButton(e);
    }
}
void ui_event_Button13(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        rollerUp(e);
    }
}
void ui_event_Button14(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        rollerDown(e);
    }
}
void ui_event_Button10(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        openTarget(e);
    }
}
void ui_event_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SignalStartStop(e);
    }
}
void ui_event_Button5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_PRESSED) {
        resetSignal(e);
    }
}
void ui_event_Button8(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Explorador, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Explorador_screen_init);
        resetSignal(e);
        backDirectory(e);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Logo_screen_init();
    ui_Explorador_screen_init();
    ui_Main_screen_init();
    ui_Loading_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Logo);
}
