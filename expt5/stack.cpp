#include <iostream>
#include <string>
#include "stack.hpp"
using namespace std;

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    checkExpression(expr);

    return 0;
}