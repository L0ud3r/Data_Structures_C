typedef struct _btree{
    int value;
    struct _btree *left, *right;
} BTree;

//Counter tem de comerçar em 1 ==> int quantosNodosRemovidos = freeBTree(root, 1);
int freeBTree(BTree* root, int counter){
    if(root){
        counter++;
        counter = btree_free(root->left, counter);
        counter = btree_free(root->right, counter);

        //free aos dados necessarios
        free(root);
    }

    return counter;
}

