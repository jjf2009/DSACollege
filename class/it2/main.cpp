#include <iostream>
#include <queue>
#include <vector>
#include "Ticket.h"
using namespace std;

// ============================================
// MAIN FUNCTION - DEMONSTRATING BOTH METHODS
// ============================================
int main() {
    // METHOD 1: Using default operator< (built into Ticket class)
    // This uses the operator< we defined in Ticket class
    priority_queue<Ticket> helpDeskQueue1;
    
    // METHOD 2: Using ComparePriority function object
    // Full syntax: priority_queue<Type, Container, Comparator>
    // FIXED SYNTAX: You had wrong syntax before!
    priority_queue<Ticket, vector<Ticket>, ComparePriority> helpDeskQueue2;
    
    cout << "========================================" << endl;
    cout << "   IT HELP DESK TICKETING SYSTEM" << endl;
    cout << "   (Demonstrating BOTH Methods)" << endl;
    cout << "========================================" << endl;
    cout << "Higher Priority Value = More Urgent\n" << endl;
    
    int choice;
    string trackID;
    int priority;
    int queueChoice = 1;  // Which queue to use (1 or 2)
    
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Insert New Ticket" << endl;
        cout << "2. Display Processing Order - Queue 1 (using operator<)" << endl;
        cout << "3. Display Processing Order - Queue 2 (using ComparePriority)" << endl;
        cout << "4. Insert to BOTH Queues and Compare" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                // INSERT TICKET TO ONE QUEUE
                cout << "\nWhich queue? (1 for operator<, 2 for ComparePriority): ";
                cin >> queueChoice;
                
                cout << "Enter Track ID (e.g., TKT001): ";
                cin >> trackID;
                cout << "Enter Priority Key (1-10, higher=more urgent): ";
                cin >> priority;
                
                if (queueChoice == 1) {
                    helpDeskQueue1.push(Ticket(trackID, priority));
                    cout << "\n✓ Ticket added to Queue 1 (operator<)!" << endl;
                } else if (queueChoice == 2) {
                    helpDeskQueue2.push(Ticket(trackID, priority));
                    cout << "\n✓ Ticket added to Queue 2 (ComparePriority)!" << endl;
                } else {
                    cout << "\n⚠ Invalid queue choice!" << endl;
                }
                break;
                
            case 2:
                // DISPLAY QUEUE 1 (operator<)
                if (helpDeskQueue1.empty()) {
                    cout << "\n⚠ Queue 1 is empty!" << endl;
                } else {
                    cout << "\n========================================" << endl;
                    cout << "   QUEUE 1 - Using operator<" << endl;
                    cout << "   PROCESSING ORDER (Highest → Lowest)" << endl;
                    cout << "========================================" << endl;
                    
                    int position = 1;
                    while (!helpDeskQueue1.empty()) {
                        cout << position << ". ";
                        helpDeskQueue1.top().display();
                        helpDeskQueue1.pop();
                        position++;
                    }
                    cout << "\n✓ All tickets from Queue 1 processed!" << endl;
                }
                break;
                
            case 3:
                // DISPLAY QUEUE 2 (ComparePriority)
                if (helpDeskQueue2.empty()) {
                    cout << "\n⚠ Queue 2 is empty!" << endl;
                } else {
                    cout << "\n========================================" << endl;
                    cout << "   QUEUE 2 - Using ComparePriority" << endl;
                    cout << "   PROCESSING ORDER (Highest → Lowest)" << endl;
                    cout << "========================================" << endl;
                    
                    int position = 1;
                    while (!helpDeskQueue2.empty()) {
                        cout << position << ". ";
                        helpDeskQueue2.top().display();
                        helpDeskQueue2.pop();
                        position++;
                    }
                    cout << "\n✓ All tickets from Queue 2 processed!" << endl;
                }
                break;
                
            case 4:
                // INSERT TO BOTH QUEUES (for comparison)
                cout << "\n--- Adding tickets to BOTH queues ---" << endl;
                cout << "Enter Track ID (e.g., TKT001): ";
                cin >> trackID;
                cout << "Enter Priority Key (1-10, higher=more urgent): ";
                cin >> priority;
                
                // Create one ticket and push to both queues
                {
                    Ticket ticket(trackID, priority);
                    helpDeskQueue1.push(ticket);
                    helpDeskQueue2.push(ticket);
                }
                
                cout << "\n✓ Ticket added to BOTH queues!" << endl;
                cout << "Now you can compare Queue 1 and Queue 2 outputs" << endl;
                break;
                
            case 5:
                cout << "\nExiting system. Goodbye!" << endl;
                break;
                
            default:
                cout << "\n⚠ Invalid choice! Please try again." << endl;
        }
        
    } while (choice != 5);
    
    return 0;
}


/* ============================================
   EXPLANATION OF BOTH METHODS
   ============================================
   
   METHOD 1: priority_queue<Ticket> helpDeskQueue1;
   
   Full syntax (with defaults):
   priority_queue<Ticket, vector<Ticket>, less<Ticket>>
                  ↑       ↑                ↑
               Element  Container    Uses operator<
   
   - Uses default container (vector)
   - Uses default comparator (less<Ticket>)
   - less<Ticket> calls operator< that we defined in Ticket class
   
   ============================================
   
   METHOD 2: priority_queue<Ticket, vector<Ticket>, ComparePriority> helpDeskQueue2;
                           ↑       ↑                ↑
                        Element  Container    Custom comparator
   
   - Explicitly specifies vector as container
   - Uses ComparePriority function object
   - ComparePriority has operator() that compares priorities
   
   ============================================
   
   YOUR SYNTAX ERROR WAS:
   priority_queue<Ticket>,ComparePriority<Ticket>> helpDeskQueue;
                        ↑                 ↑
                     Wrong!           Wrong!
   
   CORRECT SYNTAX:
   priority_queue<Ticket, vector<Ticket>, ComparePriority> helpDeskQueue;
                  ↑       ↑                ↑
              All inside < > brackets, separated by commas
   
   ============================================
   
   BOTH METHODS PRODUCE THE SAME RESULT!
   
   Example with these tickets:
   TKT001, Priority 3
   TKT002, Priority 8
   TKT003, Priority 5
   
   Queue 1 output (operator<):
   1. Track ID: TKT002 | Priority: 8
   2. Track ID: TKT003 | Priority: 5
   3. Track ID: TKT001 | Priority: 3
   
   Queue 2 output (ComparePriority):
   1. Track ID: TKT002 | Priority: 8
   2. Track ID: TKT003 | Priority: 5
   3. Track ID: TKT001 | Priority: 3
   
   SAME RESULT! ✓
   
   ============================================
   
   WHY USE ComparePriority THEN?
   
   1. More explicit - clear what you're comparing
   2. Can have multiple comparison methods without changing class
   3. Can reuse for classes you don't own (can't add operator<)
   4. More flexible for complex comparisons
   
   Example: Different comparators for same class:
   - ComparePriority: Sort by priority
   - CompareTrackID: Sort by track ID
   - CompareTime: Sort by submission time
   
   ============================================ */