#include<stdio.h>
#include<stdlib.h>

int main (){
    int numero;
    printf("Digite um numero: ");
    scanf("%d",&numero);

    if( numero % 2 == 0){
        printf("Este numero não é primo");
    }else if(numero % 3 == 0){
        printf("Este numero não é primo");
    }else if(numero % 5 == 0){
        printf("Este numero não é primo");
    }else if (numero % 7 == 0){
        printf("Este numero não é primo");
    }else{
        printf("Este numero é primo");
    }
}
