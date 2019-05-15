
//TAD Arbin
#include <stdio.h>
#include <stdlib.h>

#ifndef _TAD_Arbin_H
    #include "tadArbin.h"
#endif // _TAD_Arbin_H

/*
Funções do TAD Arbin
•Arbin inicArbin( void ) : cria e retorna uma arvore binaria vazia
•Arbin esqArbin( Arbin a): retorna a subarvore esquerda
• Pre: a!=arvore vazia
• Pos: esqArbin = subarvore esquerda
•Arbin dirArbin( Arbin a): retorna a subarvore direita
• Pre: a!=arvore vazia
• Pos: dirArbin = subarvore direita
•TipoA raizArbin( Arbin a): retorna a raiz
• Pre: a!=arvore vazia
• Pos: raizArbin = elem
void destruirArbin( Arbin a): destrói a arvore binária, retornando toda
a memória ocupada.

int vaziaArbin(Arbin a): retorna 1 se arbin vazia e 0 caso contrario

*/


Arbin inicArbin( ){
    return NULL;
}



Arbin esqArbin(Arbin a){
    if(a != NULL) // se Arbin a nao for vazia
        return a->esq;
    else
        return NULL;
}

Arbin dirArbin(Arbin a){
    if(a != NULL) // se Arbin a nao for vazia
        return a->dir;
    else
        return NULL;
}

TipoA raizArbin(Arbin a){
    if(a != NULL) // se Arbin a nao for vazia
        return a->info;
    else
        return NULL;
}


int vaziaArbin(Arbin a){

    if(a == NULL) // arbin vazia
        return 1;
    else
        return 0;
}

Arbin insArbinBusca(Arbin a, TipoA elem){

    if(a == NULL){// a == NULL ou vaziaArbin(a)
        a = (Arbin) malloc(sizeof(struct NodoArbin));
        // OU a = (Arbin) malloc(sizeof(Tarbin));

        a->info = elem;
        a->esq = NULL;
        a->dir = NULL;
        return a;
    }
    else if(elem < a->info){ //raizArbin(a)

        a->esq = insArbinBusca(a->esq, elem); // esqArbin(a)
    }
    else if(a->info != elem){
        a->dir = insArbinBusca(a->dir, elem); // dirArbin(a)
    }
    return a;
}


//----------------------------------


//destrói a arvore binária, retornando toda a memória ocupada.
void destruirArbin( Arbin a){
	if(a != NULL){
		destruirArbin(a->esq);
		destruirArbin(a->dir);
		free(a);
	}

}


//------------------------------------
//  TAD Fila com info sendo uma Arbin
//------------------------------------


Fila inicFila(void){

	Fila f = (Fila)malloc(sizeof(TFila));
	f->primeiro = f->ultimo = -1;
	return f;
}
void adicFila(Fila f, TipoF elem){

	if(f->primeiro == -1){
		f->info[0] = elem;
		f->primeiro = f->ultimo = 0;
	}
	else if(!(((f->ultimo + 1)%MAX)== f->primeiro)){
		f->ultimo = (f->ultimo + 1)%MAX;
		f->info[f->ultimo] = elem;

	}

}
void elimFila(Fila f){
	if(f->primeiro != -1){ // Fila nao esta vazia
		if(f->primeiro == f->ultimo){
			f->primeiro = f->ultimo = -1;
		}
		else{
			f->primeiro = (f->primeiro + 1)%MAX;
		}
	}

}

TipoF infoFila(Fila f){ // fila deve estar cheia
	return f->info[f->primeiro];
}
int vaziaFila(Fila f){
	return (f->primeiro == -1 && f->ultimo == -1);
}

void destruirFila(Fila f){
	free(f);
}

//exibirFila(Fila f){
//	if(f->primeiro == -1){
//		printf("\n fila Vazia \n ");
//	}
//	else{
//		int i, j;
//
//		for(i = f->primeiro i )
//	}
//}

//------------------------------------
//  Caminhamentos Arbin
//------------------------------------

void visitar(TipoA elem){

	printf("  %d  \n",  elem);

}

void preOrdemArbin(Arbin a){

	if(!vaziaArbin(a)){
		visitar(raizArbin(a));
		preOrdemArbin(esqArbin(a));
		preOrdemArbin(dirArbin(a));
	}
}

void inOrdemArbin(Arbin a){

	if(!vaziaArbin(a)){
		inOrdemArbin(esqArbin(a));
		visitar(raizArbin(a));
		inOrdemArbin(dirArbin(a));
	}
}

void posOrdemArbin(Arbin a){

	if(!vaziaArbin(a)){
		posOrdemArbin(esqArbin(a));
		posOrdemArbin(dirArbin(a));
        visitar(raizArbin(a));
	}
}


void niveisArbin(Arbin a){

    Fila f;
    Arbin arb;
    if(!vaziaArbin(a)){
        f = inicFila();
        adicFila(f,a);
        while(!vaziaFila(f)){
            arb = infoFila(f);
            elimFila(f);
            if(!vaziaArbin(arb)){
                visitar(raizArbin(arb));
                adicFila(f,esqArbin(arb));
                adicFila(f,dirArbin(arb));

            }
        }
    }

}


//------------------------------------
//  Exercicios TAD Arbin
//------------------------------------

//Verificar se um elemento está presente
//em uma árvore binária.

int estaArbin( Arbin a, TipoA elem){

	//caso1: arvore vazia, elem nao esta na arvore
	if(vaziaArbin(a))
		return 0;
	else if(elem == raizArbin(a)) // caso 2: elem == raiz
		return 1;
	else{// procurar na subarvore esquerda e direita
		return (estaArbin(esqArbin(a),elem) || estaArbin(dirArbin(a),elem));
	}

}


//Calcular e retornar o peso de uma árvore binária ( número de elementos da árvore).
int pesoArbin( Arbin a){
	//arvore vazia
	if(vaziaArbin(a))
		return 0;
	else{
		return 1 + pesoArbin(esqArbin(a)) + pesoArbin(dirArbin(a));
	}
}


//Calcular o número de folhas de uma Arbin.
int numFolhas( Arbin a){
	if(vaziaArbin(a))
		return 0;
	else if(vaziaArbin(esqArbin(a)) && vaziaArbin(dirArbin(a)))
		return 1;
	else return numFolhas(esqArbin(a)) + numFolhas(dirArbin(a));

}


int existeCaminhoABB(Arbin a, TipoA e1, TipoA e2){

    //caso 1: Arbin a vaziaArbin ---> retorna 0
    if(vaziaArbin(a))
        return 0;
    else if(raizArbin(a) == e1) //caso 2: e1 == raiz e verifico se e2 estaABB  ---> retorna 1
        return buscaNaArbinBusca(a, e2);
    else if(e1 < raizArbin(a)) //caso 3: recursao: se e1 < raiz chama a funcao passando esqArbin() senao passa dirArbin()
        return existeCaminhoABB(esqArbin(a), e1, e2);
    else
        return existeCaminhoABB(dirArbin(a), e1, e2);



}

int contaNivel(Arbin a, int nivel){

    if(vaziaArbin(a))
        return 0;
    else if(nivel == 0)
        return 1;
    else
        return(contaNivel(esqArbin(a), nivel-1) + contaNivel(dirArbin(a), nivel -1));

}

int iguaisArbin(Arbin a , Arbin b){

    if(vaziaArbin(a) && vaziaArbin(b))
        return 1;
    else
        if (raizArbin(a) == raizArbin(b))
            iguaisArbin(esqArbin(a), esqArbin(b)) && iguaisArbin(dirArbin(a), dirArbin(b));
        else
            return 0;
}
//Calcular o número de vezes que um elemento aparece na Arbin.
int numOcorrencias( Arbin a, TipoA elem){
	if(vaziaArbin(a))
		return 0;
	else if(raizArbin(a) == elem)
		return 1 + numOcorrencias(esqArbin(a),elem) + numOcorrencias(dirArbin(a),elem);
	else
		return numOcorrencias(esqArbin(a),elem) + numOcorrencias(dirArbin(a),elem);
}

int existeCaminho(Arbin a, TipoA e1, TipoA e2){
    if(vaziaArbin(a))
        return 0;
    else if(raizArbin(a) == e1){
        return estaArbin(a,e2);
    }
    else{
        return (existeCaminho(esqArbin(a), e1,e2) || existeCaminho(dirArbin(a),e1,e2));
    }
}
