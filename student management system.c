#include <stdio.h>
#include <string.h>

// Define student structure
struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

// Global array to store students
struct Student students[50];
int studentCount = 0;

// Function to add a new student
void addStudent() {
    printf("\n--- Add New Student ---\n");
    printf("Enter Roll Number: ");
    scanf("%d", &students[studentCount].rollNumber);
    
    printf("Enter Name: ");
    scanf("%s", students[studentCount].name);
    
    printf("Enter Marks: ");
    scanf("%f", &students[studentCount].marks);
    
    studentCount++;
    printf("Student added successfully!\n\n");
}

// Function to view all students
void viewAllStudents() {
    if (studentCount == 0) {
        printf("\nNo students yet!\n\n");
        return;
    }
    
    printf("\n--- All Students ---\n");
    printf("Roll No | Name          | Marks\n");
    printf("--------|---------------|-------\n");
    
    for (int i = 0; i < studentCount; i++) {
        printf("%-7d | %-13s | %.2f\n", 
               students[i].rollNumber, 
               students[i].name, 
               students[i].marks);
    }
    printf("\n");
}

// Function to search a student
void searchStudent() {
    int rollNo;
    printf("\n--- Search Student ---\n");
    printf("Enter roll number: ");
    scanf("%d", &rollNo);
    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNo) {
            printf("Found - Name: %s, Marks: %.2f\n\n", 
                   students[i].name, 
                   students[i].marks);
            return;
        }
    }
    
    printf("Not found!\n\n");
}

// Function to delete a student
void deleteStudent() {
    int rollNo;
    printf("\n--- Delete Student ---\n");
    printf("Enter roll number to delete: ");
    scanf("%d", &rollNo);
    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNo) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Deleted successfully!\n\n");
            return;
        }
    }
    
    printf("Not found!\n\n");
}

// Function to edit a student
void editStudent() {
    int rollNo;
    printf("\n--- Edit Student ---\n");
    printf("Enter roll number to edit: ");
    scanf("%d", &rollNo);
    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNo) {
            printf("Current marks: %.2f\n", students[i].marks);
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            printf("Updated successfully!\n\n");
            return;
        }
    }
    
    printf("Not found!\n\n");
}

// Function to calculate average marks
void calculateAverage() {
    if (studentCount == 0) {
        printf("\nNo students!\n\n");
        return;
    }
    
    float sum = 0;
    for (int i = 0; i < studentCount; i++) {
        sum += students[i].marks;
    }
    
    float average = sum / studentCount;
    printf("\n--- Average Marks ---\n");
    printf("Average: %.2f\n\n", average);
}

// Function to display highest and lowest marks
void displayHighestLowest() {
    if (studentCount == 0) {
        printf("\nNo students!\n\n");
        return;
    }
    
    int highest = 0, lowest = 0;
    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].marks > students[highest].marks) {
            highest = i;
        }
        if (students[i].marks < students[lowest].marks) {
            lowest = i;
        }
    }
    
    printf("\n--- Highest and Lowest ---\n");
    printf("Highest: %s - %.2f\n", students[highest].name, students[highest].marks);
    printf("Lowest: %s - %.2f\n\n", students[lowest].name, students[lowest].marks);
}

// Main function
int main() {
    // Add some default students
    students[0].rollNumber = 101;
    strcpy(students[0].name, "Atharva");
    students[0].marks = 85.5;
    
    students[1].rollNumber = 102;
    strcpy(students[1].name, "Sarvadhyna");
    students[1].marks = 92.0;
    
    students[2].rollNumber = 103;
    strcpy(students[2].name, "Piyush");
    students[2].marks = 78.5;
    
    studentCount = 3;
    
    int choice;
    
    while (1) {
        printf("\n========== STUDENT MANAGEMENT ==========\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Edit Student\n");
        printf("6. Average Marks\n");
        printf("7. Highest and Lowest\n");
        printf("8. Exit\n");
        printf("========================================\n");
        printf("Enter choice (1-8): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewAllStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                editStudent();
                break;
            case 6:
                calculateAverage();
                break;
            case 7:
                displayHighestLowest();
                break;
            case 8:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n\n");
        }
    }
    
    return 0;
}