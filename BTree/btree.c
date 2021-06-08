#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
typedef struct _Pessoa
{
    char* nome;
    int idade, key, id;
} Pessoa;

typedef struct _BTree
{
    Pessoa p;
    struct _BTree *left, *right;
} BTree;
*/

typedef struct _BTree
{
    char* nome;
    int idade, key, id;

    struct _BTree *left, *right;
} BTreePessoas;

/**
 * @brief Criar nodo de arvore
 * 
 * @param nome 
 * @param idade 
 * @param id 
 * @param chave 
 * @return BTreePessoas* 
 */
BTreePessoas *btree_new_node(char* nome, int idade, int id, int chave){
    BTreePessoas *aux = malloc(sizeof(BTreePessoas));

    aux->nome = strdup(nome);
    aux->idade = idade;
    aux->id = id;
    aux->key = chave;

    aux->left = aux->right = NULL;

    return aux;
}

/**
 * @brief Inserir nodo em arvore
 * 
 * @param root 
 * @param nome 
 * @param idade 
 * @param id 
 * @param value 
 * @return BTreePessoas* 
 */
BTreePessoas *btree_insert(BTreePessoas *root, char* nome, int idade, int id, int value){
    if(root){
        if(value < root->key)
            root->left = btree_insert(root->left, nome, idade , id, value);
        if(value > root->key)
            root->right = btree_insert(root->right, nome, idade, id, value);
    }
    else{
        root = btree_new_node(nome, idade, id, value);
    }

    return root;
}

/**
 * @brief Procura nodo especifico na arvore pela chave
 * 
 * @param root 
 * @param key 
 * @return BTreePessoas* 
 */
BTreePessoas *btree_search(BTreePessoas *root, int key){
    if(root){
        if(key < root->key)
            return btree_search(root->left, key);
        else if(key > root->key)
            return btree_search(root->right, key);
        else 
            return root;
    }
    else 
        return NULL;
}

#pragma region ListagensOrdenadas(Travessias)

/**
 * @brief Mostra arvore por ordem de chaves
 * 
 * @param root 
 */
void btree_inorder(BTreePessoas* root){
    if(root){
        btree_inorder(root->left);
        printf("%s\n", root->nome);
        btree_inorder(root->right);
    }
}

/**
 * @brief Mostra arvore a começar pelo primeiro nodo, depois lado esquerdo, depois direito
 * de cima para baixo
 * 
 * @param root 
 */
void btree_preorder(BTreePessoas* root){
    if(root){
        printf("%s\n", root->nome);
        btree_preorder(root->left);
        btree_preorder(root->right);
    }
}

/**
 * @brief Mostra arvore a começar pelo lado esquerdo, depois direito, depois o primeiro nodo
 * de baixo para cima
 * 
 * @param root 
 */
void btree_postorder(BTreePessoas* root){
    if(root){
        btree_postorder(root->left);
        btree_postorder(root->right);
        printf("%s\n", root->nome);
    }
}

#pragma endregion

/**
 * @brief Devolve tamanho da arvore
 * 
 * @param root 
 * @return int 
 */
int btree_size(BTreePessoas* root){
    if(root){
        int tamEsq, tamDir;
        tamEsq = btree_size(root->left);
        tamDir = btree_size(root->right);
        return 1 + tamEsq + tamDir;
    }
    else
        return 0;
}

//TO DO
/**
 * @brief Remove certo nodo da arvore
 * 
 * @param root 
 * @param key 
 * @return BTreePessoas* 
 */
BTreePessoas *btree_remove(BTreePessoas* root, int key){
    if(root){
        if(key < root->key)
            root->left = btree_remove(root->left, key);
        else if(key > root->key)
            root->right = btree_remove(root->right, key);
        else 
            return root;
    }
    else if(root->left == NULL)
    {
        BTreePessoas *sTree = root->right;
        free(root);
        root = sTree;
    }
    else if(root->right == NULL)
    {
        BTreePessoas *sTree = root->left;
        free(root);
        root = sTree;
    }
    else
    {
        //To do
    }
}

//Funcao teste para mostrar 1 pessoa (nodo)
void Show(BTreePessoas* root){
    printf("%s\n", root->nome);
}

int main(){
    BTreePessoas *pessoas = NULL, *aux = NULL;


    pessoas = btree_insert(pessoas, "Pedro", 20, 123, 20);
    pessoas = btree_insert(pessoas, "Maria", 16, 235, 30);
    pessoas = btree_insert(pessoas, "Andre", 43, 323, 10);
    pessoas = btree_insert(pessoas, "Jose", 43, 323, 12);
    pessoas = btree_insert(pessoas, "Sett", 43, 323, 132);
    pessoas = btree_insert(pessoas, "Jorge", 43, 323, 14);
    pessoas = btree_insert(pessoas, "Ni", 43, 323, 45);

    /*
    Show(pessoas);
    Show(pessoas->left);
    Show(pessoas->left->right);
    Show(pessoas->left->right->right);
    Show(pessoas->right);
    Show(pessoas->right->right);
    Show(pessoas->right->right->left);
    */

    btree_preorder(pessoas);

    return 0;
}