#include<iostream>
using namespace std;

template<typename T>
class Node{
   public:
   int data;
   Node<T>* next;
   Node<T>* prev;
   
   Node(int val){
   data = val;
   prev = nullptr;
   next = nullptr;
   }
};

template<typename T>
class Doubly_linked_list{
   private:
   Node<T>* head;
   Node<T>* tail;
   
   public:
   Doubly_linked_list();
   void insert_at_end(T val);
   void insert_at_beginning(T val);
   void search(T val);
   void display_forward();
   void display_backard();
   void delete_by_position(T pos);
   void reverse();
};

template<typename T>
Doubly_linked_list<T>::Doubly_linked_list(){
   head = nullptr;
   tail = nullptr;
}

template<typename T>
void Doubly_linked_list<T>::insert_at_end(T val){
   Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << val << " inserted at the end." << endl;
}

template<typename T>
void Doubly_linked_list<T>::insert_at_beginning(T val){
   Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << val << " inserted at the beginning." << endl;
}

template<typename T>
void Doubly_linked_list<T>::search(T val){
   if (head == nullptr) {
            cout << "Cannot search in an empty list." << endl;
            return;
        }
        Node<T>* temp = head;
        int position = 1;
        bool found = false;
        while (temp != nullptr) {
            if (temp->data == val) {
                cout << "Found " << val << " at position " << position << "." << endl;
                found = true;
                break;
            }
            temp = temp->next;
            position++;
        }
        if (!found) {
            cout << val << " was not found in the list." << endl;
        }
}

template<typename T>
void Doubly_linked_list<T>::delete_by_position(T pos){
   if (head == nullptr) {
            cout << "Cannot delete from an empty list." << endl;
            return;
        }
        if (pos < 1) {
            cout << "Invalid position. Position must be 1 or greater." << endl;
            return;
        }

        Node<T>* current = head;
        if (pos == 1) {
            head = current->next;
            if (head != nullptr) { 
                head->prev = nullptr;
            } 
            else { 
                tail = nullptr;
            }
            cout << "Deleted node at position 1 with value " << current->data << "." << endl;
            delete current;
            return;
        }
        int currentPos = 1;
        while (current != nullptr && currentPos < pos) {
            current = current->next;
            currentPos++;
        }

        if (current == nullptr) {
            cout << "Position " << pos << " is out of range." << endl;
            return;
        }

        current->prev->next = current->next;
        if (current->next != nullptr) { 
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        cout << "Deleted node at position " << pos << " with value " << current->data << "." << endl;
        delete current;
}

template<typename T>
void Doubly_linked_list<T>::display_forward(){
    if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        cout << "List (forward): NULL <-> ";
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;

}

template<typename T>
void Doubly_linked_list<T>::display_backard(){
   if (tail == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        cout << "List (backward): NULL <-> ";
        Node<T>* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
}

template<typename T>
void Doubly_linked_list<T>::reverse(){
   if (head == nullptr || head->next == nullptr) {
            cout << "List is too short to be reversed." << endl;
            return;
        }
        Node<T>* temp = nullptr;
        Node<T>* current = head;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr) {
            tail = head;
            head = temp->prev;
        }
        cout << "The list has been reversed." << endl;
    
}



