#include <stdlib.h>
#include <stdio.h>

typedef struct NO{
    int dado;
    struct NO *prox;
}NO;

typedef struct PILHA{
    NO *topo;
}PILHA;

void inicializaPilha(PILHA *p){
    p->topo = NULL;
}

void push(int dado, PILHA *p){
    NO *ptr = (NO*) malloc(sizeof(NO));
    if(!ptr){
        printf("Erro de alocação de nó.\n");
        return;
    } else{
        ptr->dado = dado;
        ptr->prox = p->topo;
        p->topo = ptr;
    }
}

int pop(PILHA *p){
    NO* ptr = p->topo;
    int dado;

    if(!ptr){
        printf("Pilha vazia. \n");
    } else{
        p->topo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
}

void imprimePilha(PILHA *p){
    NO *ptr = p->topo;
    if(!ptr){
        printf("Pilha vazia. \n");
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
    PILHA *p1 = (PILHA*) malloc(sizeof(PILHA));
    if(!p1){
        printf("Erro de alocação da pilha");
        exit(0);
    } else{
        inicializaPilha(p1);

        push(10,p1);
        push(20,p1);
        push(30,p1);

        imprimePilha(p1);

        printf("Desempilhando: %d\n", pop(p1));
        imprimePilha(p1);
    }
}