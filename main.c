#include <polynomes.h>
#include <complexe.h>
#include <matricesquare.h>


int main(void) {
    Matrice M = createAndInitializeMatrice(3, 3);
    M.table[0][0] = 1;
    M.table[0][1] = 1;
    M.table[0][2] = 3;
    M.table[1][0] = 1;
    M.table[1][1] = 3;
    M.table[1][2] = -3;
    M.table[2][0] = -2;
    M.table[2][1] = -4;
    M.table[2][2] = -4;

    printMatrice(M);
    Matrice M2 = invertMatrice(M);
    printMatrice(M2);

    freeMatrice(&M);
    freeMatrice(&M2);
    return EXIT_SUCCESS;
}