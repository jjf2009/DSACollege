#pragma once 
#include <iosteam>
using namespace std;

template <class T>
class Node {
public:
  T info;
  Node *left, *right;
  Node<T>(T info) : info(info), left(nullptr), right(nullptr) {} 
  ~Node<T>() {
    delete left;
    delete right; 
    left = nullptr;
    right = nullptr;
  }
};
