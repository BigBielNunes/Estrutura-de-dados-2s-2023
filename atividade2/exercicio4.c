#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contaArray[7] = {1,2,3,2,5,6,2};
    int contadorNumero = 0;
    
    for(int i = 0; i < 8; i ++){
        if(contaArray[i] == 2){
            contadorNumero = contadorNumero + 1;
        }
    }

    printf("%d", contadorNumero);

    return 0;
}