#ifndef VETOR_H
#define VETOR_H
#include "../tipos_comuns.h"

struct vetor {
	int N;
	char arquivo[NOMEARQUIVO];
	valor *v;	
};

struct vetor * aloca_vetor(int N);

void desaloca_vetor(struct vetor *v);

int preenche_vetor_aleatorio(struct vetor *v, valor max);

valor checksum(struct vetor *v);

int mostra_vetor(struct vetor *v);

int vetor_nome_arquivo(struct vetor *v, char *nome);

int salva_vetor(struct vetor *v, int texto);

struct vetor * le_vetor(char *arquivo, int texto);

#endif

