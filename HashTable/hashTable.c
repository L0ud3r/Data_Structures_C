#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 2

typedef struct _pessoa
{
    char* nome;
    int idade;
    struct _pessoa *next, *prev;
} Pessoa;

typedef struct _Hash{
    Pessoa **lista;
    int size;
} Hash;

Hash* create_hash(int size){
    //Alloca memoria para hash
    Hash* hash = malloc(sizeof(hash));

    hash->size = M;
    //A cada nodo da hash alocado, aloca memoria para uma lista de pessoas ATENÇAO:sizeof(Pessoa*) <-- apontador
    hash->lista = calloc(size, sizeof(Pessoa*));

    return hash;
}

//Insere uma pessoa na lista (new->next = list; estranho)
Pessoa* insereLista(Pessoa* list, Pessoa *data){
    Pessoa *new = malloc(sizeof(Pessoa));

    new->nome = strdup(data->nome);
    new->idade = data->idade;
    new->next = list;

    return new;
}

//Funcao hash, neste caso faz numero % 2, ou seja, par ou impar
int hash_key(int value){
    return value % M;
}

//Funcao usada para guardar uma pessoa na tabela de hash, primeiro encontra a chave, depois usa-a para dizer qual lista usar para inserir
void hash_store(Hash* hash, Pessoa *data){
    int pos = hash_key(data->idade);
    hash->lista[pos] = insereLista(hash->lista[pos], data);
}

//Printa pessoas de uma lista
void pessoas_visit(Pessoa* list){
    while(list){
        printf("NOME: %s\nIDADE: %d\n\n", list->nome, list->idade);
        list = list->next;
    }
}

//Lista todas as listas
void hash_visit(Hash* hash){
    for(int i = 0;i < hash->size; i++){
        pessoas_visit(hash->lista[i]);
    }
}

int main(){
    //Criar tabela e allocar 4 pessoas
    Hash* tabelaHash = create_hash(M);
    Pessoa* pessoas = malloc(sizeof(Pessoa));
    Pessoa* pessoas2 = malloc(sizeof(Pessoa));
    Pessoa* pessoas3 = malloc(sizeof(Pessoa));
    Pessoa* pessoas4 = malloc(sizeof(Pessoa));

    //Criar pessoas
    pessoas->nome = strdup("Pedro");
    pessoas->idade = 20;

    pessoas2->nome = strdup("Andre");
    pessoas2->idade = 21;

    pessoas3->nome = strdup("Carlos");
    pessoas3->idade = 22;

    pessoas4->nome = strdup("Duarte");
    pessoas4->idade = 35;

    //Armazena-las na tabela hash
    hash_store(tabelaHash, pessoas);
    hash_store(tabelaHash, pessoas2);
    hash_store(tabelaHash, pessoas3);
    hash_store(tabelaHash, pessoas4);

    //Printa hash toda
    hash_visit(tabelaHash);

    //Prints teste
    printf("Pessoas com idades impares (indice 1 da hash)\n\n");
    pessoas_visit(tabelaHash->lista[1]);

    printf("Pessoas com idades pares (indice 0 da hash)\n\n");
    pessoas_visit(tabelaHash->lista[0]);

    return 0;
}