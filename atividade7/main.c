#include <stdio.h>
#include "pilha.h"
#include "fila.h"

int main() {
    Pilha pilha;
    Fila fila;

    inicializarPilha(&pilha);
    inicializarFila(&fila);

    // Caso de uso da Pilha como por exemplo em uma blockchain que o ultimo bloco a entrar e o ultimo e primeiro a ser visto quando for olhar o registro
    printf("Pilha:\n");
    empilhar(&pilha, 20);
    empilhar(&pilha, 10);
    empilhar(&pilha, 30);

    while (!estaVazia(&pilha)) {
        printf("%d ", desempilhar(&pilha));
    }
    printf("\n");

    // Caso de uso da Fila como por exemplo em uma fila de estabelecimento que o primeiro a chegar vai ser o primeiro a ser chamado e assim consequentemente 
    printf("Fila:\n");
    enfileirar(&fila, 1);
    enfileirar(&fila, 2);
    enfileirar(&fila, 3);

    while (!estaVaziaFila(&fila)) {
        printf("%d ", desenfileirar(&fila));
    }
    printf("\n");

    return 0;
}
