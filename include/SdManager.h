#ifndef SD_MANAGER_H
#define SD_MANAGER_H

/*
    Encargado de administrar los archivos de texto y la memoria SD
*/

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <Core.h>

// Pines para el segundo SPI

const int MISO_2 = 27;
const int MOSI_2 = 13;
const int SCK_2  = 14;
const byte SD_CS = 15; 

extern SPIClass vspi; // Se crea el objeto para segundo SPI
extern TaskHandle_t TaskSDHandle; // Handle del TaskSD

extern File SD_Root; // Ruta del SD
extern String STR_Root; // Ruta del SD en texto

extern char fileType[]; // Arreglo para guardar los tipos de archivos (carptas o archivos)
extern String fileName[]; // Arreglo para guardar los nombres de los archivos (Usado por el sistema)
extern String fileNameStd[]; // Arreglo para guardar los nombres de los archivos (Para mostrar en Roller) 

extern char list[]; // Lista de nombres

void openFile(); // Abrir el archivo seleccionado
void SDBegin(); // Inicializar la targeta SD
char* getFileNames(File dir); // Obtener los nombres de los archivos SD
void refreshRoller(); // Refrescar el Roller 
void TaskSD(void *pvParameters); // TaskSD
void createTaskSD(); // Crear TaskSD

#endif






