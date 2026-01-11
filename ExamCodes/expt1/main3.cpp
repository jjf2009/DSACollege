#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imag;   // FIX: renamed from `complex` (reserved/confusing identifier)

public:
    // Constructor
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // FIX: operator+ should add both numbers, not modify input
    // FIX: pass by const reference
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // FIX: operator- should subtract, not negate only `c`
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // FIX: Display should not take another object
    void display() const {
        cout << "Real part: " << real << endl;
        cout << "Imaginary part: " << imag << endl;
    }
};

int main() {
    int r1, i1, r2, i2;

    // FIX: missing semicolon + incorrect input syntax
    cout << "Enter real and imaginary part of complex number 1: ";
    cin >> r1 >> i1;

    cout << "Enter real and imaginary part of complex number 2: ";
    cin >> r2 >> i2;

    Complex c1(r1, i1);
    Complex c2(r2, i2);

    Complex sum = c1 + c2;   // operator overloading in action
    Complex diff = c1 - c2;

    cout << "\nAddition Result:\n";
    sum.display();

    cout << "\nSubtraction Result:\n";
    diff.display();

    return 0;
}
