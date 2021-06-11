#include <stdio.h>
#include <stdlib.h>



typedef struct _List
{
    int value;
    struct _List *next;
} List;

List *head_insert(List *lst, int value)
{

    List *tmp = (List *)malloc(sizeof(List));

    tmp->value = value;
    tmp->next = lst;

    return tmp;
}



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

/**
 * @brief Remover primeira ocorrencia!
 * 
 * @param lst 
 * @param value 
 * @return List* 
 */
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

void free_all(List *lst)
{
    List *aux;
    for (; lst; lst = aux)
    {
        aux = lst->next;
        free(lst);
    }
}

void visit_list(List *lst)
{
    List *aux;
    for (aux = lst; aux; aux = aux->next)
    {
        printf("%d\n", aux->value);
    }
}

void visit_list_recursive(List *lst)
{
    if (lst)
    {
        printf("%d\n", lst->value);
        visit_list_recursive(lst->next);
    }
}

List* sorted_insert(List *lst, int value){
    List* new = (List*) malloc(sizeof(List));
    new->value = value;

    if(!lst || new->value < lst->value){
        new->next = lst;
        lst = new;
    }
    else {
        List *aux = lst;
        while(aux->next && new->value > aux->next->value)
            aux = aux->next;
        new->next = aux->next;
        aux->next = new;
    }
    return lst;
}

int main()
{
    List *list = NULL;

    list = sorted_insert(list, 50);
    list = sorted_insert(list, 35);
    list = sorted_insert(list, 10);
    list = sorted_insert(list, 20);
    list = sorted_insert(list, 20);
    list = sorted_insert(list, 50);

    list = list_remove(list, 20);

    visit_list(list);

    free_all(list);

    

    //visit_list_recursive(list);

    return 0;
}
