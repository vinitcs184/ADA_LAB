#include <stdio.h>
#include <stdlib.h>
#include <time.h>


long GCD(long m, long n){
    long r;
    if(n==0)
        return m;
    else{
        r=m%n;
        m=n;
        n=r;
        GCD(m,n);
    }
}

int main(){
    long a,b,result;
    clock_t start,end;

    printf("enter the vale of a,b to find GCD\n");
    printf("enter the value of a\n");
    scanf("%d",&a);
    printf("enter the value of b\n");
    scanf("%d",&b);

    start = clock();

    result=GCD(a,b);
    printf("the greatest common divisor of %d, %d is %d\n",a,b,result);

    end = clock();

    printf("Time Taken: %f sec",(float)(end-start)/CLK_TCK);

    return 0;
}
