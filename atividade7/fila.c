#include "fila.h"

void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
}

int estaVaziaFila(Fila *f) {
    return (f->tras < f->frente);
}

int estaCheiaFila(Fila *f) {
    return (f->tras - f->frente + 1) == MAX_TAMANHO_FILA;
}

void enfileirar(Fila *f, int valor) {
    if (!estaCheiaFila(f)) {
        f->dados[++f->tras] = valor;
    }
}

int desenfileirar(Fila *f) {
    if (!estaVaziaFila(f)) {
        return f->dados[f->frente++];
    }
    return -1; 
}
