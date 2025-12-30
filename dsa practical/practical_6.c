#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int q[SIZE];
int f = -1, r = -1;

void cqinsert(int x);
int cqdelete();
void display();

int main() {
    int choice, x;

    do {
        printf("\n\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nSelect your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter element to insert: ");
            scanf("%d", &x);
            cqinsert(x);
            display();
            break;

        case 2:
            x = cqdelete();
            if (x != -1) {
                printf("\n%d is deleted from queue", x);
                display();
            }
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid choice! Please select 1,2,3, or 4.");
        }
    } while (1);

    return 0;
}

// Function to insert in Circular Queue
void cqinsert(int x) {
    // Check if Queue is Full
    if ((f == 0 && r == SIZE - 1) || (r + 1 == f)) {
        printf("\nQueue is Overflow!");
        return;
    }

    // First Element
    if (f == -1) {
        f = r = 0;
        q[r] = x;
    }
    else {
        r = (r + 1) % SIZE;
        q[r] = x;
    }
}

// Function to delete from Circular Queue
int cqdelete() {
    int y;

    // Check if Queue is Empty
    if (f == -1) {
        printf("\nQueue is Underflow!");
        return -1;
    }

    y = q[f];
    q[f] = 0; // Optional: mark deleted

    // Only one element
    if (f == r) {
        f = r = -1;
    } else {
        f = (f + 1) % SIZE;
    }

    return y;
}

// Function to display Circular Queue
void display() {
    int i;

    if (f == -1) {
        printf("\nQueue is Empty!");
        return;
    }

    printf("\nQueue content: ");
    if (r >= f) {
        for (i = f; i <= r; i++)
            printf("%d ", q[i]);
    } else {
        for (i = f; i < SIZE; i++)
            printf("%d ", q[i]);
        for (i = 0; i <= r; i++)
            printf("%d ", q[i]);
    }
}
