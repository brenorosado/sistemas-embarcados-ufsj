#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fila.h"

struct fila * inicia_fila() {
    struct fila *f;
    f = malloc(sizeof(struct fila));

    if (f == NULL) {
        printf("Falha na alocacao de memoria.\n");
        return NULL;
    }

    f->seq = 0;
    f->cod = 0;
    f->next = NULL;

    return f;
}

int acrescenta_elemento(struct fila *f, void *dados, int cod) {
    if (f == NULL) {
        printf("\nFalha ao acrescentar elemento.\n");
        return 1;
    }

    struct fila *newElement;
    newElement = malloc(sizeof(struct fila));

    if (newElement == NULL) {
        free(newElement);
        printf("\nFalha ao acrescentar elemento.\n");
        return 1;
    }

    f->next = newElement;
    newElement->seq = f->seq + 1;
    newElement->cod = cod;
    newElement->dados = dados;
    newElement->next = NULL;
    return 0;
}

int remove_elemento(struct fila *f) {
    struct fila *ultimo, *penultimo;

    ultimo = f;

    while(ultimo->next != NULL) {
        penultimo = ultimo;
        ultimo = ultimo->next;
    }

    penultimo->next = NULL;
    free(ultimo);

    return 0;
}

struct fila * move(struct fila *f) {
    if (f == NULL) {
        printf("\nPonteiro passado para funcao move eh NULL.\n");
        return NULL;
    }

    return f->next;
}

int mostra(struct fila *f) {
    struct fila *aux;
    if (f == NULL) {
        printf("\nPonteiro passado para funcao mostra eh NULL.\n");
        return 1;
    }

    aux = f;
    printf("\nInicio da fila\n");
    while(aux != NULL) {
        printf("\nSEQUENCIA: %d; CODIGO: %d", aux->seq, aux->cod);
        aux = aux->next;
    }
    printf("\n\nFim da fila\n");

    return 0;
}

// int main() {
//     struct fila *sentinela, *aux;
//     void *dadosAux;
    
//     sentinela = inicia_fila();

//     aux = sentinela;

//     for(int i = 0; i < 9; i++) {
//         acrescenta_elemento(aux, dadosAux, aux->cod + 4);
//         aux = aux->next;
//     }

//     mostra(sentinela);
//     remove_elemento(sentinela);
//     mostra(sentinela);
//     sentinela = move(sentinela);
//     mostra(sentinela);

//     return 0;
// }