#include "Queue.h"
#include <iostream>
#include "../Exceptions/EmptyException.cpp"

template<class T>
Queue<T>::Queue() {
  this->first = nullptr;
  this->last = nullptr;
  this->size = 0;
}

template<class T>
void Queue<T>::add(T item) {
  QueueNode<T> *node = new QueueNode<T>(item, nullptr);

  if (isEmpty()) {
    this->first = node;
    this->last = node;
  } else {
    this->last->next = node;
    this->last = node;
  }

  this->size++;
}

template<class T>
void Queue<T>::remove() {
  if (isEmpty())
    return;

  QueueNode<T> *node = this->first;

  if (this->first == this->last) {
    this->first = nullptr;
    this->last = nullptr;
  } else {
    first = first->next;
    node->next = nullptr;
  }

  this->size--;
  delete node;
}

template<class T>
T Queue<T>::peek() {
  if (isEmpty())
    throw EmptyException();

  return this->first->item;
}

template<class T>
bool Queue<T>::isEmpty() {
  return (this->first == nullptr && this->last == nullptr) && this->size == 0;
}

template<class T>
void Queue<T>::print() {
  if (isEmpty())
    return;

  QueueNode<T> *node = this->first;

  while (node != nullptr) {
    std::cout << node->item << std::endl;
    node = node->next;
  }
}
