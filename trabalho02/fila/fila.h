#ifndef FILA_H
#define FILA_H

#define COD_VAZIO	0
#define COD_VETOR	1
#define COD_MATRIZ	2

struct fila {
	int seq;
	int cod;
	struct fila *next;
	void *dados;
};

struct fila * inicia_fila();

int acrescenta_elemento(struct fila *f, void *dados, int cod);

int remove_elemento(struct fila *f);

struct fila * move(struct fila *f);

int mostra(struct fila *f);

/* Salva fila e dados relacionados */ 
int salva_fila(struct fila *f, char *nome_arquivo);

/* Carrega fila e dados relacionados */
struct fila * carrega_fila(char *nome_arquivo);


#endif

