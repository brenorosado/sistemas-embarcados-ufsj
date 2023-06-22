#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

struct fila {
    int seq;
    int cod;
    struct fila *next;
    void *dados;
};

struct fila * inicia_fila();

int acrescenta(struct fila *f, void *dados, int cod);

int mostra(struct fila *f);

int remove_elemento(struct fila *f);

struct fila * move(struct fila *f);

#endif