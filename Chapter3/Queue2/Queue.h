#ifndef QUEUE_H
#define QUEUE_H

#include "QueueNode.h"
#include "QueueNode.cpp"

template<class T>
class Queue {

public:
  Queue();
  void add(T item);
  void remove();
  T peek();
  bool isEmpty();
  void print();

private:
  QueueNode<T> *first;
  QueueNode<T> *last;
  int size;
};

#endif
