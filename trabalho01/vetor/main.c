#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "vetor.h"

int main() {
    int N = 8, r;
    struct vetor *v1;

    v1 = aloca_vetor(N);
    if(v1 == NULL) {
        printf("\nFalha na alocacao do vetor");
        return -1;
    }

    r = preenche_vetor_aleatorio(v1, 100.00);
    if(r != 0) {
        printf("\nFalha ao preencher aleatoriamente o vetor");
        desaloca_vetor(v1);
        return -1;
    }

    mostra_vetor(v1);
    checksum(v1);

    // escreve_vetor(v1);
    // ler_vetor(v1);

    return 0;
}