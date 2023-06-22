#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "matriz.h"

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
    m->m = (val **)malloc(L * sizeof(val *));
    strcpy(m->descricao, "./arquivo.txt");

    if (m->m == NULL) {
        free(m);
        return NULL;
    }

    for (int i = 0; i < L; i++) {
        m->m[i] = (val *)malloc(C * sizeof(val));

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

int preenche_matriz_aleatoria(struct matriz *m, val max) {
    val x;

    if(m == NULL) {
        return -1;
    }

    for (int i = 0; i < m->L; i++) {
        for (int j = 0; j < m->C; j++) {
            x = (val) rand();
            m->m[i][j] = 2*(x/RAND_MAX - 0.5);
        }
    }
    
    return 0;
};

val checksum_matriz(struct matriz *m) {
    val sum = 0;
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

int escreve_matriz(struct matriz *m) {
    int i, j;
    FILE *arquivo;

    arquivo = fopen(m->descricao, "w");

    if(arquivo == NULL) {
        printf("\nFalha na abertura do arquivo!");
        return -1;
    }

    fprintf(arquivo, "#%d\t#%d", m->L, m->C);

    for(i = 0; i < m->L; i++) {
        for(j = 0; j < m->C; j++) {
            fprintf(arquivo, "\n%f", m->m[i][j]);
        }
    }

    fclose(arquivo);
}

// int main() {
//     int C = 3, L = 3, r;
//     struct matriz *m1;

//     m1 = aloca_matriz(C, L);

//     if(m1 == NULL) {
//         printf("\nFalha na alocacao da matriz");
//         return -1;
//     }

//     r = preenche_matriz_aleatoria(m1, 10000.00);

//     if(r != 0) {
//         printf("\nFalha ao preencher aleatoriamente a matriz");
//         desaloca_matriz(m1);
//         return -1;
//     }

//     mostra_matriz(m1);

//     checksum_matriz(m1);

//     return 0;
// }