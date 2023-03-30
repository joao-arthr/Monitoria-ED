#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    /*

    do{
        Instrução ou bloco de instruções;
    }while(condição);
    */
    int i = 0;
    do{
        printf("%d ", i);
        i++;
    }while(i < 10);
}
