#include<stdio.h>
#include<conio.h>

void swapbyvalue(int x,int y){
    int temp=x;
    x=y;
    y=temp;
    printf("After through values swapping %d %d",x,y);
}
void swapbyreference(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
     printf("\n After thorugh reference swapping %d %d",*x,*y);
}

void main(){
    int p,q;
    printf("Enter the value of p and q:");
    scanf("%d %d",&p,&q);

    swapbyvalue(p,q);
    swapbyreference(&p,&q);

    getch();
}