#include <stdio.h>


void troca(int *a, int *b);
void bubbleSorte(int l[], int tamanho);
void imprimir(int l[], int tamanho);

int main(){
  int array[12] ={2, 2, 7, 1, 1, 5, 12, 0, 4, 4, 11, 14};
  
  printf("Disposição inicial dos elementos no array: \n");
  imprimir(array, 12);
  printf("\n");
  
  bubbleSorte(array, 12);
  printf("Disposição dos elementos no array apos metodo bubble sort\n");
  imprimir(array, 12);
  printf("\n");
  
  return 0;
}

void troca(int *a, int *b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

void bubbleSorte(int l[], int tamanho){
  int trocou = 1;
  for(int i = 0; (i < tamanho) && trocou; i++){
    int trocou = 0;
    for(int j = 0; j < tamanho - 1 - i; j++){
      if(l[j] > l[j + 1]){
        troca(&l[j], &l[j + 1]);
        trocou = 1;
      }
    }
  }
}

void imprimir(int l[], int tamanho){
  printf("[ ");
  for(int i = 0; i < tamanho - 1; i++){
    printf("%d, ", l[i]);
  }
  printf("%d ]\n", l[tamanho - 1]);
}
