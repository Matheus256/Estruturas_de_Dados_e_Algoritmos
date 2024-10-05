#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

//Cabeçalhos
void enqueue(int dado);
int dequeue();

void imprimir();
void apagar();
int tamanho();

int getFront();

int main(){
  imprimir();
  enqueue(2);
  enqueue(12);
  enqueue(123);
  imprimir();

  printf("Retiramos o primeiro da fila que é %d\n", dequeue());
  imprimir();

  printf("O atual valor no começo da fila é %d\n", getFront());
  imprimir();

  apagar();

  
  return 0;
}

void enqueue(int dado){
  struct sNODE *node = (struct sNODE*) malloc(sizeof(struct sNODE));
  node->dado = dado;
  node->prox = NULL;
  
  if(!ini)
    ini = fim = node;
  else{
    fim->prox = node;
    fim = node;
  }
}

int dequeue(){
  if(!ini){
    printf("Fila vazia!");
    exit(1);
  }
  struct sNODE *aux = ini;
  int retorno = aux->dado;
  ini = aux->prox;
  free(aux);
  return retorno;
  
}

void imprimir(){
  struct sNODE *aux = ini;
  printf("[");
  while(aux && aux->prox){
    printf("%d, ", aux->dado);
    aux = aux->prox;
  }
  if(aux)
    printf("%d]\n", aux->dado);
  else
    printf("]\n");
}

int tamanho(){
  struct sNODE *aux = ini;
  int cont = 0;
  
  while(aux){
    cont++;
    aux = aux->prox;
  }

  return cont;
}

void apagar(){
  struct sNODE *aux = ini, *ant = NULL;

  while(aux){
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
}

int getFront(){
  if(!ini){
    printf("Fila vazia!");
    exit(1);
  }
  return ini->dado;
}
