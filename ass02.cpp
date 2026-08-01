#include <iostream>
using namespace std;

// Function to determine the letter grade based on score
char getGrade(int score) {
    // Validate score range
    if (score < 0 || score > 100) {
        return '\0';  // Return null character for invalid input
    }
    
    // Determine grade based on score
    if (score >= 80 && score <= 100) {
        return 'A';
    } else if (score >= 70 && score <= 79) {
        return 'B';
    } else if (score >= 60 && score <= 69) {
        return 'C';
    } else if (score >= 50 && score <= 59) {
        return 'D';
    } else {  // score below 50
        return 'F';
    }
}

int main() {
    int score;
    
    // Get input from user
    cout << "Enter student score (0-100): ";
    cin >> score;
    
    // Get the grade
    char grade = getGrade(score);
    
    // Display result
    if (grade == '\0') {
        cout << "Error: Score must be between 0 and 100." << endl;
    } else {
        cout << "Grade: " << grade << endl;
    }
    
    return 0;
}