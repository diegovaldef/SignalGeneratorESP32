// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: SignalGenEsp32

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_Logo
void ui_Logo_screen_init(void);
void ui_event_Logo(lv_event_t * e);
lv_obj_t * ui_Logo;
lv_obj_t * ui_Image2;
// CUSTOM VARIABLES


// SCREEN: ui_Logo0
void ui_Logo0_screen_init(void);
void ui_event_Logo0(lv_event_t * e);
lv_obj_t * ui_Logo0;
lv_obj_t * ui_Label7;
// CUSTOM VARIABLES


// SCREEN: ui_ErrorSD
void ui_ErrorSD_screen_init(void);
lv_obj_t * ui_ErrorSD;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Label4;
// CUSTOM VARIABLES


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
// CUSTOM VARIABLES


// SCREEN: ui_Main
void ui_Main_screen_init(void);
lv_obj_t * ui_Main;
lv_obj_t * ui_Container2;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_Label6;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_Label8;
lv_obj_t * ui_Panel3;
lv_obj_t * ui_Label9;
lv_obj_t * ui_Panel4;
lv_obj_t * ui_Label10;
void ui_event_Button1(lv_event_t * e);
lv_obj_t * ui_Button1;
void ui_event_Button5(lv_event_t * e);
lv_obj_t * ui_Button5;
void ui_event_Button6(lv_event_t * e);
lv_obj_t * ui_Button6;
void ui_event_Button7(lv_event_t * e);
lv_obj_t * ui_Button7;
void ui_event_Button8(lv_event_t * e);
lv_obj_t * ui_Button8;
lv_obj_t * ui_Button9;
lv_obj_t * ui_Button11;
lv_obj_t * ui_Panel5;
lv_obj_t * ui_Label12;
lv_obj_t * ui_Panel6;
lv_obj_t * ui_Label11;
void ui_event_Button12(lv_event_t * e);
lv_obj_t * ui_Button12;
// CUSTOM VARIABLES


// SCREEN: ui_Loading
void ui_Loading_screen_init(void);
lv_obj_t * ui_Loading;
lv_obj_t * ui_Container3;
lv_obj_t * ui_Spinner2;
lv_obj_t * ui_Label13;
// CUSTOM VARIABLES


// SCREEN: ui_Test
void ui_Test_screen_init(void);
lv_obj_t * ui_Test;
void ui_event_Slider1(lv_event_t * e);
lv_obj_t * ui_Slider1;
lv_obj_t * ui_Spinbox1;
void ui_event_Button15(lv_event_t * e);
lv_obj_t * ui_Button15;
void ui_event_Button16(lv_event_t * e);
lv_obj_t * ui_Button16;
// CUSTOM VARIABLES


// SCREEN: ui_Plot
void ui_Plot_screen_init(void);
lv_obj_t * ui_Plot;
lv_obj_t * ui_Container4;
lv_obj_t * ui_Chart1;
// CUSTOM VARIABLES

// EVENTS
lv_obj_t * ui____initial_actions0;

// IMAGES AND IMAGE SETS
const lv_img_dsc_t * ui_imgset_816728953[1] = {&ui_img_423428936};

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

    if(event_code == LV_EVENT_SCREEN_LOADED) {
        exitLogo(e);
    }
}

void ui_event_Logo0(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_SCREEN_LOADED) {
        exitLogo(e);
    }
}

void ui_event_Button3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        backDirectory(e);
    }
}

void ui_event_Button4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        nextDirectory(e);
    }
}

void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        refreshRollerButton(e);
    }
}

void ui_event_Button13(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        rollerUp(e);
    }
}

void ui_event_Button14(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        rollerDown(e);
    }
}

void ui_event_Button10(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        openTarget(e);
    }
}

void ui_event_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        SignalStartStop(e);
    }
}

void ui_event_Button5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        resetSignal(e);
    }
}

void ui_event_Button6(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        downFrecuency(e);
    }
}

void ui_event_Button7(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        upFrecuency(e);
    }
}

void ui_event_Button8(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        resetSignalComplete(e);
        backDirectory(e);
        AnimtoExplorer(e);
    }
}

void ui_event_Button12(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Plot, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Plot_screen_init);
    }
}

void ui_event_Slider1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_spinbox_step(ui_Spinbox1, 1);
    }
}

void ui_event_Button15(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        _ui_spinbox_step(ui_Spinbox1, 1);
    }
}

void ui_event_Button16(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        _ui_spinbox_step(ui_Spinbox1, -1);
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
    ui_Test_screen_init();
    ui_Plot_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Logo);
}
