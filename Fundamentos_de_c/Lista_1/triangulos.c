#include <stdio.h>

int main() {
  double A, B, C, aux;
  scanf("%lf %lf %lf", &A, &B, &C);
  while (!((A >= B) && (B >= C))) {
    if (A < B) {
      aux = A;
      A = B;
      B = aux;
    }
    if (B < C){
      aux = B;
      B = C;
      C = aux;
    }
  }
  if (A >= B + C)
    printf("NAO FORMA TRIANGULO\n");
  else {
    if (A*A > B*B + C*C)
      printf("TRIANGULO OBTUSANGULO\n");
    else if (A*A < B*B + C*C)
      printf("TRIANGULO ACUTANGULO\n");
    else
      printf("TRIANGULO RETANGULO\n");
    if (A == B){
      if (B == C)
        printf("TRIANGULO EQUILATERO\n");
      else
        printf("TRIANGULO ISOSCELES\n");
    }
    else if (B == C){
      if (A == B)
        printf("TRIANGULO EQUILATERO\n");
      else
        printf("TRIANGULO ISOSCELES\n");
    }
  }
  return 0;
}
