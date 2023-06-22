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

struct matriz * aloca_matriz(int L, int C);

void desaloca_matriz(struct matriz *m);

int preenche_matriz_aleatoria(struct matriz *m, val max);

val checksum_matriz(struct matriz *m);

int mostra_matriz(struct matriz *m);

#endif