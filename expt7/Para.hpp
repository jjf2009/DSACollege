#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <stdexcept>

template <typename T>
class Queue {
private:
    std::vector<T> data;
    
public:
    // Constructor
    Queue() {}
    
    // Push element to the back of queue
    void push(const T& element) {
        data.push_back(element);
    }
    
    // Pop element from the front of queue
    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty!");
        }
        T frontElement = data.front();
        data.erase(data.begin());
        return frontElement;
    }
    
    // Get front element without removing
    T front() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty!");
        }
        return data.front();
    }
    
    // Check if queue is empty
    bool isEmpty() const {
        return data.empty();
    }
    
    // Get size of queue
    size_t size() const {
        return data.size();
    }
    
    // Clear the queue
    void clear() {
        data.clear();
    }
};

#endif