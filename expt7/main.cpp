#include <iostream>
#include <string>
#include "Queue.h"
#include "PalindromeChecker.h"

using namespace std;

int main() {
    PalindromeChecker checker;
    string input;
    
    cout << "=== Palindrome Checker using Queue ===" << endl;
    cout << "Enter a string to check (or 'quit' to exit): ";
    
    while (getline(cin, input)) {
        if (input == "quit" || input == "exit") {
            cout << "Goodbye!" << endl;
            break;
        }
        
        if (input.empty()) {
            cout << "Please enter a valid string." << endl;
            cout << "\nEnter a string to check (or 'quit' to exit): ";
            continue;
        }
        
        // Set the string and check
        checker.setString(input);
        
        cout << "\nOriginal String: " << checker.getOriginalString() << endl;
        cout << "Reversed String: " << checker.getReversedString() << endl;
        
        if (checker.isPalindrome()) {
            cout << "Result: YES, it is a palindrome! ✓" << endl;
        } else {
            cout << "Result: NO, it is not a palindrome. ✗" << endl;
        }
        
        cout << "\nEnter a string to check (or 'quit' to exit): ";
    }
    
    return 0;
}