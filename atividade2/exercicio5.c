#include <stdio.h>
#include <stdlib.h>

void multiplicaArray(const int *arrayUm, const int *arrayDois, int *resultado, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        resultado[i] = arrayUm[i] * arrayDois[i];
    }
}

int main() {
    int arrayUm[] = {5, 7, 9, 6};
    int arrayDois[] = {5, 7, 9, 6};
    int tamanho = sizeof(arrayUm) / sizeof(arrayUm[0]);

    int resultado[tamanho];
    multiplicaArray(arrayUm, arrayDois, resultado, tamanho);

    printf("Saída: [");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", resultado[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}