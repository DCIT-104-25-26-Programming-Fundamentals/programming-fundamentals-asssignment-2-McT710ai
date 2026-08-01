#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Define the Student struct
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Function to display the main menu
void displayMenu() {
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

// Function to calculate the average score for a student
double calculateAverage(const Student& student) {
    if (student.scores.empty()) {
        return 0.0;
    }
    
    double sum = 0.0;
    for (double score : student.scores) {
        sum += score;
    }
    return sum / student.scores.size();
}

// Function to add a new student
void addStudent(vector<Student>& students) {
    Student newStudent;
    
    cout << "Student name: ";
    cin.ignore();  // Clear the input buffer
    getline(cin, newStudent.name);
    
    cout << "Student ID: ";
    cin >> newStudent.id;
    
    // Check if ID already exists
    for (const Student& s : students) {
        if (s.id == newStudent.id) {
            cout << "Error: Student ID " << newStudent.id << " already exists!" << endl;
            return;
        }
    }
    
    int numScores;
    cout << "How many scores? ";
    cin >> numScores;
    
    if (numScores < 0) {
        cout << "Error: Number of scores cannot be negative!" << endl;
        return;
    }
    
    // Collect scores
    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;
        
        if (score < 0 || score > 100) {
            cout << "Warning: Score " << score << " is outside the typical 0-100 range." << endl;
        }
        
        newStudent.scores.push_back(score);
    }
    
    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}

// Function to display all students in a formatted table
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }
    
    cout << "\n" << string(70, '=') << endl;
    cout << left << setw(25) << "Name" 
         << setw(15) << "ID" 
         << setw(20) << "Scores" 
         << setw(10) << "Average" << endl;
    cout << string(70, '-') << endl;
    
    for (const Student& s : students) {
        cout << left << setw(25) << s.name 
             << setw(15) << s.id;
        
        // Display all scores
        string scoresStr;
        for (size_t i = 0; i < s.scores.size(); i++) {
            scoresStr += to_string(s.scores[i]);
            if (i < s.scores.size() - 1) {
                scoresStr += ", ";
            }
        }
        cout << setw(20) << scoresStr;
        
        // Display average with 2 decimal places
        cout << fixed << setprecision(2) << setw(10) << calculateAverage(s) << endl;
    }
    cout << string(70, '=') << endl;
}

// Function to find a student by ID and calculate their average
void calculateAverageById(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }
    
    int id;
    cout << "Enter student ID: ";
    cin >> id;
    
    // Search for the student
    for (const Student& s : students) {
        if (s.id == id) {
            double avg = calculateAverage(s);
            cout << fixed << setprecision(2);
            cout << s.name << "'s average score: " << avg << endl;
            return;
        }
    }
    
    cout << "Error: Student with ID " << id << " not found!" << endl;
}

int main() {
    vector<Student> students;
    int choice;
    
    cout << "Welcome to the Student Record Management System!" << endl;
    
    do {
        displayMenu();
        cin >> choice;
        
        // Handle invalid input (non-integer)
        if (cin.fail()) {
            cin.clear();  // Clear error state
            cin.ignore(10000, '\n');  // Discard invalid input
            cout << "Error: Please enter a number between 1 and 4." << endl;
            continue;
        }
        
        // Process user choice
        switch(choice) {
            case 1:
                addStudent(students);
                break;
                
            case 2:
                displayAllStudents(students);
                break;
                
            case 3:
                calculateAverageById(students);
                break;
                
            case 4:
                cout << "\nExiting Student Record Management System. Goodbye!" << endl;
                break;
                
            default:
                cout << "Error: Invalid choice! Please enter a number from 1 to 4." << endl;
        }
        
    } while (choice != 4);
    
    return 0;
}