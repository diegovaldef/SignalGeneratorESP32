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

extern int indexFrecuency; // Valor seleccionado para la frecuencia de la senal
extern float valuesFrecuency[]; // Valores para seleccionar de frecuencia

static lv_disp_draw_buf_t draw_buf; // Buffer de datos de impresion en pantalla (LVGL)
static lv_color_t buf[ screenWidth * screenHeight / 10 ]; // Buffer de color (LVGL)

extern TFT_eSPI tft; // Clase para controlar la pantalla TFT (LVGL)
extern TaskHandle_t TaskScreenHandle; // Handle para la tarea Screen

extern int selected; // Numero de archivo seleccionado en la pantalla

extern byte ledsPin;
extern byte relePin;

void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p ); // LVGL
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data ); // Lee la pantalla revisando el tacto (LVGL)
void screenSetup(); // Inicializa la pantalla (LVGL)
void rollerUp(lv_event_t * e); // Mueve el Roller hacia arriba
void rollerDown(lv_event_t * e); // Mueve el Roller hacia abajo
void SignalStartStop(lv_event_t * e); // Detiene o Reanuda la senal
void openTarget(lv_event_t * e); // Abre el achivo o carpeta seleccionado en el Roller
void resetSignalComplete(lv_event_t * e); // Reinicia la senal completamente
void resetSignal(lv_event_t * e); // Reinicia la senal exceptuando algunos elementos
void refreshRollerButton(lv_event_t * e); // Refresca los elementos mostrados en el roller
void exitLogo(lv_event_t * e); // Verifica el estado de la sd para salir del logo
void AnimtoExplorer(lv_event_t *e); // Animacion en direccion al Explorador
void upFrecuency(lv_event_t * e); // Elevar Frecuencia
void downFrecuency(lv_event_t * e); // Disminuir Frecuencia
void gotoPlot(lv_event_t * e); // Ir a la pantalla de Plot
void backfromPlot(lv_event_t * e); // Regresar de la pantalla de Plot
void TaskScreen(void *pvParameters); // TaskScreen
void refreshLabel(); // Refresca el texto para mostrar la ruta de directorio
void createTaskScreen(); // Crea el TaskScreen

#endif