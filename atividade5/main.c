#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_de_entrada.txt>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 2;
    }

    int wordCount = 0;
    char buffer[256]; 
    while (fscanf(file, "%255s", buffer) == 1) {
        wordCount++;
    }

    rewind(file);

    char **words = (char **)malloc(wordCount * sizeof(char *));
    if (words == NULL) {
        perror("Erro ao alocar memória");
        return 3;
    }

    for (int i = 0; i < wordCount; i++) {
        words[i] = (char *)malloc(256);
        if (words[i] == NULL) {
            perror("Erro ao alocar memória");
            return 3;
        }
        fscanf(file, "%255s", words[i]);
    }

    fclose(file);

    bubbleSort(words, wordCount);

    char outputFileName[256];
    snprintf(outputFileName, sizeof(outputFileName), "%s_ordenado.txt", argv[1]);
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 4;
    }

    for (int i = 0; i < wordCount; i++) {
        fprintf(outputFile, "%s\n", words[i]);
    }

    fclose(outputFile);

    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }
    free(words);

    printf("As palavras foram ordenadas com sucesso em %s.\n", outputFileName);

    return 0;
}
