#include <stdio.h>

typedef struct _btree{
    int value;
    struct _btree *left, *right;
} BTree;

int arvoreProfundidade(BTree *root, int v){
    int counter = 0;

    while(root){
        if(v < root->value){
            counter++;
            root = root->left;
        }
            
        else if(v > root->value){
            counter++;
            root = root->right;
        }
        else 
            //A contador com a raiz
            return counter + 1;
    }

    return -1;
}

int arvoreProfundidadeRec(BTree *root, int v, int counter){
    BTree* aux = root;

    if(aux){
        if(v < aux->value){
            return arvoreProfundidade(aux->left, v, ++counter);
        }
            
        else if(v > aux->value){
            return arvoreProfundidade(aux->right, v, ++counter);
        }
        else 
            //A contador com a raiz
            return counter + 1;
    }

    return -1;
}