#include <stdio.h>

typedef struct _target{
    char* estacao;
    float distance;
    float time;
    struct _target *next;
} Target;

typedef struct _origin{
    char* estacao;
    Target* targets;
    struct _origin *next;
} Origin;

void atribuirTime(Origin* grafo){
    Origin *aux = grafo;

    while(aux){
        Target* aux2 = aux->targets;

        while(aux2){
            aux2->time = aux2->distance * 2;
            
            aux2 = aux2->next;
        }
        aux = aux->next;
    }
}