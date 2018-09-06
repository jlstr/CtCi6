#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

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

int treeHeight(Node*);
bool isBalanced(Node*, Node*);

int main() {
  Node *root = new Node(5);
  root->left = new Node(2);
  root->left->left = new Node(1);
  root->left->left->left = new Node(-1); 
  
  root->right = new Node(7);

  cout << "Is Balanced? " << ((isBalanced(root->left, root->right)) ? "YES" : "NO") << endl;

  return 0;
}

int treeHeight(Node *root) {
  if (root == nullptr) {
    return 0;
  }

  return std::max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

bool isBalanced(Node *left, Node *right) {
  return std::abs(treeHeight(left) - treeHeight(right)) < 2;
}