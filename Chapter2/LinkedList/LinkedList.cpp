#include "LinkedList.h"

template<class Data>
LinkedList<Data>::LinkedList() {
  this->head = NULL;
}

template<class Data>
void LinkedList<Data>::append(const Data &data) {
  Node *node = new Node();
  node->data = data;
  node->next = NULL;
  
  if (head == NULL) {
    head = node;
    return;
  }

  Node *ptr;
  for (ptr = head; ptr->next != NULL; ptr = ptr->next);

  ptr->next = node;
}

template<class Data>
void LinkedList<Data>::print() {
  for (Node *ptr = head; ptr != NULL; ptr = ptr->next)
    std::cout << ptr->data << "  -->  ";

  std::cout << "NULL" << std::endl;
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
