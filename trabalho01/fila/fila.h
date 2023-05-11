#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

struct fila {
int seq;
int cod;
struct fila *next;
void *dados;
};

// FUNCOES PARA SEREM IMPLEMENTADAS
// DONE // struct fila * inicia_fila();
// DONE // int acrecenta(struct fila *f, void *dados, int cod);
// DONE // int mostra(struct fila *f);
// DONE // int remove_elemento(struct fila *f);
// DONE // struct fila * move(struct fila *f);

#endif