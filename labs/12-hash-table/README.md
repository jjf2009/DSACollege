# Lab 12 — Hash Table in C++ (Chaining & Open Addressing)

**Hash table lab C++** with multiple **hash functions** and **collision resolution** strategies — insert, search, remove, display.

## Hash methods

1. Division  
2. Folding  
3. Mid-square  

## Collision resolution

1. Chaining (separate chaining with lists)  
2. Linear probing  
3. Quadratic probing  
4. Double hashing  

## Files

- `hash.hpp` — template `HashTable<K,V>`  
- `main.cpp` — interactive driver  

## Quick run

```bash
g++ -std=c++17 -Wall -o ht main.cpp && ./ht
```

## Complexity

Average search/insert with a good hash and load factor: **O(1)**. Worst case degrades toward O(n) under heavy collisions.

## Related

- Exam copy → [`../../exam/12-hash-table`](../../exam/12-hash-table/)
- BST alternative for ordered keys → [`../09-binary-search-tree`](../09-binary-search-tree/)
