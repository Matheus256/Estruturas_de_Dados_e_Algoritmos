#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], ini = 0, fim = 0;

//Cabeçalhos das funcionalidades da fila circular
//Principais funções
void enqueue(int elemento);
int dequeue();

//Funções auxiliares
int tamanho();
void imprimir();
void apagar();

int main(){

  //Codigos de teste aqui
  enqueue(100);
  enqueue(50);
  enqueue(75);
  enqueue(75);
  enqueue(75);
  enqueue(75);
  enqueue(75);
  enqueue(75);
  enqueue(80);
  
  printf("Dequeue -> %d\n", dequeue());
  printf("Dequeue -> %d\n", dequeue());
  printf("Dequeue -> %d\n", dequeue());
  printf("Dequeue -> %d\n", dequeue());

  enqueue(80);enqueue(80);enqueue(80);
  
  imprimir();
  printf("Tamanho = %d\n",tamanho());
  
  printf("Dequeue -> %d\n", dequeue());
  printf("Dequeue -> %d\n", dequeue());
  
  imprimir();
  
  printf("Dequeue -> %d\n", dequeue());
  
  imprimir();
  
  printf("Dequeue -> %d\n", dequeue());
  
  enqueue(50);
  enqueue(50);
  enqueue(50);
  enqueue(50);
  
  imprimir();

  return 0;
}


//Implementações
void enqueue(int elemento){
  if( (fim + 1) != ini && !(fim + 1 == MAX && !ini)){
    l[fim] = elemento;
    fim = (fim + 1) % MAX;
  } else {
    printf("A fila está cheia\n");
  }
}

int dequeue(){
  if(ini == fim){
    printf("A fila está vazia\n");
    exit(1);
  }
  
  int retorno = l[ini];
  ini = (ini + 1) % MAX;
  return retorno;
}

int tamanho(){
  if(fim >= ini)
    return fim - ini;
  else
    return MAX - (ini -fim);
}

void imprimir(){
  printf("[");
  for(int i = ini; ;i++){
    if(i == MAX) i = 0;
    if(i == fim) break;
    printf(" %d ", l[i]);
  }
  printf("]\n");
}

void apagar(){
  ini = fim = 0;
}
