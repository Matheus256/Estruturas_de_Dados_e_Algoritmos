#include <stdio.h>
#include <stdlib.h>

struct sNODE{
    int dado;
    struct sNODE *prox;
};

typedef struct{
    struct sNODE *topo;
} PILHA;

//Funções para as pilhas
void push(PILHA *pi, int dado);
int pop(PILHA *pi);

//Funções para a Fila
void enqueue(int dado);
int dequeue();
void imprimir();

//DEclacao das duas pilhas
PILHA pilha1 = {NULL}, pilha2 = {NULL};


int main(){
    
    enqueue(14);
    enqueue(7);
    enqueue(12);
    
    imprimir();
    printf("\n");
    
    enqueue(8);
    imprimir();
    
    printf("\n");
    
    printf("Dequeue na fila -> %d\n\n", dequeue());
    
    imprimir();
    printf("\n");
    
    printf("Dequeue na fila -> %d\n\n", dequeue());
    
    imprimir();

    return 0;
}

//Acabou nao sendo usada
void criar(PILHA *pi){
    pi->topo = NULL;
}

void push(PILHA *pi, int dado){
    struct sNODE *node = (struct sNODE*) malloc(sizeof(struct sNODE));
    node->dado = dado;
    node->prox = pi->topo;
    pi->topo = node;
}

int pop(PILHA *pi){
    if(!pi->topo){
        printf("Pilha vazia");
        exit(1);
    }
    
    struct sNODE *aux = pi->topo;
    int dado = pi->topo->dado;
    pi->topo = pi->topo->prox;
    free(aux);
    return dado;
}

void enqueue(int dado){
    push(&pilha2, dado);
}

int dequeue(){
    while(pilha2.topo)
        push(&pilha1, pop(&pilha2));
        
    int dado = pop(&pilha1);
    
    while(pilha1.topo)
        push(&pilha2, pop(&pilha1));
        
    return dado;
}

void imprimir(){
    struct sNODE *aux = pilha2.topo;
    printf("[");
    while(aux){
        printf(" %d ",aux->dado);
        aux = aux->prox;
    }
    printf("]\n");
}
