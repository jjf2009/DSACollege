//AOFBN.hpp
#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#include <type_traits>
#include <algorithm>

template <class T>
class BigAdder {
private:
    std::stack<int> integerStack1, integerStack2, integerResultStack;
    std::stack<int> fractionalStack1, fractionalStack2, fractionalResultStack;
    int integerCarry = 0, fractionalCarry = 0;
    T firstNumber, secondNumber;
    
    void addStacks(std::stack<int>& stack1, std::stack<int>& stack2, std::stack<int>& resultStack, int& carry);
    std::stack<int> reverseStack(std::stack<int> s);
    
public:
    BigAdder(T num1, T num2);
    void number_to_stack();
    void add();
    void show_result();
};


template <class T>
BigAdder<T>::BigAdder(T num1, T num2) : firstNumber(num1), secondNumber(num2) {}

template <class T>
std::stack<int> BigAdder<T>::reverseStack(std::stack<int> s) {
    std::stack<int> reversed;
    while (!s.empty()) {
        reversed.push(s.top());
        s.pop();
    }
    return reversed;
}

template <class T>
void BigAdder<T>::addStacks(std::stack<int>& stack1, std::stack<int>& stack2, std::stack<int>& resultStack, int& carry) {
    std::stack<int> tempResult;
     bool hasDecimal = !fractionalStack1.empty() || !fractionalStack2.empty();
    
    while (!stack1.empty() || !stack2.empty()) {
        int digit1 = 0, digit2 = 0;
        
        if (!stack1.empty()) {
            digit1 = stack1.top();
            stack1.pop();
        }
        if (!stack2.empty()) {
            digit2 = stack2.top();
            stack2.pop();
        }
        
        int total = digit1 + digit2 + carry;
        tempResult.push(total % 10);
        carry = total / 10;
    }
    if(!hasDecimal){
        resultStack = tempResult;
    }else{
       resultStack = reverseStack(tempResult);
    }
   
}

template <class T>
void BigAdder<T>::number_to_stack() {
    if (std::is_integral<T>::value) {
        T temporary1 = firstNumber, temporary2 = secondNumber;
        
        while (temporary1 > 0) {
            integerStack1.push(static_cast<int>(temporary1) % 10);
            std:: cout<<static_cast<int>(temporary1) % 10<< std::endl;
            temporary1 /= 10;
        }
        while (temporary2 > 0) {
            integerStack2.push(static_cast<int>(temporary2) % 10);
            std::cout<<static_cast<int>(temporary2) % 10<<std::endl;
            temporary2 /= 10;
        }
        
        integerStack1 = reverseStack(integerStack1);
        integerStack2 = reverseStack(integerStack2);
    } 
    else if (std::is_floating_point<T>::value) {
        long long wholePart1 = static_cast<long long>(firstNumber);
        long long wholePart2 = static_cast<long long>(secondNumber);
        T decimalPart1 = firstNumber - wholePart1;
        T decimalPart2 = secondNumber - wholePart2;
        // std::cout<<decimalPart1;
        //  std::cout<<decimalPart2;
        
        // Push integer digits
        while (wholePart1 > 0) {
            integerStack1.push(wholePart1 % 10);
                //  std::cout<<static_cast<int>(wholePart1) % 10<<std::endl;
            wholePart1 /= 10;
        }
        while (wholePart2 > 0) {
            integerStack2.push(wholePart2 % 10);
                //  std::cout<<static_cast<int>(wholePart2) % 10<<std::endl;
            wholePart2 /= 10;
        }
        
        integerStack1 = reverseStack(integerStack1);
        integerStack2 = reverseStack(integerStack2);
        
        const int decimalPrecision = 6;
        for (int i = 0; i < decimalPrecision; i++) {
            decimalPart1 *= 10;
            decimalPart2 *= 10;
            std::cout<<static_cast<int>(decimalPart1) % 10<<std::endl;
            fractionalStack1.push(static_cast<int>(decimalPart1) % 10);
            std::cout<<static_cast<int>(decimalPart2) % 10<<std::endl;
            fractionalStack2.push(static_cast<int>(decimalPart1) % 10);
        }
        fractionalStack1 = reverseStack(fractionalStack1);
        fractionalStack2 = reverseStack(fractionalStack2);
    }
}

template <class T>
void BigAdder<T>::add() {
    bool hasDecimal = !fractionalStack1.empty() || !fractionalStack2.empty();
    
    if (!hasDecimal) {
        addStacks(integerStack1, integerStack2, integerResultStack, integerCarry);
        if (integerCarry) {
            std::stack<int> temp;
            temp.push(integerCarry);
            while (!integerResultStack.empty()) {
                temp.push(integerResultStack.top());
                integerResultStack.pop();
            }
            integerResultStack = temp;
        }

    } else {
        // Equalize fractional stack sizes
        while (fractionalStack1.size() < fractionalStack2.size()) 
            fractionalStack1.push(0);
        while (fractionalStack2.size() < fractionalStack1.size()) 
            fractionalStack2.push(0);
        
        // Reverse fractional stacks for right-to-left addition
        fractionalStack1 = reverseStack(fractionalStack1);
        fractionalStack2 = reverseStack(fractionalStack2);
        
        addStacks(fractionalStack1, fractionalStack2, fractionalResultStack, fractionalCarry);
        addStacks(integerStack1, integerStack2, integerResultStack, integerCarry);
        
        if (fractionalCarry) {
            integerCarry += fractionalCarry;
            std::stack<int> temp = integerResultStack;
            integerResultStack = std::stack<int>();
            
            std::stack<int> reversed = reverseStack(temp);
            int firstDigit = reversed.top();
            reversed.pop();
            
            int total = firstDigit + fractionalCarry;
            integerCarry = total / 10;
            
            std::stack<int> newResult;
            newResult.push(total % 10);
            while (!reversed.empty()) {
                newResult.push(reversed.top());
                reversed.pop();
            }
            integerResultStack = reverseStack(newResult);
        }
        
        if (integerCarry) {
            std::stack<int> temp;
            temp.push(integerCarry);
            while (!integerResultStack.empty()) {
                temp.push(integerResultStack.top());
                integerResultStack.pop();
            }
            integerResultStack = temp;
        }
    }
}

template <class T>
void BigAdder<T>::show_result() {
    bool hasDecimal = !fractionalResultStack.empty();
    std::cout << "Result: ";
    
    std::vector<int> intVec, fracVec;
    std::stack<int> tempInt = integerResultStack;
    std::stack<int> tempFrac = fractionalResultStack;
    
    while (!tempInt.empty()) {
        intVec.push_back(tempInt.top());
        tempInt.pop();
    }
    
    for (int digit : intVec) 
        std::cout << digit;
    
    if (hasDecimal) {
        std::cout << ".";
        while (!tempFrac.empty()) {
            fracVec.push_back(tempFrac.top());
            tempFrac.pop();
        }
        for (int digit : fracVec) 
            std::cout << digit;
    }
    std::cout << std::endl;
}