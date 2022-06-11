#include <stdio.h>

int binary_search(int arr[], int item, int low, int up)
{
    int mid;
    while (low <= up)
    {
        mid = (low + up) / 2;
        if (arr[mid] == item)
            return mid;
        else if (arr[mid] < item)
            return binary_search(arr, item, mid + 1, up);
        else if (arr[mid] > item)
            return binary_search(arr, item, low, mid - 1);
    }
    return -1;
}
int main()
{
    int i, item;
    int arr[] = {3, 4, 5, 8, 9, 12, 16, 26};
    printf("Enter the element you want to search: ");
    scanf("%d", &item);
    int position = binary_search(arr, item, 0, 7);
    if (position == -1)
        printf("%s", "Not found");
    else
        printf("Element is present at index %d", position);
    return 0;
}