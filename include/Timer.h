#ifndef TIMER_H
#define TIMER_H

/*
    Encargado de manejar los tiempos entre señales
*/

#include "Arduino.h"
#include "esp_timer.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <Core.h>

extern hw_timer_t *My_timer; // Instancia del Timer

void IRAM_ATTR timerISR(); // Funcion que se ejecuta al terminar el timer
void initTimer(); // Incializa el timer
void vMicrosecondsdelay(uint64_t us); // Genera un retraso preciso entre señales del DAC

#endif