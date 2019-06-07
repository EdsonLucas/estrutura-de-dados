

Arbin inicArbin(){
    return NULL;
}

Arbin esqArbin(Arbin a){
    return a->esq;
}

Arbin dirArbin(Arbin a){
    return a->dir;
}

TipoA raizArbin(Arbin a){
    return a->info;
}

int vaziaArbin(Arbin a){
    if(a == NULL)
        return 1;
    return 0;
}

int destruirArbin(Arbin a){
    if(a != NULL)
    {
        destruirArbin(a->esq);
        destruirArbin(a->dir);
        free(a);
    }
}

int pesoArbin(Arbin a){
    if(a == NULL)
        return 0;
    return (1 + pesoArbin(a->esq) + pesoArbin(a->dir));
}

int estaArbin(Arbin a, TipoA elem){
    if(a == NULL)
        return 0;
    if(raizArbin(a) == elem)
        return 1;
    return (estaArbin(a->esq, elem) || estaArbin(a->dir, elem));
}

int numFolhas(Arbin a){
    if(a == NULL)
        return 0;
    else if (!vaziaArbin(a->esq) && !vaziaArbin(a->dir))
        return (numFolhas(a->esq) + numFolhas(a->dir));
    return 1;
}

int numOcorrencias( Arbin a, TipoA elem){
    if(a == NULL)
        return 0;
    if(raizArbin(a) == elem)
        return 1;
    return (numOcorrencias(a->esq, elem) + numOcorrencias(a->dir, elem));
}

int existeCaminho(Arbin a, TipoA e1, TipoA e2){
    if(a == NULL)
        return 0;
    if (raizArbin(a) == e1)
        return estaArbin(a, e2);
    if(e1 < raizArbin(a))
        return existeCaminho(a->esq, e1, e2);
    return existeCaminho(a->dir, e1, e2);
}

int contNivel(Arbin a, int nivel){
    if(a == NULL)
        return 0;
    if(nivel == 0)
        return 1;
    return (contNivel(a->esq, nivel-1) + contNivel(a->dir, nivel-1));
}

int semelhantesArbin( Arbin a1, Arbin a2){
    if(pesoArbin(a1) == pesoArbin(a2))
        return 0;
    Fila f;
    Arbin arb;
    if(!vaziaArbin(a1))
    {
        f = inicFila();
        adicFila(f, a1);
        while(!vaziaFila(f)){
            arb = infoFila(f);
            elimFila(f);
            if(!vaziaArbin(arb)){
                if(!estaArbin(a2, raizArbin(a1)))
                    return 0;
                adicFila(f, esqArbin(a1));
                adicFila(f, dirArbin(a1));
            }
        }
    }
    else{
        if(vaziaArbin(a2))
            return 1;
        return 0;
    }
}

int alturaArbin( Arbin a)

int iguaisArbin(Arbin a, Arbin b){
    if(vaziaArbin(a) && vaziaArbin(b))
        return 1;
    if(raizArbin(a) == raizArbin(a))
        return (igualArbin(a->esq, b->esq) && igualArbin(a->dir, b->dir));
    else 
        return 0; 
}

void nivelArbin(Arbin a){
    Fila f;
    Arbin arb;
    if(!vaziaArbin(a)){
        f = inicFila();
        adicFila(f, a);
        while(!vaziaFila(f)){
            arb = infoFila(f);
            elimFila(f);
            if(!vazioArbin(arb)){
                visitar(raizArbin(arb));
                adicFila(f, esqArbin(arb));
                adicFila(f, dirArbin(arb));
            }
        }
    }
}

/* fila */

Fila inicFila( void )
{
    Fila f = (Fila)malloc(sizeof(Tfila));
    f->primeiro = -1; // Fila vazia
    f->ultimo = -1;   // Fila vazia

    return f;
}

void adicFila( Fila f, Arbin a)
{
    // Se a fila não está cheia, é passado o valor 0 como inicial
    if (f->primeiro == -1)
    {
        f->info[0] = a;
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
        f->info[f->ultimo] = a;
    }
}

Arbin elimFila( Fila f)
{
    Arbin a;
    if (f->primeiro == -1)
    {
        printf("\n A fila está vazia.");
        return (Arbin)NULL;
    }
    else if (f->primeiro == f->ultimo)
    {
        a = f->info[f->primeiro];
        f->primeiro = -1; // Fila vazia
        f->ultimo = -1;   // Fila vazia
        return a;
    }
    else
    {
        a = f->info[f->primeiro];
        f->primeiro = (f->primeiro + 1) % MAX;
        return a;
    }
}

Arbin infoFila(Fila f)
{
    if (f->primeiro == -1)
    {
        printf("\n A fila está vazia.");
        return (Arbin)NULL;
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
        Arbin elem;
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

