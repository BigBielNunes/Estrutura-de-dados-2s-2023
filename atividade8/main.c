#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]){

    No* n0 = no('C', NULL);
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', NULL)))));
    No* n3 = no('U', NULL);
    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);
    lista_imprimir(n0);
    printf("\nqtd nos: %d", lista_quantidade_nos(n0));
    No* n_copia = lista_copiar(n0);
    printf("\n");
    lista_imprimir(n_copia);
    lista_concatenar(n0, n_copia);
    printf("\n");
    lista_imprimir(n0);
    lista_liberar(n0);
    n0 = NULL;
    lista_imprimir(n0);

    No* lista = NULL;

    lista_inserir_inicio(&lista, 'A');
    lista_inserir_inicio(&lista, 'B');
    lista_inserir_inicio(&lista, 'C');
    lista_inserir_inicio(&lista, 'A');
    lista_inserir_inicio(&lista, 'D');
    
    printf("Lista: ");
    lista_imprimir(lista);

    printf("Verificar existência de 'B': %d\n", lista_verificar_existencia(lista, 'B'));
    printf("Verificar existência de 'E': %d\n", lista_verificar_existencia(lista, 'E'));
    
    printf("Ocorrências de 'A': %d\n", lista_verificar_ocorrencias(lista, 'A'));
    
    printf("Lista inversa: ");
    lista_imprimir_inversa(lista);
    
    lista_inserir_no_i(&lista, 2, 'X');
    printf("Lista após inserção em posição 2: ");
    lista_imprimir(lista);
    
    lista_remover_no_i(&lista, 4);
    printf("Lista após remoção do índice 4: ");
    lista_imprimir(lista);
    
    lista_remover_no(&lista, 'A');
    printf("Lista após remoção de 'A': ");
    lista_imprimir(lista);

      exit(0);
}