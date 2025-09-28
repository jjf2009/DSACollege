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

    // Declarations
    void push(T val);
    void pop();
    T top();
    bool isempty();
    bool isfull();
    void display();

    // Bracket logic as class members
    static bool isMatching(char open, char close);
    static void checkExpression(string &expr);
};

// ---------------- Function Definitions ----------------

template <typename T>
void Stack<T>::push(T val) {
    if (isfull()) {
        cout << "The statement is unbalanced\n";
        cout << "There is overflow\n";
    } else {
        elements.push_back(val);
    }
}

template <typename T>
void Stack<T>::pop() {
    if (isempty()) {
        cout << "The statement is unbalanced\n";
        cout << "There is underflow\n";
        flag = false;
    } else {
        elements.pop_back();
    }
}

template <typename T>
T Stack<T>::top() {
    if (!isempty()) {
        return elements.back();
    }
    return '\0';
}

template <typename T>
bool Stack<T>::isempty() {
    return elements.empty();
}

template <typename T>
bool Stack<T>::isfull() {
    return elements.size() >= MAX_SIZE;
}

template <typename T>
void Stack<T>::display() {
    for (int i = elements.size() - 1; i >= 0; --i) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

// ---------------- Bracket Matching Logic ----------------

template <typename T>
bool Stack<T>::isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

template <typename T>
void Stack<T>::checkExpression(string &expr) {
    Stack<char> st;

    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (st.isempty()) {
                st.pop();
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
