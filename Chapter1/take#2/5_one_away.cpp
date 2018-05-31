#include <iostream>
#include <string>
#include <map>
using namespace std;

bool isOneAway(const std::string&, const std::string&);

int main() {
  cout << (isOneAway("pale", "bale") ? "YES" : "NO") << endl;

  return 0;
}

bool isOneAway(const std::string &original, const std::string &modified) {
  std::map<char, int> characters;
  int count = 0;

  for (std::string::size_type i = 0; i < original.size(); ++i) {
    characters[original[i]]++;
    count++;
  }

  for (std::string::size_type i = 0; i < original.size(); ++i) {
    if (characters[modified[i]]) {
      count--;
    }
  }

  return count == 1;
}
