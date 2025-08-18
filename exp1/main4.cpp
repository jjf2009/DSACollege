#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    // Constructor
    Number(int v = 0) : value(v) {}

    // Display function
    void show() {
        cout << "Value: " << value << endl;
    }

    // Unary operator overloading (-)
    Number operator-() const {
        return Number(-value);
    }

    // Binary operator overloading (+)
    Number operator+(const Number &obj) const {
        return Number(value + obj.value);
    }

    // Function to read value
    void input() {
        cout << "Enter a number: ";
        cin >> value;
    }
};

int main() {
    Number n1, n2, result;

    cout << "Enter first number\n";
    n1.input();

    cout << "Enter second number\n";
    n2.input();

    cout << "\nOriginal numbers:" << endl;
    n1.show();
    n2.show();

    // Binary operator +
    result = n1 + n2;
    cout << "\nAfter adding n1 + n2:" << endl;
    result.show();

    // Unary operator -
    result = -n1;
    cout << "\nAfter negating n1:" << endl;
    result.show();

    return 0;
}
