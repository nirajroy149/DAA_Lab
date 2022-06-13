//Linear Search =========================

#include <stdio.h>

int linear_search(int arr[], int item, int low, int up)
{
    int i;
    for (i = low; i <= up; i++)
    {
        if (item == arr[i])
        {
            return i;
        }
    }
    return -1;
}

void main()
{
    int i;
    int item, index;
    int arr[] = {3, 4, 5, 8, 9, 12, 16, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Which element do you want to search for? ");
    scanf("%d", &item);
    index = linear_search(arr, item, 0, n - 1);
    if (index == -1)
    {
        printf("Element is not present in the array.");
    }
    else
    {
        printf("Element is present in the array at %d index.", index);
    }
}

//=============================