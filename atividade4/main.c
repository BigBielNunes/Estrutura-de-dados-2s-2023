#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s [lista de números]\n", argv[0]);
        return 1;
    }

    int num_elements = argc - 1;
    int *numbers = (int *)malloc(num_elements * sizeof(int));

    // Converte os argumentos de linha de comando em números inteiros
    for (int i = 1; i < argc; i++) {
        numbers[i - 1] = atoi(argv[i]);
    }

    // Chama a função bubble_sort para ordenar os números
    bubble_sort(numbers, num_elements);

    // Imprime a lista ordenada
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Libera a memória alocada para o array de números
    free(numbers);

    return 0;
}
