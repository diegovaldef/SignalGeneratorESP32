#include <SdManager.h>

SPIClass vspi(VSPI);
TaskHandle_t TaskSDHandle;

File SD_Root;
String STR_Root;

char list[100];
char fileType[100];
String fileName[100];
String fileNameStd[100];

bool noSDFound = false;
int delay_time = 0;

void createTaskSD()
{
  xTaskCreatePinnedToCore(
      TaskSD,
      "TaskSD",
      1024 * 10,
      NULL,
      0,
      &TaskSDHandle,
      1);

}

void TaskSD(void *pvParameters)
{
  vTaskSuspend(TaskSDHandle);

  while(true){

    _ui_screen_change(&ui_ErrorSD, LV_SCR_LOAD_ANIM_FADE_OUT, 0, delay_time, &ui_ErrorSD_screen_init);

    while(!SD.begin(SD_CS, vspi)){
      SD.begin(SD_CS, vspi);
      vTaskDelay(1);
    }

    while (!SD_Root)
    {
      SD_Root = SD.open(STR_Root, FILE_READ);
      vTaskDelay(1);
    }

    refreshRoller();
    _ui_screen_change(&ui_Explorador, LV_SCR_LOAD_ANIM_FADE_OUT, 0, 0, &ui_Explorador_screen_init);
    noSDFound = false;

    vTaskSuspend(TaskSDHandle);
  }

}

void openFileRead()
{
  SD_Root = SD.open(STR_Root, FILE_READ);
  if (!SD_Root)
  {
    delay_time = 0;
    noSDFound = true;
    vTaskResume(TaskSDHandle);
  }
}

void openFileWrite()
{
  SD_Root = SD.open(STR_Root, FILE_WRITE);
  if (!SD_Root)
  {
    delay_time = 0;
    noSDFound = true;
    vTaskResume(TaskSDHandle);
  }
}

void SDBegin()
{
  STR_Root = "/";

  if (!SD.begin(SD_CS, vspi))
  {
    delay_time = 3000;
    noSDFound = true;
    vTaskResume(TaskSDHandle);
  }
  else
  {
    refreshRoller();
  }

}

char *getFileNames(File dir)
{

  char name[100];
  char symbol[100];
  char space[100];
  char sign[100];
  strcpy(list, "");
  strcpy(fileType, "");

  for (int i = 0; i < 100; i++)
  {
    fileName[i] = "";
    fileNameStd[i] = "";
  }

  byte i = 0;

  while (true)
  {

    File entry = dir.openNextFile();

    if (!entry)
    {
      sort_file_list(list);
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

      char *ext = strstr(name, ".txt");  
    
      if (ext != NULL) {
          *ext = '\0';
      }

      fileNameStd[i] = name;

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

  openFileRead();

  lv_roller_set_options(ui_Roller3, getFileNames(SD_Root),
                        LV_ROLLER_MODE_NORMAL);

  float len = strlen(fileType);

  if (int(len) % 2 == 1)
  {
    len = len / 2;
    len = floor(len);
  }
  else
  {
    len = (len / 2) - 1;
  }

  lv_roller_set_selected(ui_Roller3, len, LV_ANIM_OFF);
}

int compare_lines(const void* a, const void* b) {
    const char* lineA = *(const char**)a;
    const char* lineB = *(const char**)b;
    
    // Saltar icono y espacio (si existen)
    const char* nameA = strchr(lineA, ' ');
    const char* nameB = strchr(lineB, ' ');
    
    nameA = nameA ? nameA + 1 : lineA;
    nameB = nameB ? nameB + 1 : lineB;
    
    return strcasecmp(nameA, nameB);
}

void sort_file_list(char* list) {
    // Primera pasada: contar líneas
    int line_count = 0;
    char* temp = strdup(list); // Creamos copia temporal
    char* token = strtok(temp, "\n");
    
    while(token) {
        line_count++;
        token = strtok(NULL, "\n");
    }
    free(temp);

    // Reservar memoria para punteros
    char** lines = (char**)malloc(line_count * sizeof(char*));
    if(!lines) return; // Manejo de error

    // Segunda pasada: llenar el array
    temp = strdup(list);
    token = strtok(temp, "\n");
    for(int i = 0; i < line_count && token; i++) {
        lines[i] = strdup(token); // Almacenar cada línea
        token = strtok(NULL, "\n");
    }
    free(temp);

    // Ordenar el array
    qsort(lines, line_count, sizeof(char*), compare_lines);

    // Reconstruir cadena ordenada
    char* ptr = list;
    size_t remaining = strlen(list) + 1; // +1 para el null terminator
    
    for(int i = 0; i < line_count; i++) {
        size_t len = strlen(lines[i]);
        if(len + 1 > remaining) break; // Prevención de overflow
        
        strncpy(ptr, lines[i], remaining);
        ptr += len;
        *ptr++ = (i < line_count - 1) ? '\n' : '\0';
        remaining -= (len + 1);
        
        free(lines[i]); // Liberar cada línea
    }
    
    free(lines); // Liberar array de punteros
}