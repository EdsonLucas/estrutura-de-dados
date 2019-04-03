#include <stdio.h>
#include <stdlib.h>
#define max 5

typedef float TipoP;
typedef struct ponto
{
  TipoP x, y, z;
} * Ponto;

Ponto criaPonto(TipoP x, TipoP y, TipoP z)
{
  Ponto p = NULL;

  p = (Ponto)malloc(sizeof(struct ponto));

  if (p == NULL)
  {
    printf("deu ruim");
    exit(1);
  }

  p->x = x;
  p->y = y;
  p->z = z;

  return p;
}

TipoP getX(Ponto pto)
{
  return pto->x;
}

TipoP getY(Ponto pto)
{
  return pto->y;
}

TipoP getZ(Ponto pto)
{
  return pto->z;
}

void setX(Ponto pto, TipoP x)
{
  pto->x = x;
}

void setY(Ponto pto, TipoP y)
{
  pto->y = y;
}

void setZ(Ponto pto, TipoP z)
{
  pto->z = z;
}

Ponto centroGeom(Ponto *vetPtos, int nPtos)
{
  Ponto p = NULL;
  int i;

  p = (Ponto)malloc(sizeof(Ponto));
  setX(p, 0);
  setY(p, 0);
  setZ(p, 0);

  for (i = 0; i < max; i++)
  {
    p->x += vetPtos[i]->x;
    p->y += vetPtos[i]->y;
    p->z += vetPtos[i]->z;
  }

  p->x = p->x / nPtos;
  p->y = p->x / nPtos;
  p->z = p->x / nPtos;

  return p;
}

int main()
{
  int i;
  float x = 1, y = 2, z = 3;
  Ponto p1 = NULL, p2 = NULL, cg;
  Ponto vet[5];

  for (i = 0; i < max; i++)
  {
    vet[i] = criaPonto(i, i, i);
  }

  cg = centroGeom(vet, 5);

  printf("%f\n", cg->x);
  printf("%f\n", cg->y);
  printf("%f\n", cg->z);

  free(cg);

  return 0;
}