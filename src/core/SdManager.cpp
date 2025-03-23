#include <SdManager.h>

SPIClass vspi(VSPI);
TaskHandle_t TaskSDHandle;

File SD_Root;
String STR_Root;

char list[2048];
char fileType[100];
String fileName[100];
String fileNameStd[100];

struct FileEntry {
    char display_line[100];  // Línea completa (ej: " TEST")
    String file_name;        // Nomme completo (ej: "/TEST")
    String file_name_std;    // Nombre limpio (ej: "TEST")
    char type;               // '0' o '1'
};

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

int compare_entries(const void* a, const void* b) {
    const struct FileEntry* entryA = (const struct FileEntry*)a;
    const struct FileEntry* entryB = (const struct FileEntry*)b;
    
    // Comparar ignorando ícono + espacio inicial
    const char* nameA = strchr(entryA->display_line, ' ');
    const char* nameB = strchr(entryB->display_line, ' ');
    
    nameA = nameA ? nameA + 1 : entryA->display_line;
    nameB = nameB ? nameB + 1 : entryB->display_line;
    
    return strcmp(nameA, nameB);
}

char *getFileNames(File dir) {
    static struct FileEntry entries[100]; // Almacena temporalmente
    int entry_count = 0;
    
    strcpy(list, "");
    strcpy(fileType, "");

    // Resetear arrays globales
    for(int i = 0; i < 100; i++) {
        fileName[i] = "";
        fileNameStd[i] = "";
        fileType[i] = '\0'; // Asumiendo que fileType es char[100]
    }

    while(true) {
        File entry = dir.openNextFile();
        if(!entry) break;

        if(strlen(entry.name()) > 0 && strlen(entry.name()) <= 20) {
            // Procesamiento original
            char name[100];
            strcpy(name, entry.name());
            
            // Construir nombres (modo original)
            entries[entry_count].file_name = "/" + String(name);
            entries[entry_count].file_name_std = String(name).substring(0, String(name).indexOf(".txt"));
            
            // Construir línea de visualización
            const char* icon = entry.isDirectory() ? LV_SYMBOL_DIRECTORY : LV_SYMBOL_FILE;
            snprintf(entries[entry_count].display_line, 
                    sizeof(entries[entry_count].display_line),
                    "%s %s", icon, entries[entry_count].file_name_std.c_str());
            
            // Tipo de archivo
            entries[entry_count].type = entry.isDirectory() ? '0' : '1';
            
            entry_count++;
        }
        entry.close();
    }

    // Ordenar estructuras completas
    qsort(entries, entry_count, sizeof(struct FileEntry), compare_entries);

    // Reconstruir todos los elementos en orden
    for(int i = 0; i < entry_count; i++) {
        // Listado visual
        strcat(list, entries[i].display_line);
        strcat(list, "\n");
        
        // Arrays globales
        fileName[i] = entries[i].file_name;
        fileNameStd[i] = entries[i].file_name_std;
        fileType[i] = entries[i].type;
    }
    
    // Eliminar último salto de línea
    if(strlen(list) > 0) list[strlen(list)-1] = '\0';
    
    return list;
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