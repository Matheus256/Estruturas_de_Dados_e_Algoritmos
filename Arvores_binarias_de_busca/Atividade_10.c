#include <stdio.h>
#include <stdlib.h>

//Declaração do nó
struct sNODE {
	int dado;
	struct sNODE *esq, *dir;
};

//Raiz da arvore
struct sNODE *raiz = NULL;

//Politica de insercao e remocao dos nos da arvore
struct sNODE *inserir(struct sNODE *no, int dado);
struct sNODE *remover(struct sNODE *no, int dado);

//Politicas de consulta
void emOrdem(struct sNODE *no);
void preOrdem(struct sNODE *no);
void posOrdem(struct sNODE *no);

//Funções de busca e obtenção
struct sNODE *buscar(struct sNODE *no, int dado);
int obter(struct sNODE *no);

//Apagar a arvore
struct sNODE *apagar(struct sNODE *no);

//Funções do exercício
void mostrarFolhas(struct sNODE *no);
int getMAX(struct sNODE *no);
int getMIN(struct sNODE *no);
int distanciaDaRaiz(struct sNODE *no, int dado);
int alturaArvore(struct sNODE *no);
int distanciaEntre(struct sNODE *no, int dado1, int dado2);

int main() {
	int arr[] = {2, 4,5,6,1};
	for(int i = 0; i < 5; i++) {
		raiz = inserir(raiz, arr[i]);
	}

	emOrdem(raiz);
	printf("\n");
	printf("A altura atual da arvore eh %d\n\n", alturaArvore(raiz));

	remover(raiz, 5);

	emOrdem(raiz);
	printf("\n");
    	printf("A altura atual da arvore eh %d\n\n", alturaArvore(raiz));
    
	//remover(raiz, 1);

	//emOrdem(raiz);
	//printf("\n");

	//remover(raiz, 6);

	//emOrdem(raiz);

	//preOrdem(raiz);
	//printf("\n");

	//posOrdem(raiz);
	
	mostrarFolhas(raiz);
	printf("\n\n");
	
	printf("O maior dado na arvore eh %d\n", getMAX(raiz));
	printf("O menor dado na arvore eh %d\n\n", getMIN(raiz));
	
	printf("A distancia de %d para a raiz eh %d\n", 6,distanciaDaRaiz(raiz,6));
	printf("A distancia de %d para a raiz eh %d\n\n", 1, distanciaDaRaiz(raiz,1));
	
	int a = 1, b = 2;
	printf("A distancia entre %d e %d na arvore eh %d\n", a,b, distanciaEntre(raiz,a,b));

	return 0;
}

struct sNODE *inserir(struct sNODE *no, int dado) {
	if(!no) {
		no = (struct sNODE*) malloc(sizeof(struct sNODE));
		no->dado = dado;
		no->esq = no->dir = NULL;
	} else if(dado < no->dado)
		no->esq = inserir(no->esq, dado);
	else
		no->dir = inserir(no->dir, dado);

	return no;
}

struct sNODE *remover(struct sNODE *no, int dado) {
	if(no) {
		if(no->dado == dado) {
			if(no->dir == no->esq) {
				free(no);
				return NULL;
			} else if(!no->dir) {
				struct sNODE *aux = no->esq;
				free(no);
				return aux;
			} else if(!no->esq) {
				struct sNODE *aux = no->dir;
				free(no);
				return aux;
			} else {
				struct sNODE *aux = no->dir, *aux2 = no->dir;
				while(aux2->esq)
					aux2 = aux2->esq;
				aux2->esq = no->esq;
				free(no);
				return aux;

			}
		} else if(dado < no->dado)
			no->esq = remover(no->esq, dado);
		else
			no->dir = remover(no->dir, dado);
	}

	return no;
}

void emOrdem(struct sNODE *no) {
	if(no) {
		emOrdem(no->esq);
		printf("%d ", no->dado);
		emOrdem(no->dir);
	}
}

void preOrdem(struct sNODE *no) {
	if(no) {
		printf("%d ",no->dado);
		preOrdem(no->esq);
		preOrdem(no->dir);
	}
}

void posOrdem(struct sNODE *no) {
	if(no) {
		posOrdem(no->esq);
		posOrdem(no->dir);
		printf("%d ", no->dado);
	}
}

struct sNODE *buscar(struct sNODE *no, int dado) {
	if(no) {
		if(no->dado == dado)
			return no;
		else if(no->dado < dado)
			return buscar(no->esq, dado);
		else
			return buscar(no->dir, dado);
	}

	return NULL;
}

int obter(struct sNODE *no) {
	if(no)
		return no->dado;

	exit(0);
}

struct sNODE *apagar(struct sNODE *no) {
	if(no) {
		no->esq = apagar(no->esq);
		no->dir = apagar(no->dir);
		free(no);
	}

	return no;
}

void mostrarFolhas(struct sNODE *no){
    if(no){
        mostrarFolhas(no->esq);
        if(no->dir == no->esq)
            printf("%d ",no->dado);
        mostrarFolhas(no->dir);
    }
    
}

int getMAX(struct sNODE *no){
    if(no){
        if(no->dir)
            return getMAX(no->dir);
        else
            return no->dado;
    }
    printf("Arvore vazia");
    exit(0);
}

int getMIN(struct sNODE *no){
    if(no){
        if(no->esq)
            return getMIN(no->esq);
        else
            return no->dado;
    }
    printf("Arvore vazia");
    exit(0);
}

int distanciaDaRaiz(struct sNODE *no, int dado){
    if(no){
        if(no->dado == dado)
            return 0;
        else if(dado < no->dado)
            return 1 + distanciaDaRaiz(no->esq, dado);
        else
            return 1 + distanciaDaRaiz(no->dir, dado);
    }
    printf("Dado inexistente na arvore\n");
    exit(0);
}

int alturaArvore(struct sNODE *no){
    if(no){
        if(no->esq == no->dir)
            return 0;
        else{
            int esq = alturaArvore(no->esq);
            int dir = alturaArvore(no->dir);
            
            if(esq > dir)
                return 1 + esq;
            else
                return 1 + dir;
        }
    } else
        return 0;
}

//Entedemos que a distancia entre sempre recebe dados que existem na arvore
int distanciaEntre(struct sNODE *no, int dado1, int dado2){
    if(no){
        if( (dado1 < no->dado) && (dado2 < no->dado))
            return distanciaEntre(no->esq, dado1, dado2);
        else if( (dado1 > no->dado) && (dado2 > no->dado))
            return distanciaEntre(no->dir, dado1, dado2);
        else{
            return distanciaDaRaiz(no, dado1) + distanciaDaRaiz(no, dado2);
        }
    }
} 
//Essa última foi fantástica! 
