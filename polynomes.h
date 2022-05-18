#ifndef POLYNOMES_H
#define POLYNOMES_H

#include <complexe.h>
#include <lib.h>

/**
 * @brief Struct representing a monome,
 * with a coefficient and a degree.
 * 
 * @param coeff Complexe - The coefficient of the monome.
 * @param degre int - The degree of the monome.
 */
typedef struct Monome {
    Complexe coeff;
    int degre;
} Monome;

/**
 * @brief Struct representing a polynome,
 * with a number of monomes and an array of monomes.
 * 
 * @param nbMonomes int - The number of monomes in the polynome.
 * @param monomes Monome* - The array of monomes.
 */
typedef struct Polynome {
    int nbMonomes;
    Monome *monomes;
} Polynome;

typedef enum Boolean {
    False = 0,
    True = 1
} Boolean;

/**
 * @brief Print a Monome.
 * 
 * @param m Monome - The monome to print.
 * @param first Boolean - Change the output to be more readable.
 */
void printMonome(Monome m, Boolean first);

/**
 * @brief Print a Polynome.
 * 
 * @param p Polynome - The polynome to print.
 */
void printPolynome(Polynome p);

/**
 * @brief Free a Polynome.
 * 
 * @param p Polynome* - The polynome to free.
 */
void freePolynome(Polynome *p);

/**
 * @brief Simplify a Polynome.
 * 
 * @param p Polynome* - The polynome to simplify.
 */
void simplifyPolynome(Polynome *p);

/** 
 * @brief Swap the value at the index index1 with the value at the index index2.
 * 
 * @param p Polynome - The polynome to swap the monomes in.
 * @param index1 int - The index of the first value to swap.
 * @param index2 int - The index of the second value to swap.
 */
void swap(Polynome p, int index1, int index2);

/**
 * @brief Implement a bubble sort on the Polynome to sort the monomes by degree.
 * Smallest degree first.
 *  
 * @param p Polynome* - The polynome to order.
 */
void reorderPolynome(Polynome *p);

/**
 * @brief Implement a bubble sort on the Polynome to sort the monomes by degree.
 * Biggest degree first.
 * 
 * @param p Polynome* - The polynome to order.
 */
void inverseorderPolynome(Polynome *p);

/**
 * @brief Copy a Polynome.
 * 
 * @param p Polynome - The polynome to copy.
 * @return Polynome - The copy of the polynome.
 */
Polynome copyPolynome(Polynome p);

/**
 * @brief Add two Polynomes.
 * 
 * @param p1 Polynome - The first polynome to add.
 * @param p2 Polynome - The second polynome to add.
 * @return Polynome The sum of the two Polynomes.
 */
Polynome addPolynomes(Polynome p1, Polynome p2);

/**
 * @brief Substract two Polynomes.
 * 
 * @param p1 Polynome - The first polynome to substract.
 * @param p2 Polynome - The second polynome to substract.
 * @return Polynome The difference of the two Polynomes.
 */
Polynome subPolynomes(Polynome p1, Polynome p2);

/**
 * @brief Multiply a Polynome by a scalar.
 * 
 * @param p Polynome - The polynome to multiply.
 * @param z Complexe - The scalar to multiply the polynome by.
 * @return Polynome The product of the Polynome and the scalar.
 */
Polynome multPolynomebyScalar(Polynome p, Complexe z);

/**
 * @brief Multiply a Polynome by a Monome.
 * 
 * @param p Polynome - The polynome to multiply.
 * @param m Monome - The monome to multiply the polynome by.
 * @return Polynome The product of the Polynome and the Monome. 
 */
Polynome multPolynomebyMonome(Polynome p, Monome m);

/**
 * @brief Multiply two Polynomes.
 * 
 * @param p1 Polynome - The first polynome to multiply.
 * @param p2 Polynome - The second polynome to multiply.
 * @return Polynome The product of the two Polynomes.
 */
Polynome multPolynomebyPolynome(Polynome p1, Polynome p2);

/**
 * @brief Divide a monome by a monome.
 * 
 * @param m1 Monome - The first monome, the numerator.
 * @param m2 Monome - The second monome, the denominator.
 * @return Monome - The quotient of the two monomes.
 */
Monome divMonomebyMonome(Monome m1, Monome m2);

/**
 * @brief Euclidean division of two Polynomes. 
 * Compute q and r such as p1 = q * p2 + r.
 * 
 * @param p1 Polynome - The first polynome. 
 * @param p2 Polynome - The second polynome.
 * @param q Polynome* - The quotient.
 * @param r Polynome* - The rest.
 */
void divPolynomebyPolynome(Polynome p1, Polynome p2, Polynome *q, Polynome *r);

/**
 * @brief Derive a Polynome.
 * 
 * @param p Polynome - The polynome to derive.
 * @return Polynome - The polynome's derivative.
 */
Polynome derivePolynome(Polynome *p);

/**
 * @brief Degree of a Polynome.
 * 
 * @param p Polynome - The polynome to compute the degree of.
 * @return int - The degree of the polynome.
 */
int degrePolynome(Polynome p);

/**
 * @brief Evaluate the polynome at a complex number.
 * 
 * @param p Polynome - The polynome to evaluate.
 * @param z Complex - The complex number to evaluate the polynome at.
 * @return Complexe - The result of the evaluation?
 */
Complexe evaluatePolynome(Polynome p, Complexe z);

#endif