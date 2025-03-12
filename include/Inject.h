#ifndef INJECT_H
#define INJECT_H

/*
    Multitarea encargada de inyectar los datos del buffer de escritura en los DAC
*/

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include <Adafruit_MCP4728.h>
#include <Wire.h>
#include <Core.h>

extern Adafruit_MCP4728 mcp; // Inicializa el objeto MCP, modulo DAC
extern TaskHandle_t TaskInjectHandle; // Handle del TaskInject

void TaskInject(void *pvParameters); // TaskInject
void createTaskInject(); // Crea el taskInject
void MCPBegin(); // Inicializa el MCP, necesario para trabajar

#endif