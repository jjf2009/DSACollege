// Design a class matrix using constructors and use dynamic resourfce allocation using pointers to 2 dimensional array with also distructors operations with same class name.Write func for reading,displaying,addition,subtraction,multiplication and also check if matrix afe equal or not.

#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** data;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c){
        data = new int*[rows];
        for (int i = 0; i < rows; i++)
            data[i] = new int[cols];
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }

    // Input Function
    void read() {
        cout << "Enter elements of matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> data[i][j];
    }

    // Display Function
    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }

    // Equality Check
    bool isEqual( Matrix other) {
        if (rows != other.rows || cols != other.cols) return false;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (data[i][j] != other.data[i][j]) return false;
        return true;
    }

    // Addition
    Matrix add(Matrix other) {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions must match for addition.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    // Subtraction
    Matrix subtract( Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions must match for subtraction.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    // Multiplication
    Matrix multiply( Matrix& other)  {
        if (cols != other.rows) {
            throw invalid_argument("Matrix multiplication condition not satisfied.");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++)
                    result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
        return result;
    }
};

int main() {
    int r1, c1, r2, c2, choice;

    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;
    Matrix m1(r1, c1);
    m1.read();

    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;
    Matrix m2(r2, c2);
    m2.read();

    cout << "\nMatrix 1:\n"; m1.display();
    cout << "\nMatrix 2:\n"; m2.display();

    cout << "\n------ Matrix Operations Menu ------\n";
    cout << "1. Check Equality\n";
    cout << "2. Addition\n";
    cout << "3. Subtraction\n";
    cout << "4. Multiplication\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    try {
        switch (choice) {
            case 1:
                if (m1.isEqual(m2))
                    cout << "\nMatrices are equal.\n";
                else
                    cout << "\nMatrices are not equal.\n";
                break;

            case 2: {
                cout << "\nAddition:\n";
                Matrix sum = m1.add(m2);
                sum.display();
                break;
                }
            case 3: {
                cout << "\nSubtraction:\n";
                Matrix diff = m1.subtract(m2);
                diff.display();
                break;
                }

            case 4: {
                cout << "\nMultiplication:\n";
                Matrix prod = m1.multiply(m2);
                prod.display();
                break;
                }

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
