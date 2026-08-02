#include <iostream>
using namespace std;

// Node class represents a single element of the linked list
class Node
{
public:
    int info;   // Data stored in the node
    Node *next; // Pointer to the next node

    // Constructor to initialize a node
    Node(int v)
    {
        info = v;
        next = NULL;
    }
};

// LinkedList class manages the chain of nodes
class LinkedList
{
private:
    Node *head; // Pointer to the first node (head of the list)

public:
    // Constructor initializes the list as empty
    LinkedList()
    {
        head = NULL;
    }

    // Function to insert a new node at the beginning
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head; // Point new node to current head
        head = newNode;       // Update head to new node
    }

    // Function to insert a new node at the end
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value); // Create new node
        if (head == NULL)
        {
            head = newNode; // If list is empty, new node becomes head
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode; // Link new node at the end
        }
    }

    // Function to insert a node at a specific position (1-based index)
    void insertAtPosition(int value, int pos)
    {
        if (pos <= 0)
        {
            cout << "Invalid position. Must be >= 1.\n";
            return;
        }

        if (pos == 1)
        {
            insertAtBeginning(value); // Use existing function
            return;
        }

        Node *newNode = new Node(value);

        // Traverse to the node before the desired position
        Node *temp = head;
        int count = 1;
        while (temp != NULL && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp == NULL)
        {
            cout << "Position out of range. Inserting at the end.\n";
            insertAtEnd(value);
            delete newNode; // Prevent memory leak (since insertAtEnd already created its own node)
            return;
        }

        // Insert new node
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete the first occurrence of a value
    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        if (head->info == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << value << " from the list.\n";
            return;
        }

        Node *current = head;
        Node *prev = NULL;
        while (current != NULL && current->info != value)
        {
            prev = current;
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "Value " << value << " not found in the list.\n";
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Deleted " << value << " from the list.\n";
    }

    // Function to search for a value
    bool search(int value)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->info == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Function to display all nodes
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        cout << "Linked List: ";
        while (temp != NULL)
        {
            cout << temp->info << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Driver code
int main()
{
    LinkedList list;

    // Insert at beginning
    list.insertAtBeginning(30);
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);
    list.display(); // 10 -> 20 -> 30

    // Insert at end
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.display(); // 10 -> 20 -> 30 -> 40 -> 50

    // Insert at position
    list.insertAtPosition(25, 3); // Insert 25 at position 3
    list.insertAtPosition(5, 1);  // Insert at head
    list.insertAtPosition(100, 20); // Beyond range → goes to end
    list.display();

    // Delete nodes
    list.deleteNode(25);
    list.display();

    // Search
    cout << "Is 40 present? " << (list.search(40) ? "Yes" : "No") << endl;
    cout << "Is 99 present? " << (list.search(99) ? "Yes" : "No") << endl;

    return 0;
}
