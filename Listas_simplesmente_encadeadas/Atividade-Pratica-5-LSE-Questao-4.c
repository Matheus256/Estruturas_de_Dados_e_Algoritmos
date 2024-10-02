#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNode{
  char *nome;
  float nota1, nota2;
  double media;
  struct sNode *prox;
};
//Esta forma funciona e resolve o problema, no entanto é a única vez em que implemento dessa forma
//Nas próximas atividade sempre defino um novo tipo de registro: por exemplo, struct sAluno e daí o nó tera um campo do tipo struct sAluno

struct sLISTA{
  struct sNode *ini, *fim;
};

typedef struct sLISTA LISTA;

//Cabeçalhos das funções
void inicializar(LISTA *lst);
void imprimir(LISTA *lst);
void inserir_ord(LISTA *lst, char *nome, float nota1, float nota2, double media);

int main(void) {
  LISTA lst;
  inicializar(&lst);

  inserir_ord(&lst, "Isabella Tito Nascimento", 10, 10, 10);
  inserir_ord(&lst, "Matheus Nascimento", 9.5, 9.5, 9.5);
  inserir_ord(&lst, "Harry Potter", 3, 5, 4);

  imprimir(&lst);
  
  return 0;
}

void inicializar(LISTA *lst){
  lst->ini = lst->fim = NULL;
}

void imprimir(LISTA *lst){
  struct sNode *aux = lst->ini;
  while(aux){
    printf("ALUNO(A): %s\n", aux->nome);
    printf("NOTA1: %.2f     NOTA2: %.2f     MEDIA: %.2lf\n\n", aux->nota1, aux->nota2, aux->media);
    aux = aux->prox;
  }
}

void inserir_ord(LISTA *lst, char *nome, float nota1, float nota2, double media){
  struct sNode *node = NULL, *aux = lst->ini, *ant = NULL;
  node = malloc(sizeof(struct sNode));
  
  //Alocar o tamanho do nome e em seguida copia o contéudo de nome para node->nome
  node->nome = malloc(sizeof(char)*(strlen(nome) + 1));
  strcpy(node->nome, nome);
  
  node->nota1 = nota1;
  node->nota2 = nota2;
  node->media = media;
  node->prox = NULL;

  while(aux){
    if (aux->media < media)
      break;
    ant = aux;
    aux = aux->prox;
  }

  if(!(lst->ini))
    lst->ini = lst->fim = node;
  else if(aux == lst->ini){
    node->prox = lst->ini;
    lst->ini = node;
  } else if(ant == lst->fim){
    lst->fim->prox = node;
    lst->fim = node;
  } else 
    ant->prox = node;
    node->prox = aux;
}
