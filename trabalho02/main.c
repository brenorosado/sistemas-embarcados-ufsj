#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./vetor/vetor.h"
#include "./vetor/vetor.c"
#include "./matriz/matriz.h"
#include "./matriz/matriz.c"
#include "./fila/fila.h"
#include "./fila/fila.c"

int main() {
    struct fila *sentinela, *aux;
    struct vetor *vetor_aux;
    struct matriz *matriz_aux;

    int check_aux;

    sentinela = inicia_fila();

    aux = sentinela;

    for(int i = 0; i < 6; i++) {
        if(i % 2 == 0) {
            vetor_aux = aloca_vetor(1001);

            if(vetor_aux == NULL) {
                printf("\n Falha na alocacao do vetor");
                return -1;
            }

            check_aux = preenche_vetor_aleatorio(vetor_aux, 100.00);

            if(check_aux != 0) {
                printf("\nFalha ao preencher aleatoriamente o vetor");
                desaloca_vetor(vetor_aux);
                return -1;
            }

            acrescenta_elemento(aux, vetor_aux, 1);

            salva_vetor(vetor_aux, 1);
        } else {
            matriz_aux = aloca_matriz(101, 101);

            if(matriz_aux == NULL) {
                printf("\nFalha na alocacao da matriz");
                return -1;
            }

            check_aux = preenche_matriz_aleatoria(matriz_aux, 100.00);

            if(check_aux != 0) {
                printf("\nFalha ao preencher aleatoriamente a matriz");
                desaloca_matriz(matriz_aux);
                return -1;
            }

            acrescenta_elemento(aux, matriz_aux, 2);

            salva_matriz(matriz_aux, 1);
        }
        aux = aux->next;
    }

    mostra(sentinela);

    int resultSalvar = salva_fila(sentinela, "./arquivoFila.txt");
    sentinela = carrega_fila("./arquivoFila.txt");
    printf("\nFILA CARREGADA DO ARQUIVO");
    mostra(sentinela);

    return 0;
}