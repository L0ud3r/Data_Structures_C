#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _list{
    int n;
    struct _list *next, *prev;
} List;

#pragma region Inserts

List* head_insert(List* list, int value){
    List* new_node = malloc(sizeof(list));
    
    new_node->n = value;
    new_node->next = list;
    new_node->prev = NULL;

    if(new_node->next)
        new_node->next->prev = new_node;

        return new_node;
}

List* tail_insert(List* list, int value){
    List* aux, *new_node = malloc(sizeof(List));
    
    new_node->n = value;
    new_node->next, new_node->prev = NULL;

    if(!list) 
        list = new_node;
    else{
        for(aux = list; aux->next; aux = aux->next){    }
        aux->next = new_node;
        new_node->prev = aux;
    }

    return list;
}

List* sorted_insert(List* list , int value) {
    List* new_node = malloc (sizeof(List));

    new_node->n = value ;
    new_node->next = new_node->prev = NULL ;

    if (!list || list->n > value ) {

        new_node->next = list ;
        list = new_node;

        if ( list->next ) list->next->prev = list;
    }
    else {
        List *aux = list ;

        for (; aux->next && aux->next->n < value; aux = aux->next ) { }

        new_node->next = aux->next ;
        new_node->prev = aux ;
        aux->next = new_node;
        
        if (new_node->next ) new_node->next->prev = new_node;
    }

    return list;
}
#pragma endregion
int main(){
    List* list = NULL ;

    return 0;
}