#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

int main() {
    hash_table_init();

    hash_table_put("chave1", "valor1");
    hash_table_put("chave2", "valor2");

    char* resultado = hash_table_get("chave1");
    if (resultado != NULL) {
        printf("Valor associado a chave1: %s\n", resultado);
    } else {
        printf("Chave1 não encontrada na tabela.\n");
    }

    if (hash_table_contains("chave2")) {
        printf("Chave2 está na tabela.\n");
    } else {
        printf("Chave2 não está na tabela.\n");
    }

    hash_table_remove("chave1");

    if (hash_table_contains("chave1")) {
        printf("Chave1 está na tabela.\n");
    } else {
        printf("Chave1 não está mais na tabela.\n");
    }

    return 0;
}
