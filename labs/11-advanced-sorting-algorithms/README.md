# Lab 11 — Quick Sort, Merge Sort & Heap Sort in C++

**Advanced sorting algorithms C++ lab**: divide-and-conquer and heap-based sorts with average **O(n log n)** behavior.

## Algorithms

| Algorithm | Average | Worst | Extra space |
|-----------|---------|-------|-------------|
| Quick sort | O(n log n) | O(n²) | O(log n) stack |
| Merge sort | O(n log n) | O(n log n) | O(n) |
| Heap sort | O(n log n) | O(n log n) | O(1) |

## Files

- `sort.hpp` — partition, merge, heapify helpers  
- `main.cpp` — menu  

## Quick run

```bash
g++ -std=c++17 -Wall -o advsort main.cpp && ./advsort
```

## Viva tips

- Quick sort: pivot partition; worst case on already sorted arrays with naive pivot  
- Merge sort: stable, predictable; needs auxiliary arrays  
- Heap sort: build-max-heap then extract max  

## Related

- Basic O(n²) sorts → [`../10-basic-sorting-algorithms`](../10-basic-sorting-algorithms/)
