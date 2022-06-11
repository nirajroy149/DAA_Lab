// Finding Minimum and maximum element of the array using divide and conquer technique.
#include <stdio.h>

int max, min;
int arr[] = {3, 4, 5, 8, 9, 12, 16, 26};
int n = sizeof(arr) / sizeof(arr[0]);

void maxmin(int low, int up)

{
    int max1, min1, mid;
    if (low == up)
    {
        min = max = arr[low];
    }
    else
    {
        if (low == up - 1)
        {
            if (arr[low] < arr[up])
            {
                max = arr[up];
                min = arr[low];
            }
            else
            {
                max = arr[low];
                min = arr[up];
            }
        }
        else
        {
            mid = (low + up) / 2;
            maxmin(low, mid);
            max1 = max;
            min1 = min;
            maxmin(mid + 1, up);
            if (max < max1)
            {
                max = max1;
            }
            if (min > min1)
            {
                min = min1;
            }
        }
    }
}

void main()
{
    max = arr[0];
    min = arr[0];
    maxmin(0, n);
    printf("Minumum element in the array: %d\n", min);
    printf("Maximum element in the array: %d\n", max);
}