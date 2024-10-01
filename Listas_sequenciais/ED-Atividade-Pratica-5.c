#include <stdio.h>
#include <stdlib.h>

typedef struct{
  unsigned MAX;
  int *arr, pos;
} LISTA;


//Cabeçalhos
void criar(LISTA *lst, int tam_MAX);
void inserir(LISTA *lst, int elemento);
void inserir_ord(LISTA *lst, int elemento);
int buscar(LISTA *lst, int elemento);
void remover(LISTA *lst, int elemento);
int obter(LISTA *lst, int indice);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);
void apagar(LISTA *lst);

//Funções para dos exercícios Extras
int contar(LISTA *lst, int elemento);
int pop(LISTA *lst);
void inserirPos(LISTA *lst, int posicao,int elemento);
void copiar(LISTA *lst1, LISTA *lst2);
void estender(LISTA *lst1, LISTA *ls2);
void inverter(LISTA *lst1, LISTA * lst2);
void redimensionar(LISTA *lst, int MAX);

void inserir_v2(LISTA *lst, int elemento);
void inserirPos_v2(LISTA *lst, int posicao,int elemento);
void copiar_v2(LISTA *lst1, LISTA *lst2);
void estender_v2(LISTA *lst1, LISTA *lst2);
void inverter_v2(LISTA *lst1, LISTA * lst2);

void ordenar(LISTA *lst);
void ordenar_v2(LISTA *lst);

int main(void) {
  LISTA l1, l2;

  criar(&l1,6);
  criar(&l2,3);

  inserir(&l1,7);
  inserir(&l1,12);
  inserir(&l1,3);
  inserir(&l1,4);
  inserir(&l1,45);
  inserir(&l1,6);

  imprimir(&l1);

  //inserirPos(&l1, 2, 2);
  //printf("%d\n", pop(&l1));
  //inserirPos(&l1, 4, 21);

  inserir(&l2, 1);
  inserir(&l2,2);
  inserir(&l2,3);

  //inverter(&l2, &l1);

  //estender(&l1, &l2);

  imprimir(&l2);
  //printf("%p\n", l2.arr);
  
  //redimensionar(&l2, 12);

  //imprimir(&l2);
  //printf("%p\n", l2.arr);
  inserir_v2(&l1,1);
  inserir_v2(&l1,221);
  inserirPos_v2(&l1, 1, 1024);

  printf("=========================\n");
  imprimir(&l1);

  printf("=========================\n");
  ordenar(&l1);
  imprimir(&l1);
  
  return 0;
}


//Subrotinas

//Tentei fazer uma outra versão da função que ordena a lista, ele devria escolher o menor e ir colocando como primeiro e ao mesmo tempo ir escolhendo o maior e colocando como último. Mas ela não está funcionando como esperava, aparentemente a ordem da troca do menor com os primeiros e do maior com o útimo tem alguma sutileza
void ordenar_v2(LISTA *lst){
  int menor, pos1, aux, pos2, maior;
  for (int i = 0; i < (lst->pos)/2 + 1; i++){
    menor = lst->arr[i];
    pos1 = i;
    maior = lst->arr[lst->pos - i - 1];
    pos2 = lst->pos - i - 1;
    for (int j = i ; j < lst->pos - i ; j++){
      if (lst->arr[j] < menor){
        menor = lst->arr[j];
        pos1 = j;
      }
      if(lst->arr[j] > maior){
        maior = lst->arr[j];
        pos2 = j;
      }
    }
    aux = lst->arr[lst->pos - i - 1];
    lst->arr[lst->pos - i -1] = lst->arr[pos2];
    lst->arr[pos2] = aux;
    aux = lst->arr[i];
    lst->arr[i] = lst->arr[pos1];
    lst->arr[pos1] = aux;
    imprimir(lst);
  }
}

void ordenar(LISTA *lst){
  int menor, posicao, aux;
  for (int i = 0; i < lst->pos; i++){
    menor = lst->arr[i];
    posicao = i;
    for (int j = i; j < lst->pos; j++){
      if (lst->arr[j] < menor){
        menor = lst->arr[j];
        posicao = j;
      }
    }
    aux = lst->arr[i];
    lst->arr[i] = lst->arr[posicao];
    lst->arr[posicao] = aux;
    //imprimir(lst);
  }
}

// Com redimensionar
//===========================================================================

void inverter_v2(LISTA *lst1, LISTA * lst2){
  copiar_v2(lst1, lst2);
  int aux;
  for (int i = 0; i < lst1->pos / 2; i++){
    aux = lst1->arr[i];
    lst1->arr[i] = lst1->arr[lst1->pos - i - 1];
    lst1->arr[lst1->pos - i - 1] = aux;
  }
}

void estender_v2(LISTA *lst1, LISTA *lst2){
  if (lst1->MAX < lst2->pos + lst1->pos)
    redimensionar(lst1, lst1->pos + lst2->pos);
  for (int i = lst1->pos; i < lst1->pos + lst2->pos; i++)
    lst1->arr[i] = lst2->arr[ i - lst1->pos];
  lst1->pos += lst2->pos;
}


void copiar_v2(LISTA *lst1, LISTA *lst2){
  if(lst2->pos > lst1->MAX)
    redimensionar(lst1, lst2->pos);
  for (int i = 0; i < lst2->pos; i++)
    lst1->arr[i] = lst2->arr[i];
  lst1->pos = lst2->pos;
}


void inserir_v2(LISTA *lst, int elemento){
  if (lst->pos >= lst->MAX)
    redimensionar(lst, lst->MAX + 1);
  lst->arr[lst->pos] = elemento;
  lst->pos++;
}

void inserirPos_v2(LISTA *lst, int posicao,int elemento){
  if (posicao < 0 || posicao > lst->pos)
    printf("Posição inválida\n");   
  else {
    if (lst->pos >= lst->MAX)
      redimensionar(lst, lst->MAX + 1);
    lst->pos++;
    for (int i = lst->pos

      
      lst->arr[i] = lst->arr[i - 1];
    lst->arr[posicao] = elemento;
  }
}


//Sem redimensionar
//===========================================================================


void redimensionar(LISTA *lst, int MAX){
  if (MAX < lst->pos){
    printf("Tamanho insuficiente\n");
    exit(1);
  }
  else {
    int *pointer = (int*) malloc(sizeof(int)*MAX);
    if (!(*pointer)){
      printf("Não foi possível alocar memoria\n");
      exit(1);
    }
    for (int i = 0; i < lst->pos; i++)
      pointer[i] = lst->arr[i];
    free(lst->arr);
    lst->arr = pointer;
    lst->MAX = MAX;
  }
}

void inverter(LISTA *lst1, LISTA * lst2){
  copiar(lst1, lst2);
  int aux;
  for (int i = 0; i < lst1->pos / 2; i++){
    aux = lst1->arr[i];
    lst1->arr[i] = lst1->arr[lst1->pos - i - 1];
    lst1->arr[lst1->pos - i - 1] = aux;
  }
}

void estender(LISTA *lst1, LISTA *lst2){
  if (lst1->MAX < lst2->pos + lst1->pos)
    printf("Tamanho da lista é insuficiente\n");
  else {
    for (int i = lst1->pos; i < lst1->pos + lst2->pos; i++)
      lst1->arr[i] = lst2->arr[ i - lst1->pos];
    lst1->pos += lst2->pos;
  }
}

void copiar(LISTA *lst1, LISTA *lst2){
  if(lst2->pos > lst1->MAX)
    printf("Tamanhos de listas incompativéis\n");
  else {
    for (int i = 0; i < lst2->pos; i++)
      lst1->arr[i] = lst2->arr[i];
    lst1->pos = lst2->pos;
  }
}

void inserirPos(LISTA *lst, int posicao,int elemento){
  if (lst->pos >= lst->MAX)
    printf("Lista cheia\n");
  else if (posicao < 0 || posicao > lst->pos)
    printf("Posição inválida\n");
  else {
    lst->pos++;
    for (int i = lst->pos; i > posicao; i--)
      lst->arr[i] = lst->arr[i - 1];
    lst->arr[posicao] = elemento;
  }
}

int pop(LISTA *lst){
  if (lst->pos >= 1)
    return lst->arr[--lst->pos];
  printf("LIsta vazia. Erro!");
  exit(1);
}

int contar(LISTA *lst, int elemento){
  int contador = 0;
  for (int i = 0; i < lst->pos; i++)
    if (lst->arr[i] == elemento)
      contador++;
  return contador;
}

void criar(LISTA *lst, int tam_MAX){
  lst->MAX = tam_MAX;
  lst->pos = 0;
  lst->arr = (int*) malloc(sizeof(int) * tam_MAX);
  if (!lst->arr){
    printf("Erro fatal! Memoria nao pode ser alocada.");
    exit(1);
  }
}

void inserir(LISTA *lst, int elemento){
  if (lst->pos >= lst->MAX)
    printf("Lista cheia\n");
  else {
    lst->arr[lst->pos] = elemento;
    lst->pos++;
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
    printf(" %d ]\n", lst->arr[lst->pos-1]);
  } else 
    printf("[]\n");
}

void apagar(LISTA *lst){
  free(lst->arr);
  lst->pos = 0;
  lst->arr = NULL;
}
