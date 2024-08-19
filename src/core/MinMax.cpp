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
  double PERIOD, CH1, CH2, CH3, CH4;
  if (sscanf(line, "%lf %lf %lf %lf", &PERIOD, &CH1, &CH2, &CH3))
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
  }
}

void readMinMax()
{
  openSD();

  while (dataFile.available())
  {
    int bytesRead = dataFile.readBytesUntil('\n', readBuffer.ACTUAL_BUF, READ_BUF_SIZE - 1);
    readBuffer.ACTUAL_BUF[bytesRead] = '\0';
    processMinMax(readBuffer.ACTUAL_BUF);
  }

  dataFile.close();
}