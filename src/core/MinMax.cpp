#include <MinMax.h>

double minCH1, maxCH1;
double minCH2, maxCH2;
double minCH3, maxCH3;
double minCH4, maxCH4;


uint16_t mapDouble(double x, double in_min, double in_max, uint16_t out_min, uint16_t out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void processMinMax(const char *line)
{
  double PERIOD = 0;
  double CH1 = 0;
  double CH2 = 0;
  double CH3 = 0;
  double CH4 = 0;

  if (sscanf(line, "%lf %lf %lf %lf %lf", &PERIOD, &CH1, &CH2, &CH3, &CH4))
  {
    if (CH1 < minCH1)
      minCH1 = CH1;
    if (CH1 > maxCH1)
      maxCH1 = CH1;
    if (CH2 < minCH2)
      minCH2 = CH2;
    if (CH2 > maxCH2)
      maxCH2 = CH2;
    if (CH3 < minCH3)
      minCH3 = CH3;
    if (CH3 > maxCH3)
      maxCH3 = CH3;
    if (CH4 < minCH4)
      minCH4 = CH4;
    if (CH4 > maxCH4)
      maxCH4 = CH4;
  }
}

void readMinMax()
{
  openFileRead();

  const int bufferSize = 128;
  char buffer[bufferSize];

  String currentLine = "";
  String lastLine = "";
  String secondLastLine = "";

  bool minMaxFound = false;

  // Posicionarse al final del archivo
  SD_Root.seek(SD_Root.size());

  // Leer las últimas líneas desde el final hacia el inicio
  while (SD_Root.position() > 0 && (!minMaxFound && secondLastLine.isEmpty()))
  {
    size_t chunkSize = min((size_t)SD_Root.position(), (size_t)bufferSize);
    SD_Root.seek(SD_Root.position() - chunkSize); // Retroceder el tamaño del bloque
    SD_Root.readBytes(buffer, chunkSize);
 
    for (int i = chunkSize - 1; i >= 0; i--)
    { // Leer caracteres en orden inverso
      if (buffer[i] == '\n' || buffer[i] == '\r')
      { // Detectar fin de línea
        if (currentLine.length() > 0)
        {
          // Procesar la línea completa
          if (lastLine.isEmpty())
          {
            lastLine = currentLine; // Guardar como la última línea
          }
          else if (secondLastLine.isEmpty())
          {
            secondLastLine = currentLine; // Guardar como la penúltima línea

            // Verificar las dos últimas líneas
            if (secondLastLine.startsWith("MIN") && lastLine.startsWith("MAX"))
            {
              sscanf(secondLastLine.c_str(), "MIN %lf %lf %lf %lf", &minCH1, &minCH2, &minCH3, &minCH4);
              sscanf(lastLine.c_str(), "MAX %lf %lf %lf %lf", &maxCH1, &maxCH2, &maxCH3, &maxCH4);
              minMaxFound = true;
              break;
            }
          }

          currentLine = ""; // Reiniciar para la siguiente línea
        }
      }
      else
      {
        currentLine = String(buffer[i]) + currentLine; // Construir línea en orden inverso
      }
      vTaskDelay(1);
    }

    SD_Root.seek(SD_Root.position() - chunkSize); // Mover el puntero de lectura
    vTaskDelay(1);
  }

  if (!minMaxFound)
  {
    Serial.println("No MinMax Encontrado, escribiendo...");
    // Si no se encontraron MIN y MAX, procesar todo el archivo
    noMinMaxWritten();

    // Escribir los valores MIN y MAX encontrados
    writeMinMax();
  }

  SD_Root.seek(0);
  SD_Root.close();
}

void noMinMaxWritten()
{
  SD_Root.seek(0); // Reiniciar al inicio del archivo

  while (SD_Root.available())
  {
    int bytesRead = SD_Root.readBytesUntil('\n', readBuffer.ACTUAL_BUF, READ_BUF_SIZE - 1);
    readBuffer.ACTUAL_BUF[bytesRead] = '\0';
    processMinMax(readBuffer.ACTUAL_BUF); // Procesar cada línea para encontrar valores MIN y MAX
    vTaskDelay(1);
  }
}

void writeMinMax()
{
  SD_Root.close();
  openFileWrite();

  SD_Root.seek(SD_Root.size()); // Posicionarse al final del archivo

  SD_Root.println("");
  SD_Root.print("----- SIGNAL DETAILS ----- \n");
  SD_Root.println("");
  SD_Root.printf("MIN %lf %lf %lf %lf \n", minCH1, minCH2, minCH3, minCH4);
  SD_Root.printf("MAX %lf %lf %lf %lf \n", maxCH1, maxCH2, maxCH3, maxCH4);

  SD_Root.seek(0); // Opcional: reposicionarse al inicio
}
