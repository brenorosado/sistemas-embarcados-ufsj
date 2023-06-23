#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "vetor.h"
#include "../tipos_comuns.h"

struct vetor * aloca_vetor(int N) {
    struct vetor *novo_vetor;

    novo_vetor = malloc(sizeof(struct vetor));
    if(novo_vetor == NULL) {
        printf("\nFalha na alocacao de memoria do novo vetor!");
        return NULL;
    }

    novo_vetor->v = malloc(N*sizeof(struct vetor));
    if(novo_vetor->v == NULL) {
        free(novo_vetor);
        printf("Falha na alocacao de memoria do novo vetor!");
        return NULL;
    }

    novo_vetor->N = N;

    return novo_vetor;
}

void desaloca_vetor(struct vetor *v) {
    if(v != NULL) {
        free(v->v);
        free(v);
    }

    return;
}

int preenche_vetor_aleatorio(struct vetor *v, valor max) {
    valor x;

    if(v == NULL) {
        return -1;
    }

    for(int i = 0; i < v->N; i++) {
        x = (valor) rand();
        v->v[i] = 2*(x/RAND_MAX - 0.5);
    }
    
    return 0;
}

valor checksum (struct vetor *v) {
    valor sum = 0;
	int i = 0;

    if(v == NULL) {
        return -1;
    }

    for (i; i < v->N; i++) {
        sum = sum + v->v[i];
    }

    printf("\nO vetor possui %d elementos e a soma dos valores do vetor eh: %f", i, sum);

    return sum;
}

int mostra_vetor(struct vetor *v) {
    int i;

    if(v == NULL) {
        return -1;
    }

    for(i = 0; i < v->N; i++) {
        printf("\nValor na posicao %d: %f", i, v->v[i]);
    }

    return 0;
}

int vetor_nome_arquivo(struct vetor *v, char *nome) {
    if(v == NULL) {
        printf("\nFalha ao salvar o nome do arquivo no vetor!");
        return -1;
    }

    strcpy(v->arquivo, nome);

    return 0;
}

int salva_vetor(struct vetor *v, int texto) {
    int i;
    FILE *arquivo;

    if(texto != 0) {

        arquivo = fopen(v->arquivo, "w");

        if(arquivo == NULL) {
            printf("\nFalha na abertura do arquivo!");
            return -1;
        }

        fprintf(arquivo, "#%d", v->N);

        for(i = 0; i < v->N; i++) {
            fprintf(arquivo, "\n%f", v->v[i]);
        }

        fclose(arquivo);

        return 0;
    } else {
        // salva vetor em arquivo binario
    }
}

struct vetor * le_vetor(char *arquivo, int texto) {
    FILE *arquivoToBeRead;
    int tamanho;
    valor aux;
    int i;
    struct vetor *vetor_lido;

    if(texto != 0) {
        arquivoToBeRead = fopen(arquivo, "r");

        if(arquivoToBeRead == NULL) {
            printf("\nFalha na abertura do arquivo de vetor!");
            return NULL;
        }

        fscanf(arquivoToBeRead, "#%d", &tamanho);
        vetor_lido = aloca_vetor(tamanho);

        for(i = 0; i < tamanho; i++) {
            fscanf(arquivoToBeRead, "%f", &aux);
            vetor_lido->v[i] = aux;
        }

        fclose(arquivoToBeRead);
        return vetor_lido;
    } else {
        // fazer leitura de binario
    }

    return NULL;
}