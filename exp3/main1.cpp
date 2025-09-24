#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class LinkedList
{
private:
    Node *head;
    Node *tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    void create(int value) {
        Node *newNode = new Node{value, nullptr};
        head = tail = newNode;
        display();}

    void insertStart(int value) {
        Node *newNode = new Node{value, head};
        head = newNode;
        if (!tail)
            tail = newNode;
    display(); }

    void insertEnd(int value){
        Node *newNode = new Node{value, nullptr};
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        display();}

    void insertAt(int pos, int value){
        if (pos <= 1)
        {
            insertStart(value);
            return;
        }
        Node *temp = head;
        for (int i = 1; temp && i < pos - 1; ++i)
            temp = temp->next;
        if (!temp || !temp->next)
        {
            insertEnd(value);

            return;
        }
        Node *newNode = new Node{value, temp->next};
        temp->next = newNode;
        display();}

    int search(int value){   
        int count=1;
        Node *temp = head;
        while (temp)
        {
            if (temp->data == value){
                return count;
            }
            count=count+1;
            temp = temp->next;
            
        }
        return -1;
        display();}

    void display(){
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;}

    void reverse(){
        Node *prev = nullptr;
        Node *curr = head;
        tail = head;
        while (curr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        display();}

    void deleteStart(){
        if (!head)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
        if (!head)
            tail = nullptr;
        display();}

    void deleteEnd(){
        if (!head)
            return;
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
            temp = temp->next;
        delete tail;
        tail = temp;
        tail->next = nullptr;
        display();}

    void deleteAt(int pos){
        if (pos <= 1)
        {
            deleteStart();
            return;
        }
        Node *temp = head;
        for (int i = 1; temp && temp->next && i < pos - 1; ++i)
            temp = temp->next;
        if (!temp || !temp->next)
            return;
        Node *delNode = temp->next;
        temp->next = delNode->next;
        if (delNode == tail)
            tail = temp;
        delete delNode;
        display();}};
int main(){
    LinkedList list;
    int choice, value, pos;
    cout << "Enter first value of the Node: ";
    cin >> value;
    list.create(value);
    while (true){
        cout << "\n=== Linked List Menu ===\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Start\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Search a Value\n";
        cout << "8. Reverse List\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at start: ";
            cin >> value;
            list.insertStart(value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list.insertEnd(value);
            break;
        case 3:
            cout << "Enter position and value: ";
            cin >> pos >> value;
            list.insertAt(pos, value);
            break;
        case 4:
            list.deleteStart();
            cout << "Deleted node at start.\n";
            break;
        case 5:
            list.deleteEnd();
            cout << "Deleted node at end.\n";
            break;
        case 6:
            cout << "Enter position to delete: ";
            cin >> pos;
            list.deleteAt(pos);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            if (list.search(value)==-1)
                cout << "Value NOT found.\n";
            else
            cout << "Value found at postion "<<list.search(value)<<" in the list.\n";
            break;
        case 8:
            list.reverse();
            cout << "List reversed.\n";
            break;
        case 9:
            cout << "Current List: ";
            list.display();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";}}}
