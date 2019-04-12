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

/// Funções básicas de Lista

Lista inicLista(); /// Cria e retorna uma lista vazia
void anxLista( Lista lst, TipoL elem); /// Adiciona um elemento depois do iterador
void insLista ( Lista lst, TipoL elem); /// Adiciona um elemento antes do iterador
void elimLista( Lista lst); /// Elimina o elemento que está sob o iterador
void primLista(Lista lst); /// Coloca o iterador sobre o primeiro elemento da lista
void ultLista(Lista lst); /// Coloca o iterador sobre o útlimo elemento da lista
void segLista( Lista lst ); /// Avança o iterador uma posição
void posLista( Lista lst, int pos); /// Coloca o iterador sobre a posição pos
TipoL infoLista( Lista lst); /// Retorna o elemento sob o iterador
int longLista( Lista lst); /// Retorna a quantidade de elementos da lista
int fimLista( Lista lst); /// Retorna verdadeiro se o iterador estiver indefinido
int contaElmento(Lista lst, TipoL elem);

/// Exercicios Lista

/// 1) Verificar se duas listas têm os mesmos elementos nas mesmas posições
int iguaisListas(Lista lst1, Lista lst2);
/// 2) Verificar se duas listas têm os mesmos elementos
int semelhantesListas(Lista lst1, Lista lst2);
/// 3) Verificar se a lista lst2 é uma sublista de lst1
int subLista(Lista lst1, Lista lst2);
/// 4) Verificar se uma lista lst2 está contida numa lista lst1
int contidaLista(Lista lst1, Lista lst2);
/// 5) Verificar se uma lista lst está ordenada
int ordenadaLista(Lista lst1 );
/// 6) Adiciona o elemento elem no final de lst
void adicLista( Lista lst, TipoL elem);
/// 7) Substitue o conteúdo atual do iterador pelo elemento elem
void substitueLista( Lista lst, TipoL elem);
/// 8) Indica se o elemento elem aparece na lista
int estaNaLista( Lista lst, TipoL elem);
/// 9) Exibe todos os elementos da lista, utilizando a operação posLista para avançar
void exibeLista( Lista lst);
/// 10) Coloca o iterador na posição anterior à atual
void antLista( Lista lst);
/// 11) Retorna a posição do iterador na lista
int posIteradorLista( Lista lst);
/// 12) Deixar na lista somente uma ocorrência de cada um dos elementos
void simplificarLista( Lista lst);
/// 13) Retorna o número total de elementos diferentes em lst
int numDiferentesLista( Lista lst);
/// 14) Computa o número de vezes que o elemento elem aparece na lista
int numOcorrenciasLista( Lista lst, TipoL elem);
/// 15) Retorna o elemento que aparece mais vezes na lista não vazia lst
TipoL maxOcorrenciaLista( Lista lst);
/// 16) Retorna a posição da última ocorrência do elemento elem. Se não ocorre, retorna zero
int ultOcorrenciaLista( Lista lst, TipoL elem);
/// 17) Elimina da lista lst todos os elementos compreendidos entre a posição p1 e p2, inclusive
void eliminarLista( Lista lst, int p1, int p2);
/// 18) Ordena em ordem crescente a lista lst
void ordenarLista(Lista lst);
/// 19) Elimina da lista lst1 todos os elementos que aparecem na lista lst2
void diferencaLista( Lista lst1, Lista lst2);

/// Fuções básicas de Pilha

Pilha inicPilha( void ); /// Cria e retorna uma pilha vazia
void push( Pilha p, TipoP elem); /// Adiciona(empilha) um elemento no topo da pilha
TipoP pop( Pilha p); /// Elimina(desempilha) o elemento que está no topo da pilha e retorna este elemento
TipoP infoPilha(Pilha p); /// Retorna o elemento que está no topo da pilha sem removê-lo da pilha
int vaziaPilha(Pilha p); /// Retorna verdadeiro se a pilha está vazia e falso caso contrário
void destruirPilha(Pilha p); /// Destrói a pilha p, desalocando toda memória ocupada

/// Exercícios Pilha

/// 1) Inverter uma lista utilizando como apoio uma pilha
void invLista(Lista lst);
/// 2) Fazer uma cópia de uma pilha, usando como apoio uma lista
Pilha copiarPilha( Pilha p );
/// 3) Inverter o conteúdo de uma pilha
void invPilha( Pilha p);
/// 4) Dizer se duas pilhas são iguais sem destruir seu conteúdo
int iguaisPilhas( Pilha p1, Pilha p2);
/// 5) Avaliar uma expressão aritmética na notação posfixa
int avaliarExpressao( Lista lstExp);
/// 6) Imprimir o conteúdo de uma pilha, sem alterar seu conteúdo( a pilha deve ser restaurada)
void imprimePilha(Pilha p);
/// 7) Colocar no fundo da pilha o elemento elem
void fundoPilha( Pilha p, TipoP elem);
/// 8) Computar e retornar o número de elementos da pilha, sem alterar seu conteúdo( a pilha deve ser restaurada)
int longPilha( Pilha p);
/// 9) Eliminar da pilha todas as ocorrências do elemento elem
void elimTodosPilha( Pilha p, TipoP elem);
/// 10) Somar todos os elementos da pilha e retorna seu resultado
int somaPilha( Pilha p);
/// 11) Retornar true(1) se o conteúdo da pilha é um palíndrome e false(0) caso contrário
int palindromePilha( Pilha p);

///Fuções básicas de Fila

Fila inicFila( void ); /// Cria e retorna uma fila vazia
void adicFila( Fila f, TipoF elem);  /// Adiciona um elemento no final da fila
TipoF elimFila( Fila f); /// Elimina e retorna o primeiro elemento da fila
TipoF infoFila(Fila f); /// Retorna o primeiro elemento da fila sem remover
int vaziaFila(Fila f); /// Retorna verdadeiro se a fila está vazia e falso caso contrário
void destruirFila(Fila f); /// Destrói a fila f, desalocando toda memória ocupada
void printFila(Fila f); /// Imprime a fila

/// Exercícios Fila

/// 1) Fazer uma cópia de uma Fila, usando como apoio uma lista
Fila copiarFila( Fila f );
/// 2) Computar e retornar o número de elementos da fila, sem alterar seu conteúdo
int longFila(Fila f);
/// 3) Concatenar duas filas, deixando o resultado na primeira(f1)
void concatFilas(Fila f1, Fila f2);
/// 4) Inverter os elementos da fila
void invFila( Fila f);
/// 5) Retorna true(1) se o elemento elem está presente na fila e false(0) caso contrário
int existeElemento( Fila f, TipoF elem);
/// 6) Retorna true(1) se as filas f1 e f2 têm os mesmos elementos, na mesma ordem, e false(0) caso contrário
int iguaisFilas(Fila f1, Fila f2);
/// 7) Adiciona o elemento elem na posição pos da fila, deslocando todos os elementos seguintes uma posição para trás
void adicFilaPos( Fila f, TipoF elem, int pos);
/// 8) Remove da fila o elemento elem
void elimElemento( Fila f, TipoF elem);
/// 9) Deixa na fila f1 todos os elementos da fila f, menores que elem e na fila f2 todos os elementos maiores que elem
void partirFila( Fila f, Fila f1, Fila f2, TipoF elem);
/// 10) Coloca o elemento elem na primeira posição da fila
void primeiroDaFila( Fila f, TipoF elem);
/// 11) e 12) exercícios para implementar




#endif // FUNCOES_H_INCLUDED
