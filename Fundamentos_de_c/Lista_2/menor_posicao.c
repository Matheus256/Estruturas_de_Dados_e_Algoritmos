#include <stdio.h>

int main(){
  int tamanho;
  scanf("%d",&tamanho);
  int vetor[tamanho];
  for (int i = 0; i < tamanho - 1; i++)
    scanf("%d ",&vetor[i]);
  scanf("%d",&vetor[tamanho-1]);
  int menor=vetor[0],pos=0;
  
  for (int i = 1; i < tamanho; i++){
    if (vetor[i]<menor){
      menor = vetor[i];
      pos = i;
    }
  }
  printf("Menor valor: %d\n",menor);
  printf("Posicao: %d\n",pos);
  return 0;
}
