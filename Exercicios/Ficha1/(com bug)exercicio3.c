/*FILE:
fjdkjfdlsjf34567890fjksdhfkjsdhfkjsdhfkjhsdkjfhsdkjhfkdshfkjsdfkjhsdjkfhsdkjfksdhfksdAntonio	18.4
Antonio	18.4
Antonieta	14.3
Bruno	9.3
Catarina	19.2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct _list
{
    char *nome;
    float nota;
    struct _list *next;
} List;

List *head_insert_linked_list(List* list, List* data){
    printf("--------------.\nNome: %s\nNota: %.2f\n", data->nome, data->nota);
    data->next = list;
    
    return data;
}

List *ler_ficheiro(List* list, char *s){
    FILE *ptr = fopen(s, "r");

    List *aux = malloc(sizeof(List));
    aux->nome = malloc(50);

    while(!feof(ptr)){
        fscanf(ptr, "\n%[^\t]%f\n", aux->nome, &aux->nota);
        list = head_insert_linked_list(list, aux);
    }

    free(aux);
    return list;
}

void mostrar_alunos(List* list){
    printf("Lista de alunos e as suas notas:\n");
    for(List* aux = list; aux; aux = aux->next){
        printf("--------------.\nNome: %s\nNota: %.2f\n", aux->nome, aux->nota);
    }
    printf("--------------\n");
}

int main(){
    List *list = NULL;
    list = ler_ficheiro(list, "alunos.tsv");
    
    mostrar_alunos(list);

    return 0;
}