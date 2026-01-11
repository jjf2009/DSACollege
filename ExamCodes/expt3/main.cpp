#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val, Node* n = nullptr) : data(val), next(n) {}
};


class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtStart(int value);
    void insertAtEnd(int value);
    void insertAtPos(int pos, int value);
    void deleteAtStart();
    void deleteAtEnd();
    void reverse();
    int search(int value);
    void display();
};


void LinkedList::insertAtStart(int value) {
    Node* newNode = new Node(value, head);
    head = newNode;
    if (!tail) tail = head;
}

void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}


void LinkedList::insertAtPos(int pos, int value) {
    if (pos <= 1) {
        insertAtStart(value);
        return;
    }

    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (!temp) {
        insertAtEnd(value);
        return;
    }

    temp->next = new Node(value, temp->next);
}

int LinkedList::search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == value)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

void LinkedList::reverse() {
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


void LinkedList::deleteAtStart() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
    if (!head) tail = nullptr;
}


void LinkedList::deleteAtEnd() {
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

void LinkedList::display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
