#include "Stack.h"

template<class Data>
Stack<Data>::Stack() {
  // nothing for now
}

template<class Data>
Data Stack<Data>::peek() {
  if (this->linkedList.empty())
    throw std::length_error("Empty Stack");

  typename LinkedList<Data>::Node *node = this->linkedList.kthToLast(1);
  return node->data;
}

template<class Data>
void Stack<Data>::push(const Data &data) {
  this->linkedList.append(data);
}

template<class Data>
bool Stack<Data>::empty() {
  return this->linkedList.empty();
}

template<class Data>
void Stack<Data>::pop() {
  this->linkedList.removeTail();
}
