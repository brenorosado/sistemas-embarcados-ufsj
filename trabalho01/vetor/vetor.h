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

struct vetor * aloca_vetor(int N) {
    struct vetor *novo_vetor;

    novo_vetor = malloc(sizeof(struct vetor));
    if(novo_vetor == NULL) {
        printf("\nFalha na alocacao de memoria do novo vetor!");
        return NULL;
    }

    novo_vetor->v = malloc(N*sizeof(struct vetor));
    if(novo_vetor->v == NULL) {
        free(novo_vetor);
        printf("Falha na alocacao de memoria do novo vetor!");
        return NULL;
    }

    novo_vetor->N = N;
    strcpy(novo_vetor->descricao, "./arquivo.txt");

    return novo_vetor;
}

void desaloca_vetor(struct vetor *v) {
    if(v != NULL) {
        free(v->v);
        free(v);
    }

    return;
}

int preenche_vetor_aleatorio(struct vetor *v, valor max) {
    valor x;

    if(v == NULL) {
        return -1;
    }

    for(int i = 0; i < v->N; i++) {
        x = (valor) rand();
        v->v[i] = 2*(x/RAND_MAX - 0.5);
    }
    
    return 0;
}

valor checksum (struct vetor *v) {
    valor sum = 0;
	int i = 0;

    if(v == NULL) {
        return -1;
    }

    for (i; i < v->N; i++) {
        sum = sum + v->v[i];
    }

    printf("\nO vetor possui %d elementos e a soma dos valores do vetor eh: %f", i, sum);

    return sum;
}

int mostra_vetor(struct vetor *v) {
    int i;

    if(v == NULL) {
        return -1;
    }

    for(i = 0; i < v->N; i++) {
        printf("\nValor na posicao %d: %f", i, v->v[i]);
    }

    return 0;
}

int escreve_vetor(struct vetor *v) {
    int i;
    FILE *arquivo;

    arquivo = fopen(v->descricao, "w");

    if(arquivo == NULL) {
        printf("\nFalha na abertura do arquivo!");
        return -1;
    }

    fprintf(arquivo, "#%d", v->N);

    for(i = 0; i < v->N; i++) {
        fprintf(arquivo, "\n%f", v->v[i]);
    }

    fclose(arquivo);
}

int ler_vetor(struct vetor *v) {
    FILE *arquivo;
    int tamanho;
    valor aux;

    arquivo = fopen(v->descricao, "r");

    if(arquivo == NULL) {
        printf("\nFalha na abertura do arquivo!");
        return -1;
    }

    fscanf(arquivo, "#%d", &tamanho);

    for(tamanho; tamanho > 0; tamanho--) {
        fscanf(arquivo, "%f", &aux);
        printf("\nFROM FILE %f", aux);
    }

    fclose(arquivo);
}

#endif

