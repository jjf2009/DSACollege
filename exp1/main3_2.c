#include <iostream>
using namespace std;
class Complex {
private:
    int real, imag;
public: 
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i; }
    Complex operator-() {   
        return Complex(-real,-imag); }
    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);}
    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);};
ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real << " + " << c.imag << "i";
    return out;}
istream& operator>>(istream& in, Complex& c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;}
int main() {
    Complex c1, c2, c3;
    cout << "Enter first complex number:\n";
    cin >> c1;
    cout << "Enter second complex number:\n";
    cin >> c2;
    c3 = c1 + c2;
    Complex c4 = -c1;
    cout << "\nComplex numbers are:\n";
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = c1 + c2 = " << c3 << endl;
    cout << "c4 = -c1 = " << c4 << endl;
    return 0;}