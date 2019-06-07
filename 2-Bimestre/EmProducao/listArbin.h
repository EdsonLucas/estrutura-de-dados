typedef int TipoA;

typedef struct NoArbin{
    TipoA info;
    struct NoArbin *esq, *dir;
} NoArbin, *Arbin ;

typedef struct{
    NoArbin info[MAX];
    int primeiro;
    int ultimo;
} Tfila, *Fila;

Arbin inicArbin( void );
Arbin esqArbin( Arbin a);
Arbin dirArbin( Arbin a);
TipoA raizArbin( Arbin a);
void destruirArbin( Arbin a);
int vaziaArbin(Arbin a);


1) int pesoArbin( Arbin a);
2) int estaArbin( Arbin a, TipoA elem);
3) int numFolhas( Arbin a);
4) int numOcorrencias( Arbin a);
5) int existeCaminho( Arbin a, TipoA e1, TipoA e2);
6) int contNivel( Arbin a, int nivel);
7) int semelhantesArbin( Arbin a1, Arbin a2);
8) Desenhe duas árvores isomorfas e semelhantes, que não sejam iguais.
9) Determine os seguintes valores para uma árvore binária:
a) Número mínimo e máximo de elementos de uma árvore completa de N níveis
b) Número mínimo de níveis de uma árvore binária com peso P.
c) Número máximo de folhas de uma árvore binária com N níveis.
d) Número mínimo e máximo de elementos presentes no nível N de uma Arbin completa de altura H.
e) Número de elementos de uma Arbin cheia de N níveis
10) int alturaArbin( Arbin a);
11) int iguais(Arbin a1, Arbin a2);
12) int isomorfos(Arbin a1, Arbin a2);
13) int completaArbin(Arbin a);
14) int cheiaArbin(Arbin a);
15) Lista buscaCaminhoArbin(Arbin a, TipoA elem);
16) int ocorreArbin(Arbin a1, Arbin a2);
17) Reconstruir a Arbin com os seguintes caminhamentos:
a)
pre-ordem: 10-20-30-50-60-40-70-80-90
in-ordem: 50-30-60-20-80-70-90-40-10
b)
pre-ordem: 60-30-80-70-40-20-50-90-10
in-ordem: 30-60-20-80-70-40-10-90-50
18) int nivelArbin(Arbin a1, TipoA elem);
19) int maiorElementoArbin(Arbin a);
