#include "lista_duplamente_ligada.h"
#include <stdlib.h>
#include <stdio.h>

/* Struct NO, representa os nós da lista ligada 
 e armazena um id (idade), posicao (posição original) e 
 um ponteiro para o próximo no é um ponteiro para o nó anterior */
typedef struct no {
	int id;
	int posicao;
	struct no * proximo;
	struct no * anterior;
} NO;

// Função que libera um nó da memória Heap
void apagar_no (NO * no) {
	if (no != NULL) {
		free(no);
	}
}

/* Struct lista_ligada representa a fila que será armazenada
em forma de lista_ligada. E armazena um ponteiro para o nó sentinela,
além disso, armazena o número de elementos na fila */
struct lista_ligada {
	NO * sentinela;
	int tamanho;
};

/* função que cria uma lista e inicializa as variáveis
e retorna o endereço da lista armazenado na Heap */
LISTA_LIGADA * criar_lista () {
	LISTA_LIGADA * lista = (LISTA_LIGADA *) malloc (sizeof(lista));
	if (lista != NULL) {
		lista->sentinela = (NO *) malloc (sizeof(NO));
		if (lista->sentinela != NULL) {
			lista->sentinela->id = -1;
			lista->sentinela->proximo = lista->sentinela;
			lista->sentinela->anterior = lista->sentinela;
			lista->tamanho = 0;
		} else {
			free(lista);
			lista = NULL;
		}
	}
	return lista;
}

/* função que insere uma determinada <chave> na fila.
Como é uma fila, a inserção sempre ocorre no final.
Se conseguir inserir na fila, o retorno é a <chave>. 
Caso contrário, o retorno é 0.*/
int inserir_lista (LISTA_LIGADA * lista, int chave) {
	if (lista != NULL) {
		NO * pnovo = (NO *) malloc (sizeof(NO));
		if (pnovo != NULL) {
			pnovo->id = chave;
			pnovo->posicao = lista->tamanho + 1;
			pnovo->anterior = lista->sentinela->anterior;
			pnovo->proximo = lista->sentinela;
			lista->sentinela->anterior->proximo = pnovo;
			lista->sentinela->anterior = pnovo;
			lista->tamanho++;
			return chave;
		}
	}
	return 0;

}

/* função que remove um elemento da fila.
Como é uma fila, a remoção sempre ocorre no começo.
O retorno da função é a <chave> retirada, caso tenha algum
elemento na fila, caso contrário, retorna 0*/
int remover_inicio (LISTA_LIGADA * lista) {
	if (lista != NULL) {
		if (lista->tamanho != 0) {
			NO * aux = lista->sentinela->proximo;
			lista->sentinela->proximo = aux->proximo;
			aux->proximo->anterior = lista->sentinela;
			int id = aux->id;
			apagar_no(aux);
			return id;
		}
	}
	return 0;
}

/* Função que retira os elementos especiais da <lista>
e cria uma nova lista com esses elementos.
A função retorna essa lista alocada na heap */
LISTA_LIGADA * nova_lista(LISTA_LIGADA * lista) {
	if (lista != NULL && lista->tamanho > 0) {
		LISTA_LIGADA * lista_prioridade = criar_lista();
		if (lista_prioridade != NULL) {
			NO *paux = lista->sentinela->proximo;
			while (paux != lista->sentinela) {
				if (paux->id >= 60) {
					inserir_lista(lista_prioridade, paux->id);
					lista_prioridade->sentinela->anterior->posicao = paux->posicao;
	
					NO * prem = paux;
					paux = paux->proximo;
					prem->anterior->proximo = prem->proximo;
					prem->proximo->anterior = prem->anterior;

					apagar_no(prem);
				} else {
					paux = paux->proximo;
				}

			}
			return lista_prioridade;
		}
	}
	return NULL;
}

/* Função que imprime a lista no seguinte formato:
Posição Original - Id */
void imprimir_lista_id (LISTA_LIGADA * lista) {
	if (lista != NULL) {
		NO * paux = lista->sentinela->proximo;
		while (paux != lista->sentinela) {
			printf("%d - %d\n", paux->posicao, paux->id);
			paux = paux->proximo;
		}
	}
}

/* Função que imprime a lista no seguinte formato:
Posição Atual - Posicao Original */
void imprimir_lista_posicao (LISTA_LIGADA * lista) {
	if (lista != NULL) {
		int i = 1;
		NO * paux = lista->sentinela->proximo;
		while (paux != lista->sentinela) {
			printf("%d - %d\n", i++, paux->posicao);
			paux = paux->proximo;
		}
	}
}

/* Função que libera toda a lista da memória */
void apagar_lista(LISTA_LIGADA * lista){
	NO * aux = lista->sentinela->proximo;
		
	while(aux != lista->sentinela){
		aux = aux->proximo;
		free(aux->anterior);
	}
	free(lista->sentinela);
	free(lista);
}
