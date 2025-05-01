#include <stdio.h>
#include <math.h>

int main() {
  int voltas, placas;
  double quociente;
  scanf("%d %d", &voltas, &placas);
  quociente = voltas*placas/10.0;
  printf("%.0f",ceil(quociente));
  for (int i = 2; i < 9 ; i++)
    printf(" %.0f", ceil(quociente*i));
  printf(" %.0f\n", ceil(quociente*9));
  return 0;
}
