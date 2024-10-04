#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

//Precisamos de apenas de uma pilha...
struct sNODE *topo = NULL;

//======= Cabeçalhos ==========
void push(int dado);
int pop();

void imprimir();
void apagar();
int tamanho();

//======= A main ==============
int main(){
  char espressao[101];
  
  printf("Informa a expressão matemática: ");
  int j = scanf("%s", espressao);

  int i = 0;
  while(espressao[i]){
    if(espressao[i] == '(')
      push(1);
    else if(espressao[i] == ')'){
      if(pop() == -1)
        break;
      else if(i > 0 && espressao[i - 1] == '(')
        break;
    } 
    i++;
  }

  if(i == strlen(espressao) && tamanho() == 0)
    printf("OK\n");
  else
    printf("Não OK\n");

  apagar();
  
  return 0;
}

//======= Implementações ======
void push(int dado){
  struct sNODE *node = (struct sNODE*) malloc(sizeof(struct sNODE));
  node->dado = dado;
  node->prox = topo;
  topo = node;
}

int pop(){
  if(!topo)
    return -1;
  
  struct sNODE *aux = topo;
  topo = topo->prox;
  int dado = aux->dado;
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

void apagar(){
  struct sNODE *aux = topo, *ant = NULL;
  while(aux){
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
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
