#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sFILA{
  struct sNODE *ini, *fim;
};

//Definindo o novo tipo
typedef struct sFILA FILA;

//Cabeçalhos
void criar(FILA *fi);
void apagar(FILA *fila);

void enqueue(FILA *fi, int dado);
int dequeue(FILA *fi);

void imprimir(FILA *fi);
int tamanho(FILA *fi);

// A main...
int main(){
  FILA fila1;
  criar(&fila1);

  enqueue(&fila1, 100);
  enqueue(&fila1, 50);
  enqueue(&fila1, 200);

  printf("Dequeue na Fila 1 -> %d\n", dequeue(&fila1));

  imprimir(&fila1);

  apagar(&fila1);

  return 0;
}

// As implementações
void criar(FILA *fi){
  fi->ini = NULL;
  fi->fim = NULL;
}

void enqueue(FILA *fi, int dado){
  struct sNODE *aux = NULL;
  aux = (struct sNODE*) malloc(sizeof(struct sNODE));
  aux->dado = dado;
  aux->prox = NULL;
  
  if(!(fi->ini))
    fi->ini = fi->fim = aux;
  else{
    fi->fim->prox = aux;
    fi->fim = aux;
  }
}

int dequeue(FILA *fi){
  if(!(fi->ini)){
    printf("Lista vazia\n");
    exit(1);
  }
  
  struct sNODE *aux = fi->ini;
  int dado = aux->dado;

  fi->ini = aux->prox;
  free(aux);
  return dado;
}

void imprimir(FILA *fi){
  struct sNODE *aux = fi->ini;
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

int tamanho(FILA *fi){
  struct sNODE *aux = fi->ini;
  int cont = 0;
  while(aux){
    cont++;
    aux = aux->prox;
  }
  return cont;
}

void apagar(FILA *fi){
  struct sNODE *aux = fi->ini, *ant = NULL;
  while(aux){
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  
  fi->ini = fi->fim = NULL;
}
