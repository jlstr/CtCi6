#include <iostream>
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

bool find(Node*, Node*);
Node* findCommonAncestor(Node*, Node*, Node*);

int main() {
  Node *root = new Node(12);
  root->left = new Node(9);
  root->left->left = new Node(6);
  root->left->right = new Node(7);

  Node *ancestor = findCommonAncestor(root, root->left->left, root->left->right);

  cout << "Ancestor: " << ancestor->value << endl;

  return 0;
}

bool find(Node *root, Node *p) {
  if (root == nullptr)
    return false;
  
  if (root == p)
    return true;

  return find(root->left, p) || find(root->right, p);
}

Node* findCommonAncestor(Node *root, Node *p, Node *q) {
  if (root == nullptr)
    return nullptr;
  
  if (root == p)
    return p;

  if (root == q)
    return q;

  bool pIsOnLeft = find(root->left, p);
  bool qIsOnLeft = find(root->left, q);

  if (pIsOnLeft != qIsOnLeft)
    return root;

  Node *side = pIsOnLeft ? root->left : root->right;
  return findCommonAncestor(side, p, q);
}