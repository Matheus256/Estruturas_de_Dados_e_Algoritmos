#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

//Cabeçalhos
void enqueue(int dado);
int dequeue();

int tamanho();
void imprimir();
void apagar();

int getFront();

int main(){
  imprimir();
  enqueue(2);
  enqueue(4);
  enqueue(8);
  imprimir();

  printf("Pegando sem retirar o primeiro da fila que é %d\n", getFront());
  imprimir();

  int x = dequeue();
  imprimir();

  apagar();
  
  return 0;
}

void enqueue(int dado){
  if(pos > MAX){
    printf("Lista cheia!");
    exit(1);
  }
  l[pos++] = dado;
}

int dequeue(){
  if(pos == 0){
    printf("Lista vazia!");
    exit(1);
  }
  int valor = l[0];
  for(int i = 1; i < pos; i++)
    l[i-1] = l[i];
  pos--;
  return valor;
}

void imprimir(){
  printf("[");
  for(int i = 0; i < pos; i++)
    printf(" %d ", l[i]);
  printf("]\n");
}

void apagar(){
  pos = 0;
}

int getFront(){
  if(pos == 0){
    printf("Fila vazia!");
    exit(1);
  }

  return l[0];
}
