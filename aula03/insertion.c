#include <stdlib.h>
#include <stdio.h>

void insertionSort(int *V, int N)
{
    int i, j, aux;
  
    for(i = 1; i < N; i++)
    {
        aux = V[i];
        for(j = i; (j > 0) && (aux < V[j-1]); j--)
        {
            V[j] = V[j-1];
        }
        V[j] = aux;
    }
}

int main(void)
{

}