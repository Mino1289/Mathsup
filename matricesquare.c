#include <matricesquare.h>

Matrice eye(int order) {
    Matrice m = createAndInitializeMatrice(order, order);
    FOR(order) {
        m.table[i][i] = (Complexe) {1, 0};
    }
    return m;
}

Matrice invertMatrice(Matrice m) {
    Matrice a = createAndInitializeMatrice(m.cols, m.cols*2);
    Complexe ratio;
    int size = m.cols;

    FOR(i, size) {
        FOR(j, size) {
            a.table[i][j] = m.table[i][j];
        }
    }

    /* Augmenting Identity Matrix of Order size */
    FOR(i, size) {
        FOR(j, size) {
            if (i == j) {
                a.table[i][j + size] = (Complexe) {1, 0};
            } else {
                a.table[i][j + size] = (Complexe) {0, 0};
            }
        }
    }

    /* Applying Gauss Jordan Elimination */
    FOR(i, size) {
        if (a.table[i][i].real == 0.0 && a.table[i][i].imag == 0.0) {
            fprintf(stderr, "ERROR: Mathematical Error %d!", i);
            exit(0);
        }
        FOR(j, size) {
            if (i != j) {
                ratio = divComplexebyComplexe(a.table[j][i], a.table[i][i]);
                FOR(k, 2 * size) {
                    a.table[j][k] = subComplexe(a.table[j][k], multComplexebyComplexe(ratio, a.table[i][k]));
                }
            }
        }
    }
    /* Row Operation to Make Principal Diagonal to 1 */
    FOR(i, size) {
        FOR(j, 2 * size) {
            a.table[i][j] = divComplexebyComplexe(a.table[i][j], a.table[i][i]);
        }
    }
    Matrice B = createAndInitializeMatrice(size, size);
    FOR(i, size) {
        FOR(j, size) {
            B.table[i][j] = a.table[i][j + size];
        }
    }
    freeMatrice(&a);
    return B;
}

Matrice powerMatrice(Matrice m, int n) {
    if (n == 0) {
        Matrice I = eye(m.cols);
        return I;
    }
    Matrice a = copyMatrice(m);
    
    if (n == 1) {
        return a;
    }

    int nbf;
    int* f = factor(abs(n), &nbf);
    
    if (n < 0) {
        a = invertMatrice(a);
    }
    FOR(nbf) {
        Matrice b = copyMatrice(a);
        FOR(j, f[i] - 1) {
            a = multMatrice(a, b);
        }
        freeMatrice(&b);
    }
    return a;
}

Complexe traceMatrice(Matrice m) {
    Complexe trace = (Complexe) {0, 0};
    FOR(m.cols) {
        trace = addComplexe(trace, m.table[i][i]);
    }
    return trace;
}