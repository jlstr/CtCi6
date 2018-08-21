#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "StackNode.h"
#include "StackNode.cpp"

template<class T>
class Stack {
public:
  Stack();
  void push(T item);
  void pop();
  T peek();
  bool isEmpty();
  void print();
  T min();
  int size();

private:
  StackNode<T> *head;
  int itemCount;
};
#endif
