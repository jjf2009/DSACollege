# Lab 04 — Doubly Linked List in C++ (Template)

**Doubly linked list C++ implementation** with `prev` and `next` pointers, forward/backward display, reverse, search, and position delete.

## What is a doubly linked list?

A **doubly linked list** node has links to **both previous and next** nodes, enabling O(1) reverse traversal and simpler deletion when a node pointer is known.

## Files

- `main1.hpp` — template `Node` + `Doubly_linked_list`  
- `main1.cpp` — interactive menu  

## Quick run

```bash
g++ -std=c++17 -Wall -o dll main1.cpp && ./dll
```

## Menu operations

1. Insert end / beginning  
2. Delete by position  
3. Search  
4. Reverse  
5. Display forward / backward  

## Related

- Singly list → [`../03-singly-linked-list`](../03-singly-linked-list/)
- Exam → [`../../exam/04-doubly-linked-list`](../../exam/04-doubly-linked-list/)
