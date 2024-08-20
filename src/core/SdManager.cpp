#include <SdManager.h>

File dataFile;
File root;

char list[100];
char name[100];

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

    if(strlen(entry.name()) && strlen(entry.name()) <= 20){

      const char* str = entry.name();
      strcpy(name, str);
      strcat(name, "\n");

      if(name ){
        strcat(list, name);
      }

    }

    entry.close();
  }

}