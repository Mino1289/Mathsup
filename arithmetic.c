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

int gcd(int a, int b) {
    int m = a, n = b;
    int r;
    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int lcm(int a, int b) {
    return a * b / pgcd(a, b);
}

int imod(int a, int n) {
    int x0 = 0;
    int x1 = 1;
    int y0 = 1;
    int y1 = 0;
    int q, tempx, tempy, c;
    int b = n;
    if (gcd(a, n) != 1) {
        return 0;
    }
    do {
        c = a;
        q = (b - (b % a)) / a;
        a = b % a;
        b = c;

        tempy = y0;
        y0 = y1;
        y1 = tempy - q * y1;

        tempx = x0;
        x0 = x1;
        x1 = tempx - q * x1;
    } while (a != 0);

    int result = x0 % n; // take the result and could be negative, so we add n and it should be positive.
    if (result < 0) {
        return result + n;
    }
    return result;
}