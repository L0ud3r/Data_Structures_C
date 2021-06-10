#include <stdio.h>
#include <stdlib.h>

typedef struct _list 
{
    int value;
    struct _list *next, *prev;
} List;

List *head_insert_double_linked_list(List* list, int value){
    List* new_node = malloc(sizeof(List));

    new_node->value = value;
    new_node->next = list;
    new_node->prev = NULL;
    if(new_node->next)
        new_node->next->prev = new_node;

    return new_node;
}

void mostrar_lista_inversa(List* list){
    printf("Numeros na ordem inversa:\n\n");

    for(List* aux = list; aux; aux->next){
        printf("-> %d\n", aux->value);
    }
}

int somatorio(List* list){
    int counter = 0;
    
    for(List *aux = list; aux; aux = aux->next){
        counter += aux->value;
    }

    return counter;
}

void mostrar_lista_original(List* list){
    List *aux = list;

    if(list == NULL) return;

    printf("Numeros na ordem original:\n\n");

    for(; aux->next; aux = aux->next) { }

    while(aux){
        printf("-> %d\n", aux->value);

        aux = aux->prev;
    }
}

int main(){
    List *list = NULL;
    int number;

    printf("Insira uma sequencia de numeros (para sair insira um negativo):\n");
    do 
    {
        scanf("%d", &number);
        list = head_insert_linked_list(list, number);
    } while(number >= 0);

    mostrar_lista_original(list);
    return 0;
}