#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert a node in the BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Function to build BST from a vector
Node* buildBST(const vector<int>& v) {
    Node* root = nullptr;
    for (int val : v) {
        root = insert(root, val);
    }
    return root;
}

// Inorder traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";

}


void preorder(Node* root) {
    if (root == nullptr) return;
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}

// Driver code
int main() {
    vector<int> v = {1, 4, 3, 2, 6};
    Node* root = buildBST(v);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
      cout << endl;
    cout << "Preorder Traversal of BST: ";
    preorder(root);
      cout << endl;
    cout << "Preorder Traversal of BST: ";
    preorder(root);
    cout << endl;

    return 0;
}
