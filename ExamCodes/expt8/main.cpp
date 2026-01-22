#include <iostream>
#include <string>
#include "h.hpp"
using namespace std;

int main(){
    PalindromeChecker checker;
    string InputStr;
    cout<<"Enter your string:";
    getline(cin,InputStr);
    
    if(InputStr.empty()){
        cout<<"Kinldy add a input";
    }

    bool isPal = checker.isPalindrome(InputStr);

    cout<<"The Entered String:"<<InputStr;

    if(isPal){
        cout<<"the String is a Palindrome";
    }else{
        cout<<"The String is not a Palindrome";
    }
}