#include "LinkedList/LinkedList.h"
#include "LinkedList/LinkedList.cpp"
#include <iostream>
using namespace std;

bool isPalindrome(LinkedList<char>&);

int main() {

  LinkedList<char> list;

  list.append('s');
  list.append('e');
  list.append('e');
  list.append('s');

  list.print();
  cout << "is palindrome: " << (isPalindrome(list) ? "YES" : "NO") << endl;

  return 0;
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
