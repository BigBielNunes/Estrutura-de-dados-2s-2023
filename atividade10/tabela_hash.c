#include <stdio.h>
#include <string.h>
#include "tabela_hash.h"

char* tabela[TAMANHO_TABELA];

unsigned int hash(char* chave) {
    unsigned int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash = (hash * 31) + chave[i];
    }
    return hash % TAMANHO_TABELA;
}

void hash_table_init() {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela[i] = NULL;
    }
}

char* hash_table_get(char* chave) {
    int index = hash(chave);
    return tabela[index];
}

void hash_table_put(char* chave, char* dado) {
    int index = hash(chave);
    tabela[index] = dado;
}

int hash_table_contains(char* chave) {
    int index = hash(chave);
    return (tabela[index] != NULL);
}

void hash_table_remove(char* chave) {
    int index = hash(chave);
    tabela[index] = NULL;
}
