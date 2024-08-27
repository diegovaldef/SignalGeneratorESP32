#ifndef SCREEN_H
#define SCREEN_H

/*
    Multitarea encargada de controlar la pantalla
*/

#include <Arduino.h>

#include <lvgl.h>
#include <TFT_eSPI.h>
#include <ui.h>
#include <Flags.h>
#include <Core.h>

static const uint16_t screenWidth  = 480; // Ancho de la pantalla
static const uint16_t screenHeight = 320; // Alto de la pantalla

static lv_disp_draw_buf_t draw_buf; // Buffer de datos de impresion en pantalla (LVGL)
static lv_color_t buf[ screenWidth * screenHeight / 10 ]; // Buffer de color (LVGL)

extern TFT_eSPI tft; // Clase para controlar la pantalla TFT (LVGL)
extern TaskHandle_t TaskScreenHandle; // Handle para la tarea Screen

// Refresco de la pantalla (LVGL)
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p ); 
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data ); // Lectura de la pantalla (LVGL)
void screenSetup(); // Inicializacion de la pantalla (LVGL)
void rollerUp(lv_event_t * e); // Boton Arriba Exporador de archivos
void rollerDown(lv_event_t * e); // Boton Abajo Explorador de archivos
void SignalStartStop(lv_event_t * e); // Boton Pausar o Despausar ejecucion de señal
void openTarget(lv_event_t * e); // Boton para abrir el archivo o carpeta
void TaskScreen(void *pvParameters); // Tarea para administrar la pantalla
void createTaskScreen(); // Crea la multitarea Screen

#endif