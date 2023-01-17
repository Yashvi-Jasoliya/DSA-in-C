#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularQueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q)
{
    if ((q->r+1)%q->size == q->f)
    {
        return 1;
    }
    return 0;
}


void enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is Full");
    }
    else
    {
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Enqued Element: %d\n", val);
    }
}

int dequeue(struct circularQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is Empty");
    }
    else
    {
        q->f = (q->f+1)%q->size; 
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct circularQueue q;
    q.size = 8;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    //  if (isEmpty(&q))
    // {
    //     printf("Queue is empty...\n");
    // }
    // if(isFull(&q))
    // {
    //     printf("Queue is full...\n");
    // }

    // Enquue Few elements...........

    enqueue(&q, 22); // FIFO...........
    enqueue(&q, 15);
    enqueue(&q, 52);
    enqueue(&q, 45);

    printf("\nDequeueing element: %d\n", dequeue(&q));
    printf("Dequeueing element: %d\n", dequeue(&q));

    
    return 0;
}