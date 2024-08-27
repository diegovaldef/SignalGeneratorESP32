#ifndef INJECT_H
#define INJECT_H

/*
    Multitarea encargada de inyectar los datos del buffer de escritura en los DAC
*/

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/dac.h>
#include <freertos/queue.h>
#include <Core.h>

extern TaskHandle_t TaskInjectHandle; // Handle de tarea Inject

extern uint16_t ch1; // Valores del canal 1
extern uint16_t ch2; // Valores del canal 2
extern uint16_t ch3; // Valores del canal 3
extern uint64_t microseconds;

const int dac1Pin = 25; // Pin de salida DAC1 (CKP)
const int dac2Pin = 26; // Pin de salida DAC2 (CMP1)

void TaskInject(void *pvParameters); // Multitarea encargada de Inyectar los datos del buffer al dac
void createTaskInject(); // Inicializa la multitarea Inject

#endif