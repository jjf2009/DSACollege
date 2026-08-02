#include <iostream>
#include <string>
#include "stack.hpp"
using namespace std;

int main () {
    string value;
    cout<<"Enter your expression:";
    getline(cin,value);
    Stack<char>::ExpressionChecker(value);
    return 0;
}