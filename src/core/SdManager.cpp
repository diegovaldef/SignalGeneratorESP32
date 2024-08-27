#include <SdManager.h>

File SD_ActualFile;
File SD_Root;
String STR_Root = "/";

char list[100];
char name[100];
char symbol[100];
char space[100];
char fileTypes[100];
String fileNames[100];

void openFile(String file)
{
  SD_ActualFile = SD.open(file, FILE_READ);
  if (!SD_ActualFile)
  {
    Serial.println("Error abriendo el archivo");
    for (;;)
    {
    }
  }
}

void SDBegin()
{

  if (!SD.begin(chipSelect))
  {
    Serial.println("Error inicializando la tarjeta SD");
    for (;;)
    {
    }
  }

  xMutex = xSemaphoreCreateMutex();
  refreshRoller();
}

char *getFileNames(File dir)
{

  byte i = 0;

  while (true)
  {

    File entry = dir.openNextFile();

    if (!entry)
    {

      return list;
    }

    if (strlen(entry.name()) > 0 && strlen(entry.name()) <= 20)
    {

      const char *str = entry.name();
      strcpy(name, str);

      if (entry.isDirectory())
      {
        strcpy(symbol, LV_SYMBOL_DIRECTORY);
        strcat(fileTypes, "0");
      }
      else
      {
        strcpy(symbol, LV_SYMBOL_FILE);
        strcat(fileTypes, "1");
      }

      strcpy(space, " ");
      strcat(space, name);
      strcpy(name, space);

      strcat(symbol, name);
      strcpy(name, symbol);
      strcat(name, "\n");

      strcat(list, name);
      fileNames[i] = name;
      i++;
    }

    entry.close();
  }
}

void refreshRoller()
{
  if (xSemaphoreTake(xMutex, 0) == pdTRUE) {
    SD_Root = SD.open(STR_Root, FILE_READ);
    xSemaphoreGive(xMutex);
  }

  lv_roller_set_options(ui_Roller3, getFileNames(SD_Root),
                        LV_ROLLER_MODE_NORMAL);
                        
}