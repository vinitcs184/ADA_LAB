#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int arr[20],num,n;

void Brecur(int beg, int end){

    int mid;
    mid = (beg+end)/2;
    if(beg>end)
        printf("element %d not found\n",num);
    else{
        if(arr[mid]==num)
            printf("element %d found at position %d\n",num,mid+1);
        else if (arr[mid]>num)
                Brecur(beg, end=mid-1);
        else
            Brecur(beg=mid+1,end);
    }

}

int main(){

    int beg,end;
    clock_t start, endt;
    printf("Enter the no. of elements in the array\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("enter the element to be searched\n");
    scanf("%d",&num);
    beg=0;
    end=n-1;

    start = clock();

    Brecur(beg, end);

    end = clock();

    printf("Time Taken: %f sec",(float)(endt-start)/CLK_TCK);

    return 0;


}
