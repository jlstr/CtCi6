#include "LinkedList/LinkedList.h"
#include "LinkedList/LinkedList.cpp"
#include <iostream>
#include <string>
using namespace std;

LinkedList<int>::Node* newNode(const int);
bool sameNode(LinkedList<int>::Node*, LinkedList<int>::Node*);
LinkedList<int>::Node* intersection(LinkedList<int>&, LinkedList<int>&);

int main() {

  LinkedList<int> list1;
  LinkedList<int> list2;
  LinkedList<int>::Node *node = newNode(7);

  list1.append(1);
  list1.append(2);
  list1.append(3);
  list1.append(4);
  list1.append(node);

  list2.append(5);
  list2.append(6);
  list2.append(node);

  list1.print();
  list2.print();

  LinkedList<int>::Node *intersectionNode = intersection(list1, list2);
  cout << "Lists intersect @Node with value: " << ((intersectionNode == NULL) ? "" : std::to_string(intersectionNode->data)) << endl;

  return 0;
}

LinkedList<int>::Node* newNode(const int data) {
  LinkedList<int>::Node *node = new LinkedList<int>::Node();
  node->data = data;
  node->next = NULL;

  return node;
}

bool sameNode(LinkedList<int>::Node *n1, LinkedList<int>::Node *n2) {
  return n1 == n2;
}

LinkedList<int>::Node* intersection(LinkedList<int> &list1, LinkedList<int> &list2) {
  
  LinkedList<int> &x = list1; // larger list
  LinkedList<int> &y = list2;

  if (x.size() < y.size()) {
    LinkedList<int> &tmp = x;
    x = y;
    y = tmp;
  }

  LinkedList<int>::Node *head1 = list1.kthToLast(list1.size());
  LinkedList<int>::Node *head2 = list2.kthToLast(list2.size());

  int sizeDiff = x.size() - y.size();
  while (sizeDiff > 0) {
    head1 = head1->next;
    sizeDiff--;
  }

  while (head1 != NULL && head2 != NULL) {
    if (sameNode(head1, head2))
      return head1;

    head1 = head1->next;
    head2 = head2->next;
  }

  return NULL;
}
