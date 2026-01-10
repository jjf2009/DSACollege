int main() {
    BST<int> bst;
    int choice, value;

    while (true) {
        cout << "\n========== BST Operations Menu ==========\n";
        cout << "1. Insert a value\n";
        cout << "2. Delete a value\n";
        cout << "3. Search for a value\n";
        cout << "4. Display In-Order Traversal\n";
        cout << "5. Display Pre-Order Traversal\n";
        cout << "6. Display Post-Order Traversal\n";
        cout << "7. Get Tree Height\n";
        cout << "8. Check if tree is empty\n";
        cout << "9. Exit\n";
        cout << "=========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                bst.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                bst.deleteNode(value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                bst.search(value);
                break;

            case 4:
                cout << "In-order Traversal: ";
                bst.inorder();
                cout << endl;
                break;

            case 5:
                cout << "Pre-order Traversal: ";
                bst.preorder();
                cout << endl;
                break;

            case 6:
                cout << "Post-order Traversal: ";
                bst.postorder();
                cout << endl;
                break;

            case 7:
                cout << "Tree Height: " << bst.height() << endl;
                break;

            case 8:
                if (bst.isEmpty())
                    cout << "Tree is empty\n";
                else
                    cout << "Tree is not empty\n";
                break;

            case 9:
                cout << "Exiting program\n";
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
