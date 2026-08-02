#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <string>
using namespace std;

// ============================================
// CLASS 1: Ticket
// Stores the ticket information
// ============================================
class Ticket {
private:
    string trackID;      // Unique identifier for the ticket
    int priorityKey;     // Priority value (higher = more urgent)

public:
    // Constructor: Initialize a ticket with ID and priority
    Ticket(string id, int priority) : trackID(id), priorityKey(priority) {}
    
    // Getter methods (to access private data)
    string getTrackID() const {
        return trackID;
    }
    
    int getPriorityKey() const {
        return priorityKey;
    }
    
    // Display ticket information
    void display() const {
        cout << "Track ID: " << trackID 
             << " | Priority: " << priorityKey << endl;
    }
    
    // Overload < operator for priority comparison
    // This is used by priority_queue with default comparator
    // IMPORTANT: We return OPPOSITE because priority_queue is a MAX heap
    // We want HIGHER priority values to come out first
    bool operator<(const Ticket& other) const {
        return priorityKey < other.priorityKey;  // Lower priority = less urgent
    }
};


// ============================================
// CLASS 2: ComparePriority (Function Object)
// Alternative way to compare tickets
// ============================================
class ComparePriority {
public:
    // Overload () operator to make this class act like a function
    // Returns true if t1 has LOWER priority than t2
    bool operator()(const Ticket& t1, const Ticket& t2) const {
        return t1.getPriorityKey() < t2.getPriorityKey();
    }
};

#endif // TICKET_H