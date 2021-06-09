#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#pragma region Estruturas de Dados

typedef struct _person
{
    char *name, *country;
    int age;
} Person;

typedef struct _queueList{
    //Can use generic data structure (*void)
    Person person;
    struct _queueList *next, *prev;
} QueueList;

typedef struct _queue{
    QueueList *first, *last;
} Queue;

#pragma endregion

Queue *createNewQueue(){
    Queue *new = malloc(sizeof(Queue));
    //Not necessary, just checks if the is any bugs with the Queue
    assert(new);

    new->first = new->last = NULL;
}

//insert new node in queue
void *enqueue(Queue *q, char *name, char* country, int age){
    QueueList *new = malloc(sizeof(QueueList));
    new->person.name = strdup(name);
    new->person.country = strdup(country);
    new->person.age = age;

    if(!(q->first))
    {
        new->next = q->last;
        new->prev = NULL;

        q->first = q->last = new;
    }
    else
    {
        new->prev = q->last;
        new->next = NULL;
        q->last->next = new;
        q->last = new;
    }
}

char* dequeue(Queue *q){
    assert(q);
    if(!q->first) return NULL;

    char *firstName = q->first->person.name;

    if(q->first->next) q->first->next->prev = NULL;
    else q->last = NULL;

    free(q->first);

    q->first = q->first->next;

    return firstName;
}

void list_queue(Queue *q){
    QueueList *list = q->first;

    //Ordem de espera/chegada
    while(list){
        printf("Nome: %s\nIdade: %d\nPais: %s\n\n", list->person.name, list->person.age, list->person.country);
        list = list->next;
    }
}

void list_queue_inverse(Queue *q){
    QueueList *list = q->last;

    //Ordem inversa
    while (list)
    {
        printf("Nome: %s\nIdade: %d\nPais: %s\n\n", list->person.name, list->person.age, list->person.country);
        list = list->prev;
    }
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
    Queue *list = createNewQueue();

    enqueue(list, "Pedro", "Portugal", 20);
    enqueue(list, "Ni", "Brazil/Portugal", 18);
    enqueue(list, "Keriny", "Brazil/Portugal", 40);
    enqueue(list, "Joao Carlos", "Portugal", 48);
    enqueue(list, "Ale", "Brazil/Portugal", 22);

    list_queue(list);
    clear_queue(list);
    list_queue(list);

    free(list);
    return 0;
}