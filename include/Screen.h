#ifndef SCREEN_H
#define SCREEN_H

/*
    Multitarea encargada de controlar la pantalla
*/

#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <ui.h>
#include <Core.h>

static const uint16_t screenWidth  = 480; // Ancho de la pantalla
static const uint16_t screenHeight = 320; // Alto de la pantalla

extern int indexFrecuency;
extern float valuesFrecuency[];

static lv_disp_draw_buf_t draw_buf; // Buffer de datos de impresion en pantalla (LVGL)
static lv_color_t buf[ screenWidth * screenHeight / 10 ]; // Buffer de color (LVGL)

extern TFT_eSPI tft; // Clase para controlar la pantalla TFT (LVGL)
extern TaskHandle_t TaskScreenHandle; // Handle para la tarea Screen

extern byte selected;

void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p );
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data );
void screenSetup();
void rollerUp(lv_event_t * e);
void rollerDown(lv_event_t * e);
void SignalStartStop(lv_event_t * e);
void openTarget(lv_event_t * e);
void resetSignalComplete(lv_event_t * e);
void resetSignal(lv_event_t * e);
void refreshRollerButton(lv_event_t * e);
void exitLogo(lv_event_t * e);
void nextDirectory(lv_event_t * e);
void AnimtoExplorer(lv_event_t *e);
void upFrecuency(lv_event_t * e);
void downFrecuency(lv_event_t * e);
void TaskScreen(void *pvParameters);
void refreshLabel();
void createTaskScreen();

#endif