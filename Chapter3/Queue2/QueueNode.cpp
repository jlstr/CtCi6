#include "QueueNode.h"

template<class T>
QueueNode<T>::QueueNode(T item, QueueNode *next) {
  this->item = item;
  this->next = next;
}
