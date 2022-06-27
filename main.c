#include <polynomes.h>
#include <complexe.h>
#include <matricesquare.h>


int main(void) {
    Matrice M = createAndInitializeMatrice(3, 3);
    M.table[0][0] = (Complexe) {1, 0};
    M.table[0][1] = (Complexe) {1, -4};
    M.table[0][2] = (Complexe) {3, 0};
    M.table[1][0] = (Complexe) {1, 0};
    M.table[1][1] = (Complexe) {3, 0};
    M.table[1][2] = (Complexe) {3, 0};
    M.table[2][0] = (Complexe) {2, 0};
    M.table[2][1] = (Complexe) {4, 1};
    M.table[2][2] = (Complexe) {4, -1};

    printMatrice(M);
    // Matrice M2 = invertMatrice(M);
    // printMatrice(M2);

    // freeMatrice(&M);
    // freeMatrice(&M2);

    //gcd(x^4-3*x^2+2, x^3+x^2) = x+1

    Polynome p = (Polynome){5, (Monome*) malloc(5 * sizeof(Monome))};
    p.monomes[0] = (Monome){(Complexe) {0, 1}, 4};
    p.monomes[1] = (Monome){(Complexe) {1, 0}, 3};
    p.monomes[2] = (Monome){(Complexe) {-3, 0}, 2};
    p.monomes[3] = (Monome){(Complexe) {2, -5}, 1};
    p.monomes[4] = (Monome){(Complexe) {2, 0}, 0};
    
    printPolynome(p);
    Matrice B = evaluatePolynomeMatrice(p, M);
    Matrice A = multMatrice(M, B);
    printMatrice(B);
    printf("\n");
    printMatrice(A);
    freePolynome(&p);


    printf("\nHello, World!\n");

    return EXIT_SUCCESS;
}