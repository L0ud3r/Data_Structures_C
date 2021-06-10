#include <stdio.h>
#include <string.h>
/*
    Multiplas:
1 - a)
2 - a)
3 - a)
4 - a)
5 => CODIGO
6 - a)
7 - a)
8 => CODIGO (duvidoso)
9 - d)
10 - d)
11 => CODIGO
12 - a)
13 - b)
14 - d)
15 - enunciado com bug de imagem
16 - d)
17 - c)
18 - a)
19 - a)
20 => CODIGO
21 => CODIGO
*/

//5)
#pragma region Exercicio5
#define MAX 100000

int hash(char *string){
    return atoi(string) % MAX;
}
#pragma endregion

//8)
#pragma region Exercicio8

typedef struct _aresta
{
    int chegada;
    float peso;
    struct _aresta *next;
} Aresta;

typedef struct _vertice
{
    int partida;
    Aresta* destinos;
    struct _vertice *next;
} Vertice;

Aresta menor_peso(Vertice *grafo, int v1, int v2){
    Aresta *aux, *verticePeso1 = NULL, *verticePeso2 = NULL;
    Vertice *aux2 = grafo;

    //[v1, v2]
    while(grafo && grafo->partida != v1){
        aux = grafo->destinos;
        
        while(aux){
            if(aux->destino == v2)
                verticePeso1 = aux;
            aux = aux->next;
        }

        grafo = grafo->next;
    }

    grafo = aux2;
    
    //[v2, v1]
    while(grafo && grafo->partida != v2){
        aux = grafo->destinos;
        
        while(aux){
            if(aux->destino == v1)
                verticePeso2 = aux;
            aux = aux->next;
        }

        grafo = grafo->next;
    }

    if(!verticePeso2->peso || verticePeso1->peso < verticePeso2->peso) return verticePeso1;

    return verticePeso2;
}

#pragma endregion

//11
#pragma region Exercicio11

int num_palavras(List* lista){
    int counter = 0;

    for(List* aux = lista; aux; aux = aux->next){
        if(strcmp(aux->palavra[0], 'a') == 0 && strcmp(aux->palavra[strlen(aux->palavra) - 1], 'a') == 0)
            counter++;
    }

    return counter;
}

#pragma endregion

//20
#pragma region Exercicio20

int altura_arvore(BTree* root){
    int counter = 0;

    if(root){
        int pesoEsq = btree_depth(root->left);
        int pesoDir = btree_depth(root->right);
        
        if(pesoDir > pesoEsq)
            pesoMax = pesoDir;
        else
            pesoMax = pesoEsq;

        counter = 1 + pesoMax;
    }

    return counter;
}

#pragma endregion

//21
#pragma region Exercicio21

List* lista_invertida(List* list){
    List* aux = NULL;
    List* middleMan = malloc(sizeof(List));

    while(list){
        middleMan->value = list->value;
        aux = head_insert(aux, middleMan);
        list = list->next;
    }

    return aux;
}

#pragma endregion
