#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[10];
    int f = 0, r = -1; // front and rear
    int ch, x, y, i, found;

    do {
        printf("\nEnter 1 for Insert");
        printf("\nEnter 2 for Delete");
        printf("\nEnter 3 for Find");
        printf("\nEnter 4 for Change");
        printf("\nEnter 5 for Exit");
        printf("\nEnter your choice = ");
        scanf("%d", &ch);

        switch (ch) {
        case 1: // INSERT
            if (r == 9) {
                printf("\nQueue Overflow\n");
            } else {
                printf("\nEnter element to insert: ");
                scanf("%d", &x);
                a[++r] = x;
                printf("\nElement Inserted.\n");
            }
            break;

        case 2: // DELETE
            if (f > r) {
                printf("\nQueue Underflow\n");
            } else {
                printf("\nDeleted element = %d\n", a[f++]);
            }
            break;

        case 3: // FIND
            if (f > r) {
                printf("\nQueue is Empty\n");
            } else {
                printf("\nEnter element to find: ");
                scanf("%d", &x);
                found = 0;
                for (i = f; i <= r; i++) {
                    if (a[i] == x) {
                        printf("\nElement %d found at position %d\n", x, i);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("\nElement not found in queue.\n");
                }
            }
            break;

        case 4: // CHANGE
            if (f > r) {
                printf("\nQueue is Empty\n");
            } else {
                printf("\nEnter element to change: ");
                scanf("%d", &x);
                found = 0;
                for (i = f; i <= r; i++) {
                    if (a[i] == x) {
                        printf("\nEnter new value to replace %d: ", x);
                        scanf("%d", &y);
                        a[i] = y;
                        found = 1;
                        printf("\nElement changed successfully.\n");
                        break;
                    }
                }
                if (!found) {
                    printf("\nElement not found in queue.\n");
                }
                printf("\nCurrent Queue: ");
                for (i = f; i <= r; i++) {
                    printf("%d ", a[i]);
                }
                printf("\n");
            }
            break;

        case 5: // EXIT
            exit(0);
        default:
            printf("\nInvalid Choice!\n");
        }
    } while (ch != 5);

    return 0;
}
