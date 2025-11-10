#include <stdio.h>
#include <string.h>

// Define student structure
struct Student {
    int id;
    char name[50];
    float grade;
};

// Function prototypes
void addStudent(struct Student students[], int *count);
void updateStudent(struct Student students[], int count, int id);
void retrieveStudent(struct Student students[], int count, int id);

int main() {
    struct Student students[100];
    int count = 0;
    int choice, id;

    while(1) {
        printf("1. Add Student\n2. Update Student\n3. Retrieve Student\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(students, &count); break;
            case 2:
                printf("Enter student ID to update: ");
                scanf("%d", &id);
                updateStudent(students, count, id); break;
            case 3:
                printf("Enter student ID to retrieve: ");
                scanf("%d", &id);
                retrieveStudent(students, count, id); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

void addStudent(struct Student students[], int *count) {
    printf("Enter student ID: ");
    scanf("%d", &students[*count].id);
    printf("Enter student name: ");
    scanf("%s", students[*count].name);
    printf("Enter student grade: ");
    scanf("%f", &students[*count].grade);

    (*count)++;
    printf("Student added successfully!\n");
}

void updateStudent(struct Student students[], int count, int id) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = 1;
            printf("Enter new student name: ");
            scanf("%s", students[i].name);
            printf("Enter new student grade: ");
            scanf("%f", &students[i].grade);
            printf("Student record updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void retrieveStudent(struct Student students[], int count, int id) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = 1;
            printf("Student ID: %d\n", students[i].id);
            printf("Student Name: %s\n", students[i].name);
            printf("Student Grade: %.2f\n", students[i].grade);
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}
