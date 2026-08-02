# Lab 10 — Bubble, Selection & Insertion Sort in C++

**Basic sorting algorithms C++ lab** (O(n²)): selection sort, insertion sort, bubble sort — interactive array input.

## Algorithms

| Algorithm | Idea | Time |
|-----------|------|------|
| Selection sort | Repeatedly select min into place | O(n²) |
| Insertion sort | Build sorted prefix by inserting next key | O(n²) |
| Bubble sort | Adjacent swaps bubble max to end | O(n²) |

## Files

- `sort.hpp` — `Sort` static methods  
- `main.cpp` — menu  

## Quick run

```bash
g++ -std=c++17 -Wall -o sorts main.cpp && ./sorts
```

## When to use which

- **Insertion**: nearly sorted data, simple adaptive behavior  
- **Selection**: few swaps  
- **Bubble**: teaching adjacent-swap intuition  

For O(n log n) sorts see [Lab 11](../11-advanced-sorting-algorithms/).

## Related

- Advanced sorts → [`../11-advanced-sorting-algorithms`](../11-advanced-sorting-algorithms/)
- Classroom demos → [`../../classroom/bubble-sort`](../../classroom/bubble-sort/), [`../../classroom/selection-sort`](../../classroom/selection-sort/)
