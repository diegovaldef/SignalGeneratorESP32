#ifndef COMPILER_H
#define COMPILER_H

/*
    Compila los datos del archivo de texto y los envia al buffer de escritura
*/

#include <Arduino.h>
#include <Core.h>

extern UBaseType_t spacesAvailable; // Espacios disponibles en la estructura WriteBuffer

void processSignal(const char *line, double nextPeriod); // Pasa los datos en texto al WriteBuffer
void readSignal(); // Lee el archivo y envia cada linea de texto a processSignal
void fillBuffers(); // Rellena los Buffers con los primeros 50 datos del txt
void init_Signal();

#endif 
