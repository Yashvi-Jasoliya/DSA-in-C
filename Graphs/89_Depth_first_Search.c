#include <stdio.h>
#include <stdlib.h>

int visited[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int A[8][8] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0}};

void DFS(int i)
{
    int j;
    printf("%d, ", i);
    visited[i] = 1;
    for (j = 0; j < 8; j++)
    {
        if (A[i][j] == 1 && !visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    int i = 0;
    // DFS Implimentation..........
    
    printf("Enter the num which node through you be start DFS: \n");
    scanf("%d", &i);
    // DFS(2);
    printf("Depth First Search : \n");
    DFS(i);

    return 0;
}