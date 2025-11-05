#ifndef LARGE_HPP
#define LARGE_HPP

#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

template <typename T>
class StackAddition {
private:
    stack<int> wholeDigits1, wholeDigits2, decimalDigits1, decimalDigits2, sumStack;
    int carryOver;
    int decimalPlaces; 
    bool isDecimalType;

    void storeDigits(long long num, stack<int>& destination) {
        if (num == 0)
            destination.push(0);
        else {
            stack<int> temporary;
            while (num > 0) {
                temporary.push(num % 10);
                num /= 10;
            }
            while (!temporary.empty()) {
                destination.push(temporary.top());
                temporary.pop();
            }
        }
    }

    void flipStack(stack<int>& source, stack<int>& target) {
        while (!source.empty()) {
            target.push(source.top());
            source.pop();
        }
    }

public:
    StackAddition() {
        carryOver = 0;
        decimalPlaces = 0;
        isDecimalType = false;
    }

    StackAddition(T num1, T num2, int places = 0) {
        carryOver = 0;
        decimalPlaces = places;
        isDecimalType = std::is_floating_point<T>::value;
        separateAndStore(num1, num2);
    }

    void separateAndStore(T num1, T num2) {
        if (!isDecimalType) {
            storeDigits(static_cast<long long>(num1), wholeDigits1);
            storeDigits(static_cast<long long>(num2), wholeDigits2);
        } else {
            long long wholePart1 = static_cast<long long>(floor(num1));
            long long wholePart2 = static_cast<long long>(floor(num2));

            double fractionalPart1 = fabs(num1 - wholePart1);
            double fractionalPart2 = fabs(num2 - wholePart2);

            long long fractionalAsInt1 = static_cast<long long>(round(fractionalPart1 * pow(10, decimalPlaces)));
            long long fractionalAsInt2 = static_cast<long long>(round(fractionalPart2 * pow(10, decimalPlaces)));

            storeDigits(wholePart1, wholeDigits1);
            storeDigits(wholePart2, wholeDigits2);

            storeDigits(fractionalAsInt1, decimalDigits1);
            storeDigits(fractionalAsInt2, decimalDigits2);
        }
    }

    void addStacksIntOnly() {
        stack<int> reversed1, reversed2;
        flipStack(wholeDigits1, reversed1);
        flipStack(wholeDigits2, reversed2);

        while (!reversed1.empty() || !reversed2.empty() || carryOver != 0) {
            int digit1 = 0, digit2 = 0;
            if (!reversed1.empty()) { digit1 = reversed1.top(); reversed1.pop(); }
            if (!reversed2.empty()) { digit2 = reversed2.top(); reversed2.pop(); }

            int total = digit1 + digit2 + carryOver;
            carryOver = total / 10;
            sumStack.push(total % 10);
        }
    }

    // Add float/double numbers (integer + fractional parts)
    void addStacksFloat() {
        // Add fractional parts first
        stack<int> reversedFrac1, reversedFrac2;
        flipStack(decimalDigits1, reversedFrac1);
        flipStack(decimalDigits2, reversedFrac2);

        int fractionalCarry = 0;
        stack<int> fractionalResult;

        while (!reversedFrac1.empty() || !reversedFrac2.empty()) {
            int digit1 = 0, digit2 = 0;
            if (!reversedFrac1.empty()) { digit1 = reversedFrac1.top(); reversedFrac1.pop(); }
            if (!reversedFrac2.empty()) { digit2 = reversedFrac2.top(); reversedFrac2.pop(); }

            int total = digit1 + digit2 + fractionalCarry;
            fractionalCarry = total / 10;
            fractionalResult.push(total % 10);
        }

        // If fractional result is longer than precision, adjust
        while ((int)fractionalResult.size() > decimalPlaces) fractionalResult.pop();

        // Carry into integer part
        carryOver = fractionalCarry;

        // Add integer parts
        addStacksIntOnly();

        // Append fractional result to output
        cout << "Sum = ";
        stack<int> tempResult = sumStack;
        while (!tempResult.empty()) {
            cout << tempResult.top();
            tempResult.pop();
        }

        cout << ".";

        stack<int> tempFractional;
        while (!fractionalResult.empty()) {
            tempFractional.push(fractionalResult.top());
            fractionalResult.pop();
        }

        while (!tempFractional.empty()) {
            cout << tempFractional.top();
            tempFractional.pop();
        }
        cout << endl;
    }

    // Public wrapper
    void addAndDisplay() {
        if (isDecimalType)
            addStacksFloat();
        else {
            addStacksIntOnly();
            cout << "Sum = ";
            while (!sumStack.empty()) {
                cout << sumStack.top();
                sumStack.pop();
            }
            cout << endl;
        }
    }
};

#endif