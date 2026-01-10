#include "hash.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {

    int hashMethod, collisionMethod, capacity;

    cout << "Choose Hash Method:\n";
    cout << "1. Division\n2. Folding\n3. Mid-Square\n";
    cin >> hashMethod;

    cout << "\nChoose Collision Resolution:\n";
    cout << "1. Chaining\n2. Linear Probing\n3. Quadratic Probing\n4. Double Hashing\n";
    cin >> collisionMethod;

    cout << "\nEnter hash table capacity: ";
    cin >> capacity;

    HashTable<int, string> ht(capacity, hashMethod, collisionMethod);

    int choice, key;
    string value;

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Remove\n4. Display\n5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Key: ";
                cin >> key;
                cout << "Value: ";
                cin >> value;
                ht.insert(key, value);
                break;

            case 2:
                cout << "Key: ";
                cin >> key;
                if (ht.search(key, value))
                    cout << "Found: " << value << endl;
                else
                    cout << "Not found\n";
                break;

            case 3:
                cout << "Key: ";
                cin >> key;
                if (ht.remove(key))
                    cout << "Removed\n";
                else
                    cout << "Not found\n";
                break;

            case 4:
                ht.display();
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
