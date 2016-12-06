#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct regNo{ struct regNo *esq;int valor;struct regNo *dir;};
typedef struct regNo TNo;

TNo *AchaPai( TNo *r, int n );
void ImprimeArvore(TNo *r);

int main()
{ 
	TNo *raiz = NULL, *aux, *pai;
	int numero;
	while(1)
		{ 
		printf("\nInforme os valores da arvore\n"); scanf("%d", &numero);
		 if( numero<0) break;
		aux = (TNo *) malloc( sizeof(TNo) );
		aux->valor = numero;
		aux->dir = NULL;
		aux->esq = NULL;
		
		pai = AchaPai( raiz, numero );
		if( pai == NULL )
			raiz = aux;
		else
			if( numero <= pai->valor )
				pai->esq = aux;
		else
			pai->dir = aux;
	}
	ImprimeArvore(raiz);
	printf("\n");
	return 0;
}

TNo *AchaPai( TNo *r, int n )
{ 
	if( r == NULL )
		return NULL;
	else
		if( n <= r->valor )
			if( r->esq == NULL )
				return r;
			else
				return AchaPai( r->esq, n );
		else
			if( r->dir == NULL )
				return r;
			else
				return AchaPai( r->dir, n );
}

void ImprimeArvore(TNo *r)
{ 
	printf("< ");
	if( r != NULL ){
		printf("%d", r->valor);
		ImprimeArvore(r->esq);
		ImprimeArvore(r->dir);
	}
	printf(" >");
}

