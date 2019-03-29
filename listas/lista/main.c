#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main()
{
    Lista lst2 = inicLista();
    anxLista(lst2, 1);
    anxLista(lst2, 2);
    anxLista(lst2, 3);

    Lista lst1 = inicLista();
    anxLista(lst1, 1);
    anxLista(lst1, 1);
    anxLista(lst1, 2);
    anxLista(lst1, 3);
    anxLista(lst1, 2);


    int resp = maxOcorrenciaLista(lst1);

    printf("%i", resp);
    return 0;
}
