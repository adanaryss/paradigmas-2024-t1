#include "lista.h"

void Lista_new(Lista* lista, int data_size, void (*free_data)(void*)) {
    lista->inicio = NULL;
    lista->data_size = data_size;
    lista->free_data = free_data;
    lista->tamanho = 0;
}

void Lista_delete(Lista* lista) {
    ListaNodo* atual = lista->inicio;
    while (atual != NULL) {
        ListaNodo* prox = atual->next;
        if (lista->free_data != NULL)
            lista->free_data(atual->valor);
        free(atual);
        atual = prox;
    }
    lista->inicio = NULL;
    lista->tamanho = 0;
}

int Lista_isEmpty(Lista* lista) {
    return lista->tamanho == 0;
}

int Lista_size(Lista* lista) {
    return lista->tamanho;
}

void Lista_pushFront(Lista* lista, void* valor) {
    ListaNodo* novo_no = malloc(sizeof(ListaNodo));
    novo_no->valor = valor;
    novo_no->next = lista->inicio;
    lista->inicio = novo_no;
    lista->tamanho++;
}

void Lista_pushBack(Lista* lista, void* valor) {
    ListaNodo* novo_no = malloc(sizeof(ListaNodo));
    novo_no->valor = valor;
    novo_no->next = NULL;
    if (lista->inicio == NULL) {
        lista->inicio = novo_no;
    } else {
        ListaNodo* atual = lista->inicio;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = novo_no;
    }
    lista->tamanho++;
}


