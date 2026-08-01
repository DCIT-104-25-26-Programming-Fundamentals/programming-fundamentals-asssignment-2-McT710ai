#include <iostream>
using namespace std;

// PART A: Function to print the first N terms of the Fibonacci sequence
void printFibonacciSequence(int n) {
    // Validate input
    if (n <= 0) {
        cout << "Error: Number of terms must be positive." << endl;
        return;
    }
    
    cout << "Fibonacci sequence: ";
    
    // Handle special cases
    if (n == 1) {
        cout << "0" << endl;
        return;
    }
    
    if (n == 2) {
        cout << "0 1" << endl;
        return;
    }
    
    // Print first two terms
    cout << "0 1";
    
    // Generate and print remaining terms
    long long prev1 = 0;  // First term
    long long prev2 = 1;  // Second term
    long long current;
    
    for (int i = 3; i <= n; i++) {
        current = prev1 + prev2;
        cout << " " << current;
        prev1 = prev2;
        prev2 = current;
    }
    cout << endl;
}

// PART B: Function to check if a number belongs to the Fibonacci sequence
bool isFibonacciNumber(int num) {
    // 0 and 1 are Fibonacci numbers
    if (num == 0 || num == 1) {
        return true;
    }
    
    // Generate Fibonacci numbers until we reach or exceed the input number
    long long prev1 = 0;
    long long prev2 = 1;
    long long current;
    
    while (true) {
        current = prev1 + prev2;
        
        if (current == num) {
            return true;  // Found the number in the sequence
        }
        
        if (current > num) {
            return false;  // Exceeded the number, so it's not in the sequence
        }
        
        prev1 = prev2;
        prev2 = current;
    }
}

int main() {
    int choice;
    
    cout << "=== Fibonacci Sequence Operations ===" << endl;
    cout << "1. Print first N terms" << endl;
    cout << "2. Check if a number is Fibonacci" << endl;
    cout << "Enter your choice (1-2): ";
    cin >> choice;
    
    switch(choice) {
        case 1: {
            // PART A: Print first N terms
            int n;
            cout << "How many terms? ";
            cin >> n;
            printFibonacciSequence(n);
            break;
        }
        
        case 2: {
            // PART B: Check if number is Fibonacci
            int number;
            cout << "Enter a number to check: ";
            cin >> number;
            
            if (number < 0) {
                cout << "Error: Please enter a non-negative number." << endl;
            } else if (isFibonacciNumber(number)) {
                cout << number << " is a Fibonacci number." << endl;
            } else {
                cout << number << " is NOT a Fibonacci number." << endl;
            }
            break;
        }
        
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
}