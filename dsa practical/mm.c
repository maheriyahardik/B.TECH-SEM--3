#include <stdio.h>

#define MAX 100

// Structure to store student data
struct Student {
    char name[50];
    int marks[5];
    float average;
};

// Function to calculate average marks
float calculateAverage(int marks[], int subjects) {
    int sum = 0;
    for (int i = 0; i < subjects; i++) {
        sum += marks[i];
    }
    return (float)sum / subjects;
}

// Function to find student with highest average
int findTopper(struct Student students[], int count) {
    int topperIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].average > students[topperIndex].average) {
            topperIndex = i;
        }
    }
    return topperIndex;
}

int main() {
    struct Student students[MAX];
    int count, subjects = 5;

    printf("Enter number of students: ");
    scanf("%d", &count);

    // Input data for each student
    for (int i = 0; i < count; i++) {
        printf("\nEnter name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter marks in %d subjects:\n", subjects);
        for (int j = 0; j < subjects; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }

        students[i].average = calculateAverage(students[i].marks, subjects);
    }

    // Display all student data
    printf("\n--- Student Report ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s | Average: %.2f\n", students[i].name, students[i].average);
    }

    // Find topper
    int topper = findTopper(students, count);
    printf("\n🏆 Topper: %s with Average = %.2f\n", students[topper].name, students[topper].average);

    return 0;
}

