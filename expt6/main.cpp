#include "LargeNumberAddition.h"

int main() {
    int choice;
    
    do {
        cout << "\n===== Large Number Addition Menu =====\n";
        cout << "1. Integer Addition\n";
        cout << "2. Float Addition\n";
        cout << "3. Exit\n";
        cout << "======================================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "\n=== Integer Addition ===" << endl;
                int int1, int2;
                cout << "Enter first integer: ";
                cin >> int1;
                cout << "Enter second integer: ";
                cin >> int2;
                
                LargeNumberAddition<int> intAdder(int1, int2);
                intAdder.display();
                break;
            }
            
            case 2: {
                cout << "\n=== Float Addition ===" << endl;
                float float1, float2;
                cout << "Enter first float: ";
                cin >> float1;
                cout << "Enter second float: ";
                cin >> float2;
                
                LargeNumberAddition<float> floatAdder(float1, float2);
                floatAdder.display();
                break;
            }
            
            case 3:
                cout << "\nExiting program. Thank you!\n" << endl;
                break;
                
            default:
                cout << "\nInvalid choice! Please select 1, 2, or 3.\n" << endl;
        }
        
    } while (choice != 3);
    
    return 0;
}