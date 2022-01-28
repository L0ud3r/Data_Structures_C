// Code made by Duarte Melo
#include <stdio.h>
#include <stdlib.h>

// Estrutura de Dados que contém uma lista
typedef struct _List
{
    int value;
    struct _List *next;
} List;

// Inserir nodo na cabeça da lista (1º nodo)
List *head_insert(List *lst, int value)
{
    // Alocar memoria para nodo
    List *tmp = (List *)malloc(sizeof(List));

    // Inserir valores a guardar
    tmp->value = value;
    // Novo nodo aponta para início da lista
    tmp->next = lst;

    // Retornar o tmp, pois este agora é o início da lista
    return tmp;
}

// Inserir nodo na cauda da lista (último nodo)
List *tail_insert(List *lst, int value)
{
    // Criação de uma lista auxiliar (aux), com o fim de percorrer a mesma sem modificar o apontador da original
    List *aux = lst;

    // Alocar memória no novo nodo 
    List *tmp = (List *)malloc(sizeof(List));
    // Guardar os dados no nodo
    tmp->value = value;
    // Next do nodo = NULL, pois este será o último nodo da lista
    tmp->next = NULL;

    // Caso a lista esteja vazia
    if (!aux)
    {
        lst = tmp;
        return lst;
    }

    // No caso de não estar, percorrer a lista até ao fim
    while (aux->next)
    {
        aux = aux->next;
    }

    // No fim, colocar o novo nodo, sendo este agora o último nodo da lista
    aux->next = tmp;

    // Retornar lista inteira que não foi manipulada pois esta ainda aponta para o início
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

    // Se o nodo a remover for o primeiro membro da lista
    if (aux && aux->value == value)
    {
        lst = lst->next;
        free(aux);
    }
    // Caso não seja o primeiro nodo da lista
    else if (aux)
    {
        // Percorrer a lista
        while (aux->next)
        {
            // Caso o próximo seja o nodo pretendido a remover
            if (aux->next->value == value)
            {
                // Algoritmo de substituição de valores 
                List *aux2 = aux->next;
                aux->next = aux2->next;
                free(aux2);
            }
            aux = aux->next;
        }
    }

    // Retornar lista inicial, com nodo removido
    return lst;
}

/**
 * @brief Remover todos os nodos de uma lista
 * 
 * @param lst 
 */
void free_all(List *lst)
{
    List *aux;

    // Percorrer lista inteira, enquanto esta existir, em cada iteração lista toda o valor de aux
    for (; lst; lst = aux)
    {
        aux = lst->next;
        free(lst);
    }
}

/**
 * @brief Percorrertodos os nodos de uma lista de forma iterativa
 * 
 * @param lst 
 */
void visit_list(List *lst)
{
    List *aux;
    for (aux = lst; aux; aux = aux->next)
    {
        printf("%d\n", aux->value);
    }
}

/**
 * @brief Percorrer todos os nodos de uma lista de forma iterativa
 * 
 * @param lst 
 */
void visit_list_recursive(List *lst)
{
    if (lst)
    {
        printf("%d\n", lst->value);
        visit_list_recursive(lst->next);
    }
}

/**
 * @brief Inserção de um nodo por ordem, neste caso pela ordem crescente do valor de lst->value 
 * 
 * @param lst 
 * @param value 
 * @return List* 
 */
List* sorted_insert(List *lst, int value){
    // Criação de novo nodo e atribuição de um valor em value do mesmo
    List* new = (List*) malloc(sizeof(List));
    new->value = value;

    // Caso a lista esteja vazia ou o value do novo nodo seja menor que o primeiro nodo
    if(!lst || new->value < lst->value){
        // new passa a ser a cabeça da lista
        new->next = lst;
        // Indicar que a lista tem uma nova cabeça (new)
        lst = new;
    }
    // Caso a lista tenha nodos e o value seja maior que o value do primeiro nodo
    else {
        // Lista auxiliar para ser percorrida
        List *aux = lst;
        // Percorrer lista aux até chegar ao último nodo ou até achar um nodo em que o seu value seja maior que o value de new
        while(aux->next && new->value > aux->next->value)
            aux = aux->next;
        // Manipulação de apontadores para inserir o new no meio da lista
        new->next = aux->next;
        aux->next = new;
    }

    // Retornar lista original modificada
    return lst;
}

/**
 * @brief Função que inverte uma lista
 * 
 * @param list 
 * @return List* 
 */
List* invert_list(List* list){
    // Criação de uma nova lista
    List* inverted_list = NULL;

    // Enquanto houver lista, pegar no valor atual e inserir à cabeça da lista nova
    while (list)
    {
        inverted_list = head_insert(inverted_list, list->value);
        list = list->next;
    }

    // Libertar antiga lista, se for pretentido
    // free_all(list);
    
    return inverted_list;
}


int main()
{
    List *list = NULL;

    // Inserção de valores teste
    list = sorted_insert(list, 50);
    list = sorted_insert(list, 35);
    list = sorted_insert(list, 10);
    list = sorted_insert(list, 20);
    list = sorted_insert(list, 20);
    list = sorted_insert(list, 50);

    // Remoção de um nodo
    list = list_remove(list, 20);

    // Percorrer lista
    visit_list(list);
    //visit_list_recursive(list);

    // Inverter Lista
    List* aux = NULL;
    list = invert_list(list);

    printf("\n\n --------------Inverted list --------------\n\n");
    visit_list(list);

    // Libertar lista (Remoção de todos os nodos)
    free_all(list);

    return 0;
}
