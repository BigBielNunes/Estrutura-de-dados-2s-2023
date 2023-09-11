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

    for (int i = 1; i < argc; i++) {
        numbers[i - 1] = atoi(argv[i]);
    }

    bubble_sort(numbers, num_elements);

    for (int i = 0; i < num_elements; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);

    return 0;
}
