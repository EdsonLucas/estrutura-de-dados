#include <stdio.h>
#include <stdlib.h>
#define max 3

float *prod_vetorial(float *v1, float *v2)
{

  float *vet = NULL;

  vet = (float *)malloc(3 * sizeof(float));
  vet[0] = v1[1] * v2[2] - v1[1] * v2[2];
  vet[1] = v1[2] * v2[0] - v1[2] * v2[0];
  vet[2] = v1[0] * v2[1] - v1[0] * v2[1];

  return vet;
}

int main()
{

  int i;
  float *v1 = NULL;
  float *v2 = NULL;
  float *prodVet = NULL;

  v1 = (float *)malloc(3 * sizeof(float));
  v2 = (float *)malloc(3 * sizeof(float));

  if (v1 == NULL || v2 == NULL)
  {
    exit(1);
  }

  for (i = 0; i < max; i++)
  {
    v1[i] = i + 1;
    v2[i] = i + 2;
  }

  printf("\n\n");

  prodVet = prod_vetorial(v1, v2);

  for (i = 0; i < max; i++)
  {
    printf("%f\n", prodVet[i]);
  }

  free(v1);
  free(v2);
  free(prodVet);

  return 0;
}