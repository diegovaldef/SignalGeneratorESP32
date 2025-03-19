#ifndef MINMAX_H
#define MINMAX_H

/*
    Encargado de encontrar el maximo y minimo dato de cada canal en el archivo de texto
*/

#include <Arduino.h>
#include <Core.h>

extern double minCH1, maxCH1; // Valores minimos y maximos del canal 1
extern double minCH2, maxCH2; // Valores minimos y maximos del canal 2
extern double minCH3, maxCH3; // Valores minimos y maximos del canal 3
extern double minCH4, maxCH4; // Valores minimos y maximos del canal 4

extern bool minCH1empty; // Bandera que indica si el valor minimo del canal 1 esta vacio
extern bool minCH2empty; // Bandera que indica si el valor minimo del canal 2 esta vacio 
extern bool minCH3empty; // Bandera que indica si el valor minimo del canal 3 esta vacio
extern bool minCH4empty; // Bandera que indica si el valor minimo del canal 4 esta vacio

// Funcion map con double como entrada y uint16_t como salida
uint16_t mapDouble(double x, double in_min, double in_max, uint16_t out_min, uint16_t out_max); 
void processMinMax(const char *line); // Analiza el valor minimo y maximo de cada canal
void readMinMax(); // Lee el archivo txt en busca del MINMAX
void noMinMaxWritten(); // Funcion que se ejecuta si no esta escrito el MINMAX anteriormente
void writeMinMax(); // Escribe el MINMAX

#endif 