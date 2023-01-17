#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void linkedListTraversalReverse(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    // struct Node *ptr;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node)); // dout size of agal size nthi........

    // link first and second nodes
    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 11;
    second->next = third;

    // link third and fourth nodes
    third->data = 88;
    third->next = fourth;

    // link fourth nodes
    fourth->data = 69;
    fourth->next = NULL;

    printf("Traversal:\n");
    linkedListTraversal(head);

    // link first and second nodes
    head->prev = NULL;
    head->data = 69;
    // head->prev = NULL;

    // link second and third nodes
    second->prev = head;
    second->data = 88;
    // second->prev = head;

    // link third and fourth nodes
    third->prev = second;
    third->data = 11;
    // third->prev = second;

    // link fourth nodes
    fourth->prev = third;
    fourth->data = 7;
   
    // fourth->prev= second;

    printf("reverse :\n");
    linkedListTraversalReverse(head);

    return 0;
}