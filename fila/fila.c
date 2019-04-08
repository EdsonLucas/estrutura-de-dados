#include <stdlib.h>
#include <stdio.h>
#include "fila.h"
#include "../pilha/pilha.h"

Fila inicFila(void)
{
    Fila f = (Fila)malloc(sizeof(Tfila));
    f->primeiro = -1; // Fila vazia
    f->ultimo = -1;   // Fila vazia

    return f;
}

void adicFila(Fila f, TipoF elem)
{
    // Se a fila nao esta cheia, e passado o valor 0 como inicial
    if (f->primeiro == -1)
    {
        f->info[0] = elem;
        f->primeiro = 0;
    }
    else if ((f->ultimo + 1) % MAX == f->primeiro)
    {
        printf("\n Infelizmente a fila ja esta cheia.");
    }
    else
    {
        f->ultimo = (f->ultimo + 1) % MAX; // Descobre a nova posicao do ultimo elemento
        f->info[f->ultimo] = elem;
    }
}

TipoF elimFila(Fila f)
{
    TipoF primeiroElem;
    if (f->primeiro == -1)
    {
        printf("\n A fila esta vazia.");
        return NULL;
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
        printf("\n A fila esta vazia.");
        return NULL;
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
        printf("\n A fila esta vazia.");
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
        // A fila original esta vazia e a copia esta cheia.

        printf("\n");

        while (!vaziaFila(copia))
        {
            adicFila(f, elimFila(copia));
        }

        destruirFila(copia);
    }
}

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
        // Ao sair deste loop a fila f esta vazia e a auxiliar esta cheia

        TipoF elem;

        while (!vaziaFila(faux))
        {
            elem = elimFila(faux);
            adicFila(f, elem);
            adicFila(copia, elem);
        }
        // A fila original foi restaurada e a copia da fila esta cheia

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
        // Ao sair deste loop a fila f esta vazia e a auxiliar esta cheia

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

    while (!vaziaFila(f2))
    {
        adicFila(faux, elimFila(f2));
    }
    // Ao sair deste loop a fila 2 esta vazia e a auxiliar esta cheia

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

// 5
int existeElemento(Fila f, TipoF elem)
{
    Fila copia = inicFila();
    copia = copiarFila(f);

    while (!vaziaFila(copia))
    {
        if (elimFila(copia) == elem)
        {
            destruirFila(copia);
            return 1;
        }
    }

    destruirFila(copia);
    return 0;
}

// 6
int iguaisFilas(Fila f1, Fila f2)
{
    if (longFila(f1) == longFila(f2))
    {
        Fila copia1 = inicFila();
        copia1 = copiarFila(f1);

        Fila copia2 = inicFila();
        copia2 = copiarFila(f2);

        while (!vaziaFila(copia1))
        {
            if (elimFila(copia1) != elimFila(copia2))
            {
                destruirFila(copia1);
                destruirFila(copia2);
                return 0;
            }
        }

        destruirFila(copia1);
        destruirFila(copia2);
        return 1;
    }

    return 0;
}

// 7
void adicFilaPos(Fila f, TipoF elem, int pos)
{
    if (pos < 0 || pos > longFila(f) + 1)
    {
        printf("Posicao invalida\n");
    }
    else if (longFila(f) < pos)
    {
        adicFila(f, elem);
    }
    else
    {
        Fila copia = inicFila();
        copia = copiarFila(f);
        int cont = 0;

        while (!vaziaFila(copia))
        {
            if (cont == pos)
            {
                adicFila(f, elem);
            }
            else
            {
                adicFila(f, elimFila(copia));
                cont++;
            }
        }

        while (!vaziaFila(copia))
        {
            adicFila(f, elimFila(copia));
        }

        destruirFila(copia);
    }
}

// 8
void elimElemento(Fila f, TipoF elem)
{
    if (!vaziaFila(f))
    {
        Fila copia = inicFila();

        while (!vaziaFila(f))
        {
            if (infoFila(f) != elem)
            {
                adicFila(copia, elimFila(f));
            }
            else
            {
                elimFila(f);
            }
        }

        f = copiarFila(copia);
        destruirFila(copia);
    }
    else
    {
        printf("A fila esta vazia.\n");
    }
}

// 9
void partirFila(Fila f, Fila f1, Fila f2, TipoF elem)
{
    while (!vaziaFila(f))
    {
        if (infoFila(f) > elem)
        {
            adicFila(f2, elimFila(f));
        }
        else
        {
            adicFila(f1, elimFila(f));
        }
    }
}

// 10
void primeiroDaFila(Fila f, TipoF elem)
{
    Fila copia = inicFila();
    adicFila(copia, elem);
    copia = copiarFila(f);

    while (!vaziaFila(f))
    {
        elimFila(f);
    }

    f = copiarFila(copia);
    destruirFila(copia);
}

// 11
void simulaBanco()
{

    Fila f1 = inicFila();
    Fila f2 = inicFila();
    Fila f3 = inicFila();
    int cont1 = 0, cont2 = 0, cont3 = 0;

    // Remover 1, 2, 3
    int fila;

    int i; // Pessoas
    for (i = 1; i < 51; i++)
    {

        fila = rand() % 3;
        if (fila == 0 && cont1 < 10)
        {
            adicFila(f1, i);
            cont1++;
            printf("\n I: cont1=%d\n", cont1);
        }
        else if (cont2 < 10)
        {
            adicFila(f2, i);
            cont2++;
            printf("\n I: cont2=%d\n", cont2);
        }
        else if (cont3 < 10)
        {
            adicFila(f3, i);
            cont3++;
            printf("\n I: cont3=%d\n", cont3);
        }
        else
        {
            printf("Todas as filas estao cheias \n");
        }

        if (i % 3 == 0)
        {
            fila = rand() % 3;
            if (fila == 0 && !vaziaFila(f1))
            {
                elimFila(f1);
                cont1--;
            }
            else if (fila == 1 && !vaziaFila(f2))
            {
                elimFila(f2);
                cont2--;
            }
            else if (fila == 2 && !vaziaFila(f3))
            {
                elimFila(f3);
                cont3--;
            }
        }
    }
    printf("fila=%d fila=%d fila3=%d\n", cont1, cont2, cont3);
}
