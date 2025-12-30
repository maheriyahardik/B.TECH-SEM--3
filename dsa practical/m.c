#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    float average = (float)sum / n;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}
