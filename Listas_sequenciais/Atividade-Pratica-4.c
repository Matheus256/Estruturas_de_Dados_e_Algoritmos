#include <stdio.h>
#include <stdlib.h>

typedef struct{
  unsigned MAX;
  int *arr, pos;
} LISTA;


//Cabeçalhos
void criar(LISTA *lst, int tam_MAX);
void inserir_ord(LISTA *lst, int elemento);
int buscar(LISTA *lst, int elemento);
void remover(LISTA *lst, int elemento);
int obter(LISTA *lst, int indice);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);
void apagar(LISTA *lst);


//## dica 1 - as implementações podem ficar abaixo da main
//Subrotinas

void criar(LISTA *lst, int tam_MAX){
  lst->MAX = tam_MAX;
  lst->pos = 0;
  lst->arr = (int*) malloc(sizeof(int) * tam_MAX);
  //## dica 2 - não falei em sala, mas caso o processo não consiga alocar a memória, é retornado um ponteiro nulo. Podemos verificar e resolver da seguinte forma:
  if (!lst->arr)
  {
    printf("Erro fatal! Memoria nao pode ser alocada.");
    exit(1); //## dica 3 - como o resto do programa pressupoe a existencia da memoria alocada e esta nao foi, a unica saida eh encerrar o programa com status 1 - um status de erro
  }
}

void inserir_ord(LISTA *lst, int elemento){
  int aux;
  if (lst->pos >= lst->MAX){
    printf("Lista cheia\n");
  } else{
    lst->arr[lst->pos] = elemento;
    lst->pos++;
    for (int i = lst->pos - 1; i > 0; i--)
      if (lst->arr[i-1] > lst->arr[i]){
        aux = lst->arr[i-1];
        lst->arr[i-1] = lst->arr[i];
        lst->arr[i] = aux;
      }
  }
}

int buscar(LISTA *lst, int elemento){
  for (int i = 0; i < lst->pos; i++)
    if (lst->arr[i] == elemento)
      return i;
  return -1;
}

void remover(LISTA *lst, int elemento){
  int indice = buscar(lst, elemento);
  if (indice == -1)
    printf("Elemento não existe na lista\n");
  else {
    for (int i = indice; i < lst->pos - 1; i++)
      lst->arr[i] = lst->arr[i+1];
    lst->pos--;
  }
}

int obter(LISTA *lst, int indice){
  if (indice >= 0 && indice <= lst->MAX)
    return lst->arr[indice];
  else
    return -1;
}

int tamanho(LISTA *lst){
  return lst->pos;
}

void imprimir(LISTA *lst){
  if (lst->pos > 0){
    printf("[");
    for (int i = 0; i < lst->pos - 1; i++)
      printf(" %d,", lst->arr[i]);
    printf(" %d ]\n", lst->arr[lst->pos-1]); // ## dica 5 - bem esperta, essa solução, mas não teve como escapar do if. Porém, como o if foi para fora do for, ele foi executado apenas uma vez, sendo mais eficiente do que ser testado em cada loop do for. Parabéns.
  } else 
    printf("[]\n");
}

void apagar(LISTA *lst){
  free(lst->arr);
  lst->pos = 0;
  lst->arr = NULL; //## dica 6 - também não falei em sala, mas, em se tratando de ponteiros, excesso de cuidado nunca é demais. A função free libera a memória alocada apontada por arr, mas não apaga o endereço contido em arr. Precisamos fazer isso manualmente, para evitar problemas futuros.
}

int main(void) {
  LISTA l1, l2;

  criar(&l1,10);
  criar(&l2,20);

  inserir_ord(&l1,10);
  inserir_ord(&l1,20);
  inserir_ord(&l1,5);

  imprimir(&l1);
  imprimir(&l2);

  remover(&l1,5);
  inserir_ord(&l2,7);

  imprimir(&l1);
  imprimir(&l2);

  //apagar(&l1);
  apagar(&l1);
  
  imprimir(&l1);
  imprimir(&l2);

  return 0;
}
