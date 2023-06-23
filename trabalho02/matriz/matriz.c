#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "matriz.h"
#include "../tipos_comuns.h"

struct matriz * aloca_matriz(int L, int C) {
    if (L <= 0 || C <= 0) {
        return NULL;
    }

    struct matriz *m = (struct matriz *)malloc(sizeof(struct matriz));

    if (m == NULL) {
        return NULL;
    }

    m->L = L;
    m->C = C;
    m->m = (valor **)malloc(L * sizeof(valor *));

    if (m->m == NULL) {
        free(m);
        return NULL;
    }

    for (int i = 0; i < L; i++) {
        m->m[i] = (valor *)malloc(C * sizeof(valor));

        if (m->m[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(m->m[j]);
            }
            free(m->m);
            free(m);
            return NULL;
        }
    }

    return m;
}

void desaloca_matriz(struct matriz *m) {
    if(m != NULL) {
        free(m->m);
        free(m);
    }

    return;
}

int preenche_matriz_aleatoria(struct matriz *m, valor max) {
    valor x;

    if(m == NULL) {
        return -1;
    }

    for (int i = 0; i < m->L; i++) {
        for (int j = 0; j < m->C; j++) {
            x = (valor) rand();
            m->m[i][j] = 2*(x/RAND_MAX - 0.5);
        }
    }
    
    return 0;
};

valor checksum_matriz(struct matriz *m) {
    valor sum = 0;
	int i = 0, j = 0;

    if(m == NULL) {
        return -1;
    }

    for(i; i < m->L; i++) {
        for(j; j < m->C; j++) {
            sum = sum + m->m[i][j];
        }
    }

     printf("\nA matriz possui %d linhas x %d colunas = %d elementos e a soma dos valores da matriz eh: %f", i, j, i* j, sum);
    
    return sum;
}

int mostra_matriz(struct matriz *m) {
    int i, j;

    if(m == NULL) {
        return -1;
    }

    printf("\n");
    for(i = 0; i < m->L; i++) {
        for(j = 0; j < m->C; j++) {
            printf("[%d][%d]: %f  |  ", i, j, m->m[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int matriz_nome_arquivo(struct matriz *m, char *nome) {
    if(m == NULL) {
        printf("\nFalha ao salvar o nome do arquivo na matriz!");
        return -1;
    }

    strcpy(m->arquivo, nome);

    return 0;
}

int salva_matriz(struct matriz *m, int texto) {
    int i, j;
    FILE *arquivo;

    if(texto != 0) {
        arquivo = fopen(m->arquivo, "w");

        if(arquivo == NULL) {
            printf("\nFalha na abertura do arquivo!");
            return -1;
        }

        fprintf(arquivo, "#%d\t#%d", m->L, m->C);

        for(i = 0; i < m->L; i++) {
            fprintf(arquivo, "\n");
            for(j = 0; j < m->C; j++) {
                fprintf(arquivo, "%f\t", m->m[i][j]);
            }
        }

        fclose(arquivo);
        return 0;
    } else {
        // escreve martiz em arquivo binario
    }
}

struct matriz * le_matriz(char *arquivo, int texto) {
    FILE *arquivoToBeRead;
    int linhas, colunas, i, j;
    valor aux;
    struct matriz *matriz_lida;

    if(texto != 0) {
        arquivoToBeRead = fopen(arquivo, "r");

        if(arquivoToBeRead == NULL) {
            printf("\nFalha na abertura do arquivo de vetor!");
            return NULL;
        }

        fscanf(arquivoToBeRead, "#%d #%d", &linhas, &colunas);

        matriz_lida = aloca_matriz(linhas, colunas);
        
        for(i = 0; i < linhas; i++) {
            for(j = 0; j < colunas; j++) {
                fscanf(arquivoToBeRead, "%f", &aux);
                matriz_lida->m[i][j] = aux;
            }
        }
        
        return matriz_lida;
    } else {
        // le matriz de arquivo binario
    }
}