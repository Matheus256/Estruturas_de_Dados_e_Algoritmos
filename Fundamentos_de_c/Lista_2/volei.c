#include <stdio.h>

int main(){
  int time, saque, bloqueio, ataque;
  int total_saques = 0, total_bloqueio = 0, total_ataque = 0;
  int acertos_saques = 0, acertos_bloqueios = 0, acertos_ataque = 0;
  double perc_saques, perc_bloqueios, perc_ataques;
  char jogador[21];
  scanf("%d", &time);
  for (int i = 0; i < time; i++){
    scanf("%s", jogador);
    scanf("%d %d %d", &saque, &bloqueio, &ataque);
    total_saques += saque;
    total_bloqueio += bloqueio;
    total_ataque += ataque;
    scanf("%d %d %d", &saque, &bloqueio, &ataque);
    acertos_saques += saque;
    acertos_bloqueios += bloqueio;
    acertos_ataque += ataque;
  }
  perc_saques = acertos_saques*100.0/total_saques;
  perc_bloqueios = acertos_bloqueios*100.0/total_bloqueio;
  perc_ataques = acertos_ataque*100.0/total_ataque;
  printf("Pontos de Saque: %.2lf %%.\n", perc_saques);
  printf("Pontos de Bloqueio: %.2lf %%.\n", perc_bloqueios);
  printf("Pontos de Ataque: %.2lf %%.\n", perc_ataques);
  return 0;
}
