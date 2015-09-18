#include "lista_duplamente_ligada.h"
#include <stdio.h>

int main (void) {
	int id;
	LISTA_LIGADA * lista = criar_lista();
	while (scanf("%d", &id) != EOF) {
		inserir_lista(lista, id);
	}
	printf("Fila geral original\n");
	imprimir_lista_id(lista);
	
	//Separa as duas filas
	LISTA_LIGADA * lista_prioridade = nova_lista(lista);

	printf("\nFila preferencial\n");
	imprimir_lista_id(lista_prioridade);

	printf("\nFila geral atualizada\n");
	imprimir_lista_id(lista);

	printf("\nResultado esperado fila preferencial\n");
	imprimir_lista_posicao(lista_prioridade);

	printf("\nResultado esperado fila geral\n");
	imprimir_lista_posicao(lista);
	
	apagar_lista(lista);
	apagar_lista(lista_prioridade);

	return 0;
}   
