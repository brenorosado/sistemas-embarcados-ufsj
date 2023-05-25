#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fila.h"

int main() {
    struct fila *sentinela, *aux;
    void *dadosAux;
    
    sentinela = inicia_fila();

    aux = sentinela;

    for(int i = 0; i < 9; i++) {
        acrescenta(aux, dadosAux, aux->cod + 4);
        aux = aux->next;
    }

    mostra(sentinela);
    remove_elemento(sentinela);
    mostra(sentinela);
    sentinela = move(sentinela);
    mostra(sentinela);

    return 0;
}