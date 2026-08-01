#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    // Numbers less than 2 are not prime
    if (n < 2) {
        return false;
    }
    
    // Check for divisors from 2 to sqrt(n)
    // We only need to check up to sqrt(n) because if n has a divisor 
    // greater than sqrt(n), it must have a corresponding divisor less than sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;  // Found a divisor, not prime
        }
    }
    
    return true;  // No divisors found, number is prime
}

int main() {
    int number;
    
    // Get input from user
    cout << "Enter a number: ";
    cin >> number;
    
    // Check if the number is prime and display the result
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is NOT a prime number." << endl;
    }
    
    return 0;
}