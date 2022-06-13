//Merge Sort =======================

#include <stdio.h>

void merge(int arr[], int low,int mid, int up){
    int i,j,k,b[100];
    i = low;
    j = mid+1;
    k = low;
    while(i<=mid && j<=up){
        if(arr[i]<arr[j]){
            b[k] = arr[i];
            i++;
        }
        else{
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=up){
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            b[k] = arr[i];
            i++;
            k++;
        }
    }

    for(k=low;k<=up;k++){
        arr[k] = b[k];
    }
   
}

void merge_sort(int arr[], int low, int up){
    int mid;
    if(low<up){
        mid = (low+up)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, up);
        merge(arr, low, mid, up);
    }
}

void printArr(int arr[], int up){
    int i;
    for(i=0;i<up;i++){
        printf("%d ", arr[i]);
    }
}

void main(){
    int arr[100],i,n;
    
    printf("Enter the total number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements of of the array:\n");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    
    printf("\nBefore sorting array elements are - \n");
    printArr(arr, n);

    merge_sort(arr, 0, n - 1);
    printf("\nAfter sorting array elements are - \n");

    printArr(arr, n);
}

//=============================