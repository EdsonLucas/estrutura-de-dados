#include <stdio.h>
#include <stdlib.h>
#define max 10

void incr_vetor(int* v, int n) {
  
  int i;
  for(i = 0; i < n; i++) {
    v[i]++;
  }
}

int main() {

  int i;
  int *vet = NULL;

  vet = (int*)malloc(10*sizeof(int));

  if(vet == NULL) { exit(1); }

  for(i = 0; i < max; i++) {
    vet[i] = i + 1;
    printf("Valor: %d\n", vet[i]);
  }

  incr_vetor(vet, max);

  printf("\n");

  for(i = 0; i < max; i++) {
    printf("Valor: %d\n", vet[i]);
  }

  free(vet);

  return 0;
}