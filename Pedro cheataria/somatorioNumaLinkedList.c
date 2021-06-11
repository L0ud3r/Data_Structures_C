#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <math.h>

#pragma region Resolucao Legion

typedef struct _cell {
    int value;
    struct _cell* next;
} Cell;

typedef struct _list {
    Cell* first;
    Cell* last;
} List;


List* new_list() {
    List* list = (List*) malloc(sizeof(List));
    assert(list);

    list->first = list->last = NULL;
    return list;
}

Cell* new_cell(int n) {
    Cell* c = (Cell*) malloc(sizeof(Cell));
    assert(c);

    c->value = n;
    c->next = NULL;
    return c;
}


void insert(List *list, Cell* newCell) {  
    assert(newCell);
    if (list->first) {
        list->last->next = newCell;
    }
    else {
        list->first = newCell;
    }
    list->last = newCell;
}

void * Soma(List *list, List *lst) {  
    int i = 0;

    Cell *ptr = list->first;

    while(ptr){
        Cell *aux = list->first;
        int x = ptr->value;
        int tmp = ptr->value;
        while(aux)
        {
            if( i > 0 && x>aux->value){
                tmp = tmp + aux->value;
            }
            aux = aux->next;  
        }

        insert(lst, new_cell(tmp));

        ptr = ptr->next;
        i++;
    }
}
#pragma endregion