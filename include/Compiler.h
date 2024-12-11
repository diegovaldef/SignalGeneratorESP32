#ifndef COMPILER_H
#define COMPILER_H

/*
    Compila los datos del archivo de texto y los envia al buffer de escritura
*/

#include <Arduino.h>
#include <Core.h>

extern UBaseType_t spacesAvailable; // Espacios disponibles en el buffer de escritura
extern TaskHandle_t TaskCompilerHandle; // Handle del TaskCompiler

// Variables para guardar los valores de cada canal

extern uint16_t ch1;
extern uint16_t ch2;
extern uint16_t ch3;
extern uint16_t ch4;
extern uint64_t deltaTime;

void processSignal(const char *line, double nextPeriod); // Recibe cada linea de texto y la pasa al buffer de escritura
void readSignal(); // Lee el documento y envia cada linea a processSignal
void fillBuffers(); // Rellena los buffers de escritura la primera vez, para preparar el Inject
void init_Signal(); // Inicializa la señal, leyendo su minimo y maximo y rellenando el buffer de escritura
void createTaskCompiler(); // Crea el TaskCompiler
void TaskCompiler(void *pvParameters); // TaskCompiler
void showChannels(); // Muestra al ususario el estado de cada canal en pantalla


#endif
