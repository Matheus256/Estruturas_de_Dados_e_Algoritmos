#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *topo = NULL;

//=============== Cabeçalhos ==============
void push(int dado);
int pop();

void imprimir();
int tamanho();
void apagar();

int getTopo();

//============== A main ===================
int main(){
  push(1);
  push(3);
  push(5);
  imprimir();
  printf("O número %d está no topo da pilha.\n", getTopo());
  imprimir();
  printf("Retiramos %d do topo da pilha.\n", pop());
  imprimir();

  apagar();
  
  return 0;
}

//============= Implementações ============

void push(int dado){
  struct sNODE *node = (struct sNODE*) malloc(sizeof(struct sNODE));
  node->dado = dado;
  node->prox = topo;
  topo = node;
}

int pop(){
  if(!topo){
    printf("Lista vazia!");
    exit(1);
  }
  struct sNODE *aux = topo;
  int dado = topo->dado;
  topo = topo->prox;
  free(aux);
  return dado;
}

void imprimir(){
  struct sNODE *aux = topo;
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
  struct sNODE *aux = topo;
  int cont = 0;

  while(aux){
    cont++;
    aux = aux->prox;
  }

  return cont;
}

void apagar(){
  struct sNODE *aux = topo, *ant= NULL;
  while(aux){
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
}

int getTopo(){
  if(!topo){
    printf("Lista vazia.\n");
    exit(1);
  }
  return topo->dado;
}
