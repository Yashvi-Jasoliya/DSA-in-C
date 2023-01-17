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
    while (root != NULL) // iterative means use loop ...
    {

        if (key == root->data)
        {
            return root;
        }
        if (key < root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("can't insert %d element, it is repeated....", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
    if (key < prev->data)
    {
        printf("New node created left side....");
    }
    else
    {
        printf("New node created right side...");
    }
}

struct Node * inorderpredecessor( struct node *root){
    root = root->left;
    while(root->right!=NULL){
        root= root->right;
    }
    return root;
}

struct Node *deleteNode(struct node *root, int val)
{
    struct node* ipre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    // Search for the node to be deleted...
    if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data)
    {
       root->right = deleteNode(root->right, val);
    }
    // Deletion strategy when the node is found...
    else{
        ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left = deleteNode(root->left, ipre->data);
    }
 return root;
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
    //                /   \           
    //               1     4
    //              /  \              
    //             0    2

    inOrder(p);
    deleteNode(p, 1);     //dout...
    printf("\n");
    printf("Data is %d", p->data);
    printf("\n");
    inOrder(p);
    return 0;
}