#ifndef MINMAX_H
#define MINMAX_H

#include <Arduino.h>
#include <Core.h>

extern double minCH1, maxCH1;
extern double minCH2, maxCH2;
extern double minCH3, maxCH3;
extern double minCH4, maxCH4;

uint16_t mapDouble(double x, double in_min, double in_max, uint16_t out_min, uint16_t out_max);
void processMinMax(const char *line);
void readMinMax();

#endif 