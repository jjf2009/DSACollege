#include <iostream>
using namespace std;
class Bird{
public:
    void fly(){
        cout<<"Flying"<<endl;
    }
};
class Mammal{
public:
    virtual void  giving_birth(){
        cout<<"Giving Birth"<<endl;
    }
};
class Bat: public Bird , public Mammal{
public:
    void giving_birth() override { 
        cout<<"Giving_Birth while flying"<<endl;
    }
};
int main(){
    Bat bat1;
    bat1.giving_birth();
}