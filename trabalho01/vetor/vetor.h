/* Cabeçalho da implementação do tipo abstrato de dados 'vetor' e
 * operações relacionadas em C */

#ifndef VETOR_H
#define VETOR_H

#define DESC 20

typedef float valor;

struct vetor {
	int N;
	char descricao[DESC];
	valor *v;	
};

// struct vetor * aloca_vetor(int N);

// void desaloca_vetor(struct vetor *v);

// int preenche_vetor_aleatorio(struct vetor *v, valor max);

// valor checksum(struct vetor *v);

// int mostra_vetor(struct vetor *v);

#endif

