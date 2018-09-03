#include <iostream>
#include <vector>
#include <algorithm>
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

class BinarySearchTree {
  public:
  BinarySearchTree() {
    this->root = nullptr;
  }

  void insert(const int&);
  Node* getRoot();

  private:
  Node *root;
  Node* performInsertion(Node*&, const int&);
};

void BinarySearchTree::insert(const int &value) {
  this->root = performInsertion(this->root, value);
}

Node* BinarySearchTree::performInsertion(Node* &root, const int &value) {
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

Node* BinarySearchTree::getRoot() {
  return this->root;
}

Node* balancedInsert(Node*, vector<int>, vector<int>);

int main() {
  BinarySearchTree tree;

  int a[] = { 1, 2, 4, };
  vector<int> v(a, (a + (sizeof(a)/sizeof(int))));

  int middle = v.size() / 2;
  vector<int> left(v.begin(), v.begin() + middle);
  vector<int> right(v.begin() + middle + 1, v.end());

  tree.insert(v[middle]);

  Node *root = tree.getRoot();
  root = balancedInsert(tree.getRoot(), left, right);

  cout << root->left->value << endl;

  return 0;
}

Node* balancedInsert(Node* root, vector<int> L, vector<int> R) {
  if (L.size() == 1) {
    return new Node(L[0]);
  }

  if (R.empty()) {
    return nullptr;
  }

  int middle;
  vector<int> left;
  vector<int> right;
  Node *subRoot = nullptr;

  middle = L.size() / 2;
  subRoot = new Node(L[middle]);

  left.assign(L.begin(), L.begin() + middle);
  right.assign(L.begin() + middle + 1, L.end());
  root->left = balancedInsert(subRoot, left, right);

  middle = R.size() / 2;
  subRoot = new Node(R[middle]);

  left.assign(R.begin(), R.begin() + middle);
  right.assign(R.begin() + middle + 1, R.end());
  root->right = balancedInsert(subRoot, left, right);
  
  return root;
}