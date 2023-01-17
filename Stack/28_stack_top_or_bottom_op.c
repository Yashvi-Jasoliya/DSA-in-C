#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        //  printf("Stack is full/overflow");
        return -1;
    }
    else
    {
        //  printf("Stack is not full/overflow");
        return 0;
    }
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        //  printf("Stack is empty/Underflow");
        return -1;
    }
    else
    {
        //  printf("Stack is not empty/overflow");
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("\n--> Stack Overflow... can't push %d in the stack....\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("\n--> Stack Underflow... can't  pop from the stack....\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *sp, int i) // T.C -> O(1)....
{
    int arrayInd = sp->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not Valid position:\n");
        return -1;
    }
    else
    {
        return sp->arr[arrayInd];
    }
}

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int stackBottom(struct stack *sp)
{
    return sp->arr[0];
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 15;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("--> stack created successfully...\n");
    // printf("Before push:\n");
    // printf("For Full: %d\n", isFull(sp));
    // printf("For Empty: %d\n", isEmpty(sp));

    push(sp, 41);
    push(sp, 36);
    push(sp, 47);
    push(sp, 89);
    push(sp, 44);
    push(sp, 48);
    push(sp, 10);
    push(sp, 78);
    push(sp, 50);
    push(sp, 75);
    push(sp, 45);
    push(sp, 45);
    push(sp, 55);

    // printf("After push:\n");
    // printf("For Full: %d\n", isFull(sp));
    // printf("For Empty: %d\n\n", isEmpty(sp));

    // printf("\n--> popped %d from the stack...\n", pop(sp));
    // printf("--> popped %d from the stack...\n\n", pop(sp)); // Last in first out!(LIFO).....

    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value %d at position: %d\n", peek(sp, j), j); // ASs per LIFO output......
    }

    printf("\nThe Top most value of stack is : %d\n", stackTop(sp));
    printf("The Bottom most value of stack is : %d\n", stackBottom(sp));

    return 0;
}