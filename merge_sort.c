#include <stdio.h>

void merge(int arr[], int low, int mid, int up)
{
    int i = low;
    int j = mid+1; //important
    int b[100];
    int k = low;
    while (i <= mid && j <= up)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= up)
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    for (k = low; k <= up; k++)
    {
        arr[k] = b[k];
    }
}

void merge_sort(int arr[], int low, int up)
{
    int mid;
    if (low < up)
    {
        mid = (low + up) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, up);
        merge(arr, low, mid, up);
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

    merge_sort(arr, 0, n - 1);
    printf("\nAfter sorting array elements are - \n");

    printArr(arr, n);
}