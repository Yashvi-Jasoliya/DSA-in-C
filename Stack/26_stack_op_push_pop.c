#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr) // T.C -> O(1)....
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

int isEmpty(struct stack *ptr) // T.C -> O(1)....
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

int push(struct stack *ptr, int val) // T.C -> O(1)....
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

int pop(struct stack *ptr) // T.C -> O(1)...
{
    if (isEmpty(ptr))
    {
        printf("\n--> Stack Underflow... can't  pop from the stack....\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        //    ptr->top = ptr->top-1;  OR-...
        ptr->top--;
        return val;
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("--> stack created successfully...\n");
    printf("Before push:\n");
    printf("For Full: %d\n", isFull(sp));
    printf("For Empty: %d\n", isEmpty(sp));

    push(sp, 41);
    push(sp, 36);
    push(sp, 47);
    push(sp, 89);
    push(sp, 44);
    push(sp, 48);
    push(sp, 10);
    push(sp, 78);
    push(sp, 50);
    push(sp, 75); // ---> pushed 10 values in stack...
    push(sp, 45); // size of stack is 10 so stack become overflow......

    printf("After push:\n");
    printf("For Full: %d\n", isFull(sp));
    printf("For Empty: %d\n", isEmpty(sp));

    printf("\n--> popped %d from the stack...\n", pop(sp));
    printf("--> popped %d from the stack...\n", pop(sp)); // Last in first out!(LIFO).....

    return 0;
}