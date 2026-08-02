#ifndef PALINDROME_H
#define PALINDROME_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for std::reverse

using namespace std;

class PalindromeChecker {
private:
    vector<char> charQueue;

    void enqueue(char item);
    char dequeue();
    bool isEmpty() const;

public:
    bool isPalindrome(const string& str);
};

// Add character to the queue (back)
void PalindromeChecker::enqueue(char item) {
    charQueue.push_back(item);
}

// Remove character from the queue (front)
char PalindromeChecker::dequeue() {
    if (isEmpty()) {
        throw out_of_range("Dequeue attempted on an empty queue.");
    }
    char front = charQueue.front();
    charQueue.erase(charQueue.begin());
    return front;
}

// Check if queue is empty
bool PalindromeChecker::isEmpty() const {
    return charQueue.empty();
}

// Check if a string is palindrome
bool PalindromeChecker::isPalindrome(const string& str) {
    charQueue.clear();

    if (str.empty()) {
        return true; // empty string considered palindrome
    }

    // Enqueue lowercase version of characters
    for (char c : str) {
        enqueue(tolower(c));
    }

    // Create cleaned string and reversed string
    string cleanedStr;
    for (char c : str) {
        cleanedStr += tolower(c);
    }

    string reversedStr = cleanedStr;
    reverse(reversedStr.begin(), reversedStr.end());

    // Compare characters from queue with reversed string
    for (char reversedChar : reversedStr) {
        char originalChar = dequeue();
        if (originalChar != reversedChar) {
            charQueue.clear();
            return false;
        }
    }

    charQueue.clear();
    return true;
}

#endif // PALINDROME_H
