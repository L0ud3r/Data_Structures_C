#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _BTree
{
    char* nome;
    int idade, key, id;

    struct _BTree *left, *right;
} BTreePessoas;

BTreePessoas *btree_new_node(char* nome, int idade, int id, int chave){
    BTreePessoas *aux = malloc(sizeof(BTreePessoas));

    aux->nome = strdup(nome);
    aux->idade = idade;
    aux->id = id;
    aux->key = chave;

    aux->left = aux->right = NULL;

    return aux;
}

BTreePessoas *btree_insert(BTreePessoas *root, char* nome, int idade, int id, int value){
    if(root){
        if(value < root->key)
            root->left = btree_insert(root->left, nome, idade ,id, value);
        if(value > root->key)
            root->right = btree_insert(root->right, nome, idade, id, value);
    }
    else{
        root = btree_new_node(nome, idade, id, value);
    }

    return root;
}

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

void btree_inorder(BTreePessoas* root){
    if(root){
        btree_inorder(root->left);
        printf("%s\n", root->nome);
        btree_inorder(root->right);
    }
}

void btree_preorder(BTreePessoas* root){
    if(root){
        printf("%s\n", root->nome);
        btree_preorder(root->left);
        btree_preorder(root->right);
    }
}

void btree_postorder(BTreePessoas* root){
    if(root){
        btree_postorder(root->left);
        btree_postorder(root->right);
        printf("%s\n", root->nome);
    }
}

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

/**
 * @brief TO DO
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

int main(){
    BTreePessoas *pessoas = NULL;

    pessoas = btree_insert(pessoas, "Pedro", 20, 123, 20);
    pessoas = btree_insert(pessoas, "Maria", 16, 235, 30);
    pessoas = btree_insert(pessoas, "Andre", 43, 323, 10);

    btree_inorder(pessoas);

    return 0;
}