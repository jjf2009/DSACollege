#include <iostream>
#include <stdexcept>   // FIX: required for invalid_argument
using namespace std;

class Matrix {
private:
    int rows, cols;
    int **data;

public:
    // Constructor: allocate 2D dynamic array
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    // Destructor: FIXED delete[] usage
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];   // FIX: delete[] (not delete)
        }
        delete[] data;          // FIX: delete[]
    }

    // Input matrix elements
    void Inputdata() {
        cout << "Enter elements of matrix (" << rows << " x " << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {   // FIX: j++ (was i++)
                cin >> data[i][j];
            }
        }
    }

    // Display matrix
    void Displaydata() {
        cout << "Matrix (" << rows << " x " << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {   // FIX: j++ (was i++)
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Check equality of two matrices
    bool isEqual(Matrix& m) {
        // FIX: logical condition was wrong
        if (rows != m.rows || cols != m.cols)
            return false;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {   // FIX: j++
                if (data[i][j] != m.data[i][j]) { // FIX: direct data access
                    return false;               // FIX: missing semicolon
                }
            }
        }
        return true;
    }

    // Matrix addition
    Matrix add(Matrix& m) {
        if (rows != m.rows || cols != m.cols) {
            throw invalid_argument("Matrix dimensions must match for addition.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + m.data[i][j];
            }
        }
        return result;   // FIX: missing return
    }

    // Matrix subtraction
    Matrix sub(Matrix& m) {
        if (rows != m.rows || cols != m.cols) {
            throw invalid_argument("Matrix dimensions must match for subtraction.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - m.data[i][j];
            }
        }
        return result;   // FIX: missing return
    }

    // Matrix multiplication
    Matrix multiply(Matrix& m) {
        if (cols != m.rows) {
            throw invalid_argument("Invalid dimensions for multiplication.");
        }

        Matrix result(rows, m.cols);

        // FIX: proper matrix multiplication logic
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                result.data[i][j] = 0;   // FIX: initialize
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }
        return result;   // FIX: missing return
    }
};

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of Matrix 1: ";
    cin >> r1 >> c1;
    Matrix m1(r1, c1);
    m1.Inputdata();

    cout << "Enter rows and columns of Matrix 2: ";
    cin >> r2 >> c2;
    Matrix m2(r2, c2);
    m2.Inputdata();

    try {
        Matrix sum = m1.add(m2);
        cout << "\nAddition Result:\n";
        sum.Displaydata();

        Matrix diff = m1.sub(m2);
        cout << "\nSubtraction Result:\n";
        diff.Displaydata();

        if (c1 == r2) {
            Matrix prod = m1.multiply(m2);
            cout << "\nMultiplication Result:\n";
            prod.Displaydata();
        }
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
