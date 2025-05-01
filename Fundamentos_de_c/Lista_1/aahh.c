#include <stdio.h>
#include <string.h>

int main() {
  char jon[1001], medico[1001];
  scanf("%s", &jon);
  scanf("%s", &medico);
  if (strcmp(jon,medico) <= 0)
    printf("go\n");
  else
    printf("no\n");
}
