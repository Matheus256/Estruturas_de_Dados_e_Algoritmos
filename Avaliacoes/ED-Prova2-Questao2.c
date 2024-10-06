#include <stdio.h>
#include <stdlib.h>

typedef struct{
  unsigned MAX;
  int *l, pos;
} LISTA;

void criar(LISTA *lst, int tam_MAX);
void inserir(LISTA *lst, int dado);
void imprimir(LISTA *lst);
int tamanho(LISTA *lst);

//================ (Função da Questão 2) ====================================

void domingos_divertidos(LISTA *lst);

//================ (Função da Questão 2) ====================================

int main(void) {
  LISTA julho;
  criar(&julho, 31);
  
  for(int i = 1; i < 32;i++)
    inserir(&julho, i);

  imprimir(&julho);
  printf("Tamanho atual da lista de julho: %d\n", tamanho(&julho));
  printf("\n");

  //Removendo os domigos divertidos
  domingos_divertidos(&julho);
  imprimir(&julho);
  printf("Tamanho atual da lista de julho: %d\n", tamanho(&julho));
  
  return 0;
}

void criar(LISTA *lst, int tam_MAX){
  lst->MAX = tam_MAX;
  lst->pos = 0;
  lst->l = malloc(tam_MAX*sizeof(int));
}

void inserir(LISTA *lst, int dado){
  if(lst->pos >= lst->MAX){
    printf("Lista cheia\n");
    return;
  } else{
    lst->l[lst->pos] = dado;
    (lst->pos)++;
  }
}

void imprimir(LISTA *lst){
  printf("[");
  for(int i = 0; i < lst->pos - 1; i++){
    printf("%d, ", lst->l[i]);
    if(((i+1)%6) == 0)
      printf("\n");
  }
  printf("%d]\n", lst->l[lst->pos - 1]);
  printf("\n");
}

int tamanho(LISTA *lst){
  return lst->pos;
}

//================ (Função da Questão 2) ====================================

void domingos_divertidos(LISTA *lst){
  for(int i = 0; i < lst->pos; i++){
    if((lst->l[i] % 7) == 0){
      for(int p = i; p < lst->pos - 1; p++)
        lst->l[p] = lst->l[p + 1];
      (lst->pos)--;
    }
  }
}

//================ (Função da Questão 2) ====================================
