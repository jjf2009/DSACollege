#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    T vec[3];   // FIX: renamed to avoid confusion with class name

public:
    // FIX: array elements assigned inside constructor body
    Vector(T V1, T V2, T V3) {
        vec[0] = V1;
        vec[1] = V2;
        vec[2] = V3;
    }

    void display() {
        cout << "Vi: " << vec[0]
             << "  Vj: " << vec[1]
             << "  Vk: " << vec[2] << endl;
    }

    void modify(int id, T val) {
        if (id >= 0 && id < 3) {   // FIX: bounds check
            vec[id] = val;
        }
    }
};

int main() {
    Vector<int> v(12, 13, 14);   // FIX: template type specified
    v.display();

    v.modify(0, 20);
    v.display();

    return 0;
}
