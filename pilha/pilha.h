#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

#include "../lista/lista.h"

typedef int TipoP;

typedef struct
{
  int topo;
  TipoP info[MAX];
} Tpilha, *Pilha;

// Funcoes basicas de Pilha

Pilha inicPilha(void);          // Cria e retorna uma pilha vazia
void push(Pilha p, TipoP elem); // Adiciona(empilha) um elemento no topo da pilha
TipoP pop(Pilha p);             // Elimina(desempilha) o elemento que esta no topo da pilha e retorna este elemento
TipoP infoPilha(Pilha p);       // Retorna o elemento que esta no topo da pilha, sem remove-lo da pilha
int vaziaPilha(Pilha p);        // Retorna verdadeiro, se a pilha esta vazia e falso, caso contrario
void destruirPilha(Pilha p);    // Destroi a pilha p, desalocando toda memoria ocupada
void printPilha(Pilha p);       // Mostra o conteudo da pilha

// > Exercicios Pilha <

// 1) Inverter uma lista utilizando como apoio uma pilha
void invLista(Lista lst);
// 2) Fazer uma copia de uma pilha, usando como apoio uma lista
Pilha copiarPilha(Pilha p);
// 3) Inverter o conteudo de uma pilha
void invPilha(Pilha p);
// 4) Dizer se duas pilhas sao iguais sem destruir seu conteudo
int iguaisPilhas(Pilha p1, Pilha p2);
// 5) Avaliar uma expressao aritmetica na notacao posfixa
int avaliarExpressao(Lista lstExp);
// 6) Imprimir o conteudo de uma pilha, sem alterar seu conteudo (a pilha deve ser restaurada)
void imprimePilha(Pilha p);
// 7) Colocar no fundo da pilha o elemento elem
void fundoPilha(Pilha p, TipoP elem);
// 8) Computar e retornar o numero de elementos da pilha, sem alterar seu conteudo (a pilha deve ser restaurada)
int longPilha(Pilha p);
// 9) Eliminar da pilha todas as ocorrencias do elemento elem
void elimTodosPilha(Pilha p, TipoP elem);
// 10) Somar todos os elementos da pilha e retorna seu resultado
int somaPilha(Pilha p);
// 11) Retornar true(1) se o conteudo da pilha e um palindrome e false(0), caso contrario
int palindromePilha(Pilha p);

#endif
