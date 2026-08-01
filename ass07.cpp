#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to display the main menu
void displayMenu() {
    cout << "\n============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

// Function to add a task to the list
void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter task: ";
    cin.ignore();  // Clear the input buffer
    getline(cin, task);
    
    // Check if task is empty
    if (task.empty()) {
        cout << "Error: Task cannot be empty!" << endl;
        return;
    }
    
    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"" << endl;
}

// Function to view all tasks
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty. Great job!" << endl;
        return;
    }
    
    cout << "\nYour Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// Function to delete a task
void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Cannot delete: Your to-do list is empty!" << endl;
        return;
    }
    
    // Show current tasks with numbers
    viewTasks(tasks);
    
    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;
    
    // Validate task number
    if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        cout << "Error: Invalid task number!" << endl;
        return;
    }
    
    // Delete the task
    string deletedTask = tasks[taskNumber - 1];
    tasks.erase(tasks.begin() + taskNumber - 1);
    cout << "Task \"" << deletedTask << "\" has been removed." << endl;
}

int main() {
    vector<string> tasks;  // Vector to store tasks
    int choice;
    
    cout << "Welcome to the To-Do List Application!" << endl;
    
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
                addTask(tasks);
                break;
                
            case 2:
                viewTasks(tasks);
                break;
                
            case 3:
                deleteTask(tasks);
                break;
                
            case 4:
                cout << "\nGoodbye! Have a productive day!" << endl;
                break;
                
            default:
                cout << "Error: Invalid choice! Please enter a number from 1 to 4." << endl;
        }
        
    } while (choice != 4);
    
    return 0;
}