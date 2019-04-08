#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

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

// Funcoes basicas de Lista

Lista inicLista(void);                // Cria e retorna uma lista vazia
void anxLista(Lista lst, TipoL elem); // Adiciona um elemento depois do iterador
void insLista(Lista lst, TipoL elem); // Adiciona um elemento antes do iterador
void elimLista(Lista lst);            // Elimina o elemento que esta sob o iterador
void primLista(Lista lst);            // Coloca o iterador sobre o primeiro elemento da lista
void ultLista(Lista lst);             // Coloca o iterador sobre o ultimo elemento da lista
void segLista(Lista lst);             // Avanca o iterador uma posicao
void posLista(Lista lst, int pos);    // Coloca o iterador sobre a posicao pos
TipoL infoLista(Lista lst);           // Retorna o elemento sob o iterador
int longLista(Lista lst);             // Retorna a quantidade de elementos da lista
int fimLista(Lista lst);              // Retorna verdadeiro se o iterador estiver indefinido
int contaElmento(Lista lst, TipoL elem);

// > Exercicios Lista <

// 1) Verificar se duas listas tem os mesmos elementos nas mesmas posicoes
int iguaisListas(Lista lst1, Lista lst2);
// 2) Verificar se duas listas tem os mesmos elementos
int semelhantesListas(Lista lst1, Lista lst2);
// 3) Verificar se a lista lst2 e uma sublista de lst1
int subLista(Lista lst1, Lista lst2);
// 4) Verificar se uma lista lst2 esta contida numa lista lst1
int contidaLista(Lista lst1, Lista lst2);
// 5) Verificar se uma lista lst esta ordenada
int ordenadaLista(Lista lst1);
// 6) Adiciona o elemento elem no final de lst
void adicLista(Lista lst, TipoL elem);
// 7) Substitue o conteudo atual do iterador pelo elemento elem
void substitueLista(Lista lst, TipoL elem);
// 8) Indica se o elemento elem aparece na lista
int estaNaLista(Lista lst, TipoL elem);
// 9) Exibe todos os elementos da lista, utilizando a operacao posLista para avancar
void exibeLista(Lista lst);
// 10) Coloca o iterador na posicao anterior a atual
void antLista(Lista lst);
// 11) Retorna a posicao do iterador na lista
int posIteradorLista(Lista lst);
// 12) Deixar na lista somente uma ocorrencia de cada um dos elementos
void simplificarLista(Lista lst);
// 13) Retorna o numero total de elementos diferentes em lst
int numDiferentesLista(Lista lst);
// 14) Computa o numero de vezes que o elemento elem aparece na lista
int numOcorrenciasLista(Lista lst, TipoL elem);
// 15) Retorna o elemento que aparece mais vezes na lista nao vazia lst
TipoL maxOcorrenciaLista(Lista lst);
// 16) Retorna a posicao da ultima ocorrencia do elemento elem. Se nao ocorre, retorna zero
int ultOcorrenciaLista(Lista lst, TipoL elem);
// 17) Elimina da lista lst todos os elementos compreendidos entre a posicao p1 e p2, inclusive
void eliminarLista(Lista lst, int p1, int p2);

#endif
