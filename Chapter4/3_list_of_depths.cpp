#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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

void preOrder(Node*, int, map< int, vector<int> >&);

int main() {
  Node *root = new Node(2);
  root->left = new Node(1);
  root->left->left = new Node(0);
  root->left->right = new Node(0);

  root->right = new Node(3);

  // A HashTable that maps and Index (Height) to a vector<int>
  map< int, vector<int> > lists;
  // Call PreOrder
  preOrder(root, 0, lists);


  // Test
  vector<int> l = lists[2];
  for (vector<int>::iterator it = l.begin(); it != l.end(); ++it) {
    cout << *it << "\t";
  }

  cout << endl;

  return 0;
}

void preOrder(Node* root, int index, map< int, vector<int> > &lists) {
  if (root == nullptr) {
    return;
  }

  lists[index].push_back(root->value);
  preOrder(root->left, index + 1, lists);
  preOrder(root->right, index + 1, lists);
}
