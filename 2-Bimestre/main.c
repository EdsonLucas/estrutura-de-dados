#include <stdio.h>
#include <stdlib.h>

#ifndef _TAD_Arbin_H
    #include "tadArbin.h"
#endif // _TAD_Arbin_H


int buscaNaArbin(Arbin a, TipoA elem){

    if(vaziaArbin(a))
        return 0;
    else if(raizArbin(a) == elem)
        return 1;
    else{
        return (buscaNaArbin(esqArbin(a), elem) || buscaNaArbin(dirArbin(a), elem));
    }

}

int buscaNaArbinBusca(Arbin a, TipoA elem){

    if(vaziaArbin(a))
        return 0;
    else if(raizArbin(a) == elem)
        return 1;
    else{
        if(elem < raizArbin(a))
            return buscaNaArbinBusca(esqArbin(a), elem);
        else
            return buscaNaArbinBusca(dirArbin(a), elem);
    }

}


//---------------------------------------------


int main()
{
    printf("Hello world!\n");

    Arbin arb = inicArbin();

    arb = insArbinBusca(arb, 100);
    arb = insArbinBusca(arb, 50);
    arb = insArbinBusca(arb, 200);
    arb = insArbinBusca(arb, 40);
    arb = insArbinBusca(arb, 80);
    arb = insArbinBusca(arb, 150);
    arb = insArbinBusca(arb, 300);

    preOrdemArbin(arb);

    if(buscaNaArbinBusca(arb, 300))
        printf("\n\n 300 esta presente \n");
    else
        printf("\n\n 300 nao esta presente \n");


    printf("peso de arb = %d\n", pesoArbin(arb));

    printf("\n ====================================== \n\n\n\n");

    niveisArbin(arb);
    //preOrdemArbin(arb);

	if(existeCaminhoABB(arb, 100,40))
         printf("existe caminho do 100 para o 40 \n");
    else
        printf("Nao existe caminho \n");

    if(existeCaminhoABB(arb, 100,10))
         printf("existe caminho do 100 para o 10 \n");
    else
        printf("Nao existe caminho do 100 para o 10\n");


    int numElemPorNivel;
    numElemPorNivel = contaNivel(arb, 0);
    printf("\numElemPorNivel do nivel 0 = %d\n", numElemPorNivel);

    numElemPorNivel = contaNivel(arb, 1);
    printf("\numElemPorNivel do nivel 1 = %d\n", numElemPorNivel);

    numElemPorNivel = contaNivel(arb, 2);
    printf("\numElemPorNivel do nivel 2 = %d\n", numElemPorNivel);


    int totalFolhas = numFolhas(arb);
    printf("total de folhas = %d \n", totalFolhas);

    int totalOcorrenciasDo300 = numOcorrencias(arb,300);
    printf("total de ocorrencias do 300 = %d \n", totalOcorrenciasDo300);

    return 0;
}
