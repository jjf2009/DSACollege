# Lab 02 — C++ Templates and Multiple Inheritance

**How to use templates in C++ (function + class) and multiple inheritance** — college lab programs.

## Programs

| File | Topic |
|------|--------|
| `main1.cpp` | Function template `swap` for int/float/double/char |
| `main2.cpp` | Class template `Vector` with create/modify/display |
| `main3.cpp` | Multiple inheritance: `Bat` extends `Bird` + `Mammal` |

## Quick run

```bash
g++ -std=c++17 -Wall -o swap main1.cpp && ./swap
g++ -std=c++17 -Wall -o vector main2.cpp && ./vector
g++ -std=c++17 -Wall -o bat main3.cpp && ./bat
```

## Why templates matter for DSA

Generic stacks, lists, and BSTs in later labs use **class templates** so the same ADT works for `int`, `char`, or custom types. This experiment is the prerequisite for template-based stack/list/tree labs.

## Related

- Stack template → [`../05-stack-balanced-parentheses`](../05-stack-balanced-parentheses/)
- BST template → [`../09-binary-search-tree`](../09-binary-search-tree/)
