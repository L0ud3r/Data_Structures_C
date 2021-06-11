#include <stdio.h>
/*
    NOTA: COLISOES É: if (list2->next != NULL) colisao!! por cada nodo adicionado


    Caso seja Lista de listas -> Percorrer 1ª lista toda usar contador por incrementacao 
    contador + 1 será o numero a dividir na media

    Percorrer cada 2ª lista de cada nodo da 1ª lista e para cada um contar as colisoes
    Somar as colisoes, tendo assim COlisoesTotais

    media = ColisoesTotais / contador + 1

*/

typedef struct _listCollisions
{
    int value;
    struct _listCollisions *next;
} ListCollisions;

typedef struct _hashTable{
    ListCollisions *lista;
    struct _hashTable *next;
} HashTable;

double mediaColisoes(HashTable* hash){
    int counter1 = 0, counter2, colisoesTotais = 0;

    for(HashTable* aux = hash; aux; aux = aux->next){
        counter1++;

        if(aux->lista->next != NULL){
            counter2 = 0;
            for(ListCollisions* aux2 = hash->lista; aux2; aux2 = aux->next){
                counter2++;
            }

            //primeiro nodo nao é colisao
            colisoesTotais += (counter2 - 1);
        }
    }

    // counter + 1 é o numero de nodos da Hash
    return ((double)colisoesTotais / (counter1 + 1));
}