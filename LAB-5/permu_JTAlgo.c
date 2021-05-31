#include <stdio.h>
#include <stdbool.h>

int fact(int n)
{
    if(n == 1)
        return 1;
    else
        return n*fact(n-1);
}

int findMobileElement(int a[],bool dir[],int n)
{
    int mobile = 0;
    for(int i = 0; i < n; i++)
    {
        if(dir[a[i]-1] == 0 && i != 0)         // 0 - Right to left 
        {
            if(a[i] > a[i-1] && a[i] > mobile)
                mobile = a[i];
        }

        else if(dir[a[i]-1] == 1 && i != n-1)  // 1 - Left to right
        {
            if(a[i] > a[i+1] && a[i] > mobile)
                mobile = a[i];
        }
    }
    return mobile;
}

int getIndex(int a[],int mobile,int n)
{
    for(int i = 0; i < n; i++)
        if(a[i] == mobile)
            return i+1;
}

void printPermutation(int a[],bool dir[],int n)
{
    int mobile = findMobileElement(a,dir,n);
    int pos = getIndex(a,mobile,n) , temp;

    if(dir[a[pos-1] - 1] == 0)
    {
        temp = a[pos-2];
        a[pos-2] = a[pos-1];
        a[pos-1] = temp;
    }
    else
    {
        temp = a[pos-1];
        a[pos-1] = a[pos];
        a[pos] = temp;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d",a[i]);
        if(a[i] > mobile)
            dir[a[i]-1] ^= 1;   
    }
    printf(" ");
}

void printPermutations(int n)
{
    int a[n] , f = fact(n);
    bool dir[n];
    for(int i = 1; i <= n; i++)
        a[i-1] = i , printf("%d",a[i-1]) , dir[i-1] = 0;
    printf(" ");
    for(int i = 1; i < f; i++)
        printPermutation(a,dir,n);
}

void main()
{
    int n = 5;
    freopen("output.txt","w",stdout);
    printPermutations(n);
}
