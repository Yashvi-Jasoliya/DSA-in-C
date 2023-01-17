#include <stdio.h>
#include <stdlib.h>

struct queue // Explain in paint slide...
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is Full");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;

        // printf(" Element : ");
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is Empty");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }

    return a;
}

int main()
{
    struct queue q;
    q.size = 10;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // BFS Implimentation..........
    int node, j = 0;
    int i = 0;
    int visited[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int a[8][8] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}, 
        {0, 0, 1, 0, 0, 0, 0},
    };
    printf("BFS elements :- ");
    printf("%d, ", i);
    visited[i] = 1;
    enqueue(&q, i); // For Exploration....

    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d, ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    return 0;
}