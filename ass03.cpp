#include <iostream>
using namespace std;

// Function to calculate the sum of array elements
int calculateSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to calculate the average of array elements
double calculateAverage(int arr[], int size) {
    int sum = calculateSum(arr, size);
    return static_cast<double>(sum) / size;
}

// Function to find the maximum value in the array
int findMaximum(int arr[], int size) {
    int max = arr[0];  // Initialize with first element
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum value in the array
int findMinimum(int arr[], int size) {
    int min = arr[0];  // Initialize with first element
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int n;
    
    // Get the number of elements
    cout << "How many numbers? ";
    cin >> n;
    
    // Validate input
    if (n <= 0) {
        cout << "Error: Number of elements must be positive." << endl;
        return 1;
    }
    
    // Create array and read numbers
    int numbers[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }
    
    // Calculate statistics
    int sum = calculateSum(numbers, n);
    double average = calculateAverage(numbers, n);
    int max = findMaximum(numbers, n);
    int min = findMinimum(numbers, n);
    
    // Display results
    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;
    
    return 0;
}