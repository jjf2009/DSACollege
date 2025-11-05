#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <iostream>
#include <string>

using namespace std;

// --- Book Class (Acts as the Linked List Node) ---
class Book {
public:
    string title;
    string author;
    string isbnNumber;
    string availabilityStatus;
    Book* next; // The pointer that links the nodes

    // Default Constructor
    Book() : next(nullptr) {}
    
    // Parameterized Constructor
    Book(string t, string a, string isbn, string status) 
        : title(t), author(a), isbnNumber(isbn), availabilityStatus(status), next(nullptr) {}
};

// --- Library Manager Class (Manages Book objects directly) ---
class LibraryManager {
private:
    Book* head;

public:
    // Constructor
    LibraryManager() : head(nullptr) {}
    
    // Destructor declaration
    ~LibraryManager(); 

    // Helper
    bool isEmpty() const { return head == nullptr; }

    // Function Declarations
    void insertAt(const Book& newBookData, int location);
    void deleteAt(int location);
    void showAllBooks() const;
    string searchAndGetStatus(const string& isbn) const;
};

// ******************************************************
// --- Function Definitions (Outside the Class) ---
// ******************************************************

// Destructor Implementation
LibraryManager::~LibraryManager() {
    Book* current = head;
    while (current != nullptr) {
        Book* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

// 1. Insert at any location (0 is the head)
void LibraryManager::insertAt(const Book& newBookData, int location) {
    // Create the new node using the provided data
    Book* newNode = new Book(newBookData.title, newBookData.author, newBookData.isbnNumber, newBookData.availabilityStatus);
    
    // Case 1: Insert at the head (location 0 or if list is empty)
    if (location <= 0 || head == nullptr) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Traverse to location (one position before insertion point)
    Book* current = head;
    for (int i = 0; i < location - 1 && current->next != nullptr; ++i) {
        current = current->next;
    }

    // Insert at the calculated position (middle or end)
    newNode->next = current->next;
    current->next = newNode;
}

// 2. Delete at any location (0 is the head)
void LibraryManager::deleteAt(int location) {
    if (head == nullptr) {
        cout << "Error: List is empty. Cannot delete." << endl;
        return;
    }

    Book* temp = head;

    // Case 1: Delete the head (location 0)
    if (location == 0) {
        head = head->next;
        cout << "Book '" << temp->title << "' deleted successfully." << endl;
        delete temp;
        return;
    }

    // Case 2: Traverse to the node *before* the deletion point
    Book* prev = nullptr;
    for (int i = 0; temp != nullptr && i < location; ++i) {
        prev = temp;
        temp = temp->next;
    }

    // If location is out of bounds
    if (temp == nullptr) {
        cout << "Error: Location " << location << " out of bounds. Deletion failed." << endl;
        return;
    }

    // Case 3: Delete from the middle or end
    prev->next = temp->next;
    cout << "Book '" << temp->title << "' deleted successfully." << endl;
    delete temp; 
}

// 3. Show all books
void LibraryManager::showAllBooks() const {
    if (isEmpty()) {
        cout << "\n--- Library is Empty. No books to display. ---\n" << endl;
        return;
    }

    Book* current = head;
    int count = 1;
    cout << "\n--- Library Book Records ---" << endl;
    while (current != nullptr) {
        cout << count << ". Title: " << current->title
             << " | Author: " << current->author
             << " | ISBN: " << current->isbnNumber
             << " | Status: " << current->availabilityStatus << endl;
        current = current->next;
        count++;
    }
    cout << "----------------------------\n" << endl;
}

// 4. Search a book record and return the availability status (Search by ISBN)
string LibraryManager::searchAndGetStatus(const string& isbn) const {
    if (isEmpty()) {
        return "Not Found (Library Empty)";
    }

    Book* current = head;
    while (current != nullptr) {
        if (current->isbnNumber == isbn) {
            return current->availabilityStatus;
        }
        current = current->next;
    }

    return "Not Found (ISBN " + isbn + ")";
}

#endif // LIBRARYMANAGER_H