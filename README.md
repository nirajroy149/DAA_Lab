// 1. Binary Search=====================


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

// 2. Finding Minimum and maximum element of the array using divide and conquer technique.

#include <stdio.h>

int max, min;
int arr[100];

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
   
    int i, n;
    printf("\nEnter the total number of numbers: ");
    scanf("%d", &n);
    printf("Enter the numbers: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    min = arr[0];
    maxmin(0, n - 1);
    printf("Minumum element in the array: %d\n", min);
    printf("Maximum element in the array: %d\n", max);
}

//=============================

// 3. Merge Sort =======================

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

// 4. Quick Sort ===============================
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
    int n,i, item;
    int arr[100];

    printf("Enter the total numbers of element: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    printf("\nBefore sorting array elements are - \n");
    printArr(arr, n);

    quicksort(arr, 0, n - 1);
    printf("\nAfter sorting array elements are - \n");

    printArr(arr, n);
}
//=============================

// 5. N Queen Code =============================

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int board[20];
int count;

void print(int n)
{
    int i, j;
    printf("\n\nSolution %d:\n\n", ++count);
    for (i = 1; i <= n; ++i)
        printf("\t%d", i);
    for (i = 1; i <= n; ++i)
    {
        printf("\n\n%d", i);
        for (j = 1; j <= n; ++j) // for nxn board
        {
            if (board[i] == j)
                printf("\tQ"); // queen at i,j position
            else
                printf("\t-");
        }
    }
}
int place(int row, int column)
{
    int i;
    for (i = 1; i <= row - 1; ++i)
    {
        // checking column and digonal conflicts
        if (board[i] == column)
            return 0;
        else
            if (abs(board[i] - column) == abs(i - row))
            return 0;
    }
    return 1; // no conflicts
}

void queen(int row, int n)
{
    int column;
    for (column = 1; column <= n; ++column)
    {
        if (place(row, column))
        {
            board[row] = column; // no conflicts so place queen
            if (row == n) // dead end
                print(n); // printing the board configuration
            else // try queen with next position
                queen(row + 1, n);
        }
    }
}


int main()
{
    int n;
    printf(" - N Queens Problem Using Backtracking -");
    printf("\n\nEnter number of Queens:");
    scanf("%d", &n);
    queen(1, n);
    return 0;
}

//=================================

// 6. Chain Matrix Multiplication============================

#include <stdio.h>
#include <limits.h>

int MatrixChainMultiplication(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0; 

    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX; 

            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q; 
                }
            }
        }
    }

    return m[1][n - 1]; 
}

int main()
{
    int n, i;
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    n++;

    int arr[n];

    printf("Enter dimensions \n");

    for (i = 0; i < n; i++)
    {
        printf("Enter d%d :: ", i);
        scanf("%d", &arr[i]);
    }

    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Minimum number of multiplications is %d ", MatrixChainMultiplication(arr, size));

    return 0;
}
//==================================

// 7. Floyd Warshall =============================

#include <stdio.h>

#define V 4
#define INF 9999

void printSolution(int dist[][V])
{
	int i, j;
    printf("The following matrix shows the shortest distances between every pair of vertices \n");

    for ( i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][V])
{
    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])

                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}

int main()
{
    int graph[V][V] = {{0, 1, INF, 8},

                       {INF, 0, 9, 2},

                       {4, INF, 0, INF},

                       {INF, INF, 1, 0}

    };

    // Print the solution
    floydWarshall(graph);
    return 0;
}

//===============================

// 8. Dijkstra code =============================

#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <string.h>
#include <math.h>
#define INF 999
#define N 5

int dijsktra(int cost[][N], int source, int target)
{
    int dist[N], prev[N], selected[N] = {0}, i, m, min, start, d, j;
    char path[N];
    for (i = 1; i < N; i++)
    {
        dist[i] = INF;
        prev[i] = -1;
    }
    start = source;
    selected[start] = 1;
    dist[start] = 0;
    while (selected[target] == 0)
    {
        min = INF;
        m = 0;
        for (i = 1; i < N; i++)
        {
            d = dist[start] + cost[start][i];
            if (d < dist[i] && selected[i] == 0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if (min > dist[i] && selected[i] == 0)
            {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }
    start = target;
    j = 0;
    while (start != -1)
    {
        path[j++] = start + 65;
        start = prev[start];
    }
    path[j] = '\0';
    strrev(path);
    printf("\t%s", path);
    return dist[target];
}

int main()
{
    int cost[N][N], i, j, w, ch, co;
    int source, target, x, y;
    printf("\t The Shortest Path Algorithm ( DIJKSTRA'S ALGORITHM in C ) \n\n");
    for (i = 1; i < N; i++)
        for (j = 1; j < N; j++)
            cost[i][j] = INF;
    for (x = 1; x < N; x++)
    {
        for (y = x + 1; y < N; y++)
        {
            printf("Enter the weight of the path between nodes %d and %d: ", x, y);
            scanf("%d", &w);
            cost[x][y] = cost[y][x] = w;
        }
        printf("\n");
    }
    printf("\nEnter the source: ");
    scanf("%d", &source);
    printf("\nEnter the target: ");
    scanf("%d", &target);
    co = dijsktra(cost, source, target);
    printf("\nThe Shortest Path: %d", co);
}
//==========================================

// 9. KnapSack =============================

# include<stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity) {
   float x[20], tp = 0;
   int i, j, u;
   u = capacity;

   for (i = 0; i < n; i++)
      x[i] = 0.0;

   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }

   if (i < n)
      x[i] = u / weight[i];

   tp = tp + (x[i] * profit[i]);

   printf("\nThe result vector is:- ");
   for (i = 0; i < n; i++)
      printf("%f\t", x[i]);

   printf("\nMaximum profit is:- %f", tp);

}

int main() {
   float weight[20], profit[20], capacity;
   int num, i, j;
   float ratio[20], temp;

   printf("\nEnter the no. of objects:- ");
   scanf("%d", &num);

   printf("\nEnter the wts and profits of each object:- ");
   for (i = 0; i < num; i++) {
      scanf("%f %f", &weight[i], &profit[i]);
   }

   printf("\nEnter the capacityacity of knapsack:- ");
   scanf("%f", &capacity);

   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }

   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }

   knapsack(num, weight, profit, capacity);
   return(0);
}
// Output
// Enter the no. of objects:- 3

// Enter the wts and profits of each object:- 18 25 15 24 10 15    

// Enter the capacityacity of knapsack:- 20
// The result vector is:- 1.000000 0.500000        0.000000        
// Maximum profit is:- 31.500000

//==================================================

// 10. Job Sequencing ==============================

#include <stdio.h>

#define MAX 100

typedef struct Job {
  char id[5];
  int deadline;
  int profit;
} Job;

void jobSequencingWithDeadline(Job jobs[], int n);

int minValue(int x, int y) {
  if(x < y) return x;
  return y;
}

int main(void) {
  //variables
  int i, j;

  //jobs with deadline and profit
  Job jobs[5] = {
    {"j1", 2,  50},
    {"j2", 1, 15},
    {"j3", 2,  10},
    {"j4", 1,  25}
  };

  //temp
  Job temp;

  //number of jobs
  int n = 5;

  //sort the jobs profit wise in descending order
  for(i = 1; i < n; i++) {
    for(j = 0; j < n - i; j++) {
      if(jobs[j+1].profit > jobs[j].profit) {
        temp = jobs[j+1];
        jobs[j+1] = jobs[j];
        jobs[j] = temp;
      }
    }
  }

  printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
  for(i = 0; i < n; i++) {
    printf("%10s %10i %10i\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
  }

  jobSequencingWithDeadline(jobs, n);

  return 0;
}

void jobSequencingWithDeadline(Job jobs[], int n) {
  //variables
  int i, j, k, maxprofit;

  //free time slots
  int timeslot[MAX];

  //filled time slots
  int filledTimeSlot = 0;

  //find max deadline value
  int dmax = 0;
  for(i = 0; i < n; i++) {
    if(jobs[i].deadline > dmax) {
      dmax = jobs[i].deadline;
    }
  }

  //free time slots initially set to -1 [-1 denotes EMPTY]
  for(i = 1; i <= dmax; i++) {
    timeslot[i] = -1;
  }

  printf("dmax: %d\n", dmax);

  for(i = 1; i <= n; i++) {
    k = minValue(dmax, jobs[i - 1].deadline);
    while(k >= 1) {
      if(timeslot[k] == -1) {
        timeslot[k] = i-1;
        filledTimeSlot++;
        break;
      }
      k--;
    }

    //if all time slots are filled then stop
    if(filledTimeSlot == dmax) {
      break;
    }
  }

  //required jobs
  printf("\nRequired Jobs: ");
  for(i = 1; i <= dmax; i++) {
    printf("%s", jobs[timeslot[i]].id);

    if(i < dmax) {
      printf(" --> ");
    }
  }

  //required profit
  maxprofit = 0;
  for(i = 1; i <= dmax; i++) {
    maxprofit += jobs[timeslot[i]].profit;
  }
  printf("\nMax Profit: %d\n", maxprofit);
}
//============================================