#include <forward_list>
#include <iostream>
#include <iterator>
using namespace std;

void printList(forward_list<int>&);
int kthToLast(forward_list<int>&, int);
int kthToLast(forward_list<int>::iterator&, forward_list<int>&, int, int&);

int main() {
  forward_list<int> l;
  int numbers[] = { 44, 20, 777, 666 };
  l.assign(numbers, numbers + 4);
  printList(l);

  forward_list<int>::iterator it = l.begin();
  int save;

  kthToLast(it, l, -4, save);
  cout << save << endl;

  return 0;
}

int kthToLast(forward_list<int>::iterator &it, forward_list<int> &l, int k, int &save) {
  if (it == l.end()) {
    return 0;
  }

  forward_list<int>::iterator n = std::next(it, 1);
  int x = kthToLast(n, l, k, save) - 1;

  if (x == k) {
    save = *it;
  }

  return x;
}

void printList(forward_list<int> &l) {
  for (forward_list<int>::iterator it = l.begin(); it != l.end(); ++it)
    cout << *it << "\t";
  cout << endl;
}

int kthToLast(forward_list<int> &l, int k) {
  if (k > 0) return -1;
  int kth = k * -1, count = 0;
  forward_list<int>::iterator i, j;

  for (i = l.begin(); i != l.end(); ++i)
    count++;

  if (kth > count) return -1;

  j = l.begin();
  for (int i = 0; i < (count-kth); ++i, ++j);

  return *j;
}
