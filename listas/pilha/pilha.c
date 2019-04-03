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

// 4
int iguaisPilhas(Pilha p1, Pilha p2)
{
  if (!vaziaPilha(p1) && !vaziaPilha(p2))
  {
    Pilha p1_copia = inicPilha();
    Pilha p2_copia = inicPilha();

    p1_copia = copiarPilha(p1);
    p2_copia = copiarPilha(p2);

    while (!vaziaPilha(p1_copia))
    {
      if (infoPilha(p1_copia) == infoPilha(p2_copia))
      {
        pop(p1_copia);
        pop(p2_copia);
      }
      else
      {
        return 0;
      }
    }

    if (!vaziaPilha(p1_copia) || !vaziaPilha(p2_copia))
    {
      return 0;
    }

    return 1;
  }

  return 1;
}

// 5
int avaliarExpressao(Lista lstExp)
{
}

//6
void imprimePilha(Pilha p)
{
  Pilha copia = inicPilha();
  copia = copiarPilha(p);
  while (!vaziaPilha(copia))
  {
    printf("%i\n", pop(copia));
  }
}

//7
void fundoPilha(Pilha p, TipoP elem)
{
  Pilha copia = inicPilha();
  copia = copiarPilha(p);

  invPilha(copia);
  push(copia, elem);

  while (!vaziaPilha(p))
  {
    pop(p);
  }

  p = copiarPilha(copia);
}

// 8
int longPilha(Pilha p)
{
  Pilha copia = inicPilha();
  copia = copiarPilha(p);

  int cont = 0;

  while (!vaziaPilha(copia))
  {
    pop(copia);
    cont++;
  }

  return cont;
}

// 9
void elimTodosPilha(Pilha p, TipoP elem)
{
  while (!vaziaPilha(p))
  {
    if (infoPilha(p) == elem)
    {
      pop(p);
    }
  }
}

// 10
int somaPilha(Pilha p)
{
  Pilha copia = inicPilha();
  copia = copiarPilha(p);

  int cont = 0;

  while (!vaziaPilha(copia))
  {
    cont += infoPilha(copia);
    pop(copia);
  }

  return cont;
}

// 11
int palindromePilha(Pilha p)
{
  if(!vaziaPilha(p)) 
  {
    Pilha copia = inicPilha();

    copia = copiarPilha(p);
    invPilha(copia);

    while(!vaziaPilha(p)) 
    {
      if(infoPilha(p) == infoPilha(copia)) 
      {
        pop(p);
        pop(copia);
      }
      else
      {
        return 0;
      }
    }

    if(!vaziaPilha(p) && !vaziaPilha(copia)) 
    {
      return 1;
    }

    return 1;
  }

  return 0;
}
