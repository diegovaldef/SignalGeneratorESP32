#include <SdManager.h>

File dataFile;
File root;

char list[100];
char name[100];
char symbol[100];
char space[100];

void openSD()
{
  dataFile = SD.open("/data.txt", FILE_READ);
  if (!dataFile)
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

  root = SD.open("/", FILE_READ);
}

char* getFileNames(File dir) {

  while (true) {

    File entry =  dir.openNextFile();

    if (!entry ) {

      return list;

    }

    if(strlen(entry.name()) > 0 && strlen(entry.name()) <= 20){

      const char* str = entry.name();
      strcpy(name, str);

      if(entry.isDirectory()){
        strcpy(symbol, LV_SYMBOL_DIRECTORY);
      }
      else {
        strcpy(symbol, LV_SYMBOL_FILE);

      }

      strcpy(space, " ");
      strcat(space, name);
      strcpy(name, space);

      strcat(symbol, name);
      strcpy(name, symbol);
      strcat(name, "\n");


      strcat(list, name);
      
    }

    entry.close();
  }

}