#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista inicLista()
{
    Lista lst;
    // Aloca espaco na memoria atribuindo todos os valores a zero
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
    // Poe o iterador no ultimo elemento da lista
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
        printf("\n Erro: Iterador indefindio \n");
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
        printf("\n Erro: Iterador indefinido \n");
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

    // Tratamento de erro
    if (lst->iterador == NULL && lst->longitude > 0)
    {
        printf("\n Erro: Iterador indefinido e lista cheia \n");
    }
    else
    {

        // Alocar memoria para o novoNo a ser adicionado
        pListaNo novoNo = (pListaNo)malloc(sizeof(struct ListaNo));
        novoNo->info = elem; // Atribuir o elemento a ser armazenado
        novoNo->prox = NULL; // Atribuir NULL para deixar o novoNo preparado

        if (lst->longitude == 0) // Lista vazia
        {
            // Apontar para o novoNo
            lst->primeiro = novoNo;
            lst->ultimo = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }
        else if (lst->iterador == lst->ultimo) // Iterador sobre o ultimo elemento
        {
            // Por no campo prox do ultimo no o endereco do novoNo
            lst->iterador->prox = novoNo; //lst->ultimo->prox = novoNo;
            // Atualizar o campo ultimo com o endereco do novoNo
            lst->ultimo = novoNo;
            // Atualizar o campo iterador com o endereco do novoNo
            lst->iterador = novoNo;
            // Incrementar a quantidade de nos
            lst->longitude++;
        }
        else // Iterador sobre um noh intermediario
        {
            // O prox do novoNo aponta para o proximo Noh depois do iterador
            // Fazer o prox do iterador apontar para o novoNo
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

        // Alocar memoria para o novoNo a ser adicionado
        pListaNo novoNo = (pListaNo)malloc(sizeof(struct ListaNo));
        novoNo->info = elem; // Atribuir o elemento a ser armazenado
        novoNo->prox = NULL; // Atribuir NULL para deixar o novoNo preparado

        if (lst->longitude == 0) // Lista vazia
        {
            // Apontar para o novoNo
            lst->primeiro = novoNo;
            lst->ultimo = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }
        else if (lst->iterador == lst->primeiro) // Iterador sobre o primeiro elemento
        {
            // novoNo->prox = lst->iterador;
            novoNo->prox = lst->primeiro;
            lst->primeiro = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }
        else // Iterador sobre qualquer outro noh
        {
            // Usar um segundo iterador para percorrer a lista e parar uma posicao antes do iterador
            pListaNo p;
            for (p = lst->primeiro; p->prox != lst->iterador; p = p->prox)
            {
            }
            // Ao sair do for, p esta um noh antes do iterador
            // Acertar os ponteiros
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
        if (lst->iterador == lst->primeiro) // Se o iterador estiver sobre o primeiro elemento
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
                // lst->primeiro = lst->primeiro->prox;
                lst->primeiro = lst->iterador;
                lst->longitude--;
                free(noAserDesalocado);
            }
        }
        else // Iterador esta sobre qualquer outro No que nao o primeiro No
        {
            // Iterador sobre no intermediario ou o ultimo No
            pListaNo p;
            for (p = lst->primeiro; p->prox != lst->iterador; p = p->prox)
            {
            }
            noAserDesalocado = lst->iterador;
            p->prox = lst->iterador->prox;

            if (lst->iterador == lst->ultimo) // Se o iterador estiver sobre o utlimo No
                lst->ultimo = p;

            lst->iterador = lst->iterador->prox;
            free(noAserDesalocado);
            lst->longitude--;
        }
    }
    else
    {
        printf("\n Erro: Iterador indefinido \n");
    }
}

// 1
int iguaisListas(Lista lst1, Lista lst2)
{

    // Verificar se lst1 e lst2 sao vazias
    if (longLista(lst1) == 0 && longLista(lst2) == 0)
        return 1;
    // Senao se long de lst1 == long lst2
    if (longLista(lst1) == longLista(lst2))
    {
        // Percorrer lst1 e lst2 e comparar No a No
        for (primLista(lst1), primLista(lst2); !fimLista(lst1); segLista(lst1), segLista(lst2))
        {
            if (infoLista(lst1) != infoLista(lst2))
                return 0;
        }
        return 1;
    }
    else
    {
        // Senao nao sao iguais
        return 0;
    }
}

// 2
int semelhantesListas(Lista lst1, Lista lst2)
{

    // As duas lista estao vazias
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
        // As duas listas tem o mesmo tamanho
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
            if (fimLista(lst2)) // elem nao esta na lista lst2
                return 0;
        }
        return 1;
    }
}

// 3
int subLista(Lista lst1, Lista lst2)
{
    if (longLista(lst2) == 0)
        return 1;
    if (iguaisListas(lst1, lst2) == 1)
        return 1;
    if (longLista(lst2) > longLista(lst1))
        return 0;
    for (primLista(lst1), primLista(lst2); !fimLista(lst2); segLista(lst1))
    {
        if (infoLista(lst2) == infoLista(lst1))
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
    // Lista 2 esta vazia
    if (longLista(lst2) == 0)
    {
        return 1;
    }
    else if (longLista(lst2) > longLista(lst1))
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
        Lista aux = inicLista();
        for (primLista(lst); !fimLista(lst); segLista(lst))
        {
            adicLista(aux, infoLista(lst));
        }
        primLista(aux);
        for (primLista(lst); !fimLista(lst); segLista(lst))
        {
            if (infoLista(lst) >= infoLista(aux))
            {
                segLista(aux);
            }
            else
            {
                free(aux);
                return 0;
            }
        }
        free(aux);
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
        {
        }
        posLista(lst, i);
    }
}

// 11
int posIteradorLista(Lista lst)
{
    int i;
    pListaNo p;
    for (p = lst->primeiro, i = 1; p->prox != lst->iterador; p = p->prox, i++)
    {
    }
    return i + 1;
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
int numDiferentesLista(Lista lst)
{
    int l = longLista(lst);
    if (l == 0)
    {
        printf("Lista vazia.\n");
        return 0;
    }
    int cont = 0;
    primLista(lst);
    while (l > 0)
    {
        if (numOcorrenciasLista(lst, lst->iterador->info) > 1)
        {
            cont++;
            l = l - numOcorrenciasLista(lst, lst->iterador->info);
        }
    }
    return l + cont;
}

// 14
int numOcorrenciasLista(Lista lst, TipoL elem)
{

    int cont = 0;
    pListaNo p = lst->iterador;
    for (primLista(lst); !fimLista(lst); segLista(lst))
    {
        if (infoLista(lst) == elem)
            cont++;
    }
    for (primLista(lst); lst->iterador != p; segLista(lst))
        ; // Voltar o iterador para lugar que ja estava
    return cont;
}

// 15
TipoL maxOcorrenciaLista(Lista lst)
{
    TipoL elemMax;
    int contMax = 0;
    int i;
    for (primLista(lst); !fimLista(lst); segLista(lst))
    {
        i = numOcorrenciasLista(lst, infoLista(lst));
        if (i > contMax)
        {
            contMax = i;
            elemMax = infoLista(lst);
        }
    }
    return elemMax;
}

// 16
int ultOcorrenciaLista(Lista lst, TipoL elem)
{
    if (!estaNaLista(lst, elem))
    {
        printf("O elemento nao esta na lista.\n");
        return 0;
    }
    int n = numOcorrenciasLista(lst, elem);
    int i;
    for (primLista(lst), i = 0; i < n; segLista(lst))
    {
        if (infoLista(lst) == elem)
            i++;
    }
    antLista(lst);
    return posIteradorLista(lst);
}

// 17
void eliminarLista(Lista lst, int p1, int p2)
{
    if (longLista(lst) != 0 && p1 >= 1 && p2 <= longLista(lst) + 1)
    {
        int i;
        for (i = p1; i <= p2; i++)
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
