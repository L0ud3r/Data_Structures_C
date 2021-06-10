#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct _list
{
    char *nome;
    struct _list *next, *prev;
} List;

typedef struct _queue
{
    List *first, *last;
} Queue;

List* tail_insert_double_linked_list(List* list, char *s){
    List* new_node = malloc(sizeof(List)), *aux = list;


    if(!list) {
        for(; aux->next; aux = aux->next) { }
        aux->next = new_node;
        new_node->prev = aux;
        new_node->next = NULL;
    }
    else{
        list = new_node;
    }

    return list;
}

void queue_insert(Queue *q, char *s){
    List* new_node = malloc(sizeof(List));

    new_node->nome = strdup(s);

    if(!(q->first))
    {
        new_node->next = q->last;
        new_node->prev = NULL;

        q->first = q->last = new_node;
    }
    else
    {
        new_node->prev = q->last;
        new_node->next = NULL;
        q->last->next = new_node;
        q->last = new_node;
    }
}

Queue *new_queue(Queue* lista){
    Queue *new = malloc(sizeof(Queue));

    new->first = new->last = NULL;
    return new;
}

void mostra_queue(Queue* q){
    List *aux = q->first;

    while(aux){
        printf("%s\n", aux->nome);

        aux = aux->next;
    }
}

char* dequeue(Queue *q){
    assert(q);
    if(!q->first) return NULL;

    char *firstName = q->first->nome;

    if(q->first->next) q->first->next->prev = NULL;
    else q->last = NULL;

    free(q->first);

    q->first = q->first->next;

    return firstName;
}

void clear_queue(Queue *q){
    char *nome = dequeue(q);

    while(nome){
        free(nome);
        nome = dequeue(q);
    }
    free(nome);
}

int main(){
    Queue *lista = new_queue(lista);

    queue_insert(lista, "pedro");
    queue_insert(lista, "oleole");
    queue_insert(lista, "ni");
    queue_insert(lista, "jorge");

    mostra_queue(lista);
    clear_queue(lista);
    free(lista);

    return 0;
}