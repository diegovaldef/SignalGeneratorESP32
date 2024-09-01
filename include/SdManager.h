#ifndef SD_MANAGER_H
#define SD_MANAGER_H

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <Core.h>

extern TaskHandle_t TaskSDHandle;

extern File SD_Root;
extern String STR_Root;
const byte chipSelect = 5;

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






