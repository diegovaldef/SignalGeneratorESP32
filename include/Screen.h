#ifndef SCREEN_H
#define SCREEN_H

#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <ui.h>
#include <Core.h>

static const uint16_t screenWidth  = 480;
static const uint16_t screenHeight = 320;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight / 10 ];

extern TFT_eSPI tft;
extern TaskHandle_t TaskScreenHandle;

void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p );
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data );
void screenSetup();
void rollerUp(lv_event_t * e);
void rollerDown(lv_event_t * e);
void SignalStartStop(lv_event_t * e);
void openTarget(lv_event_t * e);
void resetSignal(lv_event_t * e);
void refreshRollerButton(lv_event_t * e);
void exitLogo(lv_event_t * e);
void nextDirectory(lv_event_t * e);
void AnimtoExplorer(lv_event_t *e);
void TaskScreen(void *pvParameters);
void refreshLabel();
void createTaskScreen();

#endif