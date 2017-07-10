#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include <vector>

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
  int numElements;

  public:

  void append(const Data&);
  void prepend(const Data&);
  void print();
  bool remove(const Data&);
  std::vector<Data> values();
  Node* kthToLast(int);
  LinkedList<Data> partition(int);
  int size();
};

#endif
