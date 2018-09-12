#include <iostream>
using namespace std;

struct Node {
  Node(const int &value, Node *parent=nullptr) {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = parent;
  }

  int value;
  Node *left;
  Node *right;
  Node *parent;
};

int findSuccessor(Node*);

int main() {
  Node *root = new Node(15);

  root->left = new Node(6, root);
  root->right = new Node(18, root);

  root->right->left = new Node(17, root->right);
  root->right->right = new Node(20, root->right);

  root->left->right = new Node(7, root->left);
  root->left->right->right = new Node(13, root->left->right);
  root->left->right->right->left = new Node(9, root->left->right->right);

  cout << "Successor of: " << root->value << " is: " << findSuccessor(root) << endl;
  cout << "Successor of: " << root->left->right->right->value << " is: " << findSuccessor(root->left->right->right) << endl;

  return 0;
}

int findSuccessor(Node *node) {
  if (node->right != nullptr) {
    Node *successor = node->right;

    while (successor->left != nullptr) {
      successor = successor->left;
    }

    return successor->value;
  } else {
    Node *successor = node;
    int value = successor->value;

    while (successor->parent != nullptr) {
      Node *current = successor;
      successor = successor->parent;

      if (successor->left == current) {
        return successor->value;
      }
    }
  }

  return 0;
}