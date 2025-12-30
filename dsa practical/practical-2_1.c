#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, *ptr, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Memory allocation using malloc
    ptr = (int*)malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }

    printf("Enter elements of array: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", ptr + i);
        sum += *(ptr + i);  // Add each element to sum
    }

    printf("Sum = %d\n", sum);

    free(ptr); // Free allocated memory
    return 0;
}
