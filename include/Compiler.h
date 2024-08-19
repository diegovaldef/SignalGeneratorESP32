#ifndef COMPILER_H
#define COMPILER_H

#include <Arduino.h>
#include <Core.h>

extern UBaseType_t spacesAvailable;

// Declaración de funciones
void processSignal(const char *line, double nextPeriod);
void readSignal();
void fillBuffers();

#endif // SIGNAL_PROCESSING_H
