#include <polynomes.h>
#include <complexe.h>
#include <matricesquare.h>
// #include <mparser.h>


int main(void) {
    // Matrice M = createAndInitializeMatrice(3, 3);
    // M.table[0][0] = 1;
    // M.table[0][1] = 1;
    // M.table[0][2] = 3;
    // M.table[1][0] = 1;
    // M.table[1][1] = 3;
    // M.table[1][2] = -3;
    // M.table[2][0] = -2;
    // M.table[2][1] = -4;
    // M.table[2][2] = -4;

    // printMatrice(M);
    // Matrice M2 = invertMatrice(M);
    // printMatrice(M2);

    // freeMatrice(&M);
    // freeMatrice(&M2);

    //gcd(x^4-3*x^2+2, x^3+x^2) = x+1

    Polynome p = (Polynome){3, (Monome*) malloc(3 * sizeof(Monome))};
    p.monomes[0] = (Monome){(Complexe) {1, 0}, 4};
    p.monomes[1] = (Monome){(Complexe) {-3, 0}, 2};
    p.monomes[2] = (Monome){(Complexe) {2, 0}, 0};

    Polynome q = (Polynome){2, (Monome*) malloc(2 * sizeof(Monome))};
    q.monomes[0] = (Monome){(Complexe) {1, 0}, 3};
    q.monomes[1] = (Monome){(Complexe) {1, 0}, 2};

    Polynome gcd = gcdPolynome(p, q);
    printPolynome(p);
    printPolynome(q);
    printPolynome(gcd);

    freePolynome(&p);
    freePolynome(&q);
    freePolynome(&gcd);

    // Complexe z =  {1.0 ,  2.0};
    
    // printComplexe(z, True);


    printf("\nHello, World!\n");

    return EXIT_SUCCESS;
}