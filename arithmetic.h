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

/**
 * @brief Calculate the greatest common divisor of two numbers.
 * Using the Euclidean algorithm.
 * 
 * @param a int - The first number
 * @param b int - The second number
 * @return int - The greatest common divisor of a and b
 */
int gcd(int a, int b);

/**
 * @brief Calculate the least common multiple of two numbers.
 * 
 * @param a int - The first number
 * @param b int - The second number
 * @return int - The least common multiple of a and b
 */
int lcm(int a, int b);

/**
 * @brief Calculate the modular inverse of a number.
 * Calculate b such as b*a = 1 mod n
 * 
 * @param a int - The number to calculate the inverse of
 * @param n int - The modulo
 * @return int - The inverse of a mod n
 */
int imod(int a, int n);

#endif