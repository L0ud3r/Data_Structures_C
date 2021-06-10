#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Tempo de execucao com head_insert: 
        real	0m0,107s
        user	0m0,083s
        sys	    0m0,024s

Tempo de execucao com tail_insert: (APENAS NO NODO 500000)
real	15m26,073s ~ 30min
user	11m31,355s ~ 22min
sys	    3m52,634s  ~ 8min

c)  head_insert => O(1)
    tail_insert => O(N)

*/
#define M 1000000

typedef struct _list
{
    int value;
    struct _list *next;
} List;

List *head_insert_linked_list(List* list, int value){
    List *new_node = malloc(sizeof(List));

    new_node->value = value;
    new_node->next = list;

    return new_node;
}

List* tail_insert_linked_list(List* list, int value){
    List* new_node = malloc(sizeof(List)), *aux = list;

    new_node->value = value;
    new_node->next = NULL;

    if(list) {
        for(;aux->next; aux = aux->next) { }
        aux->next = new_node;
    }
    else list = new_node;

    return list;
}

float media_aritmetica(List *list){
    int counter;
    for(counter = 0; list; list = list->next){
        counter += list->value;
    }

    return ((float)counter / M);
}

float desvio_padrao(List *list, float average){
    int counter;
    
    for(counter = 0; list; list = list->next){
        counter += ((list->value - average)*(list->value - average));
    }

    return ((float)counter / M);
}

int main(){
    List *list = NULL;
    int number;
    float media, desvio;
    srand(time(NULL));

    for(int i = 0; i < M; i++){
        number = rand();
        list = head_insert_linked_list(list, number);
    }

    media = media_aritmetica(list);
    desvio = desvio_padrao(list, media);

    printf("Media: %f\nDesvio Padrao: %f\n", media, desvio);

    return 0;
}