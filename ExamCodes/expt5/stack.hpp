#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack{
    private:
    vector<T> elements;
    unsigned long  MAX_SIZE = 100;

    public:
    bool flag=true;
    void push(T val);
    void pop();
    T top();
    void display();
    bool isfull();
    bool isempty();
    bool isMatching(char open,char close);
    void ExpressionChecker(string &expr)
};

template <typename T>
void Stack<T>::push(T val){
   if(isfull){
    cout<<"The expression is unbalanced";
    cout<<"Overflow occuried";
   }
   else{
    elements.push_back(val);
   }
};

template<typename T>
void Stack<T>::pop(){
   if(isempty()){
    cout<<"The expression is unbalanced";
    cout<<"Underflow has occuried"
    flag=false;
   }
   else{
    elements.pop_back();
   }
}

template<typename T>
T Stack<T>::top(){
    if(!isempty){
        return elements.back()
    }
    return '\0';
}

template<typename T>
bool Stack<T>::isfull(){
return elements.size() >= MAX_SIZE;
}

template<typename T>
bool Stack<T>::isempty(){
    return elements.empty();
}
template<typename T>
void Stack<T>::display(){
    for(int i = elements.size()-1;i>=0;i--){
        cout<<elements[i]<<" ";
    }
    cout<<endl;
}

template<typename T>
bool Stack<T>::isMatching(char open,char close){
    return((open=='('&& close==')')||(open=='['&&close==']')||(open=='{'||close='}'));
}
template<typename T>
void Stack<T>::ExpressionChecker(string &expr){
    Stack<char> st;
    for(char c :expr){
        if(c=='('||c=='{'||c=='['){
                st.push(c);
            }
        }else if((c==')'||c=='}'||c==']')){
            if(st.isempty()){
              st.pop();
               break;
            }else if (!isMatching(st.top(),c)){
                cout<<"The statment is unbalanced\m";
                cout << "Mismatched brackets: expected match for '" << st.top()
                     << "' but found '" << c << "'\n";
                     return;
        }else{
            st.pop();
        }
    }

    if(!st.isempty()&&st.flag==true){
        cout<<"The statement is unbalanced\n";
        if(st.top()=='('||st.top()=='{'||st.top()=='['){
            cout<<"There is overflow\n";
        }else {
            cout<<"There is undeflow\n";
        }
    }else if (st.isempty() && st.flag ==true){
        cout<<"It is balanced\n";
    }
}

