#ifndef LISTA_DUPLAMENTE_LIGADA_H_
#define LISTA_DUPLAMENTE_LIGADA_H_

typedef struct lista_ligada LISTA_LIGADA;

LISTA_LIGADA * criar_lista ();

int inserir_lista (LISTA_LIGADA * lista, int chave);

int remover_inicio (LISTA_LIGADA * lista);

void transferir_usuarios(LISTA_LIGADA * lista, LISTA_LIGADA ** lista1, LISTA_LIGADA ** lista2);

void imprimir_lista_posicao (LISTA_LIGADA * lista);

void imprimir_lista_id (LISTA_LIGADA * lista);

LISTA_LIGADA * nova_lista(LISTA_LIGADA * lista);
#endif
