#ifndef PALINDROME_H
#define PALINDROME_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Required for std::reverse

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


void PalindromeChecker::enqueue(char item) {
    charQueue.push_back(item);
}


char PalindromeChecker::dequeue() {
    if (isEmpty()) {
        throw out_of_range("Dequeue attempted on an empty queue.");
    }

    char front = charQueue.back(); 

    charQueue.pop_back();
    
    return front;
}


bool PalindromeChecker::isEmpty() const {
    return charQueue.empty();
}


#ifndef PALINDROME_H
#define PALINDROME_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Required for std::reverse

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


void PalindromeChecker::enqueue(char item) {
    charQueue.push_back(item);
}


char PalindromeChecker::dequeue() {
    if (isEmpty()) {
        throw out_of_range("Dequeue attempted on an empty queue.");
    }

    char front = charQueue.back(); 

    charQueue.pop_back();
    
    return front;
}


bool PalindromeChecker::isEmpty() const {
    return charQueue.empty();
}




bool PalindromeChecker::isPalindrome(const string& str) {

    charQueue.clear(); 

    if (str.empty()) {
        return true; 
    }

    for (char c : str) {
            enqueue(tolower(c));
        }
    
    string cleanedStr;
    for (char c : str) {
            cleanedStr += tolower(c);
    }
    
    string reversedStr = cleanedStr;
    std::reverse(reversedStr.begin(), reversedStr.end());

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

bool PalindromeChecker::isPalindrome(const string& str) {

    charQueue.clear(); 

    if (str.empty()) {
        return true; 
    }

    for (char c : str) {
            enqueue(tolower(c));
        }
    
    string cleanedStr;
    for (char c : str) {
            cleanedStr += tolower(c);
    }
    
    string reversedStr = cleanedStr;
    std::reverse(reversedStr.begin(), reversedStr.end());

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