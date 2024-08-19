#ifndef TIMER_H
#define TIMER_H

#include "Arduino.h"
#include "esp_timer.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <Core.h>

extern hw_timer_t *My_timer;

void IRAM_ATTR timer_isr();
void init_timer();
void vMicrosecondsdelay(uint64_t us);

#endif