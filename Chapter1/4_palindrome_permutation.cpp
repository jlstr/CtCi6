#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

bool isPermutation(string&);

int main() {
  string str = "atco atc";
  cout << str << " is palindrome permutation " << (isPermutation(str) ? "YES" : "NO") << endl;

  return 0;
}

bool isPermutation(string &str) {
  if (str.size() <= 1)
    return true;

  std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
  str.erase(end_pos, str.end());

  std::map<char, int> characterCount;

  for (string::size_type i = 0; i < str.size(); ++i) {
    if (characterCount[str[i]] == 0)
      characterCount[str[i]] = 1;
    else
      characterCount[str[i]] = characterCount[str[i]] + 1;
  }

  bool oddFound = false;
  int oddValue = 0;

  for (map<char, int>::const_iterator i = characterCount.begin(); i != characterCount.end(); ++i) {
    if (i->second%2 != 0) {
      if (oddFound)
        return false;

      oddFound = true;
      oddValue = i->second;
    }
  }
  
  if (str.size()%2 == 0) {
    if (!oddFound)
      return true;
  } else if (oddValue == 1) {
      return true;
  }

  return false;
}
