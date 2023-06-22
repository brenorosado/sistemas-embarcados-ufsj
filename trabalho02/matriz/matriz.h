#ifndef MATRIZ_H
#define MATRIZ_H
#include "../tipos_comuns.h"

struct matriz {
	int L;
	int C;
	char arquivo[NOMEARQUIVO];

	valor **m;
};

struct matriz * aloca_matriz(int L, int C);

void desaloca_matriz(struct matriz *m);

int preenche_matriz_aleatoria(struct matriz *m, valor max);

valor checksum_matriz(struct matriz *m);

int mostra_matriz(struct matriz *m);

int matriz_nome_arquivo(struct matriz *m, char *nome);

int salva_matriz(struct matriz *m, int texto);

struct matriz * le_matriz(char *arquivo, int texto);

#endif
