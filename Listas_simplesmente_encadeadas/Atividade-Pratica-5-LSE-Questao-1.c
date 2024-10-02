#include <stdio.h>
#include <stdlib.h>

struct sNode {
  int dado;
  struct sNode *prox;
};

struct sNode *ini = NULL, *fim = NULL;

void inserir(int dado);
void remover(int dado);
struct sNode *buscar(int dado);
int obter(struct sNode *node);
int tamanho();
void imprimir();
void apagar();

//===== Atividades =====//
void inserir_ini(int dado);
void inserir_ord(int dado);

//================= MAIN ======================
int main(void) {
  imprimir();

  inserir_ord(12);
  inserir_ord(7);
  inserir_ord(14);

  imprimir();
  printf("Tamanho = %d\n", tamanho());

  remover(32);
  
  inserir_ord(8);
  inserir_ord(7);
  
  imprimir();
}

//================= IMPLEMENTAÇÕES ============

void inserir(int dado){
  struct sNode *node = NULL;
  node = malloc(sizeof(struct sNode));
  node->dado = dado;
  node->prox = NULL;

  if (!ini)
    ini = fim = node;
  else {
    fim->prox = node;
    fim = node;
  }
}

void remover(int dado){
  if (!ini)
    return;
  
  struct sNode *aux = ini, *ant = NULL;
  while(aux){
    if (aux->dado == dado)
      break;
    ant = aux;
    aux = aux->prox;
  }

  if (aux == ini)
    ini = aux->prox;
  else if (aux == fim){
    fim = ant;
    fim->prox = NULL;
  } else if (!aux)
      return;
    else 
      ant->prox = aux->prox;
  
  free(aux);
}

struct sNode *buscar(int dado){
  struct sNode *aux = ini;
  while (aux){
    if (aux->dado == dado)
      return aux;
    aux = aux->prox;
  }
  return aux;
}

int obter(struct sNode *node){
  if (!node){
    printf("Erro...\n");
    return -1;
  } else
    return node->dado;
}

int tamanho(){
  struct sNode *aux = ini;
  int cont = 0;
  while(aux){
    cont++;
    aux  = aux->prox;
  }
  return cont;
}

void imprimir(){
  struct sNode *aux = ini;
  printf("[");
  while(aux){
    printf(" %d ",aux->dado);
    aux = aux->prox;
  }
  printf("]\n");
}

void apagar(){
  struct sNode *aux = ini, *ant = NULL;
  while(aux){
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  ini = fim = NULL;
}

//===== Atividades =====//
void inserir_ini(int dado){
  struct sNode *node = NULL;
  node = malloc(sizeof(struct sNode));
  node->dado = dado;

  if (!ini){
    ini = fim = node;
    node->prox = NULL;
  } else {
    node->prox = ini;
    ini = node;
  }
}

void inserir_ord(int dado){
  struct sNode *node = NULL, *aux = ini, *ant = NULL;
  node = malloc(sizeof(struct sNode));
  node->dado = dado;
  node->prox = NULL;
  
  while(aux){
    if(aux->dado > dado)
        break;
    ant = aux;
    aux = aux->prox;
  }

  if(!ini)
    ini = fim = node;
  else if(ant == fim){
    ant->prox = node;
    fim = node;
  } else if (aux == ini){
    node->prox = ini;
    ini = node;
  } else {
    ant->prox = node;
    node->prox = aux;
  }
}
