#ifndef COMPILER_H
#define COMPILER_H

/*
    Compila los datos del archivo de texto y los envia al buffer de escritura
*/

#include <Arduino.h>
#include <Core.h>

extern UBaseType_t spacesAvailable;
extern TaskHandle_t TaskCompilerHandle;

extern uint16_t ch1;
extern uint16_t ch2;
extern uint16_t ch3;
extern uint16_t ch4;
extern uint64_t deltaTime;

// Declaración de funciones
void processSignal(const char *line, double nextPeriod);
void readSignal();
void fillBuffers();
void init_Signal();
void createTaskCompiler();
void TaskCompiler(void *pvParameters);
void showChannels();


#endif // SIGNAL_PROCESSING_H
