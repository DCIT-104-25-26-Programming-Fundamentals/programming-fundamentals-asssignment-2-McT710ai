#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to display the main menu
void displayMenu() {
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

// Function to get two numbers from the user
void getNumbers(double& num1, double& num2) {
    cout << "Enter first number : ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
}

// 1. Addition function
double add(double a, double b) {
    return a + b;
}

// 2. Subtraction function
double subtract(double a, double b) {
    return a - b;
}

// 3. Multiplication function
double multiply(double a, double b) {
    return a * b;
}

// 4. Division function
double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        return 0;  // Return 0 as a safe default
    }
    return a / b;
}

// 5. Modulus function (only works with integers)
int modulus(int a, int b) {
    if (b == 0) {
        cout << "Error: Cannot calculate modulus with zero." << endl;
        return 0;
    }
    return a % b;
}

// 6. Exponentiation function
double power(double base, double exponent) {
    return pow(base, exponent);
}

int main() {
    int choice;
    double num1, num2;
    
    cout << "Welcome to the Simple Calculator!" << endl;
    
    do {
        displayMenu();
        cin >> choice;
        
        // Handle invalid input (non-integer)
        if (cin.fail()) {
            cin.clear();  // Clear error state
            cin.ignore(10000, '\n');  // Discard invalid input
            cout << "Error: Please enter a number between 1 and 7." << endl;
            continue;
        }
        
        // Process user choice
        switch(choice) {
            case 1: {  // Addition
                getNumbers(num1, num2);
                double result = add(num1, num2);
                cout << fixed << setprecision(2);
                cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                break;
            }
            
            case 2: {  // Subtraction
                getNumbers(num1, num2);
                double result = subtract(num1, num2);
                cout << fixed << setprecision(2);
                cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                break;
            }
            
            case 3: {  // Multiplication
                getNumbers(num1, num2);
                double result = multiply(num1, num2);
                cout << fixed << setprecision(2);
                cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                break;
            }
            
            case 4: {  // Division
                getNumbers(num1, num2);
                if (num2 != 0) {
                    double result = divide(num1, num2);
                    cout << fixed << setprecision(2);
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                }
                // Error message is already printed inside divide() function
                break;
            }
            
            case 5: {  // Modulus
                int int1, int2;
                cout << "Enter first number : ";
                cin >> int1;
                cout << "Enter second number: ";
                cin >> int2;
                
                // Validate that inputs are non-negative for modulus
                if (int1 < 0 || int2 < 0) {
                    cout << "Error: Modulus operation requires non-negative integers." << endl;
                } else if (int2 == 0) {
                    cout << "Error: Cannot calculate modulus with zero." << endl;
                } else {
                    int result = modulus(int1, int2);
                    cout << "Result: " << int1 << " % " << int2 << " = " << result << endl;
                }
                break;
            }
            
            case 6: {  // Exponentiation
                getNumbers(num1, num2);
                double result = power(num1, num2);
                cout << fixed << setprecision(2);
                cout << "Result: " << num1 << " ^ " << num2 << " = " << result << endl;
                break;
            }
            
            case 7:  // Quit
                cout << "\nThank you for using the calculator. Goodbye!" << endl;
                break;
                
            default:
                cout << "Error: Invalid choice! Please select a number from 1 to 7." << endl;
        }
        
    } while (choice != 7);
    
    return 0;
}