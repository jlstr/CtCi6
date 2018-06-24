#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int value): data(value), next(nullptr) {}
};

Node* intersection(Node*, Node*);

int main() {
  Node *list = new Node(1);
  list->next = new Node(2);
  list->next->next = new Node(3);

  Node *list2 = list;

  Node *i = intersection(list, list2);
  cout << i->data << endl;

  return 0;
}

Node* intersection(Node *list, Node* list2) {
  Node *i = list, *j = list2;
  while (i->next)
    i = i-> next;

  while (j->next)
    j = j->next;

  if (i != j)
    return nullptr;

  for (i = list; i != nullptr; i = i->next)
    for (j = list2; j != nullptr; j = j->next) {
      if (i == j)
        return i;
    }

  return nullptr;
}
