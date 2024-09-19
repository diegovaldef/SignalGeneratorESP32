#ifndef COMPILER_H
#define COMPILER_H

/*
    Compila los datos del archivo de texto y los envia al buffer de escritura
*/

#include <Arduino.h>
#include <Core.h>

extern UBaseType_t spacesAvailable;
extern TaskHandle_t TaskCompilerHandle;

// Declaración de funciones
void processSignal(const char *line, double nextPeriod);
void readSignal();
void fillBuffers();
void init_Signal();
void createTaskCompiler();
void TaskCompiler(void *pvParameters);


#endif // SIGNAL_PROCESSING_H
