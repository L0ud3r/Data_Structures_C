#include <stdio.h>

typedef struct _list{
    int v;
    struct _list *next;
} List;

List* indiceK(List* list, int K){
    int counter = 0;

    for(List* aux; aux; aux = aux->next && counter++){
        if(counter == K) return aux;
    }

    return NULL;
}