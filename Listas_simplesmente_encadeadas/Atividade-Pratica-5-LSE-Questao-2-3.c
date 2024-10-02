#include <stdio.h>
#include <stdlib.h>

//Definição do tipo nó
struct sNode{
  int dado;
  struct sNode *prox;
};

//Definição do tipo Lista
struct sLISTA{
  struct sNode *ini, *fim;
};

//Alias para lista
typedef struct sLISTA LISTA;

//Cabeçalhos das funções
void inicializar(LISTA *lst);
void apagar(LISTA *lst);

void inserir_ord(LISTA *lst, int dado);
void remover(LISTA *lst, int dado);
struct sNode *buscar(LISTA *lst, int dado);

int obter(struct sNode *node);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);

//Juntar listas 
LISTA juntar_ord(LISTA *lst1, LISTA *lst2);


int main(void) {
  LISTA lst, lst2, lst3;
  inicializar(&lst);
  inicializar(&lst2);
  inicializar(&lst3);

  inserir_ord(&lst, 100);
  inserir_ord(&lst, 222);
  inserir_ord(&lst, 12);
  inserir_ord(&lst,1111);
  imprimir(&lst);
  //printf("Tamanho da Lista = %d\n",tamanho(&lst));

  //remover(&lst,1111);
  //apagar(&lst);

  inserir_ord(&lst2, 333);
  inserir_ord(&lst2, 44);
  inserir_ord(&lst2, 555);

  imprimir(&lst2);

  LISTA nova_lst = juntar_ord(&lst, &lst2);
  imprimir(&nova_lst);
  //inserir_ord(&lst3, 444);
  imprimir(&lst3);
  
  //return 0;
}

void inicializar(LISTA *lst){
  lst->ini = NULL;
  lst->fim = NULL;
}

void apagar(LISTA *lst){
  struct sNode *aux = lst->ini, *ant = NULL;
  while(aux){
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  lst->ini = lst->fim = NULL;
}

void inserir_ord(LISTA *lst, int dado){
  struct sNode *node = NULL, *aux = lst->ini, *ant = NULL;
  node = malloc(sizeof(struct sNode));
  node->dado = dado;
  node->prox = NULL;

  while(aux){
    if (aux->dado > dado)
      break;
    ant = aux;
    aux = aux->prox;
  }

  if(!(lst->ini))
    lst->ini = lst->fim = node;
  else if (aux == lst->ini){
    node->prox = lst->ini;
    lst->ini = node;
  } else if (ant == lst->fim){
    lst->fim->prox = node;
    lst->fim = node;
  } else {
    ant->prox = node;
    node->prox = aux;
  }
}

void remover(LISTA *lst, int dado){
  struct sNode *aux = lst->ini, *ant = NULL;
  while(aux){
    if(aux->dado == dado){
      if (aux == lst->ini){
        lst->ini = aux->prox;
      } else if (aux == lst->fim){
        lst->fim = ant;
        ant->prox = NULL;
      } else {
        ant->prox = aux->prox;
      }
      free(aux);
      return;
    }
    ant = aux;
    aux = aux->prox;
  }
}

struct sNode *buscar(LISTA *lst, int dado){
  struct sNode *aux = lst->ini;
  while(aux){
    if (aux->dado == dado)
      return aux;
  }
  return aux;
}

int obter(struct sNode *node){
  if(!node){
    printf("Erro...");
    exit(1);
  }
  return node->dado;
}

int tamanho(LISTA *lst){
  struct sNode *aux = lst->ini;
  int cont = 0;
  while(aux){
    cont++;
    aux = aux->prox;
  }
  return cont;
}

//Imprimir a lista igual ao python hehehehe
void imprimir(LISTA *lst){
  struct sNode *aux = lst->ini;
  
  printf("[");
  while(aux && aux->prox){
    printf(" %d,", aux->dado);
    aux = aux->prox;
  }
  if (aux)
    printf(" %d ]\n", aux->dado);
  else
    printf("]\n");
}

LISTA juntar_ord(LISTA *lst1, LISTA *lst2){
  //Criando nova lista
  LISTA nova;
  inicializar(&nova);
  
  struct sNode *aux = lst1->ini;

  //Inserção dos nós da primeira lista
  while(aux){
    inserir_ord(&nova, aux->dado);
    aux = aux->prox;
  }

  //Inserção dos nós da segunda lista
  aux = lst2->ini;
  while(aux){
    inserir_ord(&nova, aux->dado);
    aux = aux->prox;
  }

  return nova;
}
