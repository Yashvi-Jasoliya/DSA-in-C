#include <stdio.h>
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
// case 1 : deletion at begining in linkedlist.....
struct Node *deleteAtFirst(struct Node *head)
{

    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// case 2 : deletion at between in linked list.....
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// case 3 : deletion at ending in linked list.....
struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// case 4 : deletion at with a given value in linked list.....
struct Node *deleteAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
   while (q->data != value && q->next != NULL)
   
    {
        p = p->next;
        q = q->next;
    }
   if(q->data == value){

    p->next = q->next;
    free(q);
   }
    return head;
}
int main()
{
    // int index;
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
    head->data = 37;
    head->next = second;

    // link second and third nodes
    second->data = 61;
    second->next = third;

    // link third and fourth nodes
    third->data = 78;
    third->next = fourth;

    // link fourth nodes
    fourth->data = 44;
    fourth->next = NULL;

    printf("Before deleting the Linked list:\n");
    linkedListTraversal(head);

    // head = deleteAtFirst(head);
    // head = deleteAtFirst(head); // 2 var call krvathi first 2 or 1 element remove thase............
    // printf("Enter index no. whose element want you delete\n");
    // scanf("%d", &index);
    head = deleteAtIndex(head, 2);
    // head = deleteAtEnd(head);
    // head = deleteAtValue(head, 61);

    printf("\nAfter deleting the Linked list:\n");
    linkedListTraversal(head);

    return 0;
}