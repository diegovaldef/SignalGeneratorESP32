#ifndef OSCILLOSCOPE_H
#define OSCILLOSCOPE_H

#include <Arduino.h>
#include <Core.h>

#include <Adafruit_ADS1X15.h>
#include <Wire.h>

extern float adc0;
extern float adc1;
extern float adc2;
extern float adc3;

extern Adafruit_ADS1015 ads;
extern lv_chart_series_t *ser[4];

extern TaskHandle_t TaskScopeHandle;
extern lv_color_t colors[];

void createTaskScope();
void TaskScope(void *pvParameters);

#endif