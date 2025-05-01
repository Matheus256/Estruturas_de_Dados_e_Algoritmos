#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  double M[12][12], soma=0;
  int cont=0;
  char op;
  scanf("%c",&op);
  for (int i = 0; i < 12; i++){
    for (int j = 0; j < 12; j++){
      scanf("%lf",&M[i][j]);
      if (j > i){
        soma = soma + M[i][j];
        cont++;
      }
    }
  }
  if(op=='S')
    printf("%.1lf\n",soma);
  else {
    soma = soma/cont;
    printf("%.1lf\n", soma);
  }
  return 0;
}
