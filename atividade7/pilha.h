#ifndef PILHA_H
#define PILHA_H

#define MAX_TAMANHO_PILHA 100

typedef struct {
    int dados[MAX_TAMANHO_PILHA];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p);
int estaVazia(Pilha *p);
int estaCheia(Pilha *p);
void empilhar(Pilha *p, int valor);
int desempilhar(Pilha *p);

#endif
