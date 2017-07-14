#ifndef STACK_H
#define STACK_H
#include "../../Chapter2/LinkedList/LinkedList.h"
#include "../../Chapter2/LinkedList/LinkedList.cpp"
#include <stdexcept>

template<class Data>
class Stack {

  public:
  Stack(); // constructor

  private:
  LinkedList<Data> linkedList;
  LinkedList<Data> minStack;
  
  public:
  Data peek();
  void push(const Data&);
  bool empty();
  void pop();
  Data min();
  
};

#endif
