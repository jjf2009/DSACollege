#include <iostream>
#include <queue>
#include "Ticket.h"
using namespace std;

// ============================================
// MAIN FUNCTION
// ============================================
int main() {
    // Create a priority queue of Ticket objects
    // By default, it uses operator< for comparison
    // MAX heap: Highest priority value comes out first
    priority_queue<Ticket> helpDeskQueue;
    
    cout << "========================================" << endl;
    cout << "   IT HELP DESK TICKETING SYSTEM" << endl;
    cout << "========================================" << endl;
    cout << "Higher Priority Value = More Urgent\n" << endl;
    
    int choice;
    string trackID;
    int priority;
    
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Insert New Ticket" << endl;
        cout << "2. Display Processing Order (Process All Tickets)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                // INSERT TICKET
                cout << "\nEnter Track ID (e.g., TKT001): ";
                cin >> trackID;
                cout << "Enter Priority Key (1-10, higher=more urgent): ";
                cin >> priority;
                
                // Create ticket and push to queue
                helpDeskQueue.push(Ticket(trackID, priority));
                
                cout << "\n✓ Ticket added successfully!" << endl;
                break;
                
            case 2:
                // DISPLAY PROCESSING ORDER
                if (helpDeskQueue.empty()) {
                    cout << "\n⚠ No tickets in the queue!" << endl;
                } else {
                    cout << "\n========================================" << endl;
                    cout << "   PROCESSING ORDER (Highest → Lowest)" << endl;
                    cout << "========================================" << endl;
                    
                    int position = 1;
                    
                    // Process all tickets (removes them from queue)
                    while (!helpDeskQueue.empty()) {
                        cout << position << ". ";
                        helpDeskQueue.top().display();  // Display top ticket
                        helpDeskQueue.pop();             // Remove it
                        position++;
                    }
                    
                    cout << "\n✓ All tickets processed!" << endl;
                }
                break;
                
            case 3:
                cout << "\nExiting system. Goodbye!" << endl;
                break;
                
            default:
                cout << "\n⚠ Invalid choice! Please try again." << endl;
        }
        
    } while (choice != 3);
    
    return 0;
}


/* ============================================
   HOW THIS WORKS - STEP BY STEP EXAMPLE
   ============================================
   
   Let's say user inserts these tickets:
   
   Insert: TKT001, Priority 3
   Insert: TKT002, Priority 8
   Insert: TKT003, Priority 5
   Insert: TKT004, Priority 10
   Insert: TKT005, Priority 2
   
   INTERNAL HEAP STRUCTURE (MAX HEAP):
   Priority queue automatically organizes as:
   
              10 (TKT004)
             /           \
         8 (TKT002)    5 (TKT003)
        /         \
    3 (TKT001)  2 (TKT005)
   
   When you call .top() and .pop():
   
   1st: TKT004 (Priority 10) ← Highest
   2nd: TKT002 (Priority 8)
   3rd: TKT003 (Priority 5)
   4th: TKT001 (Priority 3)
   5th: TKT005 (Priority 2)  ← Lowest
   
   ============================================
   KEY OPERATIONS:
   ============================================
   
   push(ticket)     → Add ticket to queue
   top()            → View highest priority ticket (doesn't remove)
   pop()            → Remove highest priority ticket
   empty()          → Check if queue is empty
   size()           → Get number of tickets in queue
   
   ============================================ */