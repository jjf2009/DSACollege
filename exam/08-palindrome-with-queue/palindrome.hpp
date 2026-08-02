#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class PalindromeChecker {
    private:
        vector<char> chracterarry;
        bool isempty() const ;
        void enqnue(char item);
        char dequeue();
    
    public:
     bool  isPalindrome(const string &str);
};

bool PalindromeChecker::isempty()const {
   return chracterarry.empty();
}

void PalindromeChecker::enqnue(char c){
   chracterarry.push_back(c);
}

char PalindromeChecker::dequeue(){
     if(isempty()){
        cout<<"The Queue is Empty";
        return;
     }
     char chr = chracterarry.front();
     chracterarry.erase(chracterarry.begin());
     return chr;
}

bool PalindromeChecker::isPalindrome(const string &input){
            
    if(input.empty()){
        return true;
    }

      for (char c : input) {
        enqnue(tolower(c));
    }


    string cleanstring;
    for(char c:input){
        cleanstring+=tolower(c);
    }

    string reversestring= cleanstring;
    reverse(reversestring.begin(),reversestring.end());

    for(char str:reversestring){
        char value = dequeue();
        if(str!=value){
            chracterarry.clear();
            return false;
        }
        chracterarry.clear();
        return true;
    }






}