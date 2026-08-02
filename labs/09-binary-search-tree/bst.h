#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;
template <typename T>
class BST {
private:
    class Node {
        T data;
        Node* left;
        Node* right;
        Node(T val);
    };

    Node* root;
    void insert(Node*& node, T val, Node* parent);
    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);
    Node* deleteNode(Node* node, T val);
    T minValue(Node* node);
    int height(Node* node);
    bool searchHelper(Node* node, T val, int level, string position,string path);

public:
    BST();
    void insert(T val);
    void inorder();
    void preorder();
    void postorder();
    void deleteNode(T val);
    int height();
    void search(T val); // Enhanced search with position and level output
};


template <typename T>
BST<T>::Node::Node(T val) {
    data = val;
    left = nullptr;
    right = nullptr;
}


template <typename T>
BST<T>::BST() {
    root = nullptr;
}
template <typename T>
void BST<T>::insert(Node*& node, T val, Node* parent) {
    if (node == nullptr) {
        node = new Node(val);
        if (parent == nullptr)
            cout << "Inserted " << val << " as Root Node\n";
        else if (val < parent->data)
            cout << "Inserted " << val << " as Left Child of " << parent->data << endl;
        else
            cout << "Inserted " << val << " as Right Child of " << parent->data << endl;
    } 
    else if (val < node->data)
        insert(node->left, val, node);
    else if (val > node->data)
        insert(node->right, val, node);
    else
        cout << "Duplicate value " << val << " ignored (already exists)\n";
}

template <typename T>
void BST<T>::insert(T val) {
    insert(root, val, nullptr);
}

template <typename T>
void BST<T>::inorder(Node* node) {
    if (node) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

template <typename T>
void BST<T>::preorder(Node* node) {
    if (node) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

template <typename T>
void BST<T>::postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}


template <typename T>
T BST<T>::minValue(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current->data;
}


template <typename T>
typename BST<T>::Node* BST<T>::deleteNode(Node* node, T val) {
    if (node == nullptr)
        return node;

    if (val < node->data)
        node->left = deleteNode(node->left, val);
    else if (val > node->data)
        node->right = deleteNode(node->right, val);
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            cout << "Deleted node " << node->data << endl;
            delete node;
            return temp;
        } 
        else if (node->right == nullptr) {
            Node* temp = node->left;
            cout << "Deleted node " << node->data << endl;
            delete node;
            return temp;
        }

        node->data = minValue(node->right);
        node->right = deleteNode(node->right, node->data);
    }
    return node;
}

template <typename T>
void BST<T>::deleteNode(T val) {
    root = deleteNode(root, val);
}

template <typename T>
int BST<T>::height(Node* node) {
    if (node == nullptr)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + max(leftHeight, rightHeight);
}

template <typename T>
int BST<T>::height() {
    return height(root);
}

template <typename T>
bool BST<T>::searchHelper(Node* node, T val, int level, string position, string path) {
    if (node == nullptr)
        return false;

    if (!path.empty()) path += " -> ";
    path += position;

    if (node->data == val) {
        path += " -> Found";
        cout << "Element found: " << val << endl;
        cout << "Path: " << path << endl;
        cout << "Level: " << level << endl;
        return true;
    }

    if (val < node->data)
        return searchHelper(node->left, val, level + 1, "Left", path);
    else
        return searchHelper(node->right, val, level + 1, "Right", path);
}


template <typename T>
void BST<T>::search(T val) {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }

    if (!searchHelper(root, val, 1, "Root", ""))
        cout << "Element not found in the tree.\n";
}

// ==========================
// Public Traversal Wrappers
// ==========================
template <typename T>
void BST<T>::inorder() {
    inorder(root);
    cout << endl;
}

template <typename T>
void BST<T>::preorder() {
    preorder(root);
    cout << endl;
}

template <typename T>
void BST<T>::postorder() {
    postorder(root);
    cout << endl;
}

#endif