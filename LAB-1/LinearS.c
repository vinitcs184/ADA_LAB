#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int found=0,pos=-1,num;
int arr[20];

void recur(int n){

    if(n<0)
        printf("element %d not found",num);
    else{
        if(arr[n]==num){
            pos==n;
            printf("%d is found in the array at position %d",num,n+1);
        }
        else
            recur(--n);
    }
}

int main(){

    int n,i;
    clock_t start, end;
    printf("enter the no. of elements in the array\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("enter the element to be searched\n");
    scanf("%d",&num);

    start = clock();
    recur(n);
    end = clock();

    printf("\nTime Taken: %f sec",(float)(end-start)/CLK_TCK);

    return 0;
}
