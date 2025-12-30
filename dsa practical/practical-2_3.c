#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, i, n1, n2;

    printf("Enter size of array: ");
    scanf("%d", &n1);

    // Allocate memory using malloc
    ptr = (int*)malloc(n1 * sizeof(int));

    if (ptr == NULL) {
        printf("Error! Memory not allocated.\n");
        exit(0);
    }

    printf("Address of previously allocated memory:\n");
    for (i = 0; i < n1; ++i)
        printf("%p\t", (ptr + i));

    // Ask for new size
    printf("\n\nEnter new size of array: ");
    scanf("%d", &n2);

    // Reallocate memory
    ptr = (int*)realloc(ptr, n2 * sizeof(int));

    if (ptr == NULL) {
        printf("Error! Memory not reallocated.\n");
        exit(0);
    }

    printf("Address of newly allocated (or reallocated) memory:\n");
    for (i = 0; i < n2; ++i)
        printf("%p\t", (ptr + i));

    free(ptr);
    return 0;
}
