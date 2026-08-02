#include "palindrome.h"

int main() {
    PalindromeChecker checker;
    string inputStr;

    cout << "--- Palindrome Checker ---" << endl;
    cout << "Enter a string to check:";
    
    getline(cin, inputStr);

    if (inputStr.empty()) {
        cout << "No input provided. Exiting." << endl;
        return 0;
    }

    bool isPal = checker.isPalindrome(inputStr); 

    cout << "\nInput String: \"" << inputStr << "\"" << endl;
    if (isPal) {
        cout << "Result: the string is a palindrome." << endl;
    } else {
        cout << "Result: the string is NOT a palindrome." << endl;
    }

    return 0;
}