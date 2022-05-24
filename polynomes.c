#include <polynomes.h>

void printMonome(Monome m, Boolean first) {
    if (first) {
        printComplexe(m.coeff, !first);
    } else {
        printf(" + ");
        printComplexe(m.coeff, first);
    }
    if (m.degre != 0) {
        printf("*%c", INDETERMINATE);
    }
    if (m.degre > 1) {
        printf("^%d", m.degre);
    }
}

void printPolynome(Polynome p) {
    for (int i = 0; i < p.nbMonomes; i++) {
        printMonome(p.monomes[i], i==0);
    }
    printf("\n");
}

void freePolynome(Polynome *p) {
    free(p->monomes);
    *p = (Polynome){0, NULL};
}

void simplifyPolynome(Polynome *p) {
    reorderPolynome(p);
    //merge the monome with the same degree
    int newNbMonomes = p->nbMonomes;
    for (int i = 0; i < p->nbMonomes; i++) {
        for (int j = i + 1; j < p->nbMonomes; j++) {
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
    for (int i = 0; i < p->nbMonomes; i++) {
        if (p->monomes[i].coeff.real == 0 && p->monomes[i].coeff.imag == 0) {
            for (int j = i; j < p->nbMonomes - 1; j++) {
                p->monomes[j] = p->monomes[j + 1];
            }
            p->nbMonomes--;
            i--;
        }
    }
    p->monomes = realloc(p->monomes, p->nbMonomes * sizeof(Monome));
}

void swap(Polynome p, int index1, int index2) {
    Monome temp = p.monomes[index1];
    p.monomes[index1] = p.monomes[index2];
    p.monomes[index2] = temp;
}

void reorderPolynome(Polynome *p) {
    Boolean weswap;
    int loop = 0;
    do {
        weswap = False;
        for (int i = 0; i < (p->nbMonomes - 1 - loop); i++) {
            if (p->monomes[i].degre > p->monomes[i + 1].degre) {
                swap(*p, i, i + 1);
                weswap = True;
            }
        }
        loop++;
    } while (weswap);
}

void inverseorderPolynome(Polynome *p) {
    Boolean weswap;
    int loop = 0;
    do {
        weswap = False;
        for (int i = 0; i < (p->nbMonomes - 1 - loop); i++) {
            if (p->monomes[i].degre < p->monomes[i + 1].degre) {
                swap(*p, i, i + 1);
                weswap = True;
            }
        }
        loop++;
    } while (weswap);
}

Polynome copyPolynome(Polynome p) {
    Polynome newP = {p.nbMonomes, NULL};
    newP.monomes = malloc(newP.nbMonomes * sizeof(Monome));
    for (int i = 0; i < p.nbMonomes; i++) {
        newP.monomes[i] = p.monomes[i];
    }
    return newP;
}

Polynome addPolynomes(Polynome p1, Polynome p2) {
    int size = p1.nbMonomes + p2.nbMonomes;
    Monome *monomes = (Monome*) malloc(size * sizeof(Monome));
    int i = 0,j;
    for (j = 0; j < p1.nbMonomes; j++) {
        monomes[i] = p1.monomes[j];
        i++;
    }
    for (j = 0; j < p2.nbMonomes; j++) {
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
    int i = 0,j;
    for (j = 0; j < p1.nbMonomes; j++) {
        monomes[i] = p1.monomes[j];
        i++;
    }
    for (j = 0; j < p2.nbMonomes; j++) {
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
    for (int i = 0; i < t.nbMonomes; i++) {
        t.monomes[i].coeff = multComplexebyComplexe(t.monomes[i].coeff, z);
    }
    simplifyPolynome(&t);
    return t;
}

Polynome multPolynomebyMonome(Polynome p, Monome m) {
    Polynome t;
    t.nbMonomes = p.nbMonomes;
    t.monomes = (Monome*) malloc(t.nbMonomes * sizeof(Monome));
    for (int i = 0; i < p.nbMonomes; i++) {
        t.monomes[i] = p.monomes[i];
    }

    for (int j = 0; j < t.nbMonomes; j++) {
        t.monomes[j].coeff = multComplexebyComplexe(t.monomes[j].coeff, m.coeff);
        t.monomes[j].degre += m.degre;
    }
    simplifyPolynome(&t);
    return t;
}

Polynome multPolynomebyPolynome(Polynome p1, Polynome p2) {
    int size = p1.nbMonomes * p2.nbMonomes;
    Monome* monomes = (Monome*) malloc(size * sizeof(Monome));
    int i = 0,j,k;
    for (j = 0; j < p1.nbMonomes; j++) {
        for (k = 0; k < p2.nbMonomes; k++) {
            monomes[i] = p1.monomes[j];
            monomes[i].coeff = multComplexebyComplexe(monomes[i].coeff, p2.monomes[k].coeff);
            monomes[i].degre += p2.monomes[k].degre;
            i++;
        }
    }
    Polynome p = {size, monomes};
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
    inverseorderPolynome(&p1);
    inverseorderPolynome(&p2);
    
    Monome m = p2.monomes[0];
    Polynome rst = copyPolynome(p1);

    int size = p2.nbMonomes;
    Monome *monomes = (Monome*) malloc(size * sizeof(Monome)); // will go to q
    
    for (int i = 0; i < p2.nbMonomes; i++) {
        monomes[i] = divMonomebyMonome(rst.monomes[0], m);
        rst = subPolynomes(rst, multPolynomebyMonome(p2, monomes[i]));
        simplifyPolynome(&rst);
        inverseorderPolynome(&rst);
    }

    q->nbMonomes = size;
    q->monomes = monomes;

    simplifyPolynome(q);
    inverseorderPolynome(q);

    simplifyPolynome(&rst);
    inverseorderPolynome(&rst);

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
    for (int i = 0; i < size; i++) {
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
    for (int i = 0; i < p.nbMonomes; i++) {
        if (p.monomes[i].degre > degre) {
            degre = p.monomes[i].degre;
        }
    }
    return degre;
}

Complexe evaluatePolynome(Polynome p, Complexe z) {
    Complexe result = {0, 0};
    for (int i = 0; i < p.nbMonomes; i++) {
        result = addComplexe(result, multComplexebyComplexe(p.monomes[i].coeff, powerComplexe(z, p.monomes[i].degre)));
    }
    return result;
}