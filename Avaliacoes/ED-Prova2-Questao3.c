#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NO {
   char emocao[18];
   struct NO *prox;
};

typedef struct{
  struct NO *ini, *fim; 
} LISTA;

void inicializar(LISTA *lst);
void inserir(LISTA *lst, char emocao[]);
void imprimir(LISTA *lst);

//================ (Função da Questão 3) ====================================

LISTA embate_emocoes(LISTA *lst1, LISTA *lst2);

//================ (Função da Questão 3) ====================================

int main(void) {
  LISTA lista1, lista2;
  inicializar(&lista1);
  inicializar(&lista2);

  inserir(&lista1, "alegria");
  inserir(&lista1, "raiva");
  inserir(&lista1, "tristeza");
  inserir(&lista1, "medo");
  inserir(&lista1, "nojo");
  imprimir(&lista1);

  inserir(&lista2, "nojo");
  inserir(&lista2, "medo");
  inserir(&lista2, "tristeza");
  inserir(&lista2, "raiva");
  inserir(&lista2, "alegria");
  imprimir(&lista2);

  LISTA resultado = embate_emocoes(&lista1, &lista2);
  imprimir(&resultado);
  
  return 0;
}

void inicializar(LISTA *lst){
  lst->ini = NULL;
  lst->fim = NULL;
}

void inserir(LISTA *lst, char emocao[]){
  struct NO *node = malloc(sizeof(struct NO));
  strcpy(node->emocao, emocao);

  if(!(lst->ini))
    lst->ini = lst->fim = node;
  else{
    lst->fim->prox = node;
    lst->fim = node;
  }
}

void imprimir(LISTA *lst){
  struct NO *aux = lst->ini;
  printf("[");
  while(aux && aux->prox){
    printf("'%s', ", aux->emocao);
    aux = aux->prox;
  }
  if(aux)
    printf("'%s']\n", aux->emocao);
  else
    printf("]\n");

  printf("\n");
}

//================ (Função da Questão 3) ====================================

LISTA embate_emocoes(LISTA *lst1, LISTA *lst2){
  LISTA embate;
  inicializar(&embate);
  
  struct NO *aux1 = lst1->ini;
  struct NO *aux2 = lst2->ini;

  while((aux1) && (aux2)){
    if( strlen(aux1->emocao) < strlen(aux2->emocao) )
      inserir(&embate, aux1->emocao);
    else
      inserir(&embate, aux2->emocao);
    
    aux1 = aux1->prox;
    aux2 = aux2->prox;
  }

  return embate;
}

//================ (Função da Questão 3) ====================================
