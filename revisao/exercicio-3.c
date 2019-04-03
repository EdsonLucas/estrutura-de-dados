#include <stdio.h>
#include <stdlib.h>

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

int main()
{
  float x = 1, y = 2, z = 3;
  Ponto p1 = NULL;

  p1 = criaPonto(x, y, z);

  printf("%f\n", p1->x);
  printf("%f\n", p1->y);
  printf("%f\n", p1->z);

  setX(p1, 10);
  setY(p1, 11);
  setZ(p1, 12);

  printf("\n\n");

  x = getX(p1);
  printf("%f\n", p1->x);
  y = getY(p1);
  printf("%f\n", p1->y);
  z = getZ(p1);
  printf("%f\n", p1->z);

  return 0;
}