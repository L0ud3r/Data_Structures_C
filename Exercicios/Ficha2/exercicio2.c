#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _queue {
    void *data;
    struct _queue *next;
} Queue;

Queue* enqueue(Queue* queue, void* data){
    Queue* new_node = malloc(sizeof(Queue));
    Queue *aux = queue;

    new_node->data = data;

    if(queue)
    {   
        for(; aux->next; aux = aux->next) { }
        aux->next = new_node;
        new_node->next = NULL;
    }
    else
        queue = new_node;

    return queue;
}

void* peek(Queue* queue){
    return queue->data;
}

Queue* dequeue(Queue* queue){
    Queue *aux = queue->next;
    queue->next = NULL;

    free(queue);
    return aux;
}

int main(){
    char *nome1 = strdup("Alberto Simoes");
    char *nome2 = strdup("Mario Joao Vale");
    Queue *queue = NULL;
    queue = enqueue(queue, nome1);
    queue = enqueue(queue, nome2);
    printf("Primeiro da lista: %s\n", (char*) peek(queue));
    queue = dequeue(queue);
    printf("Proximo da lista: %s\n", (char*) peek(queue));

    return 0;
}