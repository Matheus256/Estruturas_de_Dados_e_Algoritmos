#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *ant, *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

//Cabeçalhos
void inserir_ini(int dado);
int remover_ini();

void inserir_fim(int dado);
int remover_fim();

void imprimir();
int tamanho();
void apagar();

// A main
int main(){
  
  inserir_ini(12);
  inserir_fim(7);
  imprimir();

  inserir_fim(8);
  inserir_ini(14);
  imprimir();

  printf("Removido do inicio do deque -> %d\n",remover_ini());
  imprimir();
  printf("Removido do fim do deque -> %d\n",remover_fim());
  
  imprimir();

  apagar();
  return 0;
}

//Implementações
void inserir_ini(int dado){
  struct sNODE *aux = (struct sNODE*) malloc(sizeof(struct sNODE));
  aux->dado = dado;
  aux->ant = NULL;
  aux->prox = NULL;

  if(!ini)
    ini = fim = aux;
  else{
    aux->prox = ini;
    ini->ant = aux;
    ini = aux;
  }
}

int remover_ini(){
  if(!ini){
    printf("Deque vazia\n");
    exit(1);
  }

  struct sNODE *aux = ini;
  int dado = aux->dado;
  ini = aux->prox;
  ini->ant = NULL;
  free(aux);
  return dado;
}

void inserir_fim(int dado){
  struct sNODE *aux = (struct sNODE*) malloc(sizeof(struct sNODE));
  aux->dado = dado;
  aux-> ant = NULL;
  aux->prox = NULL;
  
  if(!ini)
    ini = fim = aux;
  else{
    fim->prox = aux;
    aux->ant = fim;
    fim = aux;
  }
}

int remover_fim(){
  if(!ini){
    printf("Deque vazio\n");
    exit(1);
  }

  struct sNODE *aux = fim;
  int dado = fim->dado;
  fim = fim->ant;
  fim->prox = NULL;
  
  free(aux);
  return dado;
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

void apagar(){
  struct sNODE *aux = ini, *ant = NULL;
  while(aux){
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
}
