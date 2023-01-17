#include<stdio.h>
void display(int arr[], int n)
{
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void indDeletion(int arr[], int size, int index)
{
    // Code for Deletion
    
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1 ];
    }
    
    printf("Array with deleted element:\n");
}

int main()
{

    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5,  index = 2;
    display(arr, size);
    indDeletion(arr, size, index);
    size -= 1;
    display(arr, size);
    return 0;
}