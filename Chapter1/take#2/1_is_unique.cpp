#include <iostream>
#include <string>
#include <map>
using namespace std;

bool isUnique(std::string&);

int main() {
  string s = "murcielago";
  cout << s << " is unique: " << (isUnique(s) ? "TRUE" : "FALSE") << endl;

  return 0;
}

bool isUnique(std::string &str) {
  map<char, bool> characters;

  for (std::string::size_type i = 0; i < str.size(); ++i) {
    if (characters[str[i]]) {
      return false;
    }

    characters[str[i]] = true;
  }

  return true;
}
