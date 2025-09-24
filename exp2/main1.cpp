#include <iostream>
using namespace std;

template <typename S>
void swaping(S num1, S num2) {
    S temp = num1;
    num1 = num2;
    num2 = temp;
    cout << "Num1:"<< num1 <<" " <<"Num2:"<< num2 << endl;
}

int main() {
    int choice;
    cout << "Choose data type to swap:\n";
    cout << "1. int\n2. float\n3. double\n4. char\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int a, b;
        cout << "Enter two integers: ";
        cin >> a >> b;
        swaping(a, b);
    } else if (choice == 2) {
        float a, b;
        cout << "Enter two floats: ";
        cin >> a >> b;
        swaping(a, b);
    } else if (choice == 3) {
        double a, b;
        cout << "Enter two doubles: ";
        cin >> a >> b;
        swaping(a, b);
    } else if (choice == 4) {
        char a, b;
        cout << "Enter one characters: ";
        cin>>a>>b;
        swaping(a, b);
    } else {
        cout << "Invalid choice!" << endl;
    }
    return 0;
}