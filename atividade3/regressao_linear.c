#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ponto {
    int x;
    float y;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nome_do_arquivo.csv>\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    int numRegistros = 0;
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo)) {
        numRegistros++;
    }

    struct Ponto *pontos = (struct Ponto *)malloc(numRegistros * sizeof(struct Ponto));

    rewind(arquivo);

    int somaX = 0;
    float somaY = 0.0;
    for (int i = 0; i < numRegistros; i++) {
        fscanf(arquivo, "%d,%f", &pontos[i].x, &pontos[i].y);
        somaX += pontos[i].x;
        somaY += pontos[i].y;
    }

    float mediaX = (float)somaX / numRegistros;
    float mediaY = somaY / numRegistros;

    float numerador = 0.0;
    float denominador = 0.0;
    for (int i = 0; i < numRegistros; i++) {
        numerador += (pontos[i].x - mediaX) * (pontos[i].y - mediaY);
        denominador += (pontos[i].x - mediaX) * (pontos[i].x - mediaX);
    }
    float coeficienteAngular = numerador / denominador;
    float coeficienteLinear = mediaY - coeficienteAngular * mediaX;

    printf("y = %.2fx + %.2f\n", coeficienteAngular, coeficienteLinear);

    free(pontos);

    fclose(arquivo);

    return 0;
}
