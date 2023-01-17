#include<stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node*)malloc (sizeof(struct Node));
    ptr->next = head;
    ptr->data = data; 
    head = ptr;   // OR
    // return ptr;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

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

    printf("Before insert the head:\n");
    linkedListTraversal(head);

    head = insertAtFirst(head, 45);
    printf("\nAfter insert the head:\n");
    linkedListTraversal(head);

    return 0;
}
