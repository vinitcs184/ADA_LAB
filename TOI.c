#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tower(int num, char from, char to,char auxi){

    if(num==1){
        printf("Move disk %d from %c to %c\n",num,from,to);
        return;
    }

    tower(num-1,from,auxi,to);
    printf("Move disk %d from %c to %c\n",num,from,to);

    tower(num-1,auxi,to,from);
}



int main(){

    clock_t start, end;
    int num;
    char A,B,C;
    printf("enter the no. of discs\n");
    scanf("%d",&num);

    start = clock();
    printf("\nThe sequence of moves involved in TOH are : \n");
    tower(num, 'A', 'B', 'C');
    end = clock();

    printf("Time Taken: %f sec",(float)(end-start)/CLK_TCK);
    return 0;

}


