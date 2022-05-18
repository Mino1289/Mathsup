#ifndef COMPLEX_H
#define COMPLEX_H

#include <lib.h>

/**
 * @brief Complexe structure,
 * contains a real and an imaginary part. 
 * 
 * @param real double - Real part of the complexe.
 * @param imag double - Imaginary part of the complexe.
 */
typedef struct Complexe {
    double real;
    double imag;
} Complexe;

void printComplexe(Complexe z);

Complexe addComplexe(Complexe z1, Complexe z2);

Complexe subComplexe(Complexe z1, Complexe z2);

Complexe conjugateComplexe(Complexe z);

double moduleComplexe(Complexe z);

double argumentComplexe(Complexe z);

Complexe multComplexebyScalar(Complexe z, double scalar);

Complexe multComplexebyComplexe(Complexe z1, Complexe z2);

Complexe inverseComplexe(Complexe z);

Complexe divComplexebyComplexe(Complexe z1, Complexe z2);

#endif