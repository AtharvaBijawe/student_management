# student_management
Student Management System in C
Project Overview

This is a terminal-based student management system written in C. It manages student records such as roll number, name, and marks using a menu-driven interface. The system supports adding, viewing, searching, editing, deleting students, and calculating statistics like average, highest, and lowest marks. All data is stored in memory while the program runs.

Why This Project Exists

This project was created to understand how real programs manage data internally instead of focusing only on syntax. It avoids files and databases to concentrate on logic, memory handling, and program structure using core C concepts.

How the Project Works

Each student is represented using a structure that groups roll number, name, and marks. Multiple students are stored in an array of structures which acts as a temporary database. The program runs in a loop and displays a menu until the user chooses to exit. Each feature is implemented as a separate function to keep the code modular.

Concepts Used and Implementation

Structures are used to group student data into a single unit. Arrays of structures store multiple student records in memory. Functions are used to separate each operation such as add, view, search, edit, delete, and calculations. Loops are used to traverse student records, calculate totals, and keep the menu running. Conditional statements control decision-making such as comparisons and validations. A switch-case statement controls menu navigation. Linear search is used to find students by roll number. Array shifting is used to delete records. Basic arithmetic logic is used to calculate average, highest, and lowest marks. Input and output are handled using scanf and printf.

Limitations

Data is not stored permanently and is lost when the program exits. The number of students is fixed. Input validation is minimal.

How to Run

Compile using gcc student_management.c -o student_management and run using ./student_management.
