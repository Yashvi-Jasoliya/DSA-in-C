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



int main()
{
    // struct stack *s;
    // s.size = 100;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    struct stack *sp; 
    sp->size = 100;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    // Pushing an element manually....
    sp->arr[0] = 7;            // |7|8|........
    sp->top++;

    sp->arr[1] = 8; 
    sp->top++;
    
    // Check if stack is empty....
    if (isEmpty(sp))
    {
        printf("The stack is empty...");
    }
    else
    {
        printf("The stack is not empty...");
    }
   
    return 0;
}