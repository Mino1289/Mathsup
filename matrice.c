#include <matrice.h>


Matrice createAndInitializeMatrice(int rows, int cols) {
    double** matrice = (double**) malloc(rows * sizeof(double*));
    if (matrice == NULL) {
        fprintf(stderr, "ERROR: Could not allocate memory for matrice.\n");
        Matrice M = {0, 0, NULL};
        return M;
    }
    for (int i = 0; i < rows; i++) {
        matrice[i] = (double*) malloc(cols * sizeof(double));
        if (matrice[i] != NULL) {
            for (int j = 0; j < cols; j++) {
                matrice[i][j] = 0;
            }
        } else {
            fprintf(stderr, "ERROR: Could not allocate memory for matrice[%d]\nFreeing the previous matrice\n", i);
            for (int j = 0; j < i; j++) {
                free(matrice[j]);
            }
            free(matrice);
            Matrice M = {0, 0, NULL};
            return M;
        }
    }
    return (Matrice) {rows, cols, matrice};
}

void fillMatrice(Matrice m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &(m.table[i][j]));
            fflush(stdin);
        }
    }
}

void printMatrice(Matrice m) {
    printf("\n");
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%.2f ", m.table[i][j]);
        }
        printf("\n");
    }
}

Matrice transposeMatrice(Matrice m) {
    Matrice newMatrice = createAndInitializeMatrice(m.cols, m.rows);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            newMatrice.table[j][i] = m.table[i][j];
        }
    }
    return newMatrice;
}

Matrice addMatrice(Matrice m1, Matrice m2) {
    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        fprintf(stderr, "ERROR: The Matrices should have the same dimension.\n");
        return (Matrice){0, 0, NULL};
    }
    Matrice newMatrice = createAndInitializeMatrice(m1.rows, m1.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            newMatrice.table[i][j] = m1.table[i][j] + m2.table[i][j];
        }
    }
    return newMatrice;
}

Matrice subMatrice(Matrice m1, Matrice m2) {
    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        fprintf(stderr,"ERROR: The Matrices should have the same dimension.\n");
        return (Matrice){0, 0, NULL};
    }
    Matrice newMatrice = createAndInitializeMatrice(m1.rows, m1.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            newMatrice.table[i][j] = m1.table[i][j] - m2.table[i][j];
        }
    }
    return newMatrice;
}

Matrice multMatrice(Matrice m1, Matrice m2) {
    if (m1.cols != m2.rows) {
        fprintf(stderr,"ERROR : The first Matrice should have the same number of columns as the seconde Matrice has rows.\n");
        return (Matrice){0, 0, NULL};
    }
    Matrice newMatrice = createAndInitializeMatrice(m1.rows, m2.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            for (int k = 0; k < m1.cols; k++) {
                newMatrice.table[i][j] += m1.table[i][k] * m2.table[k][j];
            }
        }
    }
    return newMatrice;
}

Matrice copyMatrice(Matrice m) {
    Matrice newMatrice = createAndInitializeMatrice(m.rows, m.cols);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            newMatrice.table[i][j] = m.table[i][j];
        }
    }
    return newMatrice;
}

void freeMatrice(Matrice* m) {
    if (m->table != NULL) {
        for (int i = 0; i < m->rows; i++) {
            if (m->table[i] != NULL) {
                free(m->table[i]);
            }
        }
        free(m->table);
    }
    m->table = NULL;
}