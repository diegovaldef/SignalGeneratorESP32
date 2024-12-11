#ifndef BUFFERS_H
#define BUFFERS_H

/*
    Buffers de datos para lectura del archivo de texto y escritura en los DAC 
*/

#include <Arduino.h>
#include <Core.h>
#include <freertos/queue.h>

const byte READ_BUF_SIZE = 128;  // Tamaño del buffer de lectura
const int WRITE_BUF_SIZE = 1000; // Tamaño del buffer de escritura


struct ReadBuffer
{
    char ACTUAL_BUF[READ_BUF_SIZE]; // Buffer de lectura actual
    char NEXT_BUF[READ_BUF_SIZE]; // Buffer de lectura siguiente
};

extern ReadBuffer readBuffer; // Se inicializa la estructura de lectura

struct WriteBuffer // Estructura de datos para almacenar los buffers de datos de escritura
{
    // Buffers basados en queues del FREERTOS

    QueueHandle_t CH1 = xQueueCreate(WRITE_BUF_SIZE, sizeof(uint16_t));
    QueueHandle_t CH2 = xQueueCreate(WRITE_BUF_SIZE, sizeof(uint16_t));
    QueueHandle_t CH3 = xQueueCreate(WRITE_BUF_SIZE, sizeof(uint16_t));
    QueueHandle_t CH4 = xQueueCreate(WRITE_BUF_SIZE, sizeof(uint16_t));
    QueueHandle_t TIME = xQueueCreate(WRITE_BUF_SIZE, sizeof(uint64_t));


};

extern WriteBuffer writeBuffer; // Se inicializa la estructura de escritura

#endif

