#include <stdlib.h>
#include <stdio.h>

void bubbleSort(int *V, int N){
    int i, continua, aux, fim = N;
    do{
        continua = 0;
        for(i = 0; i < fim-1; i++){
            if (V[i] > V[i+1])
            {
                aux = V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
                continua = i;
            } 
        }
        fim--;
    }while (continua != 0);
}


int main(void)
{
    int vetor[7] = {14, 10, 20, 6, 37, 18, 11};
    
    /*int tamanho = sizeof(vetor)/sizeof(int);*/
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);

    bubbleSort(vetor, tamanho);

    int i = 0;
    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    
}