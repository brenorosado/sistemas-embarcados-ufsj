#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fila.h"
#include "../tipos_comuns.h"

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
    char aux_nome_arquivo[NOMEARQUIVO];

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


    if(cod == 1) {
        sprintf(aux_nome_arquivo, "./v-%d-%d.txt", newElement->cod, newElement->seq);
        vetor_nome_arquivo(dados, aux_nome_arquivo);
    } else if (cod == 2) {
        sprintf(aux_nome_arquivo, "./m-%d-%d.txt", newElement->cod, newElement->seq);
        matriz_nome_arquivo(dados, aux_nome_arquivo);
    }
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

int salva_fila(struct fila *f, char *nome_arquivo) {
    char aux_nome_arquivo[NOMEARQUIVO];
    int num_elementos_fila = 0;
    struct fila *aux;
    FILE *arquivo;

    if (f == NULL) {
        printf("\nPonteiro passado para funcao salva_fila eh NULL.\n");
        return -1;
    }

    arquivo = fopen(nome_arquivo, "w");

    if(arquivo == NULL) {
        printf("\nFalha na abertura do arquivo!");
        return -1;
    }

    aux = f;
    while(aux != NULL) {
        num_elementos_fila++;
        aux = aux->next;
    }
    fprintf(arquivo, "#%d", num_elementos_fila);

    aux = f;
    while(aux != NULL) {
        if(aux->cod == COD_VAZIO) {
            fprintf(arquivo, "\n%d:%d", aux->seq, 0);
        } else if (aux->cod == COD_VETOR) {
            fprintf(arquivo, "\n%d:%d", aux->seq, 1);
        } else if (aux->cod == COD_MATRIZ) {
            fprintf(arquivo, "\n%d:%d", aux->seq, 2);
        }
        aux = aux->next;
    }
    fclose(arquivo);

    return 0;
}

struct fila * carrega_fila(char *nome_arquivo) {
    int numElementosFila, i;
    struct fila *sentinela, *aux;
    FILE *arquivo;
    char aux_nome_arquivo[NOMEARQUIVO];

    sentinela = malloc(sizeof(struct fila));

    if (sentinela == NULL) {
        printf("Falha na alocacao de memoria.\n");
        return NULL;
    }

    arquivo = fopen(nome_arquivo, "r");

    if(arquivo == NULL) {
        printf("\nFalha na abertura do arquivo!");
        return NULL;
    }

    fscanf(arquivo, "#%d", &numElementosFila);
    aux = sentinela;
    for(i = 0; i <= numElementosFila; i++) {
        fscanf(arquivo, "%d:%d", &aux->seq, &aux->cod);
        if(aux->cod == 1) {
            sprintf(aux_nome_arquivo, "./v-%d-%d.txt", aux->cod, aux->seq);
            aux->dados = le_vetor(aux_nome_arquivo, 1);
        } else if (aux->cod == 2) {
            sprintf(aux_nome_arquivo, "./m-%d-%d.txt", aux->cod, aux->seq);
            aux->dados = le_matriz(aux_nome_arquivo, 1);
        }

        if(aux->seq != (numElementosFila - 1)) {
            aux->next = malloc(sizeof(struct fila));
            aux = aux->next;
        } else {
            aux->next = NULL;
        }
    }
    fclose(arquivo);

    return sentinela;
}
