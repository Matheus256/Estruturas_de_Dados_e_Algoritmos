#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  unsigned MAX;
  char **l;
  int pos;
} LISTA;

//Cabeçalhos
void criar(LISTA *lst, int tam_MAX);
void inserir_ord(LISTA *lst, char elemento[]);
void imprimir(LISTA *lst);
void remover(LISTA *lst, char elemento[]);

int main(void) {
  
  //printf("%d\n", strcmp("Isabella","Matheus"));

  LISTA nomes;

  criar(&nomes, 10);
  
  inserir_ord(&nomes, "Matheus");
  inserir_ord(&nomes, "Isabella");
  inserir_ord(&nomes, "Carol");
  inserir_ord(&nomes, "Ana");
  inserir_ord(&nomes, "Matheus M");
  inserir_ord(&nomes, "Bella");
  inserir_ord(&nomes, "Batman");
  inserir_ord(&nomes, "Bob Esponja");
  inserir_ord(&nomes, "Patric Estrela");
  inserir_ord(&nomes, "Harry Poter");
  inserir_ord(&nomes, "Peter Parker");
  imprimir(&nomes);

  remover(&nomes, "Ana");
  remover(&nomes, "Carol");
  imprimir(&nomes);
  
  return 0;
}

void criar(LISTA *lst, int tam_MAX){
  lst->pos = 0;
  lst->MAX = tam_MAX;
  lst->l = malloc(tam_MAX*sizeof(char*));
  for(int i = 0; i < tam_MAX; i++)
    lst->l[i] = malloc(21*sizeof(char)); 
}

void inserir_ord(LISTA *lst, char elemento[]){
  int i;
  
  if(lst->pos >= lst->MAX){
    printf("Lista cheia.\n");
    return;
  }

  for(i = 0; i < lst->pos; i++){
    if(strcmp(lst->l[i],elemento) > 0){
      for (int p = lst->pos; p > i; p--)
        strcpy(lst->l[p], lst->l[p - 1]);
      break;
    }
  }
  
  strcpy(lst->l[i], elemento);
  (lst->pos)++;
}

void imprimir(LISTA *lst){
  printf("[");
  for(int i = 0; i < lst->pos - 1; i++){
    printf("'%s', ", lst->l[i]);
  }
  printf("'%s']\n", lst->l[lst->pos - 1]);
}

void remover(LISTA *lst, char elemento[]){
  for(int i = 0; i < lst->pos; i++){
    if(strcmp(lst->l[i], elemento) == 0){
      for(int p = i; p < lst->pos -1; p++)
        strcpy(lst->l[p], lst->l[p + 1]);
      (lst->pos)--;
      break;
    }
  }
}
