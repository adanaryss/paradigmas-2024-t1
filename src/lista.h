#ifndef _PARADIGMAS_T1_LISTA_H_
#define _PARADIGMAS_T1_LISTA_H_

/**
 * Insira seu código para solucionar o trabalho neste arquivo.
 */

typedef struct _lista_nodo {
    void* valor;
    struct _lista_nodo* next;
} ListaNodo;

typedef struct {
    ListaNodo* inicio;
    int data_size;
    void (*free_data)(void*);
    int tamanho;
} Lista;

void Lista_new(Lista* lista, int data_size, void (*free_data)(void*));
void Lista_delete(Lista* lista);
int Lista_isEmpty(Lista* lista);
int Lista_size(Lista* lista);
void Lista_pushFront(Lista* lista, void* valor);
void Lista_pushBack(Lista* lista, void* valor);

#endif /* _PARADIGMAS_T1_LISTA_H_ */
