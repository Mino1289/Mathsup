#include <matricesquare.h>

Matrice eye(int order) {
    Matrice m = createAndInitializeMatrice(order, order);
    for (int i = 0; i < order; i++) {
        m.table[i][i] = 1;
    }
    return m;
}

Matrice invertMatrice(Matrice m) {
    Matrice a = createAndInitializeMatrice(m.cols, m.cols*2);
    double ratio;
    int size = m.cols;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            a.table[i][j] = m.table[i][j];
        }
    }

    /* Augmenting Identity Matrix of Order size */
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                a.table[i][j + size] = 1;
            } else {
                a.table[i][j + size] = 0;
            }
        }
    }

    /* Applying Gauss Jordan Elimination */
    for (int i = 0; i < size; i++) {
        if (a.table[i][i] == 0.0) {
            fprintf(stderr, "ERROR: Mathematical Error %d!", i);
            exit(0);
        }
        for (int j = 0; j < size; j++) {
            if (i != j) {
                ratio = a.table[j][i] / a.table[i][i];
                for (int k = 0; k < 2 * size; k++) {
                    a.table[j][k] = a.table[j][k] - ratio * a.table[i][k];
                }
            }
        }
    }
    /* Row Operation to Make Principal Diagonal to 1 */
    for (int i = 0; i < size; i++) {
        for (int j = size; j < 2 * size; j++) {
            a.table[i][j] = a.table[i][j] / a.table[i][i];
        }
    }
    Matrice B = createAndInitializeMatrice(size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
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
        for (int i = 0; i < nbf; i++) {
            Matrice b = copyMatrice(a);
            for (int j = 0; j < f[i]-1; j++) {
                a = multMatrice(a, b);
            }
            freeMatrice(&b);
        }
        return a;
    }
    for (int i = 0; i < nbf; i++) {
        Matrice b = copyMatrice(a);
        for (int j = 0; j < f[i]-1; j++) {
            a = multMatrice(a, b);
        }
        freeMatrice(&b);
    }
    return a;
}

double traceMatrice(Matrice m) {
    double trace = 0;
    for (int i = 0; i < m.cols; i++) {
        trace += m.table[i][i];
    }
    return trace;
}