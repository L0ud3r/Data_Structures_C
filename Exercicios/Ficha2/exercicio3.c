#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _list{
    char *distrito;
    int numeroInfetados;
    struct _list *next, *prev;
} List;

List *insert_district(List* list, char* nome, int n){
    for(List *aux = list; aux; aux = aux->next)
    {
        if(strcmp(aux->distrito, nome) == 0){
            aux->numeroInfetados = n;
            return list;
        }
    }

    List *new_node = malloc(sizeof(List));

    new_node->distrito = strdup(nome);
    new_node->numeroInfetados = n;
    new_node->next = list;

    if(new_node->next){
        new_node->next->prev = new_node;
    }
    new_node->prev = NULL;

    return new_node;
}

int main(){

    return 0;
}