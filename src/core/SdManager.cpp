#include <SdManager.h>

File dataFile;

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
}