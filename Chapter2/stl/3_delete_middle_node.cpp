#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void printList(list<char>&);
void deleteNode(std::list<char>::iterator&, std::list<char>::iterator&);

int main() {

  list<char> l;
  char letters[] = { 'a', 'b', 'c', 'd', 'e' };
  l.assign(letters, letters+5);

  std::list<char>::iterator it = l.begin();
  std::list<char>::iterator end = l.end();
  std::advance(it, 2);

  printList(l);

  deleteNode(it, end);

  printList(l);


  return 0;
}

void deleteNode(std::list<char>::iterator &it, std::list<char>::iterator &end) {
  std::list<char>::iterator next = std::next(it, 1);
  *it = *next;

  it = std::next(next, 1);
}

void printList(list<char> &l) {
  list<char>::iterator it;

  for (it = l.begin(); it != l.end(); ++it)
    cout << *it << "\t";

  cout << endl;
}
