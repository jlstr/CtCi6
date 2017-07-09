#include "LinkedList/LinkedList.h"
#include "LinkedList/LinkedList.cpp"
#include <iostream>
using namespace std;

int main() {

  LinkedList<int> list;
  list.append(3);
  list.append(5);
  list.append(8);
  list.append(5);
  list.append(10);
  list.append(2);
  list.append(1);

  list.print();
  // perform partition
  list = list.partition(8);
  list.print();

  return 0;
}
