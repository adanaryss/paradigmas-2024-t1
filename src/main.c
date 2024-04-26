#include <stdio.h>
#include "lista.h"

int main() {
    Lista lista;
    Lista_new(&lista, sizeof(int), NULL);

    // Teste de inserção de elementos
    int num1 = 10;
    Lista_pushFront(&lista, &num1);

    int num2 = 20;
    Lista_pushBack(&lista, &num2);

    // Teste de verificação se a lista está vazia
    if (Lista_isEmpty(&lista)) {
        printf("A lista está vazia.\n");
    } else {
        printf("A lista não está vazia.\n");
    }

    // Teste de obtenção do tamanho da lista
    printf("Tamanho da lista: %d\n", Lista_size(&lista));

    // Libera memória da lista
    Lista_delete(&lista);

    return 0;
}
