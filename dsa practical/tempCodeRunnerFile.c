#include<stdio.h>
#include<conio.h>
void main(){
    int n;
    printf("Enter size of array:");
    scnaf("%d",&n);

    int arr[n];
    for(int i=0;i<=n;i++){
        printf("Enter %d",i);
        scnaf("%d",&arr[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    printf("Sum of array elements is %d and avg of element is%d",sum sum/n);
    getch();
}