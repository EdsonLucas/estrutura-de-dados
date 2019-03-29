#include <stdio.h>
#include <stdlib.h>
#ifndef PILHA_H_INCLUDED
#include "pilha.h"
#endif

Pilha inicPilha()
{

  Pilha p = (Pilha)malloc(sizeof(Tpilha));
  p->topo = -1; // pilha vazia
  return p;
}

void push(Pilha p, TipoP elem)
{

  if (p->topo < MAX - 1)
  {
    // Determinar a proxima posição livre
    // Incrementar o topo
    p->topo++;
    // Adicionar o elemento
    p->info[p->topo] = elem;
  }
  else
  {
    printf("A pilha está cheia.\n");
  }
}

TipoP pop(Pilha p)
{

  if (p->topo == -1)
  {
    printf("A pilha está vazia.\n");
  }
  else
  {
    // Salvo o elemento do topo para ser retornado
    TipoP elem = p->info[p->topo];
    p->topo--; // Elimina o elemento
    return elem;
  }
}

TipoP infoPilha(Pilha p)
{
  if (p->topo > -1) // pilha cheia
    return p->info[p->topo];
  else
    printf("A pilha está vazia.\n");
}

int vaziaPilha(Pilha p)
{
  return (p->topo == -1);
}

void destruirPilha(Pilha p)
{

  free(p);
}

void printPilha(Pilha p)
{

  if (p->topo == -1)
  {
    printf("A pilha está vazia.\n");
  }
  else
  {

    int i;
    for (i = p->topo; i >= 0; i--)
      printf(" %d\n ", p->info[i]);
  }
  printf("\n");
}

/*
---------------------------------
            EXERCICIOS
---------------------------------
*/

// 1
void invLista(Lista lst)
{
  Pilha p = iniciaLista();
  for (primLista(lst); !fimLista(lst);)
  {
    push(p, infoLista(lst));
    elimLista(lst);
  }
  while (!vaziaPilha(p))
  {
    anxLista(lst, pop(p));
  }
  destruirPilha(p);
}

// 2
Pilha copiarPilha(Pilha p)
{
  Lista lst = inicLista();
  Pilha copia = inicPilha();
  while (!vaziaPilha(p))
  {
    insLista(lst, pop(p));
  }
  for (primLista(lst); !fimLista(lst);)
  {
    push(p, infoLista(lst));
    push(copia, infoLista(lst));
    elimLista(lst);
  }
  return copia;
}

// 3
void invPilha(Pilha p)
{
  Lista lst = inicLista();
  while (!vaziaPilha(p))
  {
    anxLista(lst, pop(p));
  }
  for (primLista(lst); !fimLista(lst);)
  {
    push(p, infoLista(lst));
    elimLista(lst);
  }
}