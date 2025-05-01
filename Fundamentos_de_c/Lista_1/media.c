#include <stdio.h>
#include <string.h>

int main() {
  float nota1, nota2, nota3, nota4;
  float media;
  scanf("%f %f %f %f", &nota1, &nota2, &nota3, &nota4);
  media = (2*nota1 + 3*nota2 + 4*nota3 + nota4)/10;
  printf("Media: %.1f\n", media);
  if (media >= 7)
    printf("Aluno aprovado.\n");
  else if (media >= 5){
    printf("Aluno em exame.\n");
    float exame;
    scanf("%f", &exame);
    printf("Nota do exame: %.1f\n", exame);
    media = (media + exame)/2;
    if (media >= 5)
      printf("Aluno aprovado.\n");
    else
      printf("Aluno reprovado.\n");
    printf("Media final: %.1f\n", media);
  }
  else
    printf("Aluno reprovado.\n");
}
