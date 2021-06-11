#include <stdio.h>

typedef struct _list{
    int value;
    struct _list *next;
} List;

List* juntaListasOrdenadas(List* l1, List *l2){
    List* finalList = malloc(sizeof(List));

    for(List* aux = l1; aux; aux = aux->next){
        finalList = insere_ordenado(finalList, l1->value);
    }

    for(List* aux = l2; aux; aux = aux->next){
        finalList = insere_ordenado(finalList, l2->value);
    }

    return finalList;
}

List* insere_ordenado(List* list, int value){
    if(confirmaExisteNum(list, value) == 1) return list;

    List* new_node = malloc(sizeof(List));
    new_node->value = value;

    if(!list || new_node->value < list->value){
        new_node->next = list;
        list = new_node;    
    }
    else{
        List*aux = list;

        for( ;aux->next && new_node->value > aux->next->value; aux = aux->next) { }

            new_node->next = aux->next;
            aux->next = new_node;
    }

    return list;
}

int confirmaExisteNum(List* list, int value){
    for(List* aux = list; aux; aux = aux->next){
        if(aux->next == value) return 1;
    }

    return 0;
}