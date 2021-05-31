#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Swap utility
void swap(long int* a, long int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/*
void BubbleSort(long int arr[], long int n)
{
    long int i, j;
    for (i = 0; i < n - 1; i++)
                                                                                  {
        for (j = 1; j < n-i-1; j++)
            if (arr[j]< arr[i])
        swap(&arr[i], &arr[j]);
                                                                                   }
}
*/
void InsertionSort(int arr[],int n){

    for(int i=1;i<n;i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{
    long int n = 1000;
    int it = 0;
    double tim1[10];
    printf("A_size\tInsertion sort\n");
    while (it++ < 10)
    {
        long int a[n];
        for (int i = 0; i < n; i++)
                                                        {
            long int no = rand() % n + 1;
            a[i] = no;                          }
        clock_t start, end;
        start = clock();
        InsertionSort(a, n);
        end = clock();
        tim1[it] = ((double)(end - start));
        // for plotting graph with integer values
        printf("%li, %li\n",n,(long int)tim1[it]);
        // increases the size of array by 10000
        n += 1000;
    }
    return 0;
}
