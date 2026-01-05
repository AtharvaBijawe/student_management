#include <stdio.h>
#include <string.h>
#include <ctype.h>  // Added for input validation

// Define student structure
struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

// Global array to store students
struct Student students[50];
int studentCount = 0;

// Helper function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Helper function to find student by roll number (returns index or -1)
int findStudentByRoll(int rollNo) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNo) {
            return i;
        }
    }
    return -1;
}

// Function to add a new student
void addStudent() {
    // Check if array is full
    if (studentCount >= 50) {
        printf("\nError: Maximum student limit reached (50 students)!\n\n");
        return;
    }
    
    printf("\n--- Add New Student ---\n");
    
    // Input roll number with validation
    int rollNumber;
    while (1) {
        printf("Enter Roll Number: ");
        if (scanf("%d", &rollNumber) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        
        // Check for duplicate roll number
        if (findStudentByRoll(rollNumber) != -1) {
            printf("Error: Roll number %d already exists. Please use a different roll number.\n", rollNumber);
            continue;
        }
        
        if (rollNumber <= 0) {
            printf("Error: Roll number must be positive.\n");
            continue;
        }
        break;
    }
    students[studentCount].rollNumber = rollNumber;
    
    // Input name with spaces
    printf("Enter Name: ");
    if (fgets(students[studentCount].name, sizeof(students[studentCount].name), stdin) == NULL) {
        printf("Error reading name.\n");
        return;
    }
    
    // Remove trailing newline if present
    size_t len = strlen(students[studentCount].name);
    if (len > 0 && students[studentCount].name[len - 1] == '\n') {
        students[studentCount].name[len - 1] = '\0';
    }
    
    // Input marks with validation
    while (1) {
        printf("Enter Marks (0-100): ");
        if (scanf("%f", &students[studentCount].marks) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        
        if (students[studentCount].marks < 0 || students[studentCount].marks > 100) {
            printf("Error: Marks must be between 0 and 100.\n");
            continue;
        }
        break;
    }
    
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
    if (scanf("%d", &rollNo) != 1) {
        printf("Invalid input.\n\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();
    
    int index = findStudentByRoll(rollNo);
    if (index != -1) {
        printf("Found - Name: %s, Marks: %.2f\n\n", 
               students[index].name, 
               students[index].marks);
        return;
    }
    
    printf("Not found!\n\n");
}

// Function to delete a student
void deleteStudent() {
    int rollNo;
    printf("\n--- Delete Student ---\n");
    printf("Enter roll number to delete: ");
    if (scanf("%d", &rollNo) != 1) {
        printf("Invalid input.\n\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();
    
    int index = findStudentByRoll(rollNo);
    if (index != -1) {
        for (int j = index; j < studentCount - 1; j++) {
            students[j] = students[j + 1];
        }
        studentCount--;
        printf("Deleted successfully!\n\n");
        return;
    }
    
    printf("Not found!\n\n");
}

// Function to edit a student
void editStudent() {
    int rollNo;
    printf("\n--- Edit Student ---\n");
    printf("Enter roll number to edit: ");
    if (scanf("%d", &rollNo) != 1) {
        printf("Invalid input.\n\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();
    
    int index = findStudentByRoll(rollNo);
    if (index != -1) {
        printf("Current marks: %.2f\n", students[index].marks);
        
        // Input new marks with validation
        float newMarks;
        while (1) {
            printf("Enter new marks (0-100): ");
            if (scanf("%f", &newMarks) != 1) {
                printf("Invalid input. Please enter a valid number.\n");
                clearInputBuffer();
                continue;
            }
            clearInputBuffer();
            
            if (newMarks < 0 || newMarks > 100) {
                printf("Error: Marks must be between 0 and 100.\n");
                continue;
            }
            break;
        }
        
        students[index].marks = newMarks;
        printf("Updated successfully!\n\n");
        return;
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
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        
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
                printf("Invalid choice! Please enter 1-8.\n\n");
        }
    }
    
    return 0;
}