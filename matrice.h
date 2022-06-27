#ifndef __MATRICE_H__
#define __MATRICE_H__

#include <stdio.h>
#include <stdlib.h>
#include <complexe.h>

/**
 * @brief A struct representing a matrix.
 * 
 * @param rows The number of rows.
 * @param cols The number of columns.
 * @param table The table of complexes. 
 */
typedef struct Matrice {
    int rows;
    int cols;
    Complexe** table;
} Matrice;

/**
 * @brief Create a Matrice object
 * 
 * @param rows int - number of rows
 * @param cols int - number of columns
 * @return Matrice - the Matrice object
 */
Matrice createAndInitializeMatrice(int rows, int cols);

/**
 * @brief Fill a Matrice object with user input
 * 
 * @param m Matrice - the Matrice object
 */
void fillMatrice(Matrice m);

/**
 * @brief Print a Matrice object to stdin
 * 
 * @param m Matrice - the Matrice object
 */
void printMatrice(Matrice m);

/**
 * @brief Transpose a Matrice object
 * 
 * @param m Matrice - the Matrice object
 * @return Matriice - the transposed Matrice object
 */
Matrice transposeMatrice(Matrice m);

/**
 * @brief Add two Matrice objects
 * 
 * @param m1 Matrice - the first Matrice object
 * @param m2 Matrice - the second Matrice object 
 * @return Matrice - The sum of the two matrices
 */
Matrice addMatrice(Matrice m1, Matrice m2);

/**
 * @brief Substract two Matrice objects
 * 
 * @param m1 Matrice - the first Matrice object
 * @param m2 Matrice - the second Matrice object 
 * @return Matrice - The substraction of the two matrices
 */
Matrice subMatrice(Matrice m1, Matrice m2);

/**
 * @brief Multiply two Matrice objects
 * 
 * @param m1 Matrice - the first Matrice object
 * @param m2 Matrice - the second Matrice object 
 * @return Matrice - The multiplication of the two matrices
 */
Matrice multMatrice(Matrice m1, Matrice m2);

/**
 * @brief Multiply a Matrice object by a scalar
 * 
 * @param m Matrice - the Matrice object
 * @param scalar double - the scalar
 * @return Matrice product of the matrice and the scalar.
 */
Matrice multMatricebyScalar(Matrice m, double scalar);

/**
 * @brief Multiply a Matrice object by a Complex
 * 
 * @param m Matrice - the Matrice object
 * @param z Complexe - the Complexe
 * @return Matrice The product of the matrice and the complex.
 */
Matrice multMatricebyComplex(Matrice m, Complexe z);

/**
 * @brief Copy a Matrice object into another one (who will be initialized).
 * 
 * @param m Matrice - the Matrice object to copy
 * @return Matrice - Matrice object
 */
Matrice copyMatrice(Matrice m);

/**
 * @brief Free a Matrice object.
 * 
 * @param m Matrice* - pointer to the Matrice object to free.
 */
void freeMatrice(Matrice* m);

#endif