#ifndef QUEUE_H
#define QUEUE_H
#include "../../Chapter2/LinkedList/LinkedList.h"
#include "../../Chapter2/LinkedList/LinkedList.cpp"
#include <stdexcept>

template<class Data>
class Queue {
  
  public:
  Queue();

  private:
  LinkedList<Data> linkedList;

  public:
  void add(const Data&);
  void remove();
  Data peek();
  bool empty(); 

};

#endif
