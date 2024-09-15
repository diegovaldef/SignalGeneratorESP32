#ifndef INJECT_H
#define INJECT_H

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

extern uint16_t ch1;
extern uint16_t ch2;
extern uint16_t ch3;
extern uint64_t microseconds;

void TaskInject(void *pvParameters);
void createTaskInject();
void MCPBegin();

#endif