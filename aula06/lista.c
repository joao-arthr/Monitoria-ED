#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int dado;
    struct no *proximo;
    struct no *anterior;
}No;

// procedimento para inserir no início
void inserir_no_inicio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->dado = num;
        novo->proximo = *lista;
        novo->anterior = NULL;
        if(*lista)
            (*lista)->anterior = novo;
        *lista = novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no fim
void inserir_no_fim(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->dado = num;
        novo->proximo = NULL;

        // é o primeiro?
        if(*lista == NULL){
            *lista = novo;
            novo->anterior = NULL;
        }
        else{
            aux = *lista;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
            novo->anterior = aux;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no meio
void inserir_no_meio(No **lista, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->dado = num;
        // é o primeiro?
        if(*lista == NULL){
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->dado != ant && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            if(aux->proximo)
                aux->proximo->anterior = novo;
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

No* remover(No **lista, int num){
    No *aux, *remover = NULL;

    if(*lista){
        if((*lista)->dado == num){
            remover = *lista;
            *lista = remover->proximo;
            if(*lista)
                (*lista)->anterior = NULL;
        }
        else{
            aux = *lista;
            while(aux->proximo && aux->proximo->dado != num)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                if(aux->proximo)
                    aux->proximo->anterior = aux;
            }
        }
    }
    return remover;
}

void imprimir(No *no){
    printf("\n\tLista: ");
    while(no){
        printf("%d ", no->dado);
        no = no->proximo;
    }
    printf("\n\n");
}

int main(){

    int opcao, dado, anterior;
    No *removido, *lista = NULL;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir Inicio\n\t2 - Inserir Fim\n\t3 - Inserir Meio\n\t4 - Remover\n\t5 - Imprimir\n\t");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite um dado para inserir no inicio: ");
            scanf("%d", &dado);
            inserir_no_inicio(&lista, dado);
            break;
        case 2:
            printf("Digite um dado para inserir no final: ");
            scanf("%d", &dado);
            inserir_no_fim(&lista, dado);
            break;
        case 3:
            printf("Digite um dado para inserir no meio: ");
            scanf("%d", &dado);
            printf("Digite um dado de referencia: ");
            scanf("%d", &anterior);
            inserir_no_meio(&lista, dado, anterior);
            break;
        case 4:
            printf("Digite um dado a ser removido: ");
            scanf("%d", &dado);
            removido = remover(&lista, dado);
            if(removido){
                printf("Elemento a ser removido: %d\n", removido->dado);
                free(removido);
            }
            else
                printf("Elemento inexistente!\n");
            break;
        case 5:
            imprimir(lista);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}