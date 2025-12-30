#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;

// Function prototypes
void push();
void pop();
void peep();
void change();
void display();

int main() {
    int ch;
    do {
        printf("\n--- Stack Operations using Linked List ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP\n");
        printf("4. CHANGE\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peep(); break;
            case 4: change(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("\nInvalid choice! Try again.\n");
        }
    } while (ch != 6);

    return 0;
}

// PUSH operation
void push() {
    struct node *newNode;
    int x;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("\nMemory allocation failed!\n");
        return;
    }
    printf("\nEnter value to PUSH: ");
    scanf("%d", &x);
    newNode->info = x;
    newNode->link = first;
    first = newNode;
    display();
}

// POP operation
void pop() {
    if (first == NULL) {
        printf("\nStack is EMPTY!\n");
    } else {
        struct node *temp = first;
        printf("\nPopped element = %d\n", first->info);
        first = first->link;
        free(temp);
        display();
    }
}

// PEEP operation (search element)
void peep() {
    int x, i = 1, found = 0;
    struct node *temp = first;
    if (first == NULL) {
        printf("\nStack is EMPTY!\n");
        return;
    }
    printf("\nEnter element to search (PEEP): ");
    scanf("%d", &x);

    while (temp != NULL) {
        if (temp->info == x) {
            printf("Element %d found at position %d from TOP.\n", x, i);
            found = 1;
            break;
        }
        temp = temp->link;
        i++;
    }
    if (!found)
        printf("Element %d NOT found in stack.\n", x);
}

// CHANGE operation
void change() {
    int x, y, found = 0;
    struct node *temp = first;
    if (first == NULL) {
        printf("\nStack is EMPTY!\n");
        return;
    }
    printf("\nEnter element to CHANGE: ");
    scanf("%d", &x);

    while (temp != NULL) {
        if (temp->info == x) {
            printf("Enter new value: ");
            scanf("%d", &y);
            temp->info = y;
            found = 1;
            break;
        }
        temp = temp->link;
    }
    if (!found)
        printf("Element %d not found in stack.\n", x);

    display();
}

// DISPLAY operation
void display() {
    struct node *temp = first;
    if (first == NULL) {
        printf("\nStack is EMPTY!\n");
        return;
    }
    printf("\nStack elements (TOP to BOTTOM):\n");
    while (temp != NULL) {
        printf("%d\n", temp->info);
        temp = temp->link;
    }
}
