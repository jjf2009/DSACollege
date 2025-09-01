#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    T vectori[3];

public:

    Vector() {
        vectori[0] = 0;
        vectori[1] = 0;
        vectori[2] = 0;
    }

    void display() {
        cout << "Vector:"<< vectori[0] << "i + " << vectori[1] << "j + " << vectori[2] << "k" << endl;
    }

    void create(T vali, T valj, T valk) {
        vectori[0] = vali;
        vectori[1] = valj;
        vectori[2] = valk;
    }

    void modify(char index, T value) {
        if(index == 'i'){
            vectori[0]=value;
        }
        else if (index=='j') {
            vectori[1] = value;
        }  
        else if (index=='k') {
            vectori[2] = value;
        }
        else {
            cout << "Index out of bounds!" << endl;
        }
    }
};

int main() {
    Vector<int> intVector;
    int i ,j , k,value;
    char mod;
    cout<<"Enter Value for i , j , k postion of the vector:";
    cin>>i>>j>>k;
    intVector.create(i,j,k);
    intVector.display();
    cout<<"Enter the postion i , j , k to modify it and the value :";
    cin>>mod>>value;
    intVector.modify(mod,value);
    intVector.display();
    

    return 0;
}
