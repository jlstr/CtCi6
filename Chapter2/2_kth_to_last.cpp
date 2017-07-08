#include "LinkedList/LinkedList.h"
#include "LinkedList/LinkedList.cpp"
#include <iostream>
using namespace std;

int main() {
  LinkedList<char> list;

  list.append('a');
  list.append('b');
  list.append('c');
  list.append('d');
  list.append('e');

  int k = 1;
  bool found = (list.kthToLast(k) != NULL);

  cout << (found ? string(1, list.kthToLast(k)->data) : "Not Found") << endl;
  return 0;
}
