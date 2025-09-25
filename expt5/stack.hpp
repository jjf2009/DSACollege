#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> elements;
    unsigned long MAX_SIZE = 100;

public:
    bool flag = true;  

    void push(T val) {
        if (isfull()) {
            cout << "The statement is unbalanced\n";
            cout << "There is overflow\n";
        } else {
            elements.push_back(val);
        }
    }

    void pop() {
        if (isempty()) {
            cout << "The statement is unbalanced\n";
            cout << "There is underflow\n";
            flag = false;
        } else {
            elements.pop_back();
        }
    }

    T top() {
        if (!isempty()) {
            return elements.back();
        }
        return '\0';
    }

    bool isempty() {
        return elements.empty();
    }

    bool isfull() {
        return elements.size() >= MAX_SIZE;
    }

    void display() {
        for (int i = elements.size() - 1; i >= 0; --i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

// Bracket matching logic
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}

void checkExpression(string &expr) {
    Stack<char> st;

    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (st.isempty()) {
                st.pop(); // will trigger underflow + flag = false
                break;
            } else if (!isMatching(st.top(), c)) {
                cout << "The statement is unbalanced\n";
                cout << "Mismatched brackets: expected match for '" << st.top()
                    << "' but found '" << c << "'\n";
                return;
            } else {
                st.pop();
            }
        }
    }

    // Final result check
    if (!st.isempty() && st.flag == true) {
        cout << "The statement is unbalanced\n";
        if (st.top() == '(' || st.top() == '{' || st.top() == '[') {
            cout << "There is overflow\n";
        } else {
            cout << "There is underflow\n";
        }
    } else if (st.isempty() && st.flag == true) {
        cout << "It is balanced\n";
    }
}