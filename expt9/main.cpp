#include <iostream>
#include "bst.h"
using namespace std;

int main() {
    BST<int> intTree;
    BST<char> charTree;

    int choice, typeChoice;

    cout << "Choose data type:\n1. Integer\n2. Character\nEnter choice: ";
    cin >> typeChoice;

    if (typeChoice == 1) {
        int val;
        do {
            cout << "\n--- INTEGER BST MENU ---\n";
            cout << "1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Search\n6. Delete\n7. Height\n8. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter value to insert: ";
                    cin >> val;
                    intTree.insert(val);
                    break;
                case 2:
                    cout << "Inorder: ";
                    intTree.inorder();
                    break;
                case 3:
                    cout << "Preorder: ";
                    intTree.preorder();
                    break;
                case 4:
                    cout << "Postorder: ";
                    intTree.postorder();
                    break;
                case 5:
                    cout << "Enter value to search: ";
                    cin >> val;
                    intTree.search(val);
                    break;
                case 6:
                    cout << "Enter value to delete: ";
                    cin >> val;
                    intTree.deleteNode(val);
                    break;
                case 7:
                    cout << "Height: " << intTree.height() << endl;
                    break;
            }
        } while (choice != 8);
    }

    else if (typeChoice == 2) {
        char val;
        do {
            cout << "\n--- CHARACTER BST MENU ---\n";
            cout << "1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Search\n6. Delete\n7. Height\n8. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter character to insert: ";
                    cin >> val;
                    charTree.insert(val);
                    break;
                case 2:
                    cout << "Inorder: ";
                    charTree.inorder();
                    break;
                case 3:
                    cout << "Preorder: ";
                    charTree.preorder();
                    break;
                case 4:
                    cout << "Postorder: ";
                    charTree.postorder();
                    break;
                case 5:
                    cout << "Enter character to search: ";
                    cin >> val;
                    charTree.search(val);
                    break;
                case 6:
                    cout << "Enter character to delete: ";
                    cin >> val;
                    charTree.deleteNode(val);
                    break;
                case 7:
                    cout << "Height: " << charTree.height() << endl;
                    break;
            }
        } while (choice != 8);
    }

    else {
        cout << "Invalid choice!";
    }

    return 0;
}