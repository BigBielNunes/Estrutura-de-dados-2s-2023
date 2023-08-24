#include <stdio.h>
#include <stdio.h>

int main()
{
    int comparaVetor[4] = {110,21,32,41};
    int menorValor = comparaVetor[0];
    int maiorValor;
    
    
    for(int i = 0; i < 4; i ++){
        if(comparaVetor[i] > maiorValor){
            maiorValor = comparaVetor[i];
        }
        if(comparaVetor[i] < menorValor){
            menorValor =  comparaVetor[i];
        }
    }
    
    printf("O menor valor é %d\nO maior valor é %d", menorValor, maiorValor);

    return 0;
}