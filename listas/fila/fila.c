#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

Fila inicFila(void)
{
  Fila f = (Fila)malloc(sizeof(Tfila));
  f->primeiro = -1; // Fila vazia
  f->ultimo = -1;   // Fila vazia

  return f;
}

void adicFila(Fila f, TipoF elem)
{
  // Se a fila não está cheia, é passado o valor 0 como inicial
  if (f->primeiro == -1)
  {
    f->info[0] = elem;
    f->primeiro = 0;
  }
  else if ((f->ultimo + 1) % MAX == f->primeiro)
  {
    printf("Infelizmente a fila já está cheia.\n");
  }
  else
  {
    f->ultimo = (f->ultimo + 1) % MAX; // Descobre a nova posição do último elemento
    f->info[f->ultimo] = elem;
  }
}

TipoF elimFila(Fila f)
{
  TipoF primeiroElem;
  if (f->primeiro == -1)
  {
    printf("A fila está vazia.\n");
  }
  else if (f->primeiro == f->ultimo)
  {
    primeiroElem = f->info[f->primeiro];
    f->primeiro = -1; // Fila vazia
    f->ultimo = -1;   // Fila vazia
    return primeiroElem;
  }
  else
  {
    primeiroElem = f->info[f->primeiro];
    f->primeiro = (f->primeiro + 1) % MAX;
    return primeiroElem;
  }
}

TipoF infoFila(Fila f)
{
  if (f->primeiro == -1)
  {
    printf("A fila está vazia.\n");
  }
  else
  {
    return f->info[f->primeiro];
  }
}

int vaziaFila(Fila f)
{
  return (f->primeiro == -1);
}

void destruirFila(Fila f)
{
  free(f);
}

void printFila(Fila f)
{
  if (f->primeiro == -1)
  {
    printf("A fila está vazia.\n");
  }
  else
  {
    TipoF elem;
    Fila copia = inicFila();

    while (!vaziaFila(f))
    {
      elem = elimFila(f);
      printf("%d ", elem);
      adicFila(copia, elem);
    }
    // A fila original está vazia e a cópia está cheia.

    printf("\n");

    while (!vaziaFila(copia))
    {
      adicFila(f, elimFila(copia));
    }

    destruirFila(copia);
  }
}

/*
---------------------------------
            EXERCICIOS
---------------------------------
*/

// 1
Fila copiarFila(Fila f)
{
  Fila copia = inicFila();

  if (vaziaFila(f))
  {
    return copia;
  }
  else
  {
    Fila faux = inicFila();

    while (!vaziaFila(f))
    {
      adicFila(faux, elimFila(f));
    }
    // Ao sair deste loop a fila f está vazia e a auxiliar está cheia

    TipoF elem;

    while (!vaziaFila(faux))
    {
      elem = elimFila(faux);
      adicFila(f, elem);
      adicFila(copia, elem);
    }
    // A fila original foi restaurada e a copia da fila está cheia

    destruirFila(faux);

    return copia;
  }
}

// 2
int longFila(Fila f)
{

  if (vaziaFila(f))
  {
    return 0;
  }
  else
  {
    Fila faux = inicFila();

    while (!vaziaFila(f))
    {
      adicFila(faux, elimFila(f));
    }
    // Ao sair deste loop a fila f está vazia e a auxiliar está cheia

    int cont;

    while (!vaziaFila(faux))
    {
      adicFila(f, elimFila(faux));
      cont++;
    }
    // A fila original foi restaurada e os elementos contados

    destruirFila(faux);

    return cont;
  }
}

// 3
void concatFilas(Fila f1, Fila f2)
{

  Fila faux = inicFila();

  while (!vazilaFila(f2))
  {
    adicFila(faux, elimFila(f2));
  }
  // Ao sair deste loop a fila 2 está vazia e a auxiliar está cheia

  TipoF elem;

  while (!vaziaFila(faux))
  {
    elem = elimFila(faux);
    adicFila(f1, elem);
    adicFila(f2, elem);
  }
  // A fila 1 possui os elementos concatenados da 2 fila e a fila 2 foi restaurada

  destruirFila(faux);
}

// 4
void invFila(Fila f)
{
  Pilha p = inicPilha();

  while (!vaziaFila(f))
  {
    push(p, elimFila(f));
  }

  while (!vaziaPilha(p))
  {
    adicFila(f, pop(p));
  }

  destruirPilha(p);
}