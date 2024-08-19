#ifndef INJECT_H
#define INJECT_H

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/dac.h>
#include <freertos/queue.h>
#include <Core.h>

extern TaskHandle_t TaskInjectHandle;

extern uint16_t ch1;
extern uint16_t ch2;
extern uint16_t ch3;
extern uint64_t microseconds;

const int dac1Pin = 25; // Pin de salida DAC1 (CKP)
const int dac2Pin = 26; // Pin de salida DAC2 (CMP1)

void TaskInject(void *pvParameters);
void createTaskInject();

#endif