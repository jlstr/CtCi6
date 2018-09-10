#include <iostream>
#include <limits>
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

bool checkBST(Node*);

int main() {
  Node *root = new Node(8);
  root->left = new Node(4);
  root->left->left = new Node(2);
  root->left->right = new Node(6);

  root->right = new Node(10);
  root->right->right = new Node(20);

  cout << (checkBST(root) ? "TRUE" : "FALSE") << endl;

  return 0;
}

bool checkBST(Node *root) {
  if (root == nullptr) {
    return true;
  }

  bool leftCheck = checkBST(root->left);
  bool rightCheck = checkBST(root->right);

  if (!leftCheck  || !rightCheck) {
    return false;
  }

  int value = root->value;
  int L = (root->left == nullptr) ? std::numeric_limits<int>::min() : root->left->value;
  int R = (root->right == nullptr) ? std::numeric_limits<int>::max() : root->right->value;

  return (L < value) && (R > value);
}