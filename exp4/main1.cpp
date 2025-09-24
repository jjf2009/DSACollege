#include <iostream>
#include "doubly_linked_list.hpp"
using namespace std;

int main(){

    Doubly_linked_list<int> myList;
    int choice, value, pos;

    do {
        cout << "\n--- Doubly Linked List Menu (Integers) ---" << endl;
        cout << "1. Insert at End" << endl;
        cout << "2. Insert at Beginning" << endl;
        cout << "3. Delete by Position" << endl;
        cout << "4. Search for a Value" << endl;
        cout << "5. Reverse the List" << endl;
        cout << "6. Display Forward" << endl;
        cout << "7. Display Backward" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                myList.insert_at_end(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                myList.insert_at_beginning(value);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                myList.delete_by_position(value);
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                myList.search(value);
                break;
            case 5:
                myList.reverse();
                break;
            case 6:
                myList.display_forward();
                break;
            case 7:
                myList.display_backard();
                break;
            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 0);

    return 0;

}
