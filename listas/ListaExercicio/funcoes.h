#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#define MAX 100

typedef int TipoL;
typedef int TipoP;
typedef int TipoF;

typedef struct ListaNo
{
  TipoL info;
  struct ListaNo *prox;
} * pListaNo;

typedef struct TLista
{
  pListaNo primeiro, ultimo, iterador;
  int longitude;
} * Lista;

typedef struct{
    int topo;
    TipoP info[MAX];
} Tpilha, *Pilha;

typedef struct{
    TipoF info[MAX];
    int primeiro;
    int ultimo;
} Tfila, *Fila;

/// Fun��es b�sicas de Lista

Lista inicLista(); /// Cria e retorna uma lista vazia
void anxLista( Lista lst, TipoL elem); /// Adiciona um elemento depois do iterador
void insLista ( Lista lst, TipoL elem); /// Adiciona um elemento antes do iterador
void elimLista( Lista lst); /// Elimina o elemento que est� sob o iterador
void primLista(Lista lst); /// Coloca o iterador sobre o primeiro elemento da lista
void ultLista(Lista lst); /// Coloca o iterador sobre o �tlimo elemento da lista
void segLista( Lista lst ); /// Avan�a o iterador uma posi��o
void posLista( Lista lst, int pos); /// Coloca o iterador sobre a posi��o pos
TipoL infoLista( Lista lst); /// Retorna o elemento sob o iterador
int longLista( Lista lst); /// Retorna a quantidade de elementos da lista
int fimLista( Lista lst); /// Retorna verdadeiro se o iterador estiver indefinido
int contaElmento(Lista lst, TipoL elem);

/// Exercicios Lista

///1) Verificar se duas listas t�m os mesmos elementos nas mesmas posi��es
int iguaisListas(Lista lst1, Lista lst2);
///2) Verificar se duas listas t�m os mesmos elementos
int semelhantesListas(Lista lst1, Lista lst2);
///3) Verificar se a lista lst2 � uma sublista de lst1
int subLista(Lista lst1, Lista lst2);
///4) Verificar se uma lista lst2 est� contida numa lista lst1
int contidaLista(Lista lst1, Lista lst2);
///5) Verificar se uma lista lst est� ordenada
int ordenadaLista(Lista lst1 );
///6) Adiciona o elemento elem no final de lst
void adicLista( Lista lst, TipoL elem);
///7) Substitue o conte�do atual do iterador pelo elemento elem
void substitueLista( Lista lst, TipoL elem);
///8) Indica se o elemento elem aparece na lista
int estaNaLista( Lista lst, TipoL elem);
///9) Exibe todos os elementos da lista, utilizando a opera��o posLista para avan�ar
void exibeLista( Lista lst);
///10) Coloca o iterador na posi��o anterior � atual
void antLista( Lista lst);
///11) Retorna a posi��o do iterador na lista
int posIteradorLista( Lista lst);
///12) Deixar na lista somente uma ocorr�ncia de cada um dos elementos
void simplificarLista( Lista lst);
///13) Retorna o n�mero total de elementos diferentes em lst
int numDiferentesLista( Lista lst);
///14) Computa o n�mero de vezes que o elemento elem aparece na lista
int numOcorrenciasLista( Lista lst, TipoL elem);
///15) Retorna o elemento que aparece mais vezes na lista n�o vazia lst
TipoL maxOcorrenciaLista( Lista lst);
///16) Retorna a posi��o da �ltima ocorr�ncia do elemento elem. Se n�o ocorre, retorna zero
int ultOcorrenciaLista( Lista lst, TipoL elem);
///17) Elimina da lista lst todos os elementos compreendidos entre a posi��o p1 e p2, inclusive
void eliminarLista( Lista lst, int p1, int p2);

/// Fu��es b�sicas de Pilha

Pilha inicPilha( void ); /// Cria e retorna uma pilha vazia
void push( Pilha p, TipoP elem); /// Adiciona(empilha) um elemento no topo da pilha
TipoP pop( Pilha p); /// Elimina(desempilha) o elemento que est� no topo da pilha e retorna este elemento
TipoP infoPilha(Pilha p); /// Retorna o elemento que est� no topo da pilha sem remov�-lo da pilha
int vaziaPilha(Pilha p); /// Retorna verdadeiro se a pilha est� vazia e falso caso contr�rio
void destruirPilha(Pilha p); /// Destr�i a pilha p, desalocando toda mem�ria ocupada

/// Exerc�cios Pilha

/// 1) Inverter uma lista utilizando como apoio uma pilha
void invLista(Lista lst);
/// 2) Fazer uma c�pia de uma pilha, usando como apoio uma lista
Pilha copiarPilha( Pilha p );
/// 3) Inverter o conte�do de uma pilha
void invPilha( Pilha p);
/// 4) Dizer se duas pilhas s�o iguais sem destruir seu conte�do
int iguaisPilhas( Pilha p1, Pilha p2);
/// 5) Avaliar uma express�o aritm�tica na nota��o posfixa
int avaliarExpressao( Lista lstExp);
/// 6) Imprimir o conte�do de uma pilha, sem alterar seu conte�do( a pilha deve ser restaurada)
void imprimePilha(Pilha p);
/// 7) Colocar no fundo da pilha o elemento elem
void fundoPilha( Pilha p, TipoP elem);
/// 8) Computar e retornar o n�mero de elementos da pilha, sem alterar seu conte�do( a pilha deve ser restaurada)
int longPilha( Pilha p);
/// 9) Eliminar da pilha todas as ocorr�ncias do elemento elem
void elimTodosPilha( Pilha p, TipoP elem);
/// 10) Somar todos os elementos da pilha e retorna seu resultado
int somaPilha( Pilha p);
/// 11) Retornar true(1) se o conte�do da pilha � um pal�ndrome e false(0) caso contr�rio
int palindromePilha( Pilha p);

///Fu��es b�sicas de Fila

Fila inicFila( void ); /// Cria e retorna uma fila vazia
void adicFila( Fila f, TipoF elem);  /// Adiciona um elemento no final da fila
TipoF elimFila( Fila f); /// Elimina e retorna o primeiro elemento da fila
TipoF infoFila(Fila f); /// Retorna o primeiro elemento da fila sem remover
int vaziaFila(Fila f); /// Retorna verdadeiro se a fila est� vazia e falso caso contr�rio
void destruirFila(Fila f); /// Destr�i a fila f, desalocando toda mem�ria ocupada
void printFila(Fila f); /// Imprime a fila

/// Exerc�cios Fila

/// 1) Fazer uma c�pia de uma Fila, usando como apoio uma lista
Fila copiarFila( Fila f );
/// 2) Computar e retornar o n�mero de elementos da fila, sem alterar seu conte�do
int longFila(Fila f);
/// 3) Concatenar duas filas, deixando o resultado na primeira(f1)
void concatFilas(Fila f1, Fila f2);
/// 4) Inverter os elementos da fila
void invFila( Fila f);
/// 5) Retorna true(1) se o elemento elem est� presente na fila e false(0) caso contr�rio
int existeElemento( Fila f, TipoF elem);
/// 6) Retorna true(1) se as filas f1 e f2 t�m os mesmos elementos, na mesma ordem, e false(0) caso contr�rio
int iguaisFilas(Fila f1, Fila f2);
/// 7) Adiciona o elemento elem na posi��o pos da fila, deslocando todos os elementos seguintes uma posi��o para tr�s
void adicFilaPos( Fila f, TipoF elem, int pos);
/// 8) Remove da fila o elemento elem
void elimElemento( Fila f, TipoF elem);
/// 9) Deixa na fila f1 todos os elementos da fila f, menores que elem e na fila f2 todos os elementos maiores que elem
void partirFila( Fila f, Fila f1, Fila f2, TipoF elem);
/// 10) Coloca o elemento elem na primeira posi��o da fila
void primeiroDaFila( Fila f, TipoF elem);
/// 11) e 12) exerc�cios para implementar




#endif // FUNCOES_H_INCLUDED
