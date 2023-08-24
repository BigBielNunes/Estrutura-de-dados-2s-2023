#include <stdio.h>
#include <string.h>

int buscaString(const char *array[], int tamanho, const char *busca) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(array[i], busca) == 0) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    const char *array[] = {"texto", "J", "EDO"};
    int tamanho = sizeof(array) / sizeof(array[0]);

    const char *busca = "EDO";
    int resultado = buscaString(array, tamanho, busca);

    if (resultado) {
        printf("Saída: 1\n");
    } else {
        printf("Saída: 0\n");
    }

    return 0;
}