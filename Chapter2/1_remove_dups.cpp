#include "LinkedList/LinkedList.h"
#include "LinkedList/LinkedList.cpp"
#include <iostream>
#include <map>
using namespace std;

void removeDups(LinkedList<int>&);

int main() {

  LinkedList<int> linkedList;
  linkedList.append(1);
  linkedList.append(2);
  linkedList.append(2);
  linkedList.append(2);
  linkedList.append(666);
  linkedList.append(666);
  linkedList.append(777);

  linkedList.print();
  removeDups(linkedList);
  linkedList.print();

  return 0;
}

void removeDups(LinkedList<int> &linkedList) {
  vector<int> values = linkedList.values();

  if (values.empty())
    return;

  map<int, bool> dups;

  for(vector<int>::iterator i = values.begin(); i != values.end(); ++i) {
    if (dups[*i])
      linkedList.remove(*i);
    else
      dups[*i] = true;
  }
}
