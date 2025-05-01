#include <stdio.h>

int main(){
  char opcao;
  int linha;
  double M[12][12], soma = 0;
  scanf("%d ", &linha);
  scanf("%c", &opcao);
  for (int i = 0; i < 12; i++){
    for (int j = 0; j < 12; j++){
      scanf("%lf", &M[i][j]);
      if (i == linha)
        soma = soma + M[i][j];
    }
  }
  if(opcao == 'S')
    printf("%.1lf\n", soma);
  else {
    soma = soma/12;
    printf("%.1lf\n", soma);
  }
  return 0;
}
