#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
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

int push(struct stack *ptr, char val) // T.C -> O(1)....
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

char pop(struct stack *ptr) // T.C -> O(1)...
{
    if (isEmpty(ptr))
    {
        printf("\n--> Stack Underflow... can't  pop from the stack....\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        //    ptr->top = ptr->top-1;  OR-...
        ptr->top--;
        return val;
    }
}

int paranthesisMatch(char *exp)
{
    // Create an initialize the stack....
    struct stack *sp;
    sp->size = 150;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)      //    |(|5|*|9|*|8|)|)|\0|
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp))
    {
        // printf("empty..");
        return 1;        // dout....
    }
    else
    {
        // printf("success..");
        return 0;
    }
}

int main()
{
    char * exp = "123";

   if(paranthesisMatch(exp)){
    printf("The paranthesis is matching..\n");
   }
   else{
    printf("The paranthesis is not matching..\n");
   }
    return 0;
}