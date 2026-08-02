# Lab 08 — Palindrome Checker Using Queue (C++)

**Check if a string is a palindrome using a queue ADT** in C++ — enqueue characters, compare against reversed/cleaned string.

## What is a queue?

A **queue** is FIFO (First-In-First-Out). This lab uses a vector-backed queue (`enqueue` back, `dequeue` front) to process characters for palindrome testing.

## Files

- `palindrome.h` — `PalindromeChecker`  
- `main.cpp` — CLI input  

## Quick run

```bash
g++ -std=c++17 -Wall -o pal main.cpp && ./pal
# Try: Racecar
```

## Related

- Stack lab → [`../05-stack-balanced-parentheses`](../05-stack-balanced-parentheses/)
- Exam → [`../../exam/08-palindrome-with-queue`](../../exam/08-palindrome-with-queue/)
