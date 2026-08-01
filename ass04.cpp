#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

// Function to display a matrix with proper formatting
void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to read a matrix from user input
void readMatrix(int matrix[][MAX_SIZE], int rows, int cols, const string& name) {
    cout << "Enter elements for matrix " << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// PART A: Transpose a matrix
void transposeMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    int transposed[MAX_SIZE][MAX_SIZE];
    
    // Compute transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    // Display original matrix
    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix, rows, cols);
    
    // Display transposed matrix
    cout << "Transposed Matrix:" << endl;
    displayMatrix(transposed, cols, rows);
}

// PART B: Add two matrices
void addMatrices(int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];
    
    // Compute element-wise sum
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    
    // Display matrices
    cout << "\nMatrix A:" << endl;
    displayMatrix(matrixA, rows, cols);
    
    cout << "Matrix B:" << endl;
    displayMatrix(matrixB, rows, cols);
    
    cout << "Sum (A + B):" << endl;
    displayMatrix(result, rows, cols);
}

// PART C: Multiply two matrices
void multiplyMatrices(int matrixA[][MAX_SIZE], int rowsA, int colsA, 
                      int matrixB[][MAX_SIZE], int rowsB, int colsB) {
    // Check if multiplication is possible
    if (colsA != rowsB) {
        cout << "Error: Matrix multiplication not possible!" << endl;
        cout << "Number of columns in A (" << colsA << ") must equal number of rows in B (" << rowsB << ")" << endl;
        return;
    }
    
    int result[MAX_SIZE][MAX_SIZE] = {0};  // Initialize with zeros
    
    // Compute matrix multiplication
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    
    // Display matrices
    cout << "\nMatrix A (" << rowsA << " x " << colsA << "):" << endl;
    displayMatrix(matrixA, rowsA, colsA);
    
    cout << "Matrix B (" << rowsB << " x " << colsB << "):" << endl;
    displayMatrix(matrixB, rowsB, colsB);
    
    cout << "Product (A x B) (" << rowsA << " x " << colsB << "):" << endl;
    displayMatrix(result, rowsA, colsB);
}

int main() {
    int choice;
    
    cout << "=== Matrix Operations Menu ===" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    
    switch(choice) {
        case 1: {
            // PART A: Transpose
            int rows, cols;
            int matrix[MAX_SIZE][MAX_SIZE];
            
            cout << "\nEnter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;
            
            if (rows <= 0 || rows > MAX_SIZE || cols <= 0 || cols > MAX_SIZE) {
                cout << "Error: Invalid dimensions!" << endl;
                break;
            }
            
            readMatrix(matrix, rows, cols, "");
            transposeMatrix(matrix, rows, cols);
            break;
        }
        
        case 2: {
            // PART B: Addition
            int rows, cols;
            int matrixA[MAX_SIZE][MAX_SIZE];
            int matrixB[MAX_SIZE][MAX_SIZE];
            
            cout << "\nEnter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;
            
            if (rows <= 0 || rows > MAX_SIZE || cols <= 0 || cols > MAX_SIZE) {
                cout << "Error: Invalid dimensions!" << endl;
                break;
            }
            
            readMatrix(matrixA, rows, cols, "A");
            readMatrix(matrixB, rows, cols, "B");
            addMatrices(matrixA, matrixB, rows, cols);
            break;
        }
        
        case 3: {
            // PART C: Multiplication
            int rowsA, colsA, rowsB, colsB;
            int matrixA[MAX_SIZE][MAX_SIZE];
            int matrixB[MAX_SIZE][MAX_SIZE];
            
            cout << "\nEnter rows for matrix A: ";
            cin >> rowsA;
            cout << "Enter columns for matrix A: ";
            cin >> colsA;
            
            cout << "Enter rows for matrix B: ";
            cin >> rowsB;
            cout << "Enter columns for matrix B: ";
            cin >> colsB;
            
            if (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE ||
                rowsB <= 0 || rowsB > MAX_SIZE || colsB <= 0 || colsB > MAX_SIZE) {
                cout << "Error: Invalid dimensions!" << endl;
                break;
            }
            
            readMatrix(matrixA, rowsA, colsA, "A");
            readMatrix(matrixB, rowsB, colsB, "B");
            multiplyMatrices(matrixA, rowsA, colsA, matrixB, rowsB, colsB);
            break;
        }
        
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
}