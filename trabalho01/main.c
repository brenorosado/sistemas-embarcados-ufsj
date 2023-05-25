#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./vetor/vetor.h"
#include "./matriz/matriz.h"
#include "./fila/fila.h"

int main() {
    struct fila *sentinela, *aux;
    struct vetor *vetor_aux;
    struct matriz *matriz_aux;

    int check_aux;

    sentinela = inicia_fila();

    aux = sentinela;

    for(int i = 0; i < 7; i++) {
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

            acrescenta(aux, vetor_aux, 1); // acrescenta vetor na fila
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

            acrescenta(aux, matriz_aux, 2); // acrescenta matriz
        }
        aux = aux->next;
    }

    mostra(sentinela);

    aux = sentinela;
    printf("\nInicio da fila\n");
    while(aux != NULL) {
        printf("\nELEMENTO: %d; CODIGO: %d", aux->seq, aux->cod);
        if(aux->cod == 0) {
            printf("\nPonteiro de dados nao atribuido!");
        } else if (aux->cod == 1) {
            printf("\nPonteiro de dados aponta para um vetor!");
            checksum(aux->dados);
        } else if (aux->cod == 2) {
            printf("\nPonteiro de dados aponta para uma matriz!");
            checksum_matriz(aux->dados);
        } else {
            printf("\nPonteiro de dados aponta para estrutura desconhecida!");
        }
        aux = aux->next;
    }

    return 0;
}