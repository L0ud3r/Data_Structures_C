#include <stdio.h>

typedef struct _btree{
    char* nome, *apelido;
    int idade;
    struct _btree *left, *right;
} BTree;

BTree* insert_by_name(BTree* root, char* nome, char* apelido, int idade){
    if(root){
        if(strcmp(nome, root->nome) < 0)
            root->left = btree_insert(root->left, nome, apelido, idade );
        if(strcmp(nome, root->nome) > 0)
            root->right = btree_insert(root->right, nome, apelido, idade);
        else{
            if(strcmp(apelido, root->apelido) < 0)
                root->left = btree_insert(root->left, nome, apelido, idade );
            if(strcmp(apelido, root->apelido) > 0)
                root->right = btree_insert(root->right, nome, apelido, idade);
        }
    }
    else{
        root = btree_new_node(nome, apelido, idade);
    }

    return root;
} 