#ifndef SD_MANAGER_H
#define SD_MANAGER_H

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <Core.h>

extern File dataFile;
const byte chipSelect = 5;

void openSD();
void SDBegin();

#endif






