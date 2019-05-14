#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 10

typedef int TipoP;

typedef struct
{
    TipoP info[MAX];
    int topo;
} Tpilha, *Pilha;

typedef char TipoExp;

typedef struct ListaNoE
{
    TipoExp info;
    struct ListaNo *prox;
} *pListaNoE;

typedef struct TListaE
{
    pListaNoE primeiro, ultimo, iterador;
    int longitude;
} *ListaExp;

void primListaExp(ListaExp lst);
void segListaExp( ListaExp lst );
int fimListaExp( ListaExp lst);
ListaExp inicListaExp();
void anxListaExp( ListaExp lst, TipoExp elem);

Pilha inicPilha( void );
void push( Pilha p, TipoP elem);
TipoP pop( Pilha p);
int vaziaPilha(Pilha p);

int avaliarExpressao(ListaExp lstExp);

int main()
{
    ListaExp lst = inicListaExp();
    anxListaExp(lst, '2');
    anxListaExp(lst, '2');
    anxListaExp(lst, '+');
    anxListaExp(lst, '4');
    anxListaExp(lst, '1');
    anxListaExp(lst, '+');
    anxListaExp(lst, '*');
    anxListaExp(lst, '5');
    anxListaExp(lst, '*');

    for(primListaExp(lst); !fimListaExp(lst); segListaExp(lst))
        printf("%c", lst->iterador->info);
    int resultado = avaliarExpressao(lst);
    printf("\nResultado = %i", resultado);
    return 0;
}

/// ------------------------------------------------------

Pilha inicPilha()
{

    Pilha p = (Pilha) malloc (sizeof(Tpilha));
    p->topo = -1; // pilha vazia
    return p;
}

void push(Pilha p, TipoP elem)
{

    if(p->topo < MAX-1)
    {
        //determinar a proxima posicao livre
        //incrementar o topo
        p->topo++;
        //adicionar o elemento
        p->info[p->topo] = elem;
    }
    else
    {
        printf("\n pilha cheia \n");
    }
}

TipoP pop(Pilha p)
{

    if(p->topo == -1)
    {
        printf("\n pilha vazia \n");
        return (TipoP)NULL;
    }
    else
    {
        //salvo o elemento do topo para ser retornado
        TipoP elem = p->info[p->topo];
        p->topo--; // elimina o elemento
        return elem;
    }
}

int vaziaPilha(Pilha p)
{
    return (p->topo == -1);
}

/// ------------------------------------------------------

void primListaExp(ListaExp lst)
{
    lst->iterador = lst->primeiro;
}

void segListaExp( ListaExp lst )
{
    if (lst->iterador == NULL)
    {
        printf("\n erro: iterador indefindio \n");
    }
    else
    {
        lst->iterador = lst->iterador->prox;
    }
}

int fimListaExp( ListaExp lst)
{
    return (lst->iterador == NULL);
}

ListaExp inicListaExp()
{
    ListaExp lst;
    // Aloca espaço na memória atribuindo todos os valores a zero
    lst = (ListaExp)malloc(sizeof(struct TListaE));
    lst->longitude = 0;
    lst->iterador = NULL;
    lst->primeiro = NULL;
    lst->ultimo = NULL;
    return lst;
}

void anxListaExp( ListaExp lst, TipoExp elem)
{

    //tratamento de erro
    if (lst->iterador == NULL && lst->longitude > 0)
    {
        printf("\n erro: iterador indefinido e lista cheia \n");
    }
    else
    {

        //alocar memória para o novoNo a ser adicionado
        pListaNoE novoNo = (pListaNoE)malloc(sizeof(struct ListaNoE));
        novoNo->info = elem; // atribuir o elemento a ser armazenado
        novoNo->prox = NULL; // atribuir NULL para deixar o novoNo preparado

        if (lst->longitude == 0) // lista vazia
        {
            //apontar para o novoNo
            lst->primeiro = novoNo;
            lst->ultimo = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }
        else if (lst->iterador == lst->ultimo) // iterador sobre o ultimo elemento
        {
            //por no campo prox do ultimo no o endereco do novoNo
            lst->iterador->prox = novoNo;
            //lst->ultimo->prox = novoNo;
            //atualizar o campo ultimo com o endereco do novoNo
            lst->ultimo = novoNo;
            //atualizar o campo iterador com o endereco do novoNo
            lst->iterador = novoNo;
            //incrementar a quantidade de nos
            lst->longitude++;
        }
        else //iterador sobre um noh intermediario
        {
            // o prox do novoNo aponta para o proximo Noh depois do iterador
            // fazer o prox do iterador apontar para o novoNo
            novoNo->prox = lst->iterador->prox;
            lst->iterador->prox = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }
    }
}

/// ------------------------------------------------------
int avaliarExpressao(ListaExp lstExp)
{
    if (lstExp->longitude == 0)
    {
        printf("avaliarExpressao: Lista vazia.");
        return -1;
    }

    Pilha pAux = inicPilha();
    int sum = 0;

    for(primListaExp(lstExp); !fimListaExp(lstExp); segListaExp(lstExp))
    {
        if( isdigit(lstExp->iterador->info) )
        {
            push(pAux, atoi(lstExp->iterador->info));
        }
        else
        {
            if (strcmp(lstExp->iterador->info, "+") == 0)
            {
                while(!vaziaPilha(pAux))
                {
                    sum = sum + pop(pAux);
                }
            }
            if (strcmp(lstExp->iterador->info, "*") == 0)
            {
                while(!vaziaPilha(pAux))
                {
                    if (sum == 0)
                    {
                        sum = 1;
                    }
                    sum = sum * pop(pAux);
                }
            }
        }
    }
    return sum;
}
