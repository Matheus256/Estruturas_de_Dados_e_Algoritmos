#include <stdio.h>

void insertionSorte(int l[], int tamanho);
void imprimir(int l[], int tamanho);

int main(){
  int array[12] ={2, 2, 7, 1, 1, 5, 12, 0, 4, 4, 11, 14};
  
  printf("Disposição inicial dos elementos no array: \n");
  imprimir(array, 12);
  printf("\n");
  
  insertionSorte(array, 12);
  printf("Disposição dos elementos no array apos metodo selection sort\n");
  imprimir(array, 12);
  printf("\n");
  
  return 0;
}

void insertionSorte(int l[], int tamanho){
  for(int i = 1; i < tamanho; i++){
    
    int eleito = l[i], j;
    for(j = i; j > 0; j--){
      if(l[j - 1] > eleito)
        l[j] = l[j - 1];
      else
        break;
    }
    
    l[j] = eleito;
    
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
