#include <iostream>

struct Node {
  Node(const int &value) {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
  }

  int value;
  Node *left;
  Node *right;
};

class BinaryTree {
  public:
  BinaryTree();
  void insert(const int&);

  private:
  Node *root;
  Node* performInsertion(Node*&, const int&);
};

BinaryTree::BinaryTree() {
  this->root = nullptr;
}

void BinaryTree::insert(const int &value) {
  this->root = performInsertion(this->root, value);
}

Node* BinaryTree::performInsertion(Node* &root, const int &value) {
  if (root == nullptr) {
    root = new Node(value);
  } else {
    if (value <= root->value)
      performInsertion(root->left, value);
    else
      performInsertion(root->right, value);
  }

  return root;
}