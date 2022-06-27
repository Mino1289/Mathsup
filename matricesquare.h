#ifndef __MATRICESQUARE_H__
#define __MATRICESQUARE_H__

#include <matrice.h>
#include <arithmetic.h>

/**
 * @brief Return the Matrice Identity of order.
 * 
 * @param order int - the order of the Identity Matrice.
 * @return Matrice - the Idendity Matrice.
 */
Matrice eye(int order);

/**
 * @brief Invert a Matrice object
 * 
 * @param m Matrice object to invert
 * @return Matrice - the inverted matrice
 */
Matrice invertMatrice(Matrice m);

/**
 * @brief Calculate efficiently the power of a Matrice object
 * 
 * @param m Matrice - The Matrice to power
 * @param n int - The exponent
 * @return Matrice - The result of m^n 
 */
Matrice powerMatrice(Matrice m, int n);

/**
 * @brief Calculate the trace of a Matrice object
 *
 * @param m Matrice - the Matrice object to calculate the trace 
 * @return Complex - the trace of the matrice
 */
Complexe traceMatrice(Matrice m);

#endif