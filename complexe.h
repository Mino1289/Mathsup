#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define SWAP(a, b, T) { T tmp = a; a = b; b = tmp; }

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

typedef enum Boolean {
    False = 0,
    True = 1
} Boolean;

/**
 * @brief Print a complexe.
 * 
 * @param z Complexe - Complexe to print.
 * @param wparenthesis Boolean - Print the complexe in parenthesis.
 * @param wspace Boolean - Print space in the complexe.
 * @param wfirstsign Boolean - Print the first sign of the complexe.
 */
void printComplexe(Complexe z, Boolean wparenthesis, Boolean wspace, Boolean wfirstsign);


/**
 * @brief Add two complexes.
 * 
 * @param z1 Complexe - First complexe.
 * @param z2 Complexe - Second complexe.
 * @return Complexe - The sum of the two complexes.
 */
Complexe addComplexe(Complexe z1, Complexe z2);

/**
 * @brief Substract two complexes.
 * 
 * @param z1 Complexe - First complexe.
 * @param z2 Complexe - Second complexe.
 * @return Complexe - The substraction of the two complexes.
 */
Complexe subComplexe(Complexe z1, Complexe z2);

/**
 * @brief Get the conjugate of a complexe.
 * (a+b*i) => (a-b*i)
 * 
 * @param z Complexe - Complexe to get the conjugate of.
 * @return Complexe - The conjugate of the complexe.
 */
Complexe conjugateComplexe(Complexe z);

/**
 * @brief Get the module of the complexe.
 *
 * @param z Complexe - Complexe to get the module of. 
 * @return double - The module of the complexe.
 */
double moduleComplexe(Complexe z);

/**
 * @brief Get the argument of the complexe.
 * 
 * @param z Complexe - Complexe to get the argument of.
 * @return double - The argument of the complexe.
 */
double argumentComplexe(Complexe z);

/**
 * @brief Multiply a complexe by a real.
 * 
 * @param z Complexe - Complexe to multiply. 
 * @param scalar double - Real to multiply the complexe by.
 * @return Complexe - The product.
 */
Complexe multComplexebyScalar(Complexe z, double scalar);

/**
 * @brief Multiply two complexes.
 * 
 * @param z1 Complexe - The first complexe.
 * @param z2 Complexe - The second complexe.
 * @return Complexe - The product of the two complexes.
 */
Complexe multComplexebyComplexe(Complexe z1, Complexe z2);

/**
 * @brief Invert a complexe.
 * z => 1/z
 * 
 * @param z Complexe - Complexe to invert. 
 * @return Complexe - The inverse of the complexe.
 */
Complexe inverseComplexe(Complexe z);

/**
 * @brief Divide a complexe by another complexe.
 * 
 * @param z1 Complexe - The first complexe, the numerator.
 * @param z2 Complexe - The second complexe, the denominator.
 * @return Complexe - The quotient of the two complexes.
 */
Complexe divComplexebyComplexe(Complexe z1, Complexe z2);

/**
 * @brief Calculate the power of a complexe.
 * Using the "De Moivre" formula.
 * 
 * @param z Complexe - The complexe to calculate the power of.
 * @param n int - The power.
 * @return Complexe - z^n
 */
Complexe powerComplexe(Complexe z, int n);

#endif