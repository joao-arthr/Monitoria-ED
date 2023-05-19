#include <stdlib.h>
#include <stdio.h>

typedef struct NO{
    int dado;
    struct NO *prox;
}NO;

typedef struct FILA{
    NO *ini;
    NO *fim;
}FILA;

void inicializaFila(FILA *f){
    f->ini = NULL;
    f->fim = NULL;
}

void push(int dado, FILA *f){
    NO *ptr = (NO*) malloc(sizeof(NO));
    if(!ptr){
        printf("Erro de alocação de nó.\n");
        return;
    } else{
        ptr->dado = dado;
        ptr->prox = NULL;
        if(f->ini == NULL){
            f->ini = ptr;
        } else{
            f->fim->prox = ptr;
        }
        f->fim = ptr;
    }
}

int pop(FILA *f){
    NO* ptr = f->ini;
    int dado;

    if(!ptr){
        printf("Pilha vazia. \n");
    } else{
        f->ini = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        if(!f->ini){
            f->fim = NULL;
        }
        return dado;
    }
}

void imprimeFila(FILA *f){
        NO *ptr = f->ini;
    if(!ptr){
        printf("Fila vazia. \n");
    } else{
        while(ptr){
            printf("%d ", ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
    }
}

int main(void)
{
    FILA *f1 = (FILA*) malloc(sizeof(FILA));
    if(!f1){
        printf("Erro de alocação da fila");
        exit(0);
    } else{
        inicializaFila(f1);

        push(10,f1);
        push(20,f1);
        push(30,f1);

        imprimeFila(f1);

        printf("Removendo: %d\n", pop(f1));
        imprimeFila(f1);
    }
}