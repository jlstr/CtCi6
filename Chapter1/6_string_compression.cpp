#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string compressString(const string&);

int main() {
  cout << compressString("puuuuuerrcoooo") << endl;
  return 0;
}


string compressString(const string &str) {
  if (str.size() <= 1)
    return str;

  int charCount = 1;
  std::stringstream buffer;


  for (string::size_type i = 1; i < str.size(); ++i) {
    if (str[i] == str[i - 1])
      charCount++;
    else {
      buffer << str[i - 1] << charCount;
      charCount = 1;
    }
  }

  buffer << str[str.size() - 1] << charCount;

  if (buffer.str().size() > str.size())
    return str;

  return buffer.str();
}
