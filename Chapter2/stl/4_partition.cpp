#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void printList(list<int>&);
void partition(list<int>::iterator&, list<int>&);

int main() {
  int values[] = { 3, 7, 5, 8, 10, 6, 1};
  list<int> l(values, values + 7);
  list<int>::iterator i = l.begin();
  std::advance(i, l.size() / 2);

  printList(l);
  partition(i ,l);
  printList(l);

  return 0;
}

void partition(list<int>::iterator &node, list<int> &l) {
  list<int> lower;
  list<int> higher;

  for (list<int>::iterator i = l.begin(); i != l.end(); ++i) {
    if (i == node) {
      continue;
    }

    if (*i < *node) {
      lower.push_back(*i);
    } else {
      higher.push_back(*i);
    }
  }

  lower.push_back(*node);
  lower.merge(higher);
  l = lower;
}

void printList(list<int> &l) {
  list<int>::iterator it;

  for (it = l.begin(); it != l.end(); ++it)
    cout << *it << "\t";

  cout << endl;
}
