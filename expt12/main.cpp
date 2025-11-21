#include <iostream>
#include <string>
#include "hash.hpp"
using namespace std;

void displayHashMethodMenu() {
    cout << "\n====== SELECT HASH METHOD ======" << endl;
    cout << "1. Division Method (key % capacity)" << endl;
    cout << "2. Folding Method (split in half)" << endl;
    cout << "3. Mid-Square Method" << endl;
    cout << "=================================" << endl;
    cout << "Enter your choice: ";
}

void displayMenu() {
    cout << "\n======== HASH TABLE MENU ========" << endl;
    cout << "1. Insert Key-Value Pair" << endl;
    cout << "2. Search by Key" << endl;
    cout << "3. Remove by Key" << endl;
    cout << "4. Display Hash Table" << endl;
    cout << "5. Change Hash Method" << endl;
    cout << "6. Display Current Settings" << endl;
    cout << "7. Exit" << endl;
    cout << "==================================" << endl;
    cout << "Enter your choice: ";
}

HashMethod selectHashMethod() {
    int methodChoice;
    displayHashMethodMenu();
    cin >> methodChoice;
    
    switch (methodChoice) {
        case 1:
            cout << "\n✓ Division Method selected" << endl;
            return HashMethod::DIVISION;
        case 2:
            cout << "\n✓ Folding Method selected" << endl;
            return HashMethod::FOLDING;
        case 3:
            cout << "\n✓ Mid-Square Method selected" << endl;
            return HashMethod::MID_SQUARE;
        default:
            cout << "\nInvalid choice! Using Division Method as default." << endl;
            return HashMethod::DIVISION;
    }
}

int main() {
    int capacity;
    cout << "Enter hash table capacity: ";
    cin >> capacity;
    
    // Select initial hash method
    HashMethod initialMethod = selectHashMethod();
    HashTable<int, string> ht(capacity, initialMethod);
    
    int choice;
    int key;
    string value;
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "\nEnter key (integer): ";
                cin >> key;
                cout << "Enter value (string): ";
                cin.ignore();
                getline(cin, value);
                ht.insert(key, value);
                cout << "✓ Inserted successfully!" << endl;
                break;
                
            case 2:
                cout << "\nEnter key to search: ";
                cin >> key;
                if (ht.search(key, value)) {
                    cout << "✓ Found: Key " << key << " -> " << value << endl;
                } else {
                    cout << "✗ Key " << key << " not found!" << endl;
                }
                break;
                
            case 3:
                cout << "\nEnter key to remove: ";
                cin >> key;
                if (ht.remove(key)) {
                    cout << "✓ Key " << key << " removed successfully!" << endl;
                } else {
                    cout << "✗ Key " << key << " not found!" << endl;
                }
                break;
                
            case 4:
                ht.display();
                break;
                
            case 5: {
                cout << "\nChanging hash method..." << endl;
                cout << "WARNING: Changing the hash method will not rehash existing entries." << endl;
                cout << "For best results, consider creating a new hash table." << endl;
                HashMethod newMethod = selectHashMethod();
                ht.setHashMethod(newMethod);
                break;
            }
                
            case 6:
                cout << "\nCurrent Hash Method: " << ht.getHashMethodName() << endl;
                break;
                
            case 7:
                cout << "\nExiting program. Goodbye!" << endl;
                return 0;
                
            default:
                cout << "\n✗ Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}
