#include <stdio.h>
#include <stdlib.h>
#define MAX 100

#include "../lista/funcoes.h"

typedef int TipoL;

typedef struct ListaNo
{
  TipoL info;
  struct ListaNo *prox;
} * pListaNo;

typedef struct TLista
{
  pListaNo primeiro, ultimo, iterador;
  int longitude;
} * Lista;

typedef int TipoP;

typedef struct
{
  int topo;
  TipoP info[MAX];
} Tpilha, *Pilha;

// Fuções básicas de Pilha

Pilha inicPilha(void);          // Cria e retorna uma pilha vazia
void push(Pilha p, TipoP elem); // Adiciona(empilha) um elemento no topo da pilha
TipoP pop(Pilha p);             // Elimina(desempilha) o elemento que está no topo da pilha e retorna este elemento
TipoP infoPilha(Pilha p);       // Retorna o elemento que está no topo da pilha sem removê-lo da pilha
int vaziaPilha(Pilha p);        // Retorna verdadeiro se a pilha está vazia e falso caso contrário
void destruirPilha(Pilha p);    // Destrói a pilha p, desalocando toda memória ocupada
void printPilha(Pilha p);       // Mostra o conteúdo da pilha

// > Exercícios Pilha <

// 1) Inverter uma lista utilizando como apoio uma pilha
void invLista(Lista lst);
// 2) Fazer uma cópia de uma pilha, usando como apoio uma lista
Pilha copiarPilha(Pilha p);
// 3) Inverter o conteúdo de uma pilha
void invPilha(Pilha p);
// 4) Dizer se duas pilhas são iguais sem destruir seu conteúdo
int iguaisPilhas(Pilha p1, Pilha p2);
// 5) Avaliar uma expressão aritmética na notação posfixa
int avaliarExpressao(Lista lstExp);
// 6) Imprimir o conteúdo de uma pilha, sem alterar seu conteúdo( a pilha deve ser restaurada)
void imprimePilha(Pilha p);
// 7) Colocar no fundo da pilha o elemento elem
void fundoPilha(Pilha p, TipoP elem);
// 8) Computar e retornar o número de elementos da pilha, sem alterar seu conteúdo( a pilha deve ser restaurada)
int longPilha(Pilha p);
// 9) Eliminar da pilha todas as ocorrências do elemento elem
void elimTodosPilha(Pilha p, TipoP elem);
// 10) Somar todos os elementos da pilha e retorna seu resultado
int somaPilha(Pilha p);
// 11) Retornar true(1) se o conteúdo da pilha é um palíndrome e false(0) caso contrário
int palindromePilha(Pilha p);