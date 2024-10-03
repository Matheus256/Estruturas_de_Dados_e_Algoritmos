#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *ant;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

// ================================ CABEÇALHOS DAS FUNÇÕES ======================================================
void inserir(int dado);
void imprimir();
struct sNODE *buscar(int dado);
void remover(int dado);
int obter(struct sNODE *node);
int tamanho();
void apagar();
void inserir_ord(int dado);

void inserir_ini(int dado);
void imprimir_reverso();

int main(void) {
  imprimir();
  inserir_ord(15);
  imprimir();
  inserir_ord(14);
  inserir_ord(12);
  imprimir();
  remover(15);
  imprimir();
  inserir_ini(21);
  imprimir();
  imprimir_reverso();
  return 0;
}

//======================================== IMPLEMENTAÇÔES DAS FUNÇÕES ===========================================

void inserir(int dado){
  struct sNODE *node = malloc(sizeof(struct sNODE));
  node->dado = dado;
  node->prox = node->ant = NULL;

  if(!ini)
    ini = fim = node;
  else
    fim->prox = node;
    node->ant = fim;
    fim = node;
}

void imprimir(){
  struct sNODE *aux = ini;

  //Imprime até o penúltimo
  printf("[");
  while(aux && aux->prox){
    printf("%d, ",aux->dado);
    aux = aux->prox;
  }

  //imprime o último caso exista
  if(aux)
    printf("%d]\n",aux->dado);
  else
    printf("]\n");
}

struct sNODE *buscar(int dado){
  struct sNODE *aux = ini;

  while(aux){
    if(aux->dado == dado)
      return aux;
    aux = aux->prox;
  }
  return aux;
}

void remover(int dado){
  struct sNODE *aux = buscar(dado);

  if (!aux)
    return;
  else if (ini == fim) //Caso a lista tenha um único elemento
    ini = fim = NULL;
  else if(aux == ini){
    ini = aux->prox;
    ini->ant = NULL;
  } else if(aux == fim){
    fim = aux->ant;
    fim->prox = NULL;
  } else {
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
  }
  
  free(aux);
}

int obter(struct sNODE *node){
  if(node)
    return node->dado;
  exit(1);
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
  ini = fim = NULL;
}

void inserir_ord(int dado){
  struct sNODE *node = NULL;
  node = malloc(sizeof(struct sNODE));
  node->dado = dado;
  node->prox = node->ant = NULL;

  if (!ini){
    ini = fim = node;
    return;
  }

  struct sNODE *aux = ini;
  while(aux && aux->dado < dado)
    aux = aux->prox;

  if (aux == ini){
    node->prox = ini;
    ini->ant = node;
    ini = node;
  } else if(!aux){
    fim->prox = node;
    node->ant = fim;
    fim = node;
  } else {
    node->prox = aux;
    node->ant = aux->ant;
    aux->ant = node;
    aux->ant->prox = node;
  }
}

//======================================== FUNÇÕES DAS QUESTÕES 1 ===============================================

//=== a. INSERIR_INI =========
void inserir_ini(int dado){
  struct sNODE *node = malloc(sizeof(struct sNODE));
  node->dado = dado;
  node->prox = node->ant = NULL;

  if(!ini)
    ini = fim = node;
  else {
    node->prox = ini;
    ini->ant = node;
    ini = node;
  }
}

//======== b. IMPRIMIR_REVERSO =====================
void imprimir_reverso(){
  struct sNODE *aux = fim;

  printf("[");
  while(aux && aux->ant){
    printf("%d, ", aux->dado);
    aux = aux->ant;
  }

  if(aux)
    printf("%d]\n", aux->dado);
  else
    printf("]\n");
}
