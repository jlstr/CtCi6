#include "Queue.h"

template<class Data>
Queue<Data>::Queue() {
  // nothing for now
}

template<class Data>
void Queue<Data>::add(const Data &data) {
  this->linkedList.append(data);
}

template<class Data>
void Queue<Data>::remove() {
  this->linkedList.removeHead();
}

template<class Data>
Data Queue<Data>::peek() {
  if (this->linkedList.empty())
    throw std::length_error("Empty Stack");

  typename LinkedList<Data>::Node *node = this->linkedList.kthToLast(this->linkedList.size());
  return node->data;
}

template<class Data>
bool Queue<Data>::empty() {
  return this->linkedList.empty();
}
