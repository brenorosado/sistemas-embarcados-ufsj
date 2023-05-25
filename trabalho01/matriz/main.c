#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "matriz.h"

int main() {
    int C = 3, L = 3, r;
    struct matriz *m1;

    m1 = aloca_matriz(C, L);

    if(m1 == NULL) {
        printf("\nFalha na alocacao da matriz");
        return -1;
    }

    r = preenche_matriz_aleatoria(m1, 10000.00);

    if(r != 0) {
        printf("\nFalha ao preencher aleatoriamente a matriz");
        desaloca_matriz(m1);
        return -1;
    }

    mostra_matriz(m1);

    checksum_matriz(m1);

    return 0;
}