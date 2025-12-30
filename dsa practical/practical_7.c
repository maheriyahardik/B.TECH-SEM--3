#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;

void insert_begin();
void insert_end();
void insert_after();
void delete_node();
void display();

int main() {
    int ch;

    do {
        printf("\n\n1. Insert at Begin");
        printf("\n2. Insert at End");
        printf("\n3. Insert after Given Position");
        printf("\n4. Delete");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1: insert_begin(); break;
        case 2: insert_end(); break;
        case 3: insert_after(); break;
        case 4: delete_node(); break;
        case 5: display(); break;
        case 6: exit(0);
        default: printf("\nInvalid choice!");
        }
    } while (ch != 6);

    return 0;
}

void insert_begin() {
    struct node *newnode;
    int x;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter info: ");
    scanf("%d", &x);
    newnode->info = x;
    newnode->link = first;
    first = newnode;
    display();
}

void insert_end() {
    struct node *newnode, *temp;
    int x;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter info: ");
    scanf("%d", &x);
    newnode->info = x;
    newnode->link = NULL;

    if (first == NULL) {
        first = newnode;
    } else {
        temp = first;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = newnode;
    }
    display();
}

void insert_after() {
    struct node *newnode, *temp;
    int x, pos, i = 1;
    if (first == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    printf("\nEnter position after which to insert: ");
    scanf("%d", &pos);
    printf("\nEnter info: ");
    scanf("%d", &x);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;

    temp = first;
    while (i < pos && temp != NULL) {
        temp = temp->link;
        i++;
    }

    if (temp == NULL) {
        printf("\nPosition not found!\n");
        free(newnode);
    } else {
        newnode->link = temp->link;
        temp->link = newnode;
        display();
    }
}

void delete_node() {
    struct node *temp = first, *prev = NULL;
    int x;

    if (first == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    printf("\nEnter value to delete: ");
    scanf("%d", &x);

    while (temp != NULL && temp->info != x) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("\nNode not found!\n");
    } else {
        if (prev == NULL) {
            first = first->link; // deleting first node
        } else {
            prev->link = temp->link;
        }
        free(temp);
        printf("\nNode deleted successfully!\n");
        display();
    }
}

void display() {
    struct node *temp = first;
    if (first == NULL) {
        printf("\nLinked List is empty!\n");
        return;
    }

    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("|%d|", temp->info);
        if (temp->link != NULL)
            printf("->");
        temp = temp->link;
    }
    printf("\n");
}

