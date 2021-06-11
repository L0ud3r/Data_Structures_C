#include <stdio.h>

typedef struct _listSucessores
{
    int destino;
    float peso;
    struct _listSucessores *next;
} ListSucessores;

typedef struct _node
{
    int partida;
    ListSucessores *sucessores;
    struct _node *next;
} Grafo;

void free_graph(Grafo *g){
    while(g){
        Grafo *verticeToRemove = g;
        ListSucessores *aux = g->sucessores;
        g = g->next;

        free(verticeToRemove);
        while(aux){
            ListSucessores *sucessorToRemove = aux;
            aux = aux->next;
            free(sucessorToRemove);
        }
    }
}