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

// Fuções básicas de Lista

Lista inicLista(void);                // Cria e retorna uma lista vazia
void anxLista(Lista lst, TipoL elem); // Adiciona um elemento depois do iterador
void insLista(Lista lst, TipoL elem); // Adiciona um elemento antes do iterador
void elimLista(Lista lst);            // Elimina o elemento que está sob o iterador
void primLista(Lista lst);            // Coloca o iterador sobre o primeiro elemento da lista
void ultLista(Lista lst);             // Coloca o iterador sobre o último elemento da lista
void segLista(Lista lst);             // Avança o iterador uma posição
void posLista(Lista lst, int pos);    // Coloca o iterador sobre a posição pos
TipoL infoLista(Lista lst);           // Retorna o elemento sob o iterador
int longLista(Lista lst);             // Retorna a quantidade de elementos da lista
int fimLista(Lista lst);              // Retorna verdadeiro se o iterador estiver indefinido
int contaElmento(Lista lst, TipoL elem);

// > Exercícios Lista <

// 1) Verificar se duas listas têm os mesmos elementos nas mesmas posições
int iguaisListas(Lista lst1, Lista lst2);
// 2) Verificar se duas listas têm os mesmos elementos
int semelhantesListas(Lista lst1, Lista lst2);
// 3) Verificar se a lista lst2 é uma sublista de lst1
int subLista(Lista lst1, Lista lst2);
// 4) Verificar se uma lista lst2 está contida numa lista lst1
int contidaLista(Lista lst1, Lista lst2);
// 5) Verificar se uma lista lst está ordenada
int ordenadaLista(Lista lst1);
// 6) Adiciona o elemento elem no final de lst
void adicLista(Lista lst, TipoL elem);
// 7) Substitue o conteúdo atual do iterador pelo elemento elem
void substitueLista(Lista lst, TipoL elem);
// 8) Indica se o elemento elem aparece na lista
int estaNaLista(Lista lst, TipoL elem);
// 9) Exibe todos os elementos da lista, utilizando a operação posLista para avan�ar
void exibeLista(Lista lst);
// 10) Coloca o iterador na posição anterior à atual
void antLista(Lista lst);
// 11) Retorna a posição do iterador na lista
int posIteradorLista(Lista lst);
// 12) Deixar na lista somente uma ocorrência de cada um dos elementos
void simplificarLista(Lista lst);
// 13) Retorna o número total de elementos diferentes em lst
int numDiferentesLista(Lista lst);
// 14) Computa o número de vezes que o elemento elem aparece na lista
int numOcorrenciasLista(Lista lst, TipoL elem);
// 15) Retorna o elemento que aparece mais vezes na lista não vazia lst
TipoL maxOcorrenciaLista(Lista lst);
// 16) Retorna a posição da última ocorrência do elemento elem. Se não ocorre, retorna zero
int ultOcorrenciaLista(Lista lst, TipoL elem);
// 17) Elimina da lista lst todos os elementos compreendidos entre a posição p1 e p2, inclusive
void eliminarLista(Lista lst, int p1, int p2);
