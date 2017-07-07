#ifndef HASH_MAP_H
#define HASH_MAP_H
#include <iostream>
#include <vector>

template<class Data>
class LinkedList {
  
  public:

  LinkedList(); // constructor
  // ~LinkedList(); // destructor

  private:
  
  struct Node {
    Data data;
    Node *next;
  };

  Node *head;

  public:

  void append(const Data&);
  void print();
  bool remove(const Data&);
  std::vector<Data> values();

};

#endif
