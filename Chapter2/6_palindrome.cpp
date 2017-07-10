#include "LinkedList/LinkedList.h"
#include "LinkedList/LinkedList.cpp"
#include <iostream>
using namespace std;

bool isPalindrome(LinkedList<char>&);
LinkedList<char> reverse(LinkedList<char>::Node*);
bool isPalindrome(LinkedList<char>&, LinkedList<char>&);

int main() {

  LinkedList<char> list;

  list.append('p');
  list.append('o');
  list.append('o');
  list.append('p');
  list.print();

  LinkedList<char> reversed = reverse(list.kthToLast(list.size()));
  cout << "is palindrome: " << (isPalindrome(list, reversed) ? "YES" : "NO") << endl;

  return 0;
}

// THIS IS HOW YOU REVERSE A LINKED-LIST (SINGLY) RECURSIVELY!
LinkedList<char> reverse(LinkedList<char>::Node *node) {
  if (node == NULL)
    return LinkedList<char>();

  LinkedList<char> list = reverse(node->next);
  list.append(node->data);

  return list;
}

bool isPalindrome(LinkedList<char> &list, LinkedList<char> &reversed) {
  LinkedList<char>::Node *head1 = list.kthToLast(list.size()), *head2 = reversed.kthToLast(reversed.size());

  while (head1 != NULL && head2 != NULL) {
    if (head1->data != head2->data)
      return false;

    head1 = head1->next;
    head2 = head2->next;
  }

  return true;
}

bool isPalindrome(LinkedList<char> &list) {
  vector<char> listValues = list.values();
  LinkedList<char> reversed;

  for (vector<char>::iterator i = listValues.begin(); i != listValues.end(); ++i)
    reversed.prepend(*i);

  LinkedList<char>::Node *n1 = list.kthToLast(list.size());
  LinkedList<char>::Node *n2 = reversed.kthToLast(reversed.size());

  while (n1 != NULL && n2 != NULL) {
    if (n1->data != n2->data)
      return false;

    n1 = n1->next;
    n2 = n2->next;
  }
  
  return true;
}
