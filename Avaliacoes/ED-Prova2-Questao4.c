#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EMOCAO {
   char nome[18];
   int freq;
};

struct NO {
   struct EMOCAO emocao;
   struct NO *ant, *prox;
};

typedef struct{
  struct NO *ini, *fim;
} LISTA;

void inicializar(LISTA *lst);
void inserir(LISTA *lst, struct EMOCAO emocao);
void imprimir(LISTA *lst);

//================ (Funções da Questão 4) ===================================

//==== Função do item a) =======
void emocao_no_controle(LISTA *lst, char emocao[]);

//==== Função do item b) =======
struct NO *emocao_dominante(LISTA *lst);

//==== Função do item c) =======
struct NO *emocao_submissiva(LISTA *lst);

//================ (Funções da Questão 4) ===================================

int main(void) {
  LISTA Riley;
  inicializar(&Riley);

  struct EMOCAO alegria = {"alegria", 0}, raiva = {"raiva", 0}, tristeza = {"tristeza", 0};
  struct EMOCAO medo = {"medo", 0}, nojo = {"nojo", 0};

  inserir(&Riley, alegria);
  inserir(&Riley, raiva);
  inserir(&Riley, tristeza);
  inserir(&Riley, medo);
  inserir(&Riley, nojo);
  printf("Começando...\n\n");
  imprimir(&Riley);
  printf("\n");

  printf("Os dias vão passando... as coisas vão acontecendo... e as emoções vão vindo...\n");
  emocao_no_controle(&Riley, "alegria");
  emocao_no_controle(&Riley, "alegria");
  emocao_no_controle(&Riley, "raiva");
  emocao_no_controle(&Riley, "tristeza");
  emocao_no_controle(&Riley, "alegria");
  printf("\n");

  imprimir(&Riley);
  printf("\n");
  
  struct NO *dominante = emocao_dominante(&Riley);
  printf("A emoção dominanate foi '%s', com uma frequência de %d vezes!\n\n", dominante->emocao.nome, dominante->emocao.freq);

  struct NO *submissiva = emocao_submissiva(&Riley);
  printf("A emoção submissiva foi '%s', com uma frequência de %d vezes.\n", submissiva->emocao.nome, submissiva->emocao.freq);
  
  return 0;
}

void inicializar(LISTA *lst){
  lst->ini = NULL;
  lst->fim = NULL;
}

void inserir(LISTA *lst, struct EMOCAO emocao){
  struct NO *node = malloc(sizeof(struct NO));
  node->emocao = emocao;
  node->prox = node->ant = NULL;

  if(!(lst->ini))
    lst->ini = lst->fim = node;
  else{
    lst->fim->prox = node;
    node->ant = lst->fim;
    lst->fim = node;
  }
}

void imprimir(LISTA *lst){
  struct NO *aux = lst->ini;
  printf("[");
  while(aux && aux->prox){
    printf("(%s, %d), ", aux->emocao.nome, aux->emocao.freq);
    aux = aux->prox;
  }
  if(aux)
    printf("(%s, %d)]\n", aux->emocao.nome, aux->emocao.freq);
  else
    printf("]\n");
}

//==== Função do item a) =======

void emocao_no_controle(LISTA *lst, char emocao[]){
  struct NO *aux = lst->ini;

  while(aux){
    if(strcmp(aux->emocao.nome, emocao) == 0){
      aux->emocao.freq++;
    }
    aux = aux->prox;
  }
}

//==== Função do item a) =======

//==== Função do item b) =======

struct NO *emocao_dominante(LISTA *lst){
  struct NO *aux = lst->ini, *dominante = lst->ini;
  int maior = aux->emocao.freq;

  while(aux){
    if(aux->emocao.freq > maior){
      maior = aux->emocao.freq;
      dominante = aux;
    }
    aux = aux->prox;
  }

  return dominante;
}

//==== Função do item b) =======

//==== Função do item c) =======

struct NO *emocao_submissiva(LISTA *lst){
  struct NO *aux = lst->ini, *submissiva = lst->ini;
  int menor = submissiva->emocao.freq;

  while(aux){
    if(aux->emocao.freq < menor){
      submissiva = aux;
      menor = aux->emocao.freq;
    }
    aux = aux->prox;
  }

  return submissiva;
}

//==== Função do item c) =======
