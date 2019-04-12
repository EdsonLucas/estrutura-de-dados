#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#ifndef FUNCOES_C_INCLUDED
#define FUNCOES_C_INCLUDED
#include "funcoes.h"

/// Funções Lista

Lista inicLista()
{
    Lista lst;
    // Aloca espaço na memória atribuindo todos os valores a zero
    lst = (Lista)malloc(sizeof(struct TLista));
    lst->longitude = 0;
    lst->iterador = NULL;
    lst->primeiro = NULL;
    lst->ultimo = NULL;
    return lst;
}

void primLista(Lista lst)
{
    // Iterador no primeiro elemento da lista
    lst->iterador = lst->primeiro;
}

void ultLista(Lista lst)
{
    // Põe o iterador no último elemento da lista
    lst->iterador = lst->ultimo;
}

void posLista(Lista lst, int pos)
{

    if (lst->longitude > 0 && pos >= 1 && pos <= lst->longitude)
    {
        int i;
        for (i = 1, lst->iterador = lst->primeiro; i < pos; i++, lst->iterador = lst->iterador->prox)
        {
        }
    }
    else
    {
        lst->iterador = NULL;
    }
}

int fimLista(Lista lst)
{

    return (lst->iterador == NULL);
}

void segLista(Lista lst)
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

TipoL infoLista(Lista lst)
{
    if (lst->iterador == NULL)
    {
        printf("\n erro: iterador indefinido \n");
        return NULL;
    }
    else
        return lst->iterador->info;
}

int longLista(Lista lst)
{
    return lst->longitude;
}

void anxLista(Lista lst, TipoL elem)
{

    //tratamento de erro
    if (lst->iterador == NULL && lst->longitude > 0)
    {
        printf("\n erro: iterador indefinido e lista cheia \n");
    }
    else
    {

        //alocar memória para o novoNo a ser adicionado
        pListaNo novoNo = (pListaNo)malloc(sizeof(struct ListaNo));
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

void insLista(Lista lst, TipoL elem)
{

    if (lst->iterador == NULL && lst->longitude > 0)
    {
        printf("\n erro: iterador indefinido e lista cheia \n");
    }
    else
    {

        //alocar memória para o novoNo a ser adicionado
        pListaNo novoNo = (pListaNo)malloc(sizeof(struct ListaNo));
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
        else if (lst->iterador == lst->primeiro) // iterador sobre o primeiro elemento
        {
            //novoNo->prox = lst->iterador;
            novoNo->prox = lst->primeiro;
            lst->primeiro = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }
        else //iterador sobre qualquer outro noh
        {
            //usar um segundo iterador para percorrer a lista e parar uma posicao antes do iterador
            pListaNo p;
            for (p = lst->primeiro; p->prox != lst->iterador; p = p->prox)
            {
            }
            //ao sair do for, p esta um noh antes do iterador
            //acertar os ponteiros
            novoNo->prox = lst->iterador;
            p->prox = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }
    }
}

void elimLista(Lista lst)
{

    if (lst->iterador != NULL)
    {

        pListaNo noAserDesalocado;
        if (lst->iterador == lst->primeiro) // se o iterador estiver sobre o primeiro elemento
        {
            if (lst->longitude == 1)
            {

                noAserDesalocado = lst->iterador;
                lst->iterador = NULL;
                lst->primeiro = NULL;
                lst->ultimo = NULL;
                lst->longitude--;
                free(noAserDesalocado);
            }
            else
            {

                noAserDesalocado = lst->iterador;
                lst->iterador = lst->iterador->prox;
                //lst->primeiro = lst->primeiro->prox;
                lst->primeiro = lst->iterador;
                lst->longitude--;
                free(noAserDesalocado);
            }
        }
        else // iterador esta sobre qualquer outro no que nao o primeiro no
        {
            //iterador sobre no intermediario ou o ultimo no
            pListaNo p;
            for (p = lst->primeiro; p->prox != lst->iterador; p = p->prox)
            {
            }
            noAserDesalocado = lst->iterador;
            p->prox = lst->iterador->prox;

            if (lst->iterador == lst->ultimo) // se o iterador estiver sobre o utlimo no
                lst->ultimo = p;

            lst->iterador = lst->iterador->prox;
            free(noAserDesalocado);
            lst->longitude--;
        }
    }
    else
    {
        printf("\n erro: iterador indefinido \n");
    }
}
// 1
int iguaisListas(Lista lst1, Lista lst2)
{

    //verificar se lst1 e lst2 sao vazias
    if (longLista(lst1) == 0 && longLista(lst2) == 0)
        return 1;
    //senao se long de lst1 == long lst2
    if (longLista(lst1) == longLista(lst2))
    {
        //percorrer lst1 e lst2 e comparar noh a noh
        for (primLista(lst1), primLista(lst2); !fimLista(lst1); segLista(lst1), segLista(lst2))
        {
            if (infoLista(lst1) != infoLista(lst2))
                return 0;
        }
        return 1;
    }
    else
    {
        //senao nao sao iguais
        return 0;
    }
}
// 2
int semelhantesListas(Lista lst1, Lista lst2)
{

    //as duas lista estao vazias
    if (longLista(lst1) == 0 && longLista(lst2) == 0)
    {
        return 1;
    }
    else if (longLista(lst1) != longLista(lst2))
    {
        return 0;
    }
    else
    {
        // as duas listas tem o mesmo tamanho
        TipoL elem;

        for (primLista(lst1); !fimLista(lst1); segLista(lst1))
        {

            elem = infoLista(lst1);

            for (primLista(lst2); !fimLista(lst2);)
            {
                if (infoLista(lst2) != elem)
                    segLista(lst2);
                else
                    break;
            }
            if (fimLista(lst2)) //elem nao esta na lista lst2
                return 0;
        }
        return 1;
    }
}
// 3
int subLista(Lista lst1, Lista lst2)
{
    if(longLista(lst2) == 0)
        return 1;
    if(iguaisListas(lst1, lst2) == 1)
        return 1;
    if(longLista(lst2) > longLista(lst1))
        return 0;
    for (primLista(lst1), primLista(lst2); !fimLista(lst2); segLista(lst1))
    {
        if(infoLista(lst2) == infoLista(lst1))
        {
            segLista(lst2);
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
// 4
int contidaLista(Lista lst1, Lista lst2)
{
    // lista 2 esta vazia
    if (longLista(lst2) == 0)
    {
        return 1;
    }
    else if(longLista(lst2) > longLista(lst1))
    {
        return 0;
    }
    else
    {
        primLista(lst2);
        int cont = 0;
        for (primLista(lst1); !fimLista(lst1); segLista(lst1))
        {
            if (infoLista(lst2) == infoLista(lst1))
            {
                cont++;
                segLista(lst2);
            }
        }
        if (cont == longLista(lst2))
        {
            return 1;
        }
        return 0;
    }

}
// 5
int ordenadaLista(Lista lst)
{
    if (longLista(lst) != 0)
    {
        Lista copia = inicLista();
        for (primLista(lst); !fimLista(lst); segLista(lst))
        {
            adicLista(copia, infoLista(lst));
        }
        primLista(copia);
        segLista(copia);

        for (primLista(lst); !fimLista(copia); segLista(lst))
        {
            if (infoLista(lst) > infoLista(copia))
            {
                return 0;
            }
            segLista(copia);
        }
        free(copia);
        return 1;
    }
    return 1;
}
// 6
void adicLista(Lista lst, TipoL elem)
{
    if (longLista(lst) == 0)
    {
        anxLista(lst, elem);
    }
    else
    {
        ultLista(lst);
        anxLista(lst, elem);
    }
}
// 7
void substitueLista(Lista lst, TipoL elem)
{
    lst->iterador->info = elem;
}
// 8
int estaNaLista(Lista lst, TipoL elem)
{
    if (longLista(lst) != 0)
    {
        for (primLista(lst); !fimLista(lst); segLista(lst))
        {
            if (infoLista(lst) == elem)
            {
                return 1;
            }
        }
    }
    return 0;
}
// 9
void exibeLista(Lista lst)
{

    // primLista, segLista, fimLista, infoLista
    for (primLista(lst); !fimLista(lst); lst->iterador = lst->iterador->prox)
    {
        printf("%d ", lst->iterador->info);
    }
}
// 10
void antLista(Lista lst)
{
    int i;
    pListaNo p;
    if (lst->iterador != lst->primeiro)
    {
        for (p = lst->primeiro, i = 1; p->prox != lst->iterador; p = p->prox, i++)
        {}
        posLista(lst, i);
    }
}
// 11
int posIteradorLista( Lista lst)
{
    int i;
    pListaNo p;
    for (p = lst->primeiro, i = 1; p->prox != lst->iterador; p = p->prox, i++)
    {}
    return i+1;
}
// 12
void simplificarLista(Lista lst)
{
    Lista lst2 = inicLista();
    for (primLista(lst); !fimLista(lst); segLista(lst))
    {
        if (!estaNaLista(lst2, infoLista(lst)))
        {
            anxLista(lst2, infoLista(lst));
        }
    }

    for (primLista(lst); !fimLista(lst);)
    {
        elimLista(lst);
    }

    for (primLista(lst2); !fimLista(lst2);)
    {
        anxLista(lst, infoLista(lst2));
        elimLista(lst2);
    }
}
// 13
int numDiferentesLista( Lista lst)
{
    int l = longLista(lst);
    if(l == 0)
    {
        printf("Lista vazia.\n");
        return 0;
    }
    int cont = 0;
    primLista(lst);
    while(l>0)
    {
        if(numOcorrenciasLista(lst, lst->iterador->info) > 1)
        {
            cont++;
            l = l - numOcorrenciasLista(lst, lst->iterador->info);
        }
    }
    return l+cont;
}
// 14
int numOcorrenciasLista( Lista lst, TipoL elem)
{

    int cont = 0;
    pListaNo p = lst->iterador;
    for (primLista(lst); !fimLista(lst); segLista(lst))
    {
        if (infoLista(lst) == elem)
            cont++;
    }
    for(primLista(lst); lst->iterador != p; segLista(lst));//voltar o iterador para lugar que já estava
    return cont;
}
// 15
TipoL maxOcorrenciaLista( Lista lst)
{
    TipoL elemMax;
    int contMax = 0;
    int i;
    for(primLista(lst); !fimLista(lst); segLista(lst))
    {
        i = numOcorrenciasLista(lst, infoLista(lst));
        if(i > contMax)
        {
            contMax = i;
            elemMax = infoLista(lst);
        }
    }
    return elemMax;
}
// 16
int ultOcorrenciaLista( Lista lst, TipoL elem)
{
    if(!estaNaLista(lst, elem))
    {
        printf("O elemento nao esta na lista.\n");
        return 0;
    }
    int n = numOcorrenciasLista(lst, elem);
    int i;
    for(primLista(lst), i=0; i<n; segLista(lst))
    {
        if(infoLista(lst) == elem)
            i++;
    }
    antLista(lst);
    return posIteradorLista(lst);
}
// 17
void eliminarLista( Lista lst, int p1, int p2)
{
    if(longLista(lst) != 0 && p1 >= 1 && p2 <= longLista(lst)+1)
    {
        int i;
        for(i = p1; i <= p2; i++)
        {
            posLista(lst, i);
            elimLista(lst);
        }
    }
    else
    {
        printf("Erro: Posicao nao existe.\n");
    }
}
// 18
void ordenarLista(Lista lst)
{
     Pilha inverter = inicPilha();
     Lista count = inicLista();
     Lista ent = inicLista();
     TipoL aux = 0;
     int i;
     count = copiaLista(lst);
     ent = copiaLista(lst);
     simplificarLista(ent);
        for(primLista(ent);!fimLista(ent);segLista(ent))
        {
            TipoL maior = maiorElemento(ent);
            for(i = 0; i < numOcorrenciasLista(count,aux);i++)
            {
                push(inverter,maior);
            }
            elimLista(ent);

        }
        while(!vaziaPilha(inverter))
            anxLista(lst,pop(inverter));


}
//19
void diferencaLista(Lista lst1, Lista lst2)
{
    for(primLista(lst1);!fimLista(lst1);segLista(lst1))
    {
        if(estaNaLista(lst2,infoLista(lst1)))
        {
            elimLista(lst1);
        }
    }
}


/// Funções de Pilha

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

void destruirPilha(Pilha p)
{

    free(p);
}

TipoP infoPilha(Pilha p)
{
    if(p->topo > -1) // pilha cheia
        return p->info[p->topo];
    else
    {
        printf("\n pilha vazia \n");
        return (TipoP)NULL;
    }
}

void printPilha(Pilha p)
{

    if(p->topo == -1)
    {
        printf("\n pilha vazia \n");
    }
    else
    {

        int i;
        for( i = p->topo; i >= 0; i--)
            printf(" %d\n ", p->info[i]);
    }
    printf("\n");
}
// 1
void invLista(Lista lst)
{
    Pilha p = inicPilha();
    for(primLista(lst); !fimLista(lst); )
    {
        push(p, infoLista(lst));
        elimLista(lst);
    }
    while(!vaziaPilha(p))
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
    while(!vaziaPilha(p))
    {
        insLista(lst, pop(p));
    }
    for(primLista(lst); !fimLista(lst); )
    {
        push(p, infoLista(lst));
        push(copia, infoLista(lst));
        elimLista(lst);
    }
    return copia;
}
// 3
void invPilha( Pilha p)
{
    Lista lst = inicLista();
    while(!vaziaPilha(p))
    {
        anxLista(lst, pop(p));
    }
    for(primLista(lst); !fimLista(lst); )
    {
        push(p, infoLista(lst));
        elimLista(lst);
    }
}
// 4
int iguaisPilhas( Pilha p1, Pilha p2)
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
int avaliarExpressao(ListaExp lstExp) {
    if (lstExp->longitude == 0) {
        printf("avaliarExpressao: Lista vazia.");
        return -1;
    }

    Pilha pAux = inicPilha();
    int sum = 0;

    for(primListaExp(lstExp); !fimListaExp(lstExp); segListaExp(lstExp)) {
        if( isdigit(lstExp->iterador->info[0]) ) {
            push(pAux, atoi(lstExp->iterador->info));
        } else {
            if (strcmp(lstExp->iterador->info, "+") == 0) {
                while(!vaziaPilha(pAux)) {
                    sum = sum + pop(pAux);
                }
            }
            if (strcmp(lstExp->iterador->info, "*") == 0) {
                while(!vaziaPilha(pAux)) {
                    if (sum == 0) {
                        sum = 1;
                    }
                    sum = sum * pop(pAux);
                }
           }
        }
    }
    return sum;
}
// 6
void imprimePilha(Pilha p)
{
    Pilha copia = inicPilha();
    copia = copiarPilha(p);
    while (!vaziaPilha(copia))
    {
        printf("%i\n", pop(copia));
    }
}
// 7
void fundoPilha( Pilha p, TipoP elem)
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
void elimTodosPilha( Pilha p, TipoP elem)
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
int somaPilha( Pilha p)
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
int palindromePilha( Pilha p)
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

/// Funções Fila

Fila inicFila( void )
{
    Fila f = (Fila)malloc(sizeof(Tfila));
    f->primeiro = -1; // Fila vazia
    f->ultimo = -1;   // Fila vazia

    return f;
}

void adicFila( Fila f, TipoF elem)
{
    // Se a fila não está cheia, é passado o valor 0 como inicial
    if (f->primeiro == -1)
    {
        f->info[0] = elem;
        f->primeiro = 0;
        f->ultimo = 0;
    }
    else if ((f->ultimo + 1) % MAX == f->primeiro)
    {
        printf("\n Infelizmente a fila já está cheia.");
    }
    else
    {
        f->ultimo = (f->ultimo + 1) % MAX; // Descobre a nova posição do último elemento
        f->info[f->ultimo] = elem;
    }
}

TipoF elimFila( Fila f)
{
    TipoF primeiroElem;
    if (f->primeiro == -1)
    {
        printf("\n A fila está vazia.");
        return (TipoF)NULL;
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
        printf("\n A fila está vazia.");
        return (TipoF)NULL;
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
        printf("\n A fila está vazia.");
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
// 1
Fila copiarFila( Fila f )
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

    while (!vaziaFila(f2))
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
void invFila( Fila f)
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
int existeElemento( Fila f, TipoF elem)
{
    Fila copia = inicFila();
    copia = copiarFila(f);

    while(!vaziaFila(copia))
    {
        if(elimFila(copia) == elem)
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
    if(longFila(f1) == longFila(f2))
    {
        Fila copia1 = inicFila();
        copia1 = copiarFila(f1);

        Fila copia2 = inicFila();
        copia2 = copiarFila(f2);

        while(!vaziaFila(copia1))
        {
            if(elimFila(copia1) != elimFila(copia2))
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
void adicFilaPos( Fila f, TipoF elem, int pos)
{
    if(pos < 0 || pos > longFila(f) + 1)
    {
        printf("Posicao invalida\n");
    }
    else if(longFila(f) < pos)
    {
        adicFila(f, elem);
    }
    else
    {
        Fila copia = inicFila();
        copia = copiarFila(f);
        int cont = 0;

        while(!vaziaFila(copia))
        {
            if(cont == pos)
            {
                adicFila(f, elem);
            }
            else
            {
                adicFila(f, elimFila(copia));
                cont++;
            }
        }

        while(!vaziaFila(copia))
        {
            adicFila(f, elimFila(copia));
        }

        destruirFila(copia);
    }
}
// 8
void elimElemento( Fila f, TipoF elem)
{
    if(!vaziaFila(f))
    {
        Fila copia = inicFila();

        while(!vaziaFila(f))
        {
            if(infoFila(f) != elem)
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
void partirFila( Fila f, Fila f1, Fila f2, TipoF elem)
{
    while(!vaziaFila(f))
    {
        if(infoFila(f) > elem)
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
void primeiroDaFila( Fila f, TipoF elem)
{
    Fila copia = inicFila();
    adicFila(copia, elem);
    while(!vaziaFila(f))
    {
        adicFila(copia, elimFila(f));
    }
    while(!vaziaFila(copia))
    {
        adicFila(f, elimFila(copia));
    }
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
            printf("\n Fila 1 tem %d pessoa(s).\n", cont1);
        }
        else if (fila == 1 && cont2 < 10)
        {
            adicFila(f2, i);
            cont2++;
            printf("\n Fila 2 tem %d pessoa(s).\n", cont2);
        }
        else if (fila == 2 && cont3 < 10)
        {
            adicFila(f3, i);
            cont3++;
            printf("\n Fila 3 tem %d pessoa(s).\n", cont3);
        }
        else
        {
            printf("\n Todas as filas estao cheias.\n");
        }

        if (i % 3 == 0)
        {
            fila = rand() % 3;
            if (fila == 0 && !vaziaFila(f1))
            {
                elimFila(f1);
                cont1--;
                printf("\n Atendimento fila 1.\n");
            }
            else if (fila == 1 && !vaziaFila(f2))
            {
                elimFila(f2);
                cont2--;
                printf("\n Atendimento fila 2\n");
            }
            else if (fila == 2 && !vaziaFila(f3))
            {
                elimFila(f3);
                cont3--;
                printf("\n Atendimento fila 3\n");
            }
        }
    }
    printf("\n Fila 1 = %d, Fila 2 = %d, Fila 3 = %d\n", cont1, cont2, cont3);
}

#endif // FUNCOES_C_INCLUDED
