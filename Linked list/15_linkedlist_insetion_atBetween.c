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
// case1 :insertion at begining
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

//case 3: insert at end
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    // ptr->next = head;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->data = data;
    return head;
}

// case 4: insert at after node
struct Node *insertAfterNode(struct Node *head, struct Node *preNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = preNode->next;
    preNode->next = ptr;
    return head;
}



// case 2: insertion at between
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
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

    printf("Before insert the Linked list:\n");
    linkedListTraversal(head);

    // head = insertAtFirst(head, 45);
    head = insertAtIndex(head, 45, 3);
    // head = insertAtEnd(head, 45);
    // head = insertAfterNode(head, second, 100);

    printf("\nAfter insert the Linked list:\n");
    linkedListTraversal(head);

    return 0;
}
