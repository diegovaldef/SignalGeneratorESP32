#include <SdManager.h>

File SD_Root;
String STR_Root = "/";

char list[100];
char name[100];
char symbol[100];
char space[100];

char fileType[100];
String fileName[100];

void openFile()
{
  SD_Root = SD.open(STR_Root, FILE_READ);
  if (!SD_Root)
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

  refreshRoller();

}

char* getFileNames(File dir) {

  byte i = 0;

  while (true) {

    File entry =  dir.openNextFile();

    if (!entry ) {

      return list;

    }

    if(strlen(entry.name()) > 0 && strlen(entry.name()) <= 20){

      const char* str = entry.name();
      strcpy(name, str);
      fileName[i] = name;

      if(entry.isDirectory()){
        strcpy(symbol, LV_SYMBOL_DIRECTORY);
        strcat(fileType, "0");
      }
      else {
        strcpy(symbol, LV_SYMBOL_FILE);
        strcat(fileType, "1");
      }

      strcpy(space, " ");
      strcat(space, name);
      strcpy(name, space);

      strcat(symbol, name);
      strcpy(name, symbol);
      strcat(name, "\n");


      strcat(list, name);
      i++;
      
    }

    entry.close();
  }

}

void refreshRoller(){

  SD_Root = SD.open(STR_Root, FILE_READ);

  lv_roller_set_options(ui_Roller3, getFileNames(SD_Root),
                   LV_ROLLER_MODE_NORMAL);

}