#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Creation (add first node)
    void create(int value) {
        Node* newNode = new Node{value, nullptr};
        head = tail = newNode;
    }

    // Insert at start
    void insertStart(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
        if (!tail) tail = newNode;
    }

    // Insert at end
    void insertEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void insertAt(int pos, int value) {
        if (pos <= 1) {
            insertStart(value);
            return;
        }
        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; ++i)
            temp = temp->next;
        if (!temp || !temp->next) {
            insertEnd(value);
            return;
        }
        Node* newNode = new Node{value, temp->next};
        temp->next = newNode;
    }

    // Search for a value
    bool search(int value) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    // Display/Traverse
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Reverse the list
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        tail = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // Delete at start
    void deleteStart() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) tail = nullptr;
    }

    // Delete at end
    void deleteEnd() {
        if (!head) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != tail)
            temp = temp->next;
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    // Delete at position (1-based index)
    void deleteAt(int pos) {
        if (pos <= 1) {
            deleteStart();
            return;
        }
        Node* temp = head;
        for (int i = 1; temp && temp->next && i < pos - 1; ++i)
            temp = temp->next;
        if (!temp || !temp->next) return;
        Node* delNode = temp->next;
        temp->next = delNode->next;
        if (delNode == tail) tail = temp;
        delete delNode;
    }
};

int main() {
    LinkedList list;
    list.create(10);
    list.insertStart(5);
    // list.insertEnd(20);
    // list.insertAt(2, 15); 
    // list.display(); 
    // cout << "Search 15: " << (list.search(15) ? "Found" : "Not Found") << endl;
    // list.reverse();
    // list.display(); 
    // list.deleteStart();
    // list.deleteEnd();
    // list.deleteAt(2); 
    list.display(); 
    return 0;
}