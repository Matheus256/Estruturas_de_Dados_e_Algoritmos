#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int l[MAX], pos = 0;

//============ Cabeçalhos ================
void push(int dado);
int pop();

int tamanho();
void imprimir();
void apagar();

int getTopo();

//================== A main ==============
int main(){
    imprimir();
    //int x = pop();
    push(1);
    imprimir();
    push(2);
    imprimir();
    push(4);
    imprimir();

    printf("No topo temos %d\n", getTopo());
    imprimir();


    printf("Desempilhando novamente temos %d\n", pop());
    imprimir();

    return 0;
}

//================= Implementações =======
void push(int dado){
    if(pos >= MAX){
        printf("Lista cheia!\n");
        exit(1);
    }
    l[pos++] = dado;
}

int pop(){
    if(pos <= 0){
        printf("Lista vazia!\n");
        exit(1);
    }
    return l[--pos];
}

void imprimir(){
    printf("[");
    for(int i = 0; i < pos - 1; i++)
        printf("%d, ", l[i]);
    if(pos <= 0)
        printf("]\n");
    else
        printf("%d]\n", l[pos - 1]);
}

int getTopo(){
    if(pos <= 0)
        printf("Lista vazia!\n");
    return l[pos - 1];
}
