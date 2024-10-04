#include <stdio.h>
#include <stdlib.h>

struct sPILHA{
  int *arr, pos;
  int MAX;
};

typedef struct sPILHA PILHA;

//=============== Cabeçalhos ==================
void criar(PILHA *pi, int tam_MAX);
void push(PILHA *pi, int dado);
int pop(PILHA *pi);

int tamanho(PILHA *pi);
void imprimir(PILHA *pi);
void apagar(PILHA *pi);

//============== A main ========================
int main(){
  PILHA pilha;
  criar(&pilha, 101);

  char entrada[101];
  printf("Informe a frase: ");
  fgets(entrada, 101, stdin);

  int i = 0;
  while(entrada[i]){
    if(entrada[i] == '(')
      push(&pilha, 1);
    else if(entrada[i] == ')')
      push(&pilha, -1);
    else if(entrada[i] == '[')
      push(&pilha, 2);
    else if(entrada[i] == ']')
      push(&pilha, -2);
    else if(entrada[i] == '{')
      push(&pilha, 3);
    else if(entrada[i] == '}')
      push(&pilha, -3);
    
    i++;
  }

  //imprimir(&pilha);

  int com = pop(&pilha), soma = 0;
  while(com){
    soma = soma + com;
    com = pop(&pilha);
  }

  if(soma)
    printf("Não Balanceada\n");
  else
    printf("Balanceada\n");

  apagar(&pilha);

  return 0;
}

//============== Implementações ================
void criar(PILHA *pi, int tam_MAX){
  pi->MAX = tam_MAX;
  pi->pos = 0;

  pi->arr = (int*) malloc(sizeof(int)*tam_MAX);
}

void push(PILHA *pi, int dado){
  if(pi->pos > pi->MAX){
    printf("Pilha cheia!");
    exit(1);
  }
  pi->arr[(pi->pos)++] = dado;
}

int pop(PILHA *pi){
  if(pi->pos <= 0){
    //printf("Pilha vazia!\n");
    return 0;
  }
  return pi->arr[--(pi->pos)];
}

void apagar(PILHA *pi){
  free(pi->arr);
  pi->arr = NULL;
  pi->pos = 0;
}

void imprimir(PILHA *pi){
  printf("[");
  for(int i = 0; i < pi->pos; i++)
    printf(" %d ",pi->arr[i]);
  printf("]\n");
}
