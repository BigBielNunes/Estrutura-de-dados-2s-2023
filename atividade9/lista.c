#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(char valor, No* proximo_no){
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void lista_inserir_no(No* L, No* no){
    if(L != NULL){
        if(L->proximo_no == NULL){
            L->proximo_no = no;
        }
        else{
            lista_inserir_no(L->proximo_no, no);
        }
    }
}

void lista_imprimir(No* L){
    if(L != NULL){
        printf("%c ", L->valor);
        lista_imprimir(L->proximo_no);
    }
}

int lista_quantidade_nos(No* L){
    if(L != NULL){
        return 1 + lista_quantidade_nos(L->proximo_no);
    }
    return 0;
}

No* lista_copiar(No* L){
    if(L != NULL){
        return no(L->valor, lista_copiar(L->proximo_no));
    }
    return NULL;
}

void lista_concatenar(No* L, No* Lc){
    lista_inserir_no(L, Lc);
}

void lista_liberar(No* L){
    if(L != NULL){
        lista_liberar(L->proximo_no);
        free(L);
    }
}
void lista_inserir_inicio(No** L, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo_no = *L;
    *L = novo_no;
}
int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1;  // Valor encontrado na lista
        }
        atual = atual->proximo_no;
    }
    return 0;  // Valor não encontrado na lista
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int contador = 0;
    No* atual = L;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            contador++;
        }
        atual = atual->proximo_no;
    }
    return contador;
}

void lista_imprimir_inversa(No* L) {
    if (L == NULL) {
        return;
    }
    lista_imprimir_inversa(L->proximo_no);
    printf("%c ", L->valor);
}

void lista_inserir_no_i(No** L, int i, char valor) {
    if (i == 0) {
        lista_inserir_inicio(L, valor);
        return;
    }
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    No* anterior = *L;
    for (int j = 0; j < i - 1; j++) {
        if (anterior == NULL) {
            free(novo_no);
            return;  // Índice fora dos limites da lista
        }
        anterior = anterior->proximo_no;
    }
    novo_no->proximo_no = anterior->proximo_no;
    anterior->proximo_no = novo_no;
}

void lista_remover_no_i(No** L, int i) {
    if (*L == NULL) {
        return;  // Lista vazia
    }
    if (i == 0) {
        No* temp = *L;
        *L = (*L)->proximo_no;
        free(temp);
        return;
    }
    No* anterior = *L;
    for (int j = 0; j < i - 1; j++) {
        if (anterior == NULL || anterior->proximo_no == NULL) {
            return;  // Índice fora dos limites da lista
        }
        anterior = anterior->proximo_no;
    }
    if (anterior->proximo_no != NULL) {
        No* temp = anterior->proximo_no;
        anterior->proximo_no = temp->proximo_no;
        free(temp);
    }
}

void lista_remover_no(No** L, char valor_busca) {
    while (*L != NULL && (*L)->valor == valor_busca) {
        No* temp = *L;
        *L = (*L)->proximo_no;
        free(temp);
    }
    if (*L == NULL) {
        return;  // Lista vazia ou todos os elementos removidos
    }
    No* atual = *L;
    while (atual->proximo_no != NULL) {
        if (atual->proximo_no->valor == valor_busca) {
            No* temp = atual->proximo_no;
            atual->proximo_no = temp->proximo_no;
            free(temp);
        } else {
            atual = atual->proximo_no;
        }
    }
}

void lista_inserir_no_ordenado(No* L, No* no) {
    No* atual = L;
    No* anterior = NULL;

    while (atual != NULL && atual->valor < no->valor) {
        anterior = atual;
        atual = atual->proximo_no;
    }

    if (anterior != NULL) {
        anterior->proximo_no = no;
        no->proximo_no = atual;
    } else {
        no->proximo_no = L;
        L = no;
    }
}