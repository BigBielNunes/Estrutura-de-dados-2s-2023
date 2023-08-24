#include <stdio.h>
#include <stdio.h>

int main()
{
    int somaArray[4] = {1,2,3,4};
    int resultadoSoma = 0;
    
    for(int i = 0; i < 4; i ++){
        resultadoSoma = resultadoSoma + somaArray[i];
    }
    
    printf("O resultado da soma de todos os elementos é %d", resultadoSoma);
    
    return 0;
}