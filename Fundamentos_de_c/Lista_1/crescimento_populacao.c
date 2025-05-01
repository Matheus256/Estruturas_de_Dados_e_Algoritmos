#include <stdio.h>

int main() {
  int T,anos, acrescimo;
  int PA, PB;
  double G1, G2;
  scanf("%d", &T);
  for (int i = 0; i < T; i++){
    scanf("%d %d %lf %lf", &PA, &PB, &G1, &G2);
    anos=0;
    while (PA <= PB){
      acrescimo = PA*G1/100.0;
      PA = PA + acrescimo;
      acrescimo = PB*G2/100.0;
      PB = PB + acrescimo;
      anos++;
      if (anos > 100){
        break;
      }
    }
    if (anos > 100)
      printf("Mais de 1 seculo.\n");
    else
      printf("%d anos.\n", anos);
  }
  return 0;
}
