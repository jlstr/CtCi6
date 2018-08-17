#include "Stack.h"
#include "../Exceptions/EmptyException.cpp"

template<class T>
Stack<T>::Stack() {
  this->head = nullptr;
  this->size = 0;
};

template<class T>
void Stack<T>::push(T item) {
  if (isEmpty()) {
    this->head = new StackNode<T>(item, nullptr);
  } else {
    this->head = new StackNode<T>(item, this->head);
  }

  this->size++;
}

template<class T>
void Stack<T>::pop() {
  if (isEmpty())
    return;

  StackNode<T> *tmp = this->head;
  this->head = this->head->next;
  delete tmp;
}

template<class T>
T Stack<T>::peek() {
  if (isEmpty())
    throw EmptyException();

  return this->head->data;
}

template<class T>
bool Stack<T>::isEmpty() {
  return this->size == 0;
}

template<class T>
void Stack<T>::print() {
  StackNode<T> *node = this->head;

  while (node != nullptr) {
    std::cout << node->data << ((node == this->head) ? " <-- Top" : "") << '\n';
    node = node->next;
  }
}
