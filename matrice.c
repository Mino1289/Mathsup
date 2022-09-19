#include <matrice.h>


Matrice createAndInitializeMatrice(int rows, int cols) {
    Complexe** matrice = (Complexe**) malloc(rows * sizeof(Complexe*));
    if (matrice == NULL) {
        fprintf(stderr, "ERROR: Could not allocate memory for matrice.\n");
        Matrice M = {0, 0, NULL};
        return M;
    }
    FOR(i,rows) {
        matrice[i] = (Complexe*) malloc(cols * sizeof(Complexe));
        if (matrice[i] != NULL) {
            FOR(j, cols) {
                matrice[i][j] = (Complexe) {0, 0};
            }
        } else {
            fprintf(stderr, "ERROR: Could not allocate memory for matrice[%d]\nFreeing the previous matrice\n", i);
            FOR(j, i) {
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
    FOR(i, m.rows) {
        FOR(j, m.cols) {
            printf("A[%d][%d] = ", i, j);
            fillComplexe(&m.table[i][j]);
        }
    }
}

void printMatrice(Matrice m) {
    printf("\n");
    FOR(i, m.rows) {
        FOR(j, m.cols) {
            printComplexe(m.table[i][j], False, False, True);
            printf("\t");
        }
        printf("\n");
    }
    printf("\n");
}

Matrice transposeMatrice(Matrice m) {
    Matrice newMatrice = createAndInitializeMatrice(m.cols, m.rows);
    FOR(i, m.rows) {
        FOR(j, m.cols) {
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
    FOR(i, m1.rows) {
        FOR(j, m1.cols) {
            newMatrice.table[i][j] = addComplexe(m1.table[i][j], m2.table[i][j]);
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
    FOR(i, m1.rows) {
        FOR(j, m1.cols) {
            newMatrice.table[i][j] = subComplexe(m1.table[i][j], m2.table[i][j]);
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
    FOR(i, m1.rows) {
        FOR(j, m2.cols) {
            FOR(k, m1.cols) {
                newMatrice.table[i][j] = addComplexe(newMatrice.table[i][j], multComplexebyComplexe(m1.table[i][k], m2.table[k][j]));
            }
        }
    }
    return newMatrice;
}

Matrice multMatricebyScalar(Matrice m, double scalar) {
    FOR(i, m.rows) {
        FOR(j, m.cols) {
            m.table[i][j] = multComplexebyScalar(m.table[i][j], scalar);
        }
    }
    return m;
}

Matrice multMatricebyComplex(Matrice m, Complexe z) {
    FOR(i, m.rows) {
        FOR(j, m.cols) {
            m.table[i][j] = multComplexebyComplexe(m.table[i][j], z);
        }
    }
    return m;
}

Matrice copyMatrice(Matrice m) {
    Matrice newMatrice = createAndInitializeMatrice(m.rows, m.cols);
    FOR(i, m.rows) {
        FOR(j, m.cols) {
            newMatrice.table[i][j] = m.table[i][j];
        }
    }
    return newMatrice;
}

void freeMatrice(Matrice* m) {
    if (m->table != NULL) {
        FOR(i, m->rows) {
            if (m->table[i] != NULL) {
                free(m->table[i]);
            }
        }
        free(m->table);
    }
    m->table = NULL;
}