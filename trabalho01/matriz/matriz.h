/* Cabeçalho da implementação do tipo abstrato de dados 'matriz' e
 * operações relacionadas em C */

#ifndef MATRIZ_H
#define MATRIZ_H

#define DESC 20

typedef float val;

struct matriz {
	int L;
	int C;
	char descricao[DESC];

	val **m;
};

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

#endif
