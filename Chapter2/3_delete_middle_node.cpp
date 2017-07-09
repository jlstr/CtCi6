#include "LinkedList/LinkedList.h"
#include "LinkedList/LinkedList.cpp"
#include <iostream>
using namespace std;

void removeNode(LinkedList<int>::Node*);

int main() {

  LinkedList<int> list;

  list.append(666);
  list.append(555);
  list.append(777);

  list.print();

  LinkedList<int>::Node *node = list.kthToLast(2);
  removeNode(node);

  list.print();

  return 0;
}

void removeNode(LinkedList<int>::Node *node) {
  node->data = node->next->data;
  node->next = node->next->next;
}
