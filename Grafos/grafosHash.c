#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//Para poder registar uma grande quantidade de dados (nome, idade, cc, nascimento, profissao, etc.)
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

Grafo *grafo_insert_vertice(Grafo *g, int value){
    Grafo *new = malloc(sizeof(Grafo));

    new->partida = value;
    new->sucessores = NULL;
    new->next = g;

    return new;
}

void grafo_insert_verticeChegada(Grafo *g, int partida, int destino, float peso){
    Grafo *vertice_partida = grafo_procura_vertice(g, partida);

    if(vertice_partida){
        ListSucessores *new = malloc(sizeof(ListSucessores));
        new->destino = destino;
        new->peso = peso;
        new->next = vertice_partida->sucessores;
        vertice_partida->sucessores = new;
    }
}

ListSucessores *grafo_tem_aresta(Grafo *g, int partida, int destino){
    while(g && g->partida != partida)
        g = g->next;
    
    if(g){
        ListSucessores *aux = g->sucessores;

        while(aux && aux->destino != destino){
            aux = aux->next;
        }

        return aux;
    }

    return NULL;
}

void listar_sucessores(Grafo *g, int partida){
    while(g && g->partida != partida)
        g = g->next;
    
    if(g){
        ListSucessores *aux = g->sucessores;

        printf("Sucessores do vertice %d\n", g->partida);
        while(aux){
            printf("%d ", aux->destino);
        }
    }
    else printf("O vertice %d nao tem qualquer sucessores\n", g->partida);
}

void listar_antecessores(Grafo *g, int destino){
    ListSucessores *aux;

    while(g){
        aux = g->sucessores;
        while(aux && aux->destino != destino){
            printf("%d ", g->partida);
            aux = aux->next;
        }

        g = g->next;
    }
}

void listar_arestas(Grafo *g){
    ListSucessores *aux;
    while(g){
        for(aux = g->sucessores; aux; aux = aux->next){
            printf("[%d;%d]: %d", g->partida, aux->destino, aux->peso);
        }
        
        g = g->next;
    }
}

Grafo *grafo_procura_vertice(Grafo *g, int value){
    while(g && g->partida != value)
        g = g->next;

    return g; 
}

int contar_vertices(Grafo *g){
    int counter = 0;

    while(g){
        counter++;
        g = g->next;
    }

    return counter;
}

int contar_arestar(Grafo *g){
    int counter = 0;

    while (g)
    {
        for(ListSucessores *aux = g->sucessores; aux; aux = aux->next){
            counter++;
        }        
        g = g->next;
    }

    return counter;
}

void free_grafo(Grafo *g){
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

int main(){
    Grafo *grafo = NULL;


    return 0;
}