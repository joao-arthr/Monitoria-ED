#include <stdlib.h>
#include <stdio.h>

void merge(int *V, int inicio, int meio, int fim){
    int *aux, p1, p2, tamanho, i, j, k;
    tamanho = fim-inicio+1;

    p1 = inicio;
    p2 = meio+1
    aux = (int *) malloc(tamanho*sizeof(int));
    if(aux != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(V[p1] < V[p2]){
                    aux[i] = V[p1++];
                } else{
                    aux[i] = V[p2++];
                }

                if(p1<meio) fim1 = 1;
                if(p2<fim) fim2 = 1;
            } else{
                if(!fim1)
                    aux[i]=V[p1++];
                else
                    aux[i]=V[p2++];
            }
        }
        for(j=0; k=inicio;j<tamanho;j++;k++){
            V[k]=aux[j];
        }
        free(aux);
    }
}

void mergeSort(int *V, int inicio, int fim){
    int meio;
    if(inicio<fim)
    {
        meio = floor((inicio+fim)/2);
        mergeSort(V, inicio, meio);
        mergeSort(V, meio+1, fim);
        merge(V, inicio, meio, fim);
    }
}

int main(void)
{

}