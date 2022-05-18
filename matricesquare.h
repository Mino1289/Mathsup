#ifndef __MATRICESQUARE_H__
#define __MATRICESQUARE_H__

#include <matrice.h>

/**
 * @brief Invert a Matrice object
 * 
 * @param m Matrice object to invert
 * @return Matrice - the inverted matrice
 */
Matrice invertMatrice(Matrice m);

/**
 * @brief Calculate the trace of a Matrice object
 *
 * @param m Matrice - the Matrice object to calculate the trace 
 * @return double - the trace of the matrice
 */
double traceMatrice(Matrice m);

#endif