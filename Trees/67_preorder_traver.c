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

void preOrder(struct node *root)
{

    if (root != NULL)
    {
        printf("%d, ", root->data);
        preOrder(root->left);
        preOrder(root->right);
        // printf("%d, ", root->data);
    }
}

int main()
{

    // Constructing the root node using functions(Recommended)

    struct node *p = createNode(3);
    struct node *p1 = createNode(4);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(2);
    struct node *p4 = createNode(1); // According to preorder..

    // Linking the root node with left and right children.....
    p->left = p1;
    p->right = p4;
    p1->left = p2;
    p1->right = p3;

    //     Tree looks Like:
    //                  3
    //                /   \           3 [4 6 2] 1 -> preorder
    //               4     1
    //              /  \
    //             6    2
    printf("According to Preorder Tree :\n");
    preOrder(p);
    return 0;
}