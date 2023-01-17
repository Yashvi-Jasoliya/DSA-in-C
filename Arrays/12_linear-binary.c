#include <stdio.h>

// For Linear Search
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            // printf("Element not found\n");
            return i;
        }
    }

    return -1;
}

// For binary Search
int binarySearch(int arr[], int size , int element)
{
    int low, mid, high;
    low=0;
    high = size-1;
    // Start Searching
    //keep searching untill low <= high
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // Seaching ends
    return -1;
}

int main()
{
    //Unsorted array for linear search

    // int arr[] = {1, 3, 5, 56, 4, 3, 23, 5, 4, 54634, 54, 34, 12, 59};
    // int size = sizeof(arr) / sizeof(int);

    // Sorted array for binary search
     int arr[] = {1, 3, 5, 6, 24, 33, 43, 55, 64, 66, 74, 84, 112, 159};
    int size = sizeof(arr) / sizeof(int);
    int element;
    printf("Enter you want to element:\n");
    scanf("%d", &element);
    int searchIndex = binarySearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);
    return 0;
}