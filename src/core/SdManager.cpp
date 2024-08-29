#include <SdManager.h>

File SD_Root;
String STR_Root;

char list[100];
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

  STR_Root = "/";
  refreshRoller();
}

char *getFileNames(File dir)
{

  char name[100];
  char symbol[100];
  char space[100];
  char sign[100];
  strcpy(list, "");
  strcpy(fileType, "");

  for (int i = 0; i < 100; i++) {
      fileName[i] = "";
  }

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

      strcpy(sign, "/");
      strcat(sign, name);
      strcpy(name, sign);
      fileName[i] = name;

      strcpy(name, str);

      if (entry.isDirectory())
      {
        strcpy(symbol, LV_SYMBOL_DIRECTORY);
        strcat(fileType, "0");
      }
      else
      {
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

void refreshRoller()
{

  SD_Root = SD.open(STR_Root, FILE_READ);

  lv_roller_set_options(ui_Roller3, getFileNames(SD_Root),
                        LV_ROLLER_MODE_NORMAL);

  float len = strlen(fileType);

  if (int(len) % 2 == 1){
    len = len / 2;
    len = floor(len);
  }
  else{
    len = (len / 2) - 1;
  }

  lv_roller_set_selected(ui_Roller3, len, LV_ANIM_OFF);
}