#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include <vector>
#include <map>

template<class Data>
class LinkedList {
  
  public:

  LinkedList(); // constructor
  // ~LinkedList(); // destructor

  struct Node {
    Data data;
    Node *next;
  };

  private:
  Node *head;

  public:

  void append(const Data&);
  void append(Node*);
  void prepend(const Data&);

  void print();
  bool remove(const Data&);
  bool empty();
  std::vector<Data> values();
  Node* kthToLast(int);
  LinkedList<Data> partition(int);
  int size();
  Node* loopingNode();
  
  void removeTail();
  void removeHead();
};

#endif
