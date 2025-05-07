#include <stdio.h>
#include <string.h>
 
int main() {
  int T, quant, vitamina;
  char alimento[25];
  scanf("%d", &T);
  while (T != 0){
    vitamina = 0;
    for (int i = 0; i < T; i++){
      scanf("%d ", &quant);
      fgets(alimento, 25, stdin);
      if (strcmp(alimento,"suco de laranja\n") == 0)
        vitamina = vitamina + quant*120;
      else if (strcmp(alimento,"morango fresco\n") == 0)
        vitamina += quant*85;
      else if (strcmp(alimento,"mamao\n") == 0)
        vitamina += quant*85;
      else if (strcmp(alimento,"goiaba vermelha\n") == 0)
        vitamina += quant*70;
      else if (strcmp(alimento,"manga\n") == 0)
        vitamina += quant*56;
      else if (strcmp(alimento,"laranja\n") == 0)
        vitamina += quant*50;
      else
        vitamina += quant*34;
    }
    if (vitamina < 110)
      printf("Mais %d mg\n",110-vitamina);
    else if (vitamina <= 130)
      printf("%d mg\n", vitamina);
    else
      printf("Menos %d mg\n", vitamina-130);
    scanf("%d", &T);
  }
  return 0;
}
