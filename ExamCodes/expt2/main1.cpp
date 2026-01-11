#include <iostream>
using namespace std;

template<typename T>
void swapValues(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 12, b = 13;

    swapValues(&a, &b);

    cout << "A: " << a << endl;
    cout << "B: " << b << endl;

    return 0;
}
