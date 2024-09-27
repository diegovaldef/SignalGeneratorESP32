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
#include <Adafruit_MCP4728.h>
#include <Wire.h>
#include <Core.h>

extern Adafruit_MCP4728 mcp;
extern TaskHandle_t TaskInjectHandle;

void TaskInject(void *pvParameters);
void createTaskInject();
void MCPBegin();

#endif