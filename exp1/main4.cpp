//Write a C++ program to understand overloading of unary operators, binary operators and insertion and extraction operators
#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    Complex() :real(0), imag(0) {}
    Complex(float r, float i) :real(r), imag(i) {}

    Complex operator-() const {
        return Complex(-real, -imag);
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0)
            out <<" + " <<c.imag <<"i";
        else
            out <<" - " <<-c.imag <<"i";
        return out;
    }

    friend istream& operator>>(istream& in, Complex& c) {
        cout <<"Enter real part: ";
        in >>c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }
};

int main() {
    Complex c1, c2;
    cout <<"Enter first complex number:\n";
    cin >>c1;
    cout <<"Enter second complex number:\n";
    cin >>c2;

    cout <<"\nFirst complex number: " <<c1 <<endl;
    cout <<"Second complex number: " <<c2 <<endl;

    Complex neg = -c1;
    cout <<"\nUnary minus of first complex number: " <<neg <<endl;

    Complex sum =c1+c2;
    cout <<"Sum of the two complex numbers: " <<sum <<endl;

    return 0;
}