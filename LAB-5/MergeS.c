#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>

void merge(int arr[],int l,int m,int r)
{
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1],R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 +j];

    i = j = 0;
    k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[j] = R[j];
            j++;
        }
        k++;
    }

    // Remaining elements in L[]
    while(i < n1)
    {
        arr[k] = L[i];
        i++ , k++;
    }

    // Remaining elements in R[]
    while(j < n2)
    {
        arr[k] = R[j];
        j++ , k++;
    }
}

void mergeSort(int arr[],int l,int r)
{
    if(l < r)
    {
        int m = (l + r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
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
        mergeSort(a,0,n[k]-1);
        end = clock();
        t=((double)(end-start))/(double)CLOCKS_PER_SEC;

        printf("Time taken for n = %d is %.5fs\n",n[k],t);
        k++;
    }
}
