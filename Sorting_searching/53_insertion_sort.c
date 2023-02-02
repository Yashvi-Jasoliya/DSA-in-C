#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n)
{
    int key, j;
    //  Loop for passes
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;

        // Loop for each pass..
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    // -1    0   1   2   3    4   5   6
    //      10,| 50, 40, 60, 20, 70, 30..   i=1, key=50, j=0
    //      10,| 50, 40, 60, 20, 70, 30.. --> 1st pass done (i=1)

    //      10, 50,| 40, 60, 20, 70, 30..  i= 2, key= 40, j=1
    //      10, 50,| 40, 60, 20, 70, 30..  2nd pass done (i=2)

    //      10, 40, 50,| 60, 20, 70, 30..  i=3, key = 60; j=2
    //      10, 40, 50, |60, 20, 70, 30..  3rd pass done (i=3)

    //      10, 40, 50, 60,| 20, 70, 30..  i=4, key = 20; j=3
    //      10, 40, 50, 60,| 20, 70, 30..  4th pass done (i=4)

    //      10, 20, 40, 50, 60,| 70, 30..  i=5, key = 70; j=4
    //      10, 20, 40, 50, 60,| 70, 30..  5th pass done (i=5)

    //      10, 20, 40, 50, 60, 70,|30..  i=6, key = 30; j=5
    //      10, 20, 30, 40, 50, 60, 70|..  After the 6th pass....

    int A[] = {10, 50, 40, 60, 20, 70, 30};
    int n = 7;
    printf("Before the sorting :- ");
    printArray(A, n);
    printf("After the sorting  :- ");
    insertionSort(A, n);
    printArray(A, n);
    return 0;
}