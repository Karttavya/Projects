/*
CODES IN C THAT WILL COMPLETE THIS CHALLENGE
*/

#include<stdio.h>
int main(){
    int x,y,z;
    printf("Enter two numbers:");
    y = scanf("%d%d",&x,&y);
    x = printf("%d%d",x,y);
    z = printf("sum=%d",x+y);
    printf("\n\n\n%d\n%d\n%d ",x,y,z);
}