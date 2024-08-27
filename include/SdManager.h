#ifndef SD_MANAGER_H
#define SD_MANAGER_H

/*
    Encargado de administrar los archivos de texto y la memoria SD
*/

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <Core.h>

extern File SD_ActualFile;
extern File SD_Root;
const byte chipSelect = 5;
extern char fileTypes[];
extern String fileNames[];
extern String STR_Root; 

void openFile(String file);
void SDBegin();
char* getFileNames(File dir);
void refreshRoller();

#endif






