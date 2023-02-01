#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

void BubbleSort(int *A, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // For number of pass...
    {
        printf("Working on pass number %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass...(Inner..)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void BubbleSortAdaptive(int *A, int n)  // Function for already sorted...
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // For number of pass...
    {
        printf("Working on pass number %d\n", i + 1);
        isSorted = 1;                         // For sorted..
        for (int j = 0; j < n - 1 - i; j++)  // For comparison in each pass...(Inner..)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0 ; // For not sorted..
            }
        }
        if (isSorted) // if array sorted then it will be stop..
        {
            return;
        }
    }
}

int main()
{
    int A[] = {10, 50, 40, 60, 20, 70, 30};
    // int A[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;
    printf("Before sorting :- \n");
    printArray(A, n); // Printing the array before sorting...
    printf("After sorting  :- \n");
    BubbleSortAdaptive(A, n); // Function to sort the array...
    printArray(A, n); // Printing the array after sorting...

    return 0;
}