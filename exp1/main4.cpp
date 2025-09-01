#include <iostream>
using namespace std;
class Number {
private:
    int value;
public:
    Number(int v = 0) : value(v) {}
    Number operator<<( Number &obj) {
        return Number(value + obj.value);}
    Number operator>>( Number &obj) {
        return Number(value - obj.value);}
    Number operator+( Number &obj) {
        return Number(value + obj.value);}
    Number operator-() {
        return Number(-value);}
    void show() {
        cout << value << endl;}
};
int main() { +
    Number n1(10), n2(5), result;

    cout << "n1 = 10, n2 = 5\n";

    // Custom <<
    result = n1 << n2;
    cout << "n1 << n2 (custom addition): ";
    result.show();

    // Custom >>
    result = n1 >> n2;
    cout << "n1 >> n2 (custom subtraction): ";
    result.show();

    // Normal +
    result = n1 + n2;
    cout << "n1 + n2 (normal addition): ";
    result.show();

    // Normal -
    result = -n2;
     // Unary operator (-)
    result = -n1;
    cout << "Negation of first number: ";
    result.show();

    return 0;
}
