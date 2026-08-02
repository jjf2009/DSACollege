# Lab 03 — Singly Linked List in C++

**Singly linked list C++ lab code** with insert, delete, search, reverse, and display — classic college DSA practical.

## What is a singly linked list?

A **singly linked list** stores elements in nodes where each node holds **data** and a **pointer to the next node**. Access is sequential from the head; insert/delete at the head is O(1), search is O(n).

## Operations implemented

- Create list / insert at start  
- Insert at end  
- Insert at position  
- Delete start / end / position  
- Search  
- Reverse  
- Display  

## Quick run

```bash
g++ -std=c++17 -Wall -o sll main1.cpp && ./sll
```

## Complexity

| Operation | Time |
|-----------|------|
| Insert at head | O(1) |
| Insert at end (with tail) | O(1) |
| Search / reverse | O(n) |

## Related

- Doubly linked list → [`../04-doubly-linked-list`](../04-doubly-linked-list/)
- Classroom list basics → [`../../classroom/singly-linked-list-basics`](../../classroom/singly-linked-list-basics/)
- Exam variant → [`../../exam/03-singly-linked-list`](../../exam/03-singly-linked-list/)
