#include "LibraryManager.h" 
#include <iostream> 

using namespace std;


int main() {
    // Instantiate the non-templated LibraryManager
    LibraryManager library; 

    int choice, location;
    string isbnSearch;
    string tempTitle, tempAuthor, tempISBN, tempStatus;

    do {
    cout << "\n--- Library Operations ---" << endl;
    cout << "1. Insert a Book Record" << endl;
    cout << "2. Delete a Book Record" << endl;
    cout << "3. Show All Books" << endl;
    cout << "4. Search Book Status by ISBN" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin>>choice;

        switch (choice) {
            case 1: // Insert
                // cin.ignore() removes the newline left after reading 'choice' or 'location'
                cout << "Enter Title: "; cin.ignore(); getline(cin, tempTitle); 
                cout << "Enter Author: "; getline(cin, tempAuthor);
                cout << "Enter ISBN: "; getline(cin, tempISBN);
                cout << "Enter Status (Available/Issued): "; getline(cin, tempStatus);
                cout << "Enter location to insert (0 for head, > list size for end): "; 
                
                if (!(cin >> location)) {
                    cin.clear(); cin.ignore(256, '\n');
                    location = -1; // Default to end insertion on bad input
                }
                
                // Construct and insert the Book object directly
                library.insertAt(
                    Book(tempTitle, tempAuthor, tempISBN, tempStatus), 
                    location
                );
                break;
            
            case 2: // Delete
                cout << "Enter location to delete (0 for head, 1 for second, etc.): "; 
                
                if (!(cin >> location)) {
                    cin.clear(); cin.ignore(256, '\n');
                    cout << "Invalid location input." << endl;
                    break;
                }
                library.deleteAt(location);
                break;
            
            case 3: // Show All
                library.showAllBooks();
                break;
            
            case 4: // Search
                // cin.ignore() removes the newline left after reading 'choice' or 'location'
                cout << "Enter ISBN to search: "; cin.ignore(); getline(cin, isbnSearch); 
                cout << "Status for ISBN " << isbnSearch << ": **" 
                     << library.searchAndGetStatus(isbnSearch) << "**" << endl;
                break;
            
            case 5:
                cout << "Exiting Library Manager. Goodbye!" << endl;
                break;
            
            default:
                if(choice != 0) {
                    cout << "Invalid choice. Please try again." << endl;
                }
        }
    } while (choice != 5);

    return 0;
}