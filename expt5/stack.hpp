#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> elements;
    int capacity;

public:
    Stack(int cap = 100) { 
        capacity = cap;
    }

    void push(T val) {
        if (elements.size() < capacity) {
            elements.push_back(val);
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        } else {
            cout << "Stack underflow!" << endl;
        }
    }

    T top() {
        if (!elements.empty()) {
            return elements.back();
        }
        else {
            return '\0';
        }
    }

    bool empty() {
        return elements.empty();
    }

    int size() {
        return elements.size();
    }
};


