#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

float distEntrePtos(Ponto p1, Ponto p2)
{
  float dab, ab;

  dab = sqrt(
      pow(getX(p2) - getX(p1), 2) +
      pow(getY(p2) - getY(p1), 2) +
      pow(getZ(p2) - getZ(p1), 2));

  return dab;
}

int main()
{
  float x = 1, y = 2, z = 3;
  Ponto p1 = NULL, p2 = NULL;

  p1 = criaPonto(x, y, z);
  p2 = criaPonto(y, x, z);

  x = distEntrePtos(p1, p2);

  printf("Ponto 1: (%f, %f, %f)\n", p1->x, p1->y, p1->z);
  printf("Ponto 2: (%f, %f, %f)\n", p2->x, p2->y, p2->z);
  printf("%f", x);

  return 0;
}