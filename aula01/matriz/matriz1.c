#include <stdlib.h>
#include <stdio.h>

int main(void){
    int linha = 0, coluna = 0, i = 0, j = 0, matriz[3][3];
  
    for (linha = 0; linha < 3; linha++)
    {
        for (coluna = 0; coluna < 3; coluna++)
        {
            printf("Linha %d & Coluna %d: ", linha, coluna);
            scanf("%d", &matriz[linha][coluna]);
        }  
    }


    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("|%d| ", matriz[i][j]);
        }  
        printf("\n");
    }
}