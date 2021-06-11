#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _List
{
    int value;
    struct _List *next;
} List;

List *tail_insert(List *lst, int value)
{

    List *aux = lst;

    List *tmp = (List *)malloc(sizeof(List));
    tmp->value = value;
    tmp->next = NULL;

    if (!aux)
    {
        lst = tmp;
        return lst;
    }

    while (aux->next)
    {
        aux = aux->next;
    }
    aux->next = tmp;

    return lst;
}

List *apenas_index_par(List *lst){
    List *new_List = NULL;

    List *aux = lst;
    int contador = 1;
    while (aux){
        if(contador % 2 == 0){
            new_List = tail_insert(new_List, aux->value);
        }
        contador++;
        aux = aux->next;
    }


    return new_List;

}



List *list_remove(List *lst, int value)
{
    List *aux = lst;

    if (aux && aux->value == value)
    {
        lst = lst->next;
        free(aux);
    }
    else if (aux)
    {
        while (aux->next)
        {

            if (aux->next->value == value)
            {
                List *aux2 = aux->next;
                aux->next = aux2->next;
                free(aux2);
                
            }
            aux = aux->next;
        }
    }

    return lst;
}

List *maior_no_fim(List *lst){
    List *aux = lst;
    int maior = 0;
    if(!aux){
        return aux;
    }
    else {
        
        while (aux){
            if(aux->value > maior){
                maior = aux-> value;
            }
            aux = aux->next;
        }
        list_remove(lst, maior);
        tail_insert(lst, maior);

    }

    return lst;

    

    
}



void visit_list(List *lst)
{
    List *aux;
    for (aux = lst; aux; aux = aux->next)
    {
        printf("%d\n", aux->value);
    }
}






int main()
{
    List *list = NULL;
    list = tail_insert(list, 20);
    list = tail_insert(list, 40);
    list = tail_insert(list, 60);
    list = tail_insert(list, 80);
    list = tail_insert(list, 100);
    list = tail_insert(list, 120);
    list = tail_insert(list, 140);
    list = tail_insert(list, 180);
    list = tail_insert(list, 200);

    //List *list2 = apenas_index_par(list);

    //list = maior_no_fim(list);
    visit_list(list);
    printf("---\n");

    

    List *list2 = NULL;
    list2 = apenas_index_par(list);
    visit_list(list2);



    
    return 0;
}
