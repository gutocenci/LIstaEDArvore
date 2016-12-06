#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct regNo{ struct regNo *esq;int valor;struct regNo *dir;};
typedef struct regNo TNo;

TNo *AchaPai( TNo *r, int n );
void ImprimeArvore(TNo *r, int n);
int ContaNos(TNo *r);
int SomaNos(TNo *r);
int ContaPares(TNo *r);
int Equivalencia(TNo *raiz1, TNo *raiz2);
int main()
{ 
	TNo *raiz1 = NULL,*raiz2 = NULL, *aux, *pai;
	int numero;
	while(1)
		{ 
		printf("\nInforme o valor da arvore 1:\n"); scanf("%d", &numero);
		 if( numero<0) break;
		aux = (TNo *) malloc( sizeof(TNo) );
		aux->valor = numero;
		aux->dir = NULL;
		aux->esq = NULL;
		
		pai = AchaPai( raiz1, numero );
		if( pai == NULL )
			raiz1 = aux;
		else
			if( numero <= pai->valor )
				pai->esq = aux;
		else
			pai->dir = aux;
	}
	while(1)
		{ 
		printf("\nInforme o valor da arvore 2:\n"); scanf("%d", &numero);
		 if( numero<0) break;
		aux = (TNo *) malloc( sizeof(TNo) );
		aux->valor = numero;
		aux->dir = NULL;
		aux->esq = NULL;
		
		pai = AchaPai( raiz2, numero );
		if( pai == NULL )
			raiz2 = aux;
		else
			if( numero <= pai->valor )
				pai->esq = aux;
		else
			pai->dir = aux;
	}
	printf("\n\nA arvore1 possui %d elementos:\n", ContaNos(raiz1));
	ImprimeArvore(raiz1, 0);
	printf("\n");
	printf("\n\nA arvore2 possui %d elementos:\n", ContaNos(raiz2));
	ImprimeArvore(raiz2, 0);
	if(ContaNos(raiz1)==0 && ContaNos(raiz2)==0)
	{
		printf("As arvores estão vazias");
	}
	else
	{
		if(Equivalencia(raiz1,raiz2)==1)
		{
			printf("As arvores sao equivalentes");
		}
		else
		{
			printf("As nao arvores sao equivalentes");
		}
	}
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

int ContaNos(TNo *r)
{ 
if(r == NULL)
	return 0;
else
	return 1 + ContaNos(r->esq) + ContaNos(r->dir);
}

void ImprimeArvore(TNo *r, int n)
{ 
	int c;
	if( r != NULL )
	{ 
		for( c=0; c<n; c++) printf("\t");
		printf("%d\n", r->valor);
		ImprimeArvore(r->esq, n+1);
		ImprimeArvore(r->dir, n+1);
	}
}

int Equivalencia(TNo *raiz1, TNo *raiz2)
{	
	if(raiz1 == NULL || raiz2 == NULL)
		return 1;
	else
		if(raiz1->valor == raiz2->valor)
			return Equivalencia(raiz1->esq,raiz2->esq) * Equivalencia(raiz1->dir,raiz2->dir);
		else
			return 0;
}