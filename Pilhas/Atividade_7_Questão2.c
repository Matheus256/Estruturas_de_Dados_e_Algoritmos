#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sPILHA{
    int *arr;
    int MAX, pos;
};

typedef struct sPILHA PILHA;

//============ Cabeçalhos ================
void criar(PILHA *pi, int tam_MAX);
void apagar(PILHA *pi);

void push(PILHA *pi, int dado);
int pop(PILHA *pi);

int tamanho(PILHA *pi);
void imprimir(PILHA *pi);

//================== A main ==============
int main(){
    PILHA pilha1;
    criar(&pilha1, 10);

    push(&pilha1, 100);
    push(&pilha1, 50);
    push(&pilha1, 200);

    printf("Pop em Pilha 1 -> %d\n",pop(&pilha1));

    imprimir(&pilha1);

    apagar(&pilha1);

    return 0;
}

//================= Implementações =======
void criar(PILHA *pi, int tam_MAX){
    pi->MAX = tam_MAX;
    pi->pos = 0;
    pi->arr = (int*) malloc(sizeof(int)*tam_MAX);
}

void push(PILHA *pi, int dado){
    if(pi->pos >= pi->MAX){
        printf("Lista cheia!\n");
        exit(1);
    }
    pi->arr[pi->pos++] = dado;
}

int pop(PILHA *pi){
    if(pi->pos <= 0){
        printf("Lista vazia!\n");
        exit(1);
    }
    return pi->arr[--(pi->pos)];
}

void imprimir(PILHA *pi){
    printf("[");
    for(int i = 0; i < pi->pos - 1; i++)
        printf("%d, ", pi->arr[i]);
    if(pi->pos <= 0)
        printf("]\n");
    else
        printf("%c]\n", pi->arr[pi->pos - 1]);
}

void apagar(PILHA *pi){
    pi->pos = 0;
    free(pi->arr);
    pi->arr = NULL;
}

int tamanho(PILHA *pi){
    return pi->pos;
}
