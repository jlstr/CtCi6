#include "LinkedList/LinkedList.h"
#include "LinkedList/LinkedList.cpp"
#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef LinkedList<char>::Node Node;
bool equalNodes(Node*, Node*);

int main() {
  LinkedList<char> list;
  map<int, Node*> nodes;

  Node *node1 = new Node();
  node1->data = 'A';

  Node *node2 = new Node();
  node2->data = 'B';

  Node *node3 = new Node();
  node3->data = 'C';

  Node *node4 = new Node();
  node4->data = 'D';
  
  Node *node5 = new Node();
  node5->data = 'E';

  list.append(node1);
  list.append(node2);
  list.append(node3);
  list.append(node4);
  list.append(node5);
  list.append(node2);

  Node *problemNode = list.loopingNode();
  cout << ((problemNode == NULL) ? "OK" : string(1, problemNode->data)) << endl;
  
  return 0;
}

bool equalNodes(Node *node1, Node *node2) {
  return node1 == node2;
}
