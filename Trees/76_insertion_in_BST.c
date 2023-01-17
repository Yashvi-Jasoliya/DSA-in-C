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
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
        // printf("%d, ", root->data);
    }
}

void postOrder(struct node *root)
{

    if (root != NULL)
    {
        // printf("%d, ", root->data);
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node *root)
{

    if (root != NULL)
    {
        // printf("%d, ", root->data);
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            isBST(root->left);
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node *searchIter(struct node *root, int key)
{
    while (root != NULL)       // iterative means use loop ...
    {

        if (key == root->data)
        {
            return root;
        }
        if (key < root->data)
        {
            root = root-> right;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

int main()
{

    // Constructing the root node using functions(Recommended)

    struct node *p = createNode(3);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);
    struct node *p3 = createNode(0);
    struct node *p4 = createNode(2);

    // Linking the root node with left and right children.....
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    //                  3
    //                /   \           left lesser...
    //               1     4          right higher....
    //              /  \              inorder :[0 1 2] 3 4 also say ascending order
    //             0    2

   Insert(p, 10);

    return 0;
}