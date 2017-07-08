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

  cout << list.kthToLast(1) << endl;
  return 0;
}
