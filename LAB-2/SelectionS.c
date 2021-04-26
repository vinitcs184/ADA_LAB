#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

    int a[100], n, i, j, position, swap;
    clock_t start, endt;
    printf("Enter number of elements n: ");
    scanf("%d", &n);
    printf("Enter %d Numbers: \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = clock();

    for(i = 0; i < n - 1; i++){
        position=i;
        for(j = i + 1; j < n; j++){
            if(a[position] > a[j])
            position=j;
        }

        if(position != i){
            swap=a[i];
            a[i]=a[position];
            a[position]=swap;
        }
    }

    endt = clock();

    printf("Sorted Array: ");
    for(i = 0; i < n; i++)
    printf("%d  ", a[i]);

    printf("Time Taken: %f sec",(float)(endt-start)/CLK_TCK);

    return 0;
}
