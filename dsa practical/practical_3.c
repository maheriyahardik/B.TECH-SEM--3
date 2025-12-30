#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[10], top = 0, x, ch, y, i;

    do {
        printf("\nEnter 1 for push");
        printf("\nEnter 2 for pop");
        printf("\nEnter 3 for peep");
        printf("\nEnter 4 for change");
        printf("\nEnter 5 for exit");
        printf("\nEnter your choice = ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: // Push
                if (top >= 10) {
                    printf("Stack overflow\n");
                } else {
                    printf("Enter element to insert: ");
                    scanf("%d", &x);
                    top++;
                    a[top] = x;

                    printf("Current Stack: ");
                    for(i = top; i >= 1; i--) {
                        printf("%d ", a[i]);
                    }
                    printf("\n");
                }
                break;

            case 2: // Pop
                if (top == 0) {
                    printf("Stack underflow\n");
                } else {
                    printf("Pop element = %d\n", a[top]);
                    top--;

                    printf("Current Stack: ");
                    for(i = top; i >= 1; i--) {
                        printf("%d ", a[i]);
                    }
                    if(top==0) printf("Empty");
                    printf("\n");
                }
                break;

            case 3: // Peep
                printf("Enter position for peep: ");
                scanf("%d", &x);
                if((top - x + 1) <= 0) {
                    printf("Stack Underflow\n");
                } else {
                    printf("Element at position %d from top = %d\n", x, a[top-x+1]);
                }
                break;

            case 4: // Change
                printf("Enter position to change: ");
                scanf("%d", &x);
                if((top - x + 1) <= 0) {
                    printf("Stack Underflow\n");
                } else {
                    printf("Enter the element to change: ");
                    scanf("%d", &y);
                    a[top-x+1] = y;

                    printf("Current Stack: ");
                    for(i = top; i >= 1; i--) {
                        printf("%d ", a[i]);
                    }
                    printf("\n");
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(ch != 5);

    return 0;
}
