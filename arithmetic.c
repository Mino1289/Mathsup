#include <arithmetic.h>

unsigned long long factorial(int n) {
    if (n < 0) {
        fprintf(stderr, "ERROR: Cannot calculate factorial of a negative number!\n");
        return 0;
    }
    if (n > MAX_FACTORIAL) {
        fprintf(stderr, "ERROR: Factorial is too large!\n");
        return n;
    }
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

Boolean isPrime(int n) {
    if (n < 2) {
        return False;
    }
    if (n == 2) {
        return True;
    }
    if (n % 2 == 0) {
        return False;
    }
    int nmax = sqrt(n)+1;
    for (int i = 3; i < nmax; i += 2) {
        if (n % i == 0) {
            return False;
        }
    }
    return True;
}

int* factor(int n, int *nbf) {
    int* f = malloc(sizeof(int));
    if (n <= 1) {
        fprintf(stderr, "ERROR: Cannot factorize %d!\n", n);
        return f;
    }
    if (isPrime(n)) {
        f[0] = n;
        *nbf = 1;
        return f;
    }
    int i = 2, pos = 0;
    while (i <= n) {
        if (n % i == 0) {
            f = realloc(f, sizeof(int)*(pos+1));
            f[pos] = i;
            pos++;
            n /= i;
        } else {
            i++;
        }
    }
    *nbf = pos;
    return f;
}