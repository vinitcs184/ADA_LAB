#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l-1;
    for(int j = l; j < h; j++)
    {
        if(arr[j] < pivot)
        {
            ++i;
            swap(&arr[i] , &arr[j]);
        }
    }
    swap(&arr[i+1] , &arr[h]);
    return i+1;
}

void quick_sort(int arr[], int l, int h)
{
    if(l < h)
    {
        int p = partition(arr, l, h);
        quick_sort(arr, l, p-1);
        quick_sort(arr, p+1, h);
    }
}

void main()
{
    int min,temp,k=0;
    double t;
    clock_t start,end;
    int n[10]={100,500,1000,5000,7500,10000,25000,50000,75000,100000};
    freopen("output.txt","w",stdout);
    while(k<10)
    {
        int *a = (int*)malloc(n[k]*sizeof(int));
        for(int i=0;i<n[k];i++)
            a[i] = rand() % INT_MAX;

        start = clock();
        quick_sort(a,0,n[k]-1);
        end = clock();
        t=((double)(end-start))/(double)CLOCKS_PER_SEC;

        printf("Time taken for n = %d is %.5fs\n",n[k],t);
        k++;
    }
}
