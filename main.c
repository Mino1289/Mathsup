#include <lib.h>
#include <polynomes.h>


int main(void) {
    Polynome p1 = {5, NULL};
    p1.monomes = malloc(p1.nbMonomes * sizeof(Monome));
    p1.monomes[0] = (Monome){(Complexe){1, 0}, 5};
    p1.monomes[1] = (Monome){(Complexe){-1, 0}, 4};
    p1.monomes[2] = (Monome){(Complexe){-1, 0}, 3};
    p1.monomes[3] = (Monome){(Complexe){3, 0}, 2};
    p1.monomes[4] = (Monome){(Complexe){-2, 0}, 1};

    Polynome p2 = {3, NULL};
    p2.monomes = malloc(p2.nbMonomes * sizeof(Monome));
    p2.monomes[0] = (Monome){(Complexe){1, 0}, 0};
    p2.monomes[1] = (Monome){(Complexe){-1, 0}, 1};
    p2.monomes[2] = (Monome){(Complexe){1, 0}, 2};



    Polynome q,r;
    divPolynomebyPolynome(p1, p2, &q, &r);
    printf("\n\n");
    printPolynome(q);
    printPolynome(r);

    freePolynome(&q);
    freePolynome(&r);

    freePolynome(&p2);
    freePolynome(&p1);

    return EXIT_SUCCESS;
}