#ifndef SD_MANAGER_H
#define SD_MANAGER_H

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <Core.h>

extern File dataFile;
extern File root;
const byte chipSelect = 5;

void openSD();
void SDBegin();
char* getFileNames(File dir);

#endif






