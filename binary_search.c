// Binary Search=====================


#include <stdio.h>

int binarySearch(int arr[],int low,int up,int item){
    int mid;
    while(low<=up){
        mid = (low+up)/2;
        if(arr[mid]==item){
            return mid;
        }
        else if(arr[mid]>item){
            return binarySearch(arr, low, mid-1, item);
        }
        else if(arr[mid]<item){
            return binarySearch(arr, mid+1, up, item);
        }
    }
    return -1;
}

int main(){
    int arr[100],n,item, i,index;
    printf("Enter total numbers of element in array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array in sorted order: ");
    for(i=0; i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("Which element do you want to search for? ");
    scanf("%d", &item);
     
    index = binarySearch(arr, 0, n-1, item);
    if(index==-1){
        printf("%d not found.",item);
    }
    else{
        printf("%d found at index %d.",item, index);
    }
    return 0;
}

//========================================