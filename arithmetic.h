#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <polynomes.h>

#define MAX_FACTORIAL 20

/**
 * @brief Calculate the factorial of a number
 * 
 * @param n int - The number to calculate the factorial of (max 20)
 * @return unsigned long long - The factorial of n.
 */
unsigned long long factorial(int n);

/**
 * @brief Check if a number is a prime number.
 * 
 * @param n int - The number to check
 * @return Boolean True if n is a prime number, False otherwise.
 */
Boolean isPrime(int n);

/**
 * @brief Factorize n into prime factors.
 * 
 * @param n int - The number to factorize
 * @param nbf int* - The number of factors of n (by address)
 * @return int* - The array of the nbf factors of n
 */
int* factor(int n, int* nbf);


#endif