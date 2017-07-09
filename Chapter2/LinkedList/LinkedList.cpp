#include "LinkedList.h"
#include <vector>

template<class Data>
LinkedList<Data>::LinkedList() {
  this->head = NULL;
  this->numElements = 0;
}

template<class Data>
void LinkedList<Data>::append(const Data &data) {
  Node *node = new Node();
  node->data = data;
  node->next = NULL;
  // Increase num-elements count
  this->numElements++;
  
  if (head == NULL) {
    head = node;
    return;
  }

  Node *ptr;
  for (ptr = head; ptr->next != NULL; ptr = ptr->next);

  ptr->next = node;
}

template<class Data>
int LinkedList<Data>::size() {
  return this->numElements;
}

template<class Data>
void LinkedList<Data>::print() {
  for (Node *ptr = head; ptr != NULL; ptr = ptr->next)
    std::cout << ptr->data << "  -->  ";

  std::cout << "END" << std::endl;
}

template<class Data>
bool LinkedList<Data>::remove(const Data &data) {
  if (head == NULL)
    return false;

  Node *tmp = head, *prev = head;

  while (tmp != NULL) {
    if (tmp->data == data) {

      if (prev == tmp)
        head = tmp->next;
      else {
        prev->next = tmp->next;
        tmp->next = NULL;
      }
      
      delete tmp;
      return true;
    } else {
      prev = tmp;
      tmp = tmp->next;
    }
  } 

  return false;
}

template<class Data>
std::vector<Data> LinkedList<Data>::values() {
  std::vector<Data> listValues;

  for (Node *tmp = head; tmp != NULL; tmp = tmp->next)
    listValues.push_back(tmp->data);

  return listValues;
}

template<class Data>
typename LinkedList<Data>::Node* LinkedList<Data>::kthToLast(int k) {
  Node *tmp = head, *kth = head;

  for (int i = 0; i < k; ++i) // Move a pointer k places
    tmp = tmp->next;

  while (tmp != NULL) { // Then move the 2 pointers at the same rate
    tmp = tmp->next;
    kth = kth->next;
  }

  return kth;
}

template<class Data>
LinkedList<Data> LinkedList<Data>::partition(int x) {
  LinkedList<Data> lower;
  LinkedList<Data> higher;

  int highCount = 0;

  for (Node *node = head; node != NULL; node = node->next) {
    if (node->data < x)
      lower.append(node->data);
    else {
      // If node->data is equal to x it should prepend instead.
      higher.append(node->data);
      highCount++;
    }
  }

  Node *lastLower = lower.kthToLast(1);
  Node *firstHigher = higher.kthToLast(highCount);
  // Merge both lists
  lastLower->next = firstHigher;

  return lower;
}
