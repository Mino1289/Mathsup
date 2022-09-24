#include <polynomes.h>

void printMonome(Monome m, Boolean first) {
    if (first) {
        printComplexe(m.coeff, !first, True, True);
    } else {
        if (m.coeff.real > 0) {
            printf(" + ");
        } else {
            printf(" - ");
        }
        printComplexe(m.coeff, (m.coeff.real != 0 && m.coeff.imag != 0), True, False);
    }
    if (m.degre != 0) {
        printf("*%c", INDETERMINATE);
    }
    if (m.degre > 1) {
        printf("^%d", m.degre);
    }
}

void printPolynome(Polynome p) {
    FOR(p.nbMonomes) {
        printMonome(p.monomes[i], i==0);
    }
    printf("\n");
}

void freePolynome(Polynome *p) {
    free(p->monomes);
    *p = (Polynome){0, NULL};
}

void simplifyPolynome(Polynome *p) {
    reorderPolynome(p, True);
    //merge the monome with the same degree
    int newNbMonomes = p->nbMonomes;
    FOR(i, p->nbMonomes) {
        FOR(j, i+1, p->nbMonomes) {
            if (p->monomes[i].degre == p->monomes[j].degre) {
                p->monomes[i].coeff = addComplexe(p->monomes[i].coeff, p->monomes[j].coeff);
                p->monomes[j].coeff.real = 0;
                p->monomes[j].coeff.imag = 0;
                newNbMonomes--;
            }
        }
    }
    p->nbMonomes = newNbMonomes;
    p->monomes = realloc(p->monomes, newNbMonomes * sizeof(Monome));

    //remove the monome with a coeff of 0
    FOR(i, p->nbMonomes) {
        if (p->monomes[i].coeff.real == 0 && p->monomes[i].coeff.imag == 0) {
            FOR(j, i, p->nbMonomes-1) {
                p->monomes[j] = p->monomes[j + 1];
            }
            p->nbMonomes--;
            i--;
        }
    }
    p->monomes = realloc(p->monomes, p->nbMonomes * sizeof(Monome));
    //remove the monome with a negative degree
    FOR(i, p->nbMonomes) {
        if (p->monomes[i].degre < 0) {
            FOR(j, i, p->nbMonomes-1) {
                p->monomes[j] = p->monomes[j + 1];
            }
            p->nbMonomes--;
            i--;
        }
    }
    p->monomes = realloc(p->monomes, p->nbMonomes * sizeof(Monome));
}


void reorderPolynome(Polynome *p, Boolean reverse) {
    Boolean weswap;
    int loop = 0;
    do {
        weswap = False;
        FOR(i, p->nbMonomes - 1 - loop) {
            if (reverse ? p->monomes[i].degre > p->monomes[i + 1].degre : p->monomes[i].degre < p->monomes[i + 1].degre) {
                SWAPI(p->monomes, i, i + 1, Monome);
                weswap = True;
            }
        }
        loop++;
    } while (weswap);
}

Polynome copyPolynome(Polynome p) {
    Polynome newP = {p.nbMonomes, NULL};
    newP.monomes = malloc(newP.nbMonomes * sizeof(Monome));
    FOR(p.nbMonomes) {
        newP.monomes[i] = p.monomes[i];
    }
    return newP;
}

Polynome addPolynomes(Polynome p1, Polynome p2) {
    int size = p1.nbMonomes + p2.nbMonomes;
    Monome *monomes = (Monome*) malloc(size * sizeof(Monome));
    int i = 0;
    FOR(j, p1.nbMonomes) {
        monomes[i] = p1.monomes[j];
        i++;
    }
    FOR(j, p2.nbMonomes) {
        monomes[i] = p2.monomes[j];
        i++;
    }
    Polynome p = {size, monomes};
    simplifyPolynome(&p);
    return p;
}

Polynome subPolynomes(Polynome p1, Polynome p2) {
    int size = p1.nbMonomes + p2.nbMonomes;
    Monome *monomes = (Monome*) malloc(size * sizeof(Monome));
    int i = 0;
    FOR(j, p1.nbMonomes) {
        monomes[i] = p1.monomes[j];
        i++;
    }
    FOR(j, p2.nbMonomes) {
        monomes[i] = p2.monomes[j];
        monomes[i].coeff = multComplexebyScalar(monomes[i].coeff, -1);
        i++;
    }
    Polynome p = {size, monomes};
    simplifyPolynome(&p);
    return p;
}

Polynome multPolynomebyScalar(Polynome p, Complexe z) {
    Polynome t = copyPolynome(p);
    FOR(t.nbMonomes) {
        t.monomes[i].coeff = multComplexebyComplexe(t.monomes[i].coeff, z);
    }
    simplifyPolynome(&t);
    return t;
}

Polynome multPolynomebyMonome(Polynome p, Monome m) {
    Polynome t;
    t.nbMonomes = p.nbMonomes;
    t.monomes = (Monome*) malloc(t.nbMonomes * sizeof(Monome));
    FOR(i, t.nbMonomes) {
        t.monomes[i] = p.monomes[i];
    }

    FOR(j, t.nbMonomes) {
        t.monomes[j].coeff = multComplexebyComplexe(t.monomes[j].coeff, m.coeff);
        t.monomes[j].degre += m.degre;
    }
    simplifyPolynome(&t);
    return t;
}

Polynome multPolynomebyPolynome(Polynome p1, Polynome p2) {
    int size = p1.nbMonomes * p2.nbMonomes;
    Monome* monomes = (Monome*) malloc(size * sizeof(Monome));
    int i = 0;
    FOR(j, p1.nbMonomes) {
        FOR(k, p2.nbMonomes) {
            monomes[i] = p1.monomes[j];
            monomes[i].coeff = multComplexebyComplexe(monomes[i].coeff, p2.monomes[k].coeff);
            monomes[i].degre += p2.monomes[k].degre;
            i++;
        }
    }
    Polynome p = (Polynome) {size, monomes};
    simplifyPolynome(&p);
    return p;
}

Monome divMonomebyMonome(Monome m1, Monome m2) {
    Monome m;
    m.coeff = divComplexebyComplexe(m1.coeff, m2.coeff);
    m.degre = m1.degre - m2.degre;
    return m;
}


void divPolynomebyPolynome(Polynome p1, Polynome p2, Polynome *q, Polynome *r) {
    reorderPolynome(&p1, False);
    reorderPolynome(&p2, False);
    
    Monome m = p2.monomes[0];
    Polynome rst = copyPolynome(p1);

    int size = p2.nbMonomes;
    Monome *monomes = (Monome*) malloc(size * sizeof(Monome)); // will go to q
    
    FOR(size) {
        monomes[i] = divMonomebyMonome(rst.monomes[0], m);
        rst = subPolynomes(rst, multPolynomebyMonome(p2, monomes[i]));
        simplifyPolynome(&rst);
        reorderPolynome(&rst, False);
    }

    q->nbMonomes = size;
    q->monomes = monomes;

    simplifyPolynome(q);
    reorderPolynome(q, False);

    simplifyPolynome(&rst);
    reorderPolynome(&rst, False);

    *r = rst;
}

Polynome gcdPolynome(Polynome p1, Polynome p2) {
    Polynome m = copyPolynome(p1), n = copyPolynome(p2);
    Polynome r,q;
    while (n.nbMonomes != 0) {
        divPolynomebyPolynome(m, n, &q, &r);
        freePolynome(&m);
        m = copyPolynome(n);
        freePolynome(&n);
        n = copyPolynome(r);
    }
    freePolynome(&q);
    freePolynome(&r);
    freePolynome(&n);
    return m;
}

Polynome derivePolynome(Polynome *p) {
    int size = p->nbMonomes;
    FOR(size) {
        p->monomes[i].coeff = multComplexebyScalar(p->monomes[i].coeff, (double) p->monomes[i].degre);
        if (p->monomes[i].degre > 0) {
            p->monomes[i].degre--;
        }
    }
    simplifyPolynome(p);
    return *p;
}

int degrePolynome(Polynome p) {
    int degre = -1;
    FOR(p.nbMonomes) {
        if (p.monomes[i].degre > degre) {
            degre = p.monomes[i].degre;
        }
    }
    return degre;
}

Complexe evaluatePolynomeComplex(Polynome p, Complexe z) {
    Complexe result = {0, 0};
    FOR(p.nbMonomes) {
        result = addComplexe(result, multComplexebyComplexe(p.monomes[i].coeff, powerComplexe(z, p.monomes[i].degre)));
    }
    return result;
}

Matrice evaluatePolynomeMatrice(Polynome p, Matrice m) {
    if (m.rows != m.cols) {
        fprintf(stderr, "ERROR: Cannot evaluate a polynome on a non-square matrix\n");
        return m;
    }
    Matrice result = createAndInitializeMatrice(m.rows, m.cols);
    FOR(m.rows) {
        result = addMatrice(result, multMatricebyComplex(powerMatrice(m, p.monomes[i].degre), p.monomes[i].coeff));
    }
    return result;
}