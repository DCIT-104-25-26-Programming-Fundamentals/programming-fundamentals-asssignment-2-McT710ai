#include <iostream>
#include <iomanip>
using namespace std;

// PART A: Function to print multiplication table for a single number
void printSingleTable(int num) {
    cout << "\nMultiplication Table for " << num << ":" << endl;
    cout << "----------------------------" << endl;
    
    for (int i = 1; i <= 12; i++) {
        cout << setw(2) << num << "  x  " << setw(2) << i << "  =  " << setw(3) << num * i << endl;
    }
}

// PART B: Function to print multiplication tables from 1 to N
void printTablesUpToN(int n) {
    // Validate input
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }
    
    cout << "\n=== FULL MULTIPLICATION TABLES (1 to " << n << ") ===" << endl;
    
    for (int num = 1; num <= n; num++) {
        // Print table header
        cout << "\nMultiplication Table for " << num << ":" << endl;
        cout << "----------------------------" << endl;
        
        // Print multiplication table for current number
        for (int i = 1; i <= 12; i++) {
            cout << setw(2) << num << "  x  " << setw(2) << i << "  =  " << setw(3) << num * i << endl;
        }
        
        // Add separator line between tables (except after the last one)
        if (num < n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int choice;
    
    cout << "=== Multiplication Table Generator ===" << endl;
    cout << "1. Print table for a single number" << endl;
    cout << "2. Print tables from 1 to N" << endl;
    cout << "Enter your choice (1-2): ";
    cin >> choice;
    
    switch(choice) {
        case 1: {
            // PART A: Single table
            int number;
            cout << "Enter a number: ";
            cin >> number;
            printSingleTable(number);
            break;
        }
        
        case 2: {
            // PART B: Tables from 1 to N
            int n;
            cout << "Enter N (positive integer): ";
            cin >> n;
            
            if (n <= 0) {
                cout << "Error: N must be a positive integer." << endl;
            } else {
                printTablesUpToN(n);
            }
            break;
        }
        
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
}