#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct{
//  unsigned MAX;
//  char *l;
//  int pos;
//} LISTA;

#define MAX 10

char l[MAX][21];
int pos = 0;

//Cabeçalhos
void inserir_ord(char elemento[]);
void imprimir();
void remover(char elemento[]);

int main(void) {

  //printf("%d\n", strcmp("Isabella","Matheus"));
  
  inserir_ord("Matheus");
  inserir_ord("Isabella");
  inserir_ord("Carol");
  inserir_ord("Ana");
  imprimir();

  remover("Ana");
  remover("Carol");
  imprimir();
  
  return 0;
}

void inserir_ord(char elemento[]){
  int i;
  
  if(pos >= MAX){
    printf("Lista cheia.\n");
    return;
  }

  for(i = 0; i < pos; i++){
    if(strcmp(l[i],elemento) > 0){
      for (int p = pos; p > i; p--)
        strcpy(l[p], l[p - 1]);
      break;
    }
  }
  
  strcpy(l[i], elemento);
  pos++;
}

void imprimir(){
  printf("[");
  for(int i = 0; i < pos - 1; i++){
    printf("'%s', ", l[i]);
  }
  printf("'%s']\n", l[pos - 1]);
}

void remover(char elemento[]){
  for(int i = 0; i < pos; i++){
    if(strcmp(l[i], elemento) == 0){
      for(int p = i; p < pos -1; p++)
        strcpy(l[p],l[p + 1]);
      pos--;
      break;
    }
  }
}
