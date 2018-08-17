#include "StackNode.h"

template<class T>
StackNode<T>::StackNode() {
}

template<class T>
StackNode<T>::StackNode(T data, StackNode *next) {
  this->data = data;
  this->next = next;
}
