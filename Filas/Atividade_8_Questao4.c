#include <stdio.h>
#include <stdlib.h>

struct sVOO{
  int num_voo;
  char modelo[21];
  char piloto[21];
  int num_passageiros;
};

struct sNODE{
  struct sVOO voo;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

//Cabeçalhos
void adicionar_aviao(struct sVOO voo);
int quantidade_avioes_espera();
int autorizar_decolagem();
void listar_voos();
void primeiro_voo();

int main(){
  printf("\n");
  struct sVOO voo1 = {221, "Airbus A340", "Matheus Nascimento", 52};
  struct sVOO voo2 = {134, "Boeing 747", "Isabella Tito", 81};
  struct sVOO voo3= {518, "Airbus A380", "Harry Potter", 180};

  adicionar_aviao(voo1);
  adicionar_aviao(voo2);
  adicionar_aviao(voo3);
  listar_voos();

  printf("Voo de número %d autorizado a decolar\n\n", autorizar_decolagem());

  primeiro_voo();

  printf("Voo de número %d autorizado a decolar\n\n", autorizar_decolagem());

  listar_voos();

  return 0;
}

//Implementações
void adicionar_aviao(struct sVOO voo){
  struct sNODE *aux = (struct sNODE*) malloc(sizeof(struct sNODE));
  aux->voo = voo;
  aux->prox = NULL;

  if(!ini)
    ini = fim = aux;
  else{
    fim->prox = aux;
    fim = aux;
  }
}

int quantidade_avioes_espera(){
  struct sNODE *aux = ini;
  int cont = 0;
  while(aux){
    cont++;
    aux = aux->prox;
  }
  return cont;
}

int autorizar_decolagem(){
  if(!ini){
    printf("Sem voos na fila de decolagem.\n\n");
    return -1;
  }
  
  struct sNODE *aux = ini;
  int num_voo = (ini->voo).num_voo;
  ini = ini->prox;
  free(aux);
  return num_voo;
}

void listar_voos(){
  struct sNODE *aux = ini;
  printf("[");
  while(aux && aux->prox){
    printf("(Numero do voo: %d, Nome do piloto: %s),\n", aux->voo.num_voo, aux->voo.piloto);
    aux = aux->prox;
  }
  if(aux)
    printf("(Numero do voo: %d, Nome do piloto: %s)]\n", aux->voo.num_voo, aux->voo.piloto);
  else
    printf("]\n");

  printf("\n");
}

void primeiro_voo(){
  if(!ini){
    printf("Sem voos na fila de espera para decolagem.\n\n");
    return;
  }

  printf("Informações do primeiro voo da fila de decolagem:\n");
  printf("  Número do voo: %d\n", ini->voo.num_voo);
  printf("  Modelo da aeronave: %s\n", ini->voo.modelo);
  printf("  Nome do piloto: %s\n", ini->voo.piloto);
  printf("  Número de passageiros: %d\n", ini->voo.num_passageiros);
  printf("\n");
}
