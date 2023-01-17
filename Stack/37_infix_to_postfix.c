#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};
int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

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

int precedence(char ch){
    if(ch == '*' || ch == '/'){
        return 3;                      // High precedence
    }
    else if(ch == '+' || ch == '-'){
        return 2;                        // low precedence
    }
    else{
        return 0;
    }
}

int isOperator(char ch){                         
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return 1;
    }
    else{
        return 0;
    }
}

char *infixTopostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Track infix traversal...
    int j = 0; // Track postfix addition..
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {                          // infix:  |a|*|b|-|c|/|d|\0|
            postfix[j] = infix[i]; // postfix: | | | | | |
            j++;
            i++;
        }
        else
        {
            if(precedence(infix[i])>precedence(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;

            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;         // dout....
}


int main()
{
    char *infix = "x-y/z-k*d";
    printf("Infix to postfix is : %s",infixTopostfix(infix));

    return 0;
}