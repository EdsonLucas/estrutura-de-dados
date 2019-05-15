
#ifndef _TAD_Arbin_H
#define _TAD_Arbin_H

//TAD Arbin
#include <stdio.h>

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

typedef int TipoA;

typedef struct NodoArbin{
TipoA info;
struct NodoArbin *esq, *dir;
}Tarbin, *Arbin;

// cria e retorna uma arvore binaria vazia
Arbin inicArbin( void );

//retorna a subarvore esquerda
Arbin esqArbin( Arbin a);

//retorna a subarvore direita
Arbin dirArbin( Arbin a);

//retorna a raiz
TipoA raizArbin( Arbin a);

//destrói a arvore binária, retornando toda a memória ocupada.
void destruirArbin( Arbin a);

//retorna 1 se arbin vazia e 0 caso contrario
int vaziaArbin(Arbin a);

//------------------------------------
//  TAD Fila com info sendo uma Arbin
//------------------------------------

typedef Arbin TipoF;


#define MAX 1000

typedef struct{
	TipoF info[MAX]; // vetor circular
	int primeiro;    // posicao do primeiro elemento
	int ultimo;      // posicao do ultimo elemento
}TFila, *Fila;

Fila inicFila(void);
void adicFila(Fila f, TipoF elem);
void elimFila(Fila f);
TipoF infoFila(Fila f);
int vaziaFila(Fila f);
void destruirFila(Fila f);


//------------------------------------
//  Caminhamentos Arbin
//------------------------------------

void visitar(TipoA elem);
void preOrdemArbin(Arbin a);
void inOrdemArbin(Arbin a);
void posOrdemArbin(Arbin a);
void niveisArbin(Arbin a);

//------------------------------------
//  Exercicios da Lista
//------------------------------------
int existeCaminho(Arbin a, TipoA e1, TipoA e2);

#endif // _TAD_Arbin_H
