# Lab 05 — Stack ADT & Balanced Parentheses in C++

**How to check balanced parentheses using a stack in C++** — template stack with push, pop, overflow/underflow, and expression validation.

## What is a stack?

A **stack** is a LIFO (Last-In-First-Out) ADT. Core operations: `push`, `pop`, `top` / peek, `isEmpty`, `isFull`. Parenthesis matching uses a stack: push opening brackets; on closing brackets, pop and match.

## Files

- `stack.hpp` — template `Stack<T>` + `checkExpression`  
- `stack.cpp` — reads expression from stdin  

## Quick run

```bash
g++ -std=c++17 -Wall -o paren stack.cpp && ./paren
# Enter: { [ ( ) ] }
```

## Algorithm (parentheses)

1. Scan each character left to right.  
2. Push opening `(`, `[`, `{`.  
3. On closing bracket, if stack empty or top does not match → unbalanced.  
4. If stack empty at end → balanced; else unbalanced.  

## Related

- Large number addition with stacks → [`../06-large-number-addition`](../06-large-number-addition/)
- Exam → [`../../exam/05-stack-balanced-parentheses`](../../exam/05-stack-balanced-parentheses/)
