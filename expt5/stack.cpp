#include <iostream>
#include <string>
#include "stack.hpp"
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}

bool checkBalanced(const string &expr) {
    Stack<char> st(100);

    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (st.empty() || !isMatching(st.top(), c)) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (checkBalanced(expr)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }
    return 0;
}
