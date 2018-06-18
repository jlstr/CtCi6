#include <iostream>
#include <list>
#include <iterator>
#include <string>
using namespace std;

void palindrome(list<char>::iterator&, list<char>::iterator&, string&);

int main() {

  char letters[] = { 'r', 'a', 'c', 'e', 'c', 'a', 'r' };
  list<char> word(letters, letters + (sizeof(letters)/sizeof(char)));
  string s = "";
  list<char>::iterator i = word.begin(), j = word.end();
  palindrome(i, j, s);

  cout << "PALINDROME: " << ((s.empty()) ? "YES!" : "NO!") << endl;

  return 0;
}

void palindrome(list<char>::iterator &i, list<char>::iterator &end, string &s) {
  if (i == end)
    return;

  s.push_back(*i);
  list<char>::iterator current = i;
  list<char>::iterator n = next(current, 1);
  palindrome(n, end, s);

  if (s.front() == *current)
    s = s.substr(1);
}
