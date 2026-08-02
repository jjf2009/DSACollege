# Lab 09 — Binary Search Tree (BST) in C++

**Binary search tree C++ lab**: insert, delete, search, inorder / preorder / postorder traversal, and height — menu-driven for int or char keys.

## What is a BST?

A **binary search tree** is a binary tree where for every node, all keys in the left subtree are smaller and all keys in the right subtree are greater. Average search/insert/delete: **O(log n)**; worst case (skewed): **O(n)**.

## Operations

| Operation | Description |
|-----------|-------------|
| Insert | Recursive place by key order |
| Delete | Leaf / one child / two children (inorder successor) |
| Search | Path, level, position feedback |
| Inorder | Sorted key order |
| Preorder / Postorder | Classic DFS orders |
| Height | Longest root-to-leaf path length |

## Files

- `bst.h` + `main.cpp` — primary template BST  
- `template-variant/` — alternate header/main  

## Quick run

```bash
g++ -std=c++17 -Wall -o bst main.cpp && ./bst
```

## Related

- Classroom BST → [`../../classroom/binary-search-tree-basics`](../../classroom/binary-search-tree-basics/)
- Exam → [`../../exam/09-binary-search-tree`](../../exam/09-binary-search-tree/)
- Sorting (produce ordered data without tree) → [`../10-basic-sorting-algorithms`](../10-basic-sorting-algorithms/)
