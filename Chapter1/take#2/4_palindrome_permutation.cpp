#include <iostream>
#include <string>
#include <map>
using namespace std;

bool isPermutation(std::string&, std::string&);

int main() {

  return 0;
}

bool isPermutation(std::string &palindrome, std::string &permutation) {
  std::map<char, int> characters;

  for(std::string::size_type i = 0; i < palindrome.size(); ++i) {
    if (palindrome[i] != ' ') {
      map[palindrome[i]] = map[palindrome[i]] + 1;
    }
  }

  // TODO: Not done

  return true;
}
