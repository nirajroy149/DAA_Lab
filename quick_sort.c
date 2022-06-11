
#include <stdio.h>

int partition(int arr[], int low, int up)
{
    int pivot = arr[low];
    int start = low + 1; // Important
    int end = up;
    int temp;

    while (start <= end)
    {
        while (pivot > arr[start])
            start++;
        while (pivot < arr[end])
            end--;
        if (start < end)
        {
            // swaping a[start] a[end]

            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
        else
        {
            start++;
        }
    }
    // swaping a[lb] a[end]
    arr[low] = arr[end];
    arr[end] = pivot;

    return end;
}

void quicksort(int arr[], int low, int up)
{
    int pivloc;
    if (low < up)
    {

        pivloc = partition(arr, low, up);
        quicksort(arr, low, pivloc - 1);
        quicksort(arr, pivloc + 1, up);
    }
}

void printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
void main()
{
    int n, item;
    int arr[] = {9, 4, 6, 72, 8, 45, 13, 62, 74};

    n = sizeof(arr) / sizeof(arr[0]);
    printf("\nBefore sorting array elements are - \n");

    printArr(arr, n);

    quicksort(arr, 0, n - 1);
    printf("\nAfter sorting array elements are - \n");

    printArr(arr, n);
}
