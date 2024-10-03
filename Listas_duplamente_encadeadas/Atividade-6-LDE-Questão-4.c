#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Leseira minha só pra imprimir algumas palavras em negrito.
void bold(int status) {
 static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
 printf("%s", seq[!!status]);
}

//Exemplo de uso do negrito
//printf("one "); bold(1); printf("two "); bold(0); printf("three\n");

// Definição do registro do tipo funcionario
typedef struct{
  char nome[30];
  char ocupacao[30];
  float salario;
} FUNCIONARIO;

struct sNODE{
  FUNCIONARIO dado;
  struct sNODE *ant;
  struct sNODE *prox;
};

struct sLISTA{
  struct sNODE *ini, *fim;
};

typedef struct sLISTA LISTA;

typedef struct {
  LISTA gerentes;
  LISTA supervisores;
  LISTA peoes;
} New_LISTA;

void inicializar(New_LISTA *lst);
void inserir_ord(LISTA *lst, FUNCIONARIO dado);

void imprimir(LISTA *lst);
void imprimir_funcionarios(New_LISTA *lst);

void buscar(LISTA *lst, FUNCIONARIO dado);
void apagar(LISTA *lst);

void inserir_funcionario(New_LISTA *lst, FUNCIONARIO dado);

int main(void) {
  New_LISTA lst;
  FUNCIONARIO funcionario3 = {"Harry Potter", "peão", 2000.0};
  FUNCIONARIO funcionario1 = {"Matheus Nascimento", "supervisor", 10000.50};
  FUNCIONARIO funcionario2 = {"Isabella Tito", "gerente", 30000.00};
  FUNCIONARIO funcionario4 = {"CBUM", "gerente", 15000.00};
  FUNCIONARIO funcionario5 = {"Michael Jordan", "gerente", 25000.00};
  FUNCIONARIO funcionario6 = {"Naruto Uzumaki", "supervisor", 25000.00};
  FUNCIONARIO funcionario7 = {"Arqueiro Verde", "peao", 1000.00};
  FUNCIONARIO funcionario8 = {"Batman", "peão", 1500.00};
  
  inicializar(&lst);
  inserir_funcionario(&lst, funcionario1);
  inserir_funcionario(&lst, funcionario2);
  inserir_funcionario(&lst, funcionario3);
  inserir_funcionario(&lst, funcionario4);
  inserir_funcionario(&lst, funcionario5);
  inserir_funcionario(&lst, funcionario6);
  inserir_funcionario(&lst, funcionario7);
  inserir_funcionario(&lst, funcionario8);
  
  imprimir_funcionarios(&lst);

  //apagar(&lst);

  return 0;
}

void inicializar(New_LISTA *lst){
  lst->gerentes.ini = NULL;
  lst->gerentes.fim = NULL;

  lst->supervisores.ini = NULL;
  lst->supervisores.fim = NULL;

  lst->peoes.ini = NULL;
  lst->peoes.fim = NULL;
}

void inserir_ord(LISTA *lst, FUNCIONARIO dado){
  //Aloca o novo nó
  struct sNODE *node = (struct sNODE*) malloc(sizeof(struct sNODE));
  node->dado = dado;
  node->ant = NULL;
  node->prox = NULL;

  //Se a lista tá vazia ele já coloca o elemento e vai embora
  if(!(lst->ini)){
    lst->ini = lst->fim = node;
    return;
  }

  //Coloca os ponteiros na posição boa (de inserção)
  struct sNODE *aux = lst->ini;
  while(aux && (aux->dado).salario > dado.salario)
    aux = aux->prox;

  //Verifica os casos para acrescentar o novo no no começo, fim ou no meio 
  if(aux == lst->ini){
    node->prox = lst->ini;
    lst->ini->ant = node;
    lst->ini = node;
  } else if(!aux){
    node->ant = lst->fim;
    lst->fim->prox = node;
    lst->fim = node;
  } else{
    node->prox = aux;
    node->ant = aux->ant;
    aux->ant->prox = node;
    aux->ant = node;
  }
}

void imprimir(LISTA *lst){
  struct sNODE *aux = lst->ini;

  while(aux){
    bold(1); printf("Nome: "); bold(0); printf("%s\n", aux->dado.nome);
    bold(1); printf("Ocupação: "); bold(0); printf("%s", aux->dado.ocupacao);
    bold(1); printf("        Salario: "); bold(0); printf("%.2f\n", aux->dado.salario);
    printf("\n");
    aux = aux->prox;
  }
}

void imprimir_funcionarios(New_LISTA *lst){
  imprimir(&(lst->gerentes));
  imprimir(&(lst->supervisores));
  imprimir(&(lst->peoes));
}

void apagar(LISTA *lst){
  struct sNODE *aux = lst->ini, *ant = NULL;
  while(aux){
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  lst->fim = lst->fim = NULL;
}

void inserir_funcionario(New_LISTA *lst, FUNCIONARIO dado){
  if(!strcmp(dado.ocupacao,"gerente"))
    inserir_ord(&(lst->gerentes), dado);
  else if(!(strcmp(dado.ocupacao, "supervisor")))
    inserir_ord(&(lst->supervisores), dado);
  else
    inserir_ord(&(lst->peoes), dado);
}
