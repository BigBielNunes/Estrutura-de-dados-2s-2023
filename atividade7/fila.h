#ifndef FILA_H
#define FILA_H

#define MAX_TAMANHO_FILA 100

typedef struct {
    int dados[MAX_TAMANHO_FILA];
    int frente, tras;
} Fila;

void inicializarFila(Fila *f);
int estaVaziaFila(Fila *f);
int estaCheiaFila(Fila *f);
void enfileirar(Fila *f, int valor);
int desenfileirar(Fila *f);

#endif
