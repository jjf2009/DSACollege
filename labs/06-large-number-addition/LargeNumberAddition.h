#ifndef LARGE_NUMBER_ADDITION_H
#define LARGE_NUMBER_ADDITION_H

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

template <typename T>
class LargeNumberAddition {
private:
    string num1;
    string num2;
    
public:
    LargeNumberAddition(T n1, T n2);
    string add();
    void display();
    string numberToString(T number);
};


template <typename T>
string LargeNumberAddition<T>::numberToString(T number) {
    ostringstream oss;
    oss << number;
    return oss.str();
}

template <typename T>
LargeNumberAddition<T>::LargeNumberAddition(T n1, T n2) {
    num1 = numberToString(n1);
    num2 = numberToString(n2);
}


template <typename T>
string LargeNumberAddition<T>::add() {
    string s1 = num1;
    string s2 = num2;
    

    size_t dot1 = s1.find('.');
    size_t dot2 = s2.find('.');
    int decimalPlaces = 0;
    

    if (dot1 != string::npos) {
        decimalPlaces = max(decimalPlaces, (int)(s1.length() - dot1 - 1));
    }
    if (dot2 != string::npos) {
        decimalPlaces = max(decimalPlaces, (int)(s2.length() - dot2 - 1));
    }
    

    s1.erase(std::remove(s1.begin(), s1.end(), '.'), s1.end());
    s2.erase(std::remove(s2.begin(), s2.end(), '.'), s2.end());
    

    while (s1.length() < s2.length()) s1 = "0" + s1;
    while (s2.length() < s1.length()) s2 = "0" + s2;
    

    stack<char> stack1, stack2, resultStack;

    for (char c : s1) stack1.push(c);
    for (char c : s2) stack2.push(c);
    
    int carry = 0;
    

    while (!stack1.empty() || !stack2.empty() || carry) {
        int digit1 = 0, digit2 = 0;
        
        if (!stack1.empty()) {
            digit1 = stack1.top() - '0'; 
            stack1.pop();
        }
        
        if (!stack2.empty()) {
            digit2 = stack2.top() - '0';
            stack2.pop();
        }
        
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;                  
        resultStack.push((sum % 10) + '0'); 
    }
    

    string result = "";
    while (!resultStack.empty()) {
        result += resultStack.top();
        resultStack.pop();
    }
    

    if (decimalPlaces > 0) {

        while (result.length() <= decimalPlaces) {
            result = "0" + result;
        }
        

        result.insert(result.length() - decimalPlaces, ".");
        

        while (result.back() == '0') {
            result.pop_back();
        }
        if (result.back() == '.') {
            result.pop_back();
        }
    }
    
    return result;
}


template <typename T>
void LargeNumberAddition<T>::display() {
    cout << "Number 1: " << num1 << endl;
    cout << "Number 2: " << num2 << endl;
    cout << "Sum: " << add() << endl;
}

#endif