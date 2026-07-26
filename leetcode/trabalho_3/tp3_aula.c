/*
===============================================================================

	LeetCode 775 - Inversoes Globais e Locais ( Global and Local Inversions )
	Use avl na solucao

	Voce recebe um array de inteiros nums de comprimento n que representa
	uma permutacao de todos os inteiros no intervalo [0, n - 1].

	O numero de inversoes GLOBAIS e o numero de pares ( i, j ) diferentes
	onde:

		0 <= i < j < n  e  nums[i] > nums[j]

	O numero de inversoes LOCAIS e o numero de indices i onde:

		0 <= i < n - 1  e  nums[i] > nums[i + 1]

	Retorne true se o numero de inversoes globais for igual ao numero de
	inversoes locais.

	Exemplo 1:

		Entrada: nums = [1,0,2]
		Saida: true
		Explicacao: ha 1 inversao global e 1 inversao local.

	Exemplo 2:

		Entrada: nums = [1,2,0]
		Saida: false
		Explicacao: ha 2 inversoes globais e 1 inversao local.

	Restricoes:

		n == nums.length
		1 <= n <= 10^5
		0 <= nums[i] < n
		Todos os inteiros de nums sao distintos
		nums e uma permutacao de todos os numeros no intervalo [0, n - 1]

	Nota: existe solucao mais eficiente, esta versao e para estudar a tecnica de arvore avl.

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no_s {
	int					valor;
	int					tamanho;
	int					altura;
	struct no_s *		esq;
	struct no_s *		dir;
} no_t;

/*
====================
Altura
====================
*/
static int Altura( const no_t *n ) {
	return n ? n->altura : 0;
}

/*
====================
Tamanho
====================
*/
static int Tamanho( const no_t *n ) {
	return n ? n->tamanho : 0;
}

/*
====================
Atualizar
====================
*/
static void Atualizar( no_t *n ) {
	int		he;
	int		hd;

	he = Altura( n->esq );
	hd = Altura( n->dir );
	n->altura = ( he > hd ? he : hd ) + 1;
	n->tamanho = 1 + Tamanho( n->esq ) + Tamanho( n->dir );
}

/*
====================
RotacaoDireita
====================
*/
static no_t *RotacaoDireita( no_t *y ) {
	no_t *	x;

	x = y->esq;
	y->esq = x->dir;
	x->dir = y;
	Atualizar( y );
	Atualizar( x );
	return x;
}

/*
====================
RotacaoEsquerda
====================
*/
static no_t *RotacaoEsquerda( no_t *x ) {
	no_t *	y;

	y = x->dir;
	x->dir = y->esq;
	y->esq = x;
	Atualizar( x );
	Atualizar( y );
	return y;
}

/*
====================
FatorBalanceamento
====================
*/
static int FatorBalanceamento( const no_t *n ) {
	return Altura( n->esq ) - Altura( n->dir );
}

/*
====================
Rebalancear
====================
*/
static no_t *Rebalancear( no_t *n ) {
	int		fb;

	Atualizar( n );
	fb = FatorBalanceamento( n );

	if ( fb > 1 ) {
		if ( FatorBalanceamento( n->esq ) < 0 ) {
			n->esq = RotacaoEsquerda( n->esq );
		}
		return RotacaoDireita( n );
	}
	if ( fb < -1 ) {
		if ( FatorBalanceamento( n->dir ) > 0 ) {
			n->dir = RotacaoDireita( n->dir );
		}
		return RotacaoEsquerda( n );
	}
	return n;
}

/*
====================
Inserir_r

	Essa funcao insere um valor na arvore e retorna a nova raiz.
====================
*/
no_t *Inserir_r( no_t *raiz, int valor ) {
	no_t *	n;

	if ( !raiz ) {
		n = malloc( sizeof( no_t ) );
		n->valor = valor;
		n->tamanho = 1;
		n->altura = 1;
		n->esq = NULL;
		n->dir = NULL;
		return n;
	}
	if ( valor < raiz->valor ) {
		raiz->esq = Inserir_r( raiz->esq, valor );
	} else {
		raiz->dir = Inserir_r( raiz->dir, valor );
	}
	return Rebalancear( raiz );
}

/*
====================
Liberar_r
====================
*/
void Liberar_r( no_t *n ) {
	if ( !n ) {
		return;
	}
	Liberar_r( n->esq );
	Liberar_r( n->dir );
	free( n );
}

/*
====================
isIdealPermutation

	RESOLVER ESSA FUNCAO USANDO ARVORE AVL PARA CONTAR O NUMERO DE INVERSOES GLOBAIS.

====================
*/
bool isIdealPermutation( int *nums, int numsSize ) {
    bool resultado = ehPermutacao();

	return resultado;
}

bool ehPermutacao(no_t* raiz, int tamanho){
    int *nos;
    int global;
    int local;

    global = nos[0] * nos[1]; //esquerda * direita (e a raiz?)
    local = (nos[0] * 2) + (nos[1] * 2); //não é isso, vai dar um valor muito maior
    nos = contarNo(raiz);
    for (int i = 0; i < tamanho; i++){
        /* code */
    }
    // se a arvore for balanceada vai ter praticamente o mesmo tamanho na esquerda e na direta
    //criar uma funcao de contar nó para a esquerda e a direita
    //todos os nós da direita obrigatoriamente serão maiores que a raiz e os da esquerda
    //fazer uma operacao de multiplicacao para encontrar o valor
    //fazer um calculo de permutacao nos elementos da esquerda e outros no da direita e depois somar os dois
    //comparar a soma dos dois lados com a multiplicação de um lador por outro e retornar se o valor é o mesmo ou não
    // comparar com a raiz?
    return false;
}

int* contarNo(no_t *raiz) {
    int *nos = (int *)malloc(2 * sizeof(int));
    if (raiz == NULL){
        return NULL;
    } else {
        nos[0] = 1 + contarNo(raiz->esq);
        nos[1] = 1 + contarNo(raiz->dir);
    }
    return nos;
}

/*
====================
ForcaBruta

	Referencia O( n^2 ) usada para conferir os resultados dos testes.
====================
*/
static bool ForcaBruta( const int *nums, int n ) {
	long long	global;
	long long	local;
	int			i;
	int			j;

	global = 0;
	for ( i = 0; i < n; i++ ) {
		for ( j = i + 1; j < n; j++ ) {
			if ( nums[i] > nums[j] ) {
				global++;
			}
		}
	}

	local = 0;
	for ( i = 0; i + 1 < n; i++ ) {
		if ( nums[i] > nums[i + 1] ) {
			local++;
		}
	}

	return global == local;
}

/*
====================
ImprimirArray
====================
*/
static void ImprimirArray( const int *a, int n ) {
	int		i;

	printf( "[" );
	for ( i = 0; i < n; i++ ) {
		printf( "%d%s", a[i], i + 1 < n ? "," : "" );
	}
	printf( "]" );
}

/*
====================
RodarTeste
====================
*/
static int RodarTeste( int num, int *nums, int n, bool esperado ) {
	bool	obtido;
	bool	bruto;
	int		ok;

	obtido = isIdealPermutation( nums, n );
	bruto = ForcaBruta( nums, n );
	ok = ( obtido == esperado ) && ( bruto == esperado );

	printf( "Teste %2d: nums = ", num );
	ImprimirArray( nums, n );
	printf( "\n  esperado = %s | avl = %s | forca bruta = %s  ->  %s\n\n",
			esperado ? "true" : "false",
			obtido ? "true" : "false",
			bruto ? "true" : "false",
			ok ? "OK" : "FALHOU" );
	return ok;
}

/*
====================
main
====================
*/
int main( void ) {
	// int		passou;
    bool resposta;
	// int		t1[]  = { 1, 0, 2 };				/* exemplo 1 do enunciado             */
	// int		t2[]  = { 1, 2, 0 };				/* exemplo 2 do enunciado             */
	// int		t3[]  = { 0 };						/* elemento unico                     */
	// int		t4[]  = { 0, 1, 2, 3, 4 };			/* identidade: zero inversoes         */
	// int		t5[]  = { 1, 0, 3, 2, 4 };			/* trocas adjacentes disjuntas        */
	// int		t6[]  = { 2, 0, 1 };				/* valor a 2 posicoes do lugar        */
	// int		t7[]  = { 4, 3, 2, 1, 0 };			/* permutacao reversa                 */
	// int		t8[]  = { 0, 2, 1 };				/* uma troca adjacente no fim         */
	// int		t9[]  = { 1, 0, 2, 4, 3 };			/* trocas nas duas pontas             */
	// int		t10[] = { 3, 0, 1, 2 };				/* 3 globais, 1 local                 */

    no_t *raiz = NULL;
    no_t *raiz2 = NULL;
    int *raiz_teste;
	// passou = 0;
	// passou += RodarTeste(  1, t1,  3, true );
	// passou += RodarTeste(  2, t2,  3, false );
	// passou += RodarTeste(  3, t3,  1, true );
	// passou += RodarTeste(  4, t4,  5, true );
	// passou += RodarTeste(  5, t5,  5, true );
	// passou += RodarTeste(  6, t6,  3, false );
	// passou += RodarTeste(  7, t7,  5, false );
	// passou += RodarTeste(  8, t8,  3, true );
	// passou += RodarTeste(  9, t9,  5, true );
	// passou += RodarTeste( 10, t10, 4, false );

    Inserir_r(raiz, 1);
    Inserir_r(raiz, 0);
    Inserir_r(raiz, 2);

    Inserir_r(raiz2, 0);
    Inserir_r(raiz2, 1);
    Inserir_r(raiz2, 2);
    Inserir_r(raiz2, 3);
    Inserir_r(raiz2, 4);

    printf("%d", Tamanho(raiz2));
   // resposta = isIdealPermutation(/*(int )*/raiz, Tamanho(raiz)); //espera int, raiz é tipo nó
    resposta = ehPermutacao(raiz, Tamanho(raiz));

	//printf( "Resultado final: %d/10 testes passaram\n", passou );
	//return passou == 10 ? 0 : 1;
}
