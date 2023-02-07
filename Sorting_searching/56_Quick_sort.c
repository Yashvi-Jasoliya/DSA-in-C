#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int temp;
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (A[i] <= pivot)
        {
            i++; // For element max than pivot
        }

        while (A[j] > pivot)
        {
            j--; // For element min or equal than pivot
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{

    int partitionIndex; // Index of pivot after partition..

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        printArray(A,6);
        quickSort(A, low, partitionIndex - 1);  // sort left subArray..
        quickSort(A, partitionIndex + 1, high); // sort right subArray..
    }
}

int main()
{
    int A[] = {100, 50, 60, 40, 20, 15};
    int n = 6;

    printf("Before the sorting :- ");
    printArray(A, n);
    printf("After Quick sort :-   \n");
    quickSort(A, 0, n - 1);
    printArray(A, n);
    printf("Sorted Successfully...\n");
    return 0;
}