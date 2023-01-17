#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer...
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap...
    n->data = data;                                 // setting the data...
    n->left = NULL;                                 // setting the left and right children to NULL...
    n->right = NULL;
    return n; // retrning the created node...
}

int main()
{
    /*
    // Constructing the root node......
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = 8;
    p->left = NULL;
    p->right = NULL;

    // Constructing the second node.......
    struct node *p1;
    p1 = (struct node *)malloc(sizeof(struct node));
    p->data = 5;
    p1->left = NULL;
    p1->right = NULL;

    // Constructing the third node.......
    struct node *p2;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = 2;
    p2->left = NULL;
    p2->right = NULL;

    // Linking the root node with left and right children.....
    p->left = p1;
    p->right = p2;
*/

    // Constructing the root node with left and right children......
     printf("<-- Tree -->");
    struct node *p = createNode(8);  
    struct node *p1 = createNode(5);
    struct node *p2 = createNode(2);

    p->left = p1;
    p->right = p2;
    printf("\n--> The root of Tree is = %d\n", *p);
    printf("--> left child of the root is = %d\n",*p1);
    printf("--> right child of the root is = %d",*p2);
    return 0;
}