#include <stdlib.h>
#include <stdio.h>

int main(void){
    int i = 0, vetor[5];

    for (i = 0; i < 5; i++)
    {
        printf("Digite um valor para a posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < 5; i++){
        printf("%d esta armazenado na posicao %d\n", vetor[i], i);
    }
    
}