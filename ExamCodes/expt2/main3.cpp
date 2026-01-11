#include <iostream>
using namespace std;

class Bird{
    public:
    void fly(){
        cout<<"Flying";
    }
};

class Mamale{
    public:
    virtual void giving_birth(){
        cout<<"Giving Birth";
    }
};

class Bat:public Bird , Mamale{
    public:
    void giving_birth() override{
      cout<<"Giving Birth while flying";
    }
};

int main(){
    Bat b ;
    b.fly();
    b.giving_birth();
    return 0;
}