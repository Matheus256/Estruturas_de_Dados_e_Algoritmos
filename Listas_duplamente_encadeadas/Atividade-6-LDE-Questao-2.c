#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox, *ant;
};

//Definição do tipo lista que permite criar varias listas
struct sLISTA{
  struct sNODE *ini, *fim;
};

typedef struct sLISTA LISTA;

//Cabeçalhos das funções
void inicializar(LISTA *lst);
void apagar(LISTA *lst);

void inserir_ord(LISTA *lst, int dado);
void remover(LISTA *lst, int dado);
struct sNODE *buscar(LISTA *lst, int dado);

int obter(struct sNODE *node);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);

int main(void) {
  LISTA lst;
  inicializar(&lst);

  inserir_ord(&lst, 100);
  inserir_ord(&lst, 12);
  inserir_ord(&lst, 1);
  imprimir(&lst);

  remover(&lst,0);
  remover(&lst, 100);
  imprimir(&lst);

  apagar(&lst);
  
  return 0;
}

//======================= IMPLEMENTAÇÕES DAS FUNÇÔES =========================

void inicializar(LISTA *lst){
  lst->ini = NULL;
  lst->fim = NULL;
}

void inserir_ord(LISTA *lst, int dado){
  struct sNODE *node = (struct sNODE*) malloc(sizeof(struct sNODE));
  node->dado = dado;
  node->ant = node->prox = NULL;

  if(!(lst->ini)){
    lst->ini = lst->fim = node;
    return;
  }

  struct sNODE *aux = lst->ini;
  while(aux && aux->dado < dado)
    aux = aux->prox;

  if(aux == lst->ini){
    lst->ini->ant = node;
    node->prox = lst->ini;
    lst->ini = node;
  } else if(!aux){
    lst->fim->prox = node;
    node->ant = lst->fim;
    lst->fim = node;
  } else {
    node->prox = aux;
    node->ant = aux->ant;
    aux->ant->prox = node;
    aux->ant = node;
  }
}

void imprimir(LISTA *lst){
  struct sNODE *aux = lst->ini;
  
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

void apagar(LISTA *lst){
  struct sNODE *aux = lst->ini, *ant = NULL;

  while(aux){
    ant = aux;
    aux = aux->prox;
    free(ant);
  }

  lst->ini = NULL;
  lst->fim = NULL;
}

struct sNODE *buscar(LISTA *lst, int dado){
  struct sNODE *aux = lst->ini;
  while(aux){
    if(aux->dado == dado)
      return aux;
    aux = aux->prox;
  }
  return aux;
}

void remover(LISTA *lst, int dado){
  struct sNODE *aux = buscar(lst, dado);

  if(!aux)
    return;
  else if(lst->ini == lst->fim)
    lst->ini = lst->ini = NULL;
  else if(aux == lst->ini){
    lst->ini = aux->prox;
    lst->ini->ant = NULL;
  } else if(aux == lst->fim){
    aux->ant->prox = NULL;
    lst->fim = aux->ant;
  } else {
    aux->prox->ant = aux->ant;
    aux->ant->prox = aux->prox;
  }

  free(aux);
}

int obter(struct sNODE *node){
  if(node)
    return node->dado;
  exit(1);
}

int tamanho(LISTA *lst){
  struct sNODE *aux = lst->ini;
  int cont = 0;

  while(aux){
    cont++;
    aux = aux->prox;
  }

  return cont;
}
