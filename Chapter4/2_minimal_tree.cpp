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

Node* minimalBST(vector<int>);

int main() {
  int a[] = { 1, 2, 3, 4, 5, 6, };
  vector<int> array(a,  a + (sizeof(a)/sizeof(int)));
  Node *node = minimalBST(array);

  cout << node->value << endl;
  cout << node->left->right->value << endl;

  return 0;
}

Node* minimalBST(vector<int> array) {
  if (array.size() == 0) {
    return nullptr;
  }

  int middle = array.size() / 2;
  Node *node = new Node(array[middle]);
  node->left = minimalBST(vector<int>(array.begin(), array.begin() + middle));
  node->right = minimalBST(vector<int>(array.begin() + middle + 1, array.end()));

  return node;
}