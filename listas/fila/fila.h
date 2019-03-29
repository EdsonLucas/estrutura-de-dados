#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef int TipoF;

typedef struct
{
    TipoF info[MAX]; // Vetor circular
    int primeiro;    // Posição do primeiro elemento
    int ultimo;      // Posição do último elemento
} Tfila, *Fila;

// Fuções básicas de Fila

Fila inicFila(void);               // Cria e retorna uma fila vazia
void adicFila(Fila f, TipoF elem); // Adiciona um elemento no final da fila
TipoF elimFila(Fila f);            // Elimina e retorna o primeiro elemento da fila
TipoF infoFila(Fila f);            // Retorna o primeiro elemento da fila sem remover
int vaziaFila(Fila f);             // Retorna verdadeiro se a fila está vazia e falso caso contrário
void destruirFila(Fila f);         // Destrói a fila f, desalocando toda memória ocupada
void printFila(Fila f);            // Mostra todo conteúdo da fila

// > Exercícios Fila <

// 1) Fazer uma cópia de uma Fila, usando como apoio uma lista
Fila copiarFila(Fila f);
// 2) Computar e retornar o número de elementos da fila, sem alterar seu conteúdo
int longFila(Fila f);
// 3) Concatenar duas filas, deixando o resultado na primeira(f1)
void concatFilas(Fila f1, Fila f2);
// 4) Inverter os elementos da fila
void invFila(Fila f);
// 5) Retorna true(1) se o elemento elem está presente na fila e false(0) caso contrário
int existeElemento(Fila f, TipoF elem);
// 6) Retorna true(1) se as filas f1 e f2 têm os mesmos elementos, na mesma ordem, e false(0) caso contrário
int iguaisFilas(Fila f1, Fila f2);
// 7) Adiciona o elemento elem na posição pos da fila, deslocando todos os elementos seguintes uma posição para trás
void adicFilaPos(Fila f, TipoF elem, int pos);
// 8) Remove da fila o elemento elem
void elimElemento(Fila f, TipoF elem);
// 9) Deixa na fila f1 todos os elementos da fila f, menores que elem e na fila f2 todos os elementos maiores que elem
void partirFila(Fila f, Fila f1, Fila f2, TipoF elem);
// 10) Coloca o elemento elem na primeira posição da fila
void primeiroDaFila(Fila f, TipoF elem);
// 11) e 12) exercícios para implementar
