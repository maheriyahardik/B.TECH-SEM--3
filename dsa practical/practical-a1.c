#include <stdio.h> 

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i]; // Directly summing here
    }

    float avg = (float)sum / n;

    printf("Sum is %d\n", sum);
    printf("Average is %.2f\n", avg);

    return 0;
}
