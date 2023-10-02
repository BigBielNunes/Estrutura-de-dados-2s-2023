#include "pilha.h"

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == MAX_TAMANHO_PILHA - 1;
}

void empilhar(Pilha *p, int valor) {
    if (!estaCheia(p)) {
        p->dados[++p->topo] = valor;
    }
}

int desempilhar(Pilha *p) {
    if (!estaVazia(p)) {
        return p->dados[p->topo--];
    }
    return -1; 
}
