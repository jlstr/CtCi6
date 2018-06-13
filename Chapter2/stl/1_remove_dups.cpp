#include <iostream>
#include <list>
#include <iterator>
#include <map>
using namespace std;

void printList(list<int>&);
void removeDuplicates(list<int>&);

int main() {
  list<int> numbers;

  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(3);
  numbers.push_back(3);

  printList(numbers);
  removeDuplicates(numbers);
  printList(numbers);

  return 0;
}

void removeDuplicates(list<int> &l) {
  map<int, bool> m;
  list<int> newl;

  for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
    if (!m[*it])
      newl.push_back(*it);

    m[*it] = true;
  }

  l = newl;
}

void printList(list<int> &l) {
  list<int>::iterator it;

  for (it = l.begin(); it != l.end(); ++it)
    cout << *it << "\t";

  cout << endl;
}
