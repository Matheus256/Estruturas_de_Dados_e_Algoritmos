#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNODE{
  char dado;
  struct sNODE *prox;
};

struct sNODE *topo = NULL;

//=============== Cabeçalhos ==============
void push(char dado);
char pop();

void imprimir();
int tamanho();
void apagar();

char getTopo();

//============== A main ===================
int main(){

  char entrada[101];
  printf("Informe o text: ");
  fgets(entrada, 101, stdin);

  int size = strlen(entrada);
  for(int i = 0; i < size; i++){
    if(entrada[i] != ' ' && entrada[i] != '\n'){
      push(entrada[i]);
    }else{ 
      while(topo)
        printf("%c", pop());
      
      printf(" ");
    }
  }
  printf("\n");
  
  apagar();

  return 0;
}

//============= Implementações ============

void push(char dado){
  struct sNODE *node = (struct sNODE*) malloc(sizeof(struct sNODE));
  node->dado = dado;
  node->prox = topo;
  topo = node;
}

char pop(){
  if(!topo){
    printf("Lista vazia!");
    exit(1);
  }
  struct sNODE *aux = topo;
  char dado = topo->dado;
  topo = topo->prox;
  free(aux);
  return dado;
}

void imprimir(){
  struct sNODE *aux = topo;
  printf("[");
  while(aux && aux->prox){
    printf("%c, ", aux->dado);
    aux = aux->prox;
  }
  if(aux)
    printf("%c]\n", aux->dado);
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

char getTopo(){
  if(!topo){
    printf("Lista vazia.\n");
    exit(1);
  }
  return topo->dado;
}
