#ifndef MANAGER_H
#define MANAGER_H

#include <Arduino.h>
#include <Core.h>

struct taskStates {

    bool compiler = false;
    bool inject = false;
    bool sd = false;
    bool scope = false;
};

extern taskStates globalStates;
extern TaskHandle_t TaskManagerHandle;

void reloadTasks(); // Recargar tareas
void createTaskManager(); // Crear TaskManager
void TaskManager(void *pvParameters); // TaskManager

#endif