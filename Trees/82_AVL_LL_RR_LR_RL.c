#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getHeight(struct Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

struct Node *createNode(int key){
    struct Node* node =  (struct Node *)malloc(sizeof( struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

int getBalanceFactor(struct Node * n){
    if(n==NULL){
        return 0;
    }
}
