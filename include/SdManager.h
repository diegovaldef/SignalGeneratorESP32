#ifndef SD_MANAGER_H
#define SD_MANAGER_H

/*
    Encargado de administrar los archivos de texto y la memoria SD
*/

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <Core.h>

const int MISO_2 = 27;
const int MOSI_2 = 13;
const int SCK_2  = 14;

extern SPIClass vspi;
extern TaskHandle_t TaskSDHandle;

extern File SD_Root;
extern String STR_Root;
const byte SD_CS = 15;

extern char fileType[];
extern String fileName[];

extern char list[];

void openFile();
void SDBegin();
char* getFileNames(File dir);
void refreshRoller();
void TaskSD(void *pvParameters);
void createTaskSD();

#endif






