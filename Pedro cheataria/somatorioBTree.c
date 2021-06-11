#include <stdio.h>

typedef struct _btree{
    int value;
    struct _btree *left, *right;
} BTree;

void convertTree(BTree *b){
  int left_sum = 0, right_sum = 0, diff;


    if(b == NULL || (b->left == NULL && b->right == NULL))
        return;
    else {
        convertTree(b->left);
        convertTree(b->right);

        if(b->left != NULL)
        left_sum = b->left->value;

        if(b->right != NULL)
        right_sum = b->right->value;

        b->value = left_sum + right_sum + b->value;
    }
}