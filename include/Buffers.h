#ifndef BUFFERS_H
#define BUFFERS_H

/*
    Buffers de datos para lectura del archivo de texto y escritura en los DAC 
*/

#include <Arduino.h>
#include <Core.h>
#include <freertos/queue.h>

const byte READ_BUF_SIZE = 128;  // Tamaño del buffer de lectura
const byte WRITE_BUF_SIZE = 50; // Tamaño del buffer de datos
struct ReadBuffer // Estructura para guardar la informacion e lectura
{
    char ACTUAL_BUF[READ_BUF_SIZE]; // Buffer de lectura actual
    char NEXT_BUF[READ_BUF_SIZE]; // Buffer de lectura siguiente
};

extern ReadBuffer readBuffer; // Se inicializa la estructura

struct WriteBuffer // Estructura de datos para almacenar los buffers de datos de escritura
{
    QueueHandle_t CH1 = xQueueCreate(WRITE_BUF_SIZE, sizeof(uint16_t)); // Canal 1
    QueueHandle_t CH2 = xQueueCreate(WRITE_BUF_SIZE, sizeof(uint16_t)); // Canal 2
    QueueHandle_t CH3 = xQueueCreate(WRITE_BUF_SIZE, sizeof(uint16_t)); // Canal 3
    QueueHandle_t CH4 = xQueueCreate(WRITE_BUF_SIZE, sizeof(uint16_t)); // Canal 4
    QueueHandle_t TIME = xQueueCreate(WRITE_BUF_SIZE, sizeof(uint64_t)); // Tiempo (Periodo)

};

extern WriteBuffer writeBuffer; // Se inicializa la estructura

#endif

