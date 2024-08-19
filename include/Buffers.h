#ifndef BUFFERS_H
#define BUFFERS_H

#include <Arduino.h>
#include <Core.h>
#include <freertos/queue.h>

// Constantes
const byte READ_BUF_SIZE = 128;  // Tamaño del buffer de lectura
const byte WRITE_BUF_SIZE = 50; // Tamaño del buffer de datos


struct ReadBuffer
{
    char ACTUAL_BUF[READ_BUF_SIZE];
    char NEXT_BUF[READ_BUF_SIZE];
};

extern ReadBuffer readBuffer;

// Estructura de datos para almacenar los buffers de datos
struct WriteBuffer
{
    QueueHandle_t CH1 = xQueueCreate(WRITE_BUF_SIZE, sizeof(uint16_t));
    QueueHandle_t CH2 = xQueueCreate(WRITE_BUF_SIZE, sizeof(uint16_t));
    QueueHandle_t CH3 = xQueueCreate(WRITE_BUF_SIZE, sizeof(uint16_t));
    QueueHandle_t CH4 = xQueueCreate(WRITE_BUF_SIZE, sizeof(uint16_t));
    QueueHandle_t TIME = xQueueCreate(WRITE_BUF_SIZE, sizeof(uint64_t));
    QueueHandle_t REAL_TIME = xQueueCreate(WRITE_BUF_SIZE, sizeof(uint64_t));

};

// Declaración de la variable global
extern WriteBuffer writeBuffer;

#endif // BUFFERS_H

