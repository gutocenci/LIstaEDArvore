#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct arvore{
    int valor;
    struct arvore *esq;
    struct arvore *dir;
}TArvore;

void inserir(TArvore **, int );
void ImprimeArvoreA(TArvore *);
TArvore *MDireita(TArvore **);
void remover(TArvore **, int );

int main(){
    int inclue=0,remove=0;
    TArvore *Raiz = NULL;
	
    while(1){
			printf("Informe o numero: ");
			scanf(" %d",&inclue);
			if(inclue == -999)
				break;
      inserir(&Raiz,inclue);
    };
	if(Raiz == NULL){
		printf("Arvore vazia - Nao ah oq exibir ou excluir\n");
		return 0;
	}
	
	else {
		printf("Conteudo da arvore\n");
		ImprimeArvoreA(Raiz);
		printf("\n");
		while(1){
			printf("Informe o numero a exluir:");
			scanf(" %d",&remove);
				if(remove == -999)
					break;
			remover(&Raiz,remove);
		}
	}

    printf("Nova Arvore:\n");
    ImprimeArvoreA(Raiz);
  	
    return 0;
}

void inserir(TArvore **pRaiz, int x){
    if(*pRaiz == NULL){
        *pRaiz = (TArvore *) malloc(sizeof(TArvore));
        (*pRaiz)->esq = NULL;
        (*pRaiz)->dir = NULL;
        (*pRaiz)->valor = x;
    }else{
        if(x < (*pRaiz)->valor)
            inserir(&(*pRaiz)->esq, x);
        if(x > (*pRaiz)->valor)
            inserir(&(*pRaiz)->dir, x);
    }
}

 void ImprimeArvoreA(TArvore *Raiz){
     if(Raiz==NULL)
		return;
     printf(" %d",Raiz->valor);
     ImprimeArvoreA(Raiz->esq);
     ImprimeArvoreA( Raiz->dir);
 }
 
  TArvore *MDireita(TArvore **no){
    if((*no)->dir != NULL)
       return MDireita(&(*no)->dir);
    else{
       TArvore *aux = *no;
       if((*no)->esq != NULL) 
          *no = (*no)->esq;
       else
          *no = NULL;
       return aux;
       }
}

void remover(TArvore **pRaiz, int valor){
    if(*pRaiz == NULL){ 
       printf("Numero nao existe na arvore, continue informando\n");
       return;
    }
    if(valor < (*pRaiz)->valor)
       remover(&(*pRaiz)->esq, valor);
    else
       if(valor > (*pRaiz)->valor)
          remover(&(*pRaiz)->dir, valor);
       else{    
          TArvore *pAux = *pRaiz;
          if (((*pRaiz)->esq == NULL) && ((*pRaiz)->dir == NULL)){        
                free(pAux);
                (*pRaiz) = NULL;
               }
          else{     
             if ((*pRaiz)->esq == NULL){
                (*pRaiz) = (*pRaiz)->dir;
                pAux->dir = NULL;
                free(pAux); pAux = NULL;
                }
             else{           
                if ((*pRaiz)->dir == NULL){
                    (*pRaiz) = (*pRaiz)->esq;
                    pAux->esq = NULL;
                    free(pAux);
                    pAux = NULL;
                    }
                else{       
                   pAux = MDireita(&(*pRaiz)->esq);
                   pAux->esq = (*pRaiz)->esq;
                   pAux->dir = (*pRaiz)->dir;
                   (*pRaiz)->esq = (*pRaiz)->dir = NULL;
                   free((*pRaiz));
                    *pRaiz = pAux;
                    pAux = NULL;
                   }
                }
             }
          }
}