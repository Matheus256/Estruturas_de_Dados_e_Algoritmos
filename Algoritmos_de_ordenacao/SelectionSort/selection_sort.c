#include <stdio.h>


void troca(int *a, int *b);
void selectionSorte(int l[], int tamanho);
void imprimir(int l[], int tamanho);

int main(){
  int array[12] ={2, 2, 7, 1, 1, 5, 12, 0, 4, 4, 11, 14};
  
  printf("Disposição inicial dos elementos no array: \n");
  imprimir(array, 12);
  printf("\n");
  
  selectionSorte(array, 12);
  printf("Disposição dos elementos no array apos metodo selection sort\n");
  imprimir(array, 12);
  printf("\n");
  
  return 0;
}

void troca(int *a, int *b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

void selectionSorte(int l[], int tamanho){
  for(int i = 0; i < tamanho - 1; i++){
  
    int index_menor = i + 1;
    for(int j = i + 1; j < tamanho; j++){
      if(l[j] < l[index_menor])
        index_menor = j;
    }
    
    if(l[index_menor] < l[i] )
      troca(&l[i], &l[index_menor]);
    
    //Acompanhar a ordenação
    //imprimir(l, tamanho);
  }
}

void imprimir(int l[], int tamanho){
  printf("[ ");
  for(int i = 0; i < tamanho - 1; i++){
    printf("%d, ", l[i]);
  }
  printf("%d ]\n", l[tamanho - 1]);
}
