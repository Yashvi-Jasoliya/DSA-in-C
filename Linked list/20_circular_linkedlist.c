#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    printf("Circular linked list Elements :\n");
    do
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data; // dout
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point p is at last Node in CL......

    p->next = ptr;
    ptr->next = head;
    head = ptr;
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
    head->data = 45;
    head->next = second;

    // link second and third nodes
    second->data = 23;
    second->next = third;

    // link third and fourth nodes
    third->data = 63;
    third->next = fourth;

    // link fourth nodes
    fourth->data = 12;
    fourth->next = head;
    printf("Before inserting the Linked list:\n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 50);
    head = insertAtFirst(head, 75);
    printf("\nAfter inserting the Linked list:\n");
    linkedListTraversal(head);

    return 0;
}