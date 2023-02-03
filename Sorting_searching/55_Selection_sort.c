#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n)
{
    int indexOfmin, temp;
    printf("Running After Selection sort... \n");
    for (int i = 0; i < n - 1; i++)
    {
        indexOfmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfmin])
            {
                indexOfmin = j;
            }
        }
        //  Swap A[i] and A[indexOfmin] ...
        temp = A[i];
        A[i] = A[indexOfmin];
        A[indexOfmin] = temp;
    }
}

int main()
{
    //    0   1   2   3   4   (There will be total n-1 passes,5-1= 4 in this case..)
    //   |10, 50, 60, 40, 20

    //  After the first pass..
    //   10, |50, 60, 40, 20

    //  After the second pass..
    //   10, 20, |60, 40, 50

    //  After the third pass..
    //   10, 20, 40, |60, 50

    //  After the third pass..
    //   10, 20, 40, 50, |60

    int A[] = {10, 50, 60, 40, 20};
    int n = 5;

    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);

    return 0;
}