#include <iostream>
#include <string>
#include <sstream>
using namespace std;

std::string urlify(const string&, const int);

int main() {

  const string str = "Mr John Smith     ";
  const int size = 13;

  cout << urlify(str, size) << endl;

  return 0;
}

std::string urlify(const string &original, const int size) {
  std::stringstream stream;

  for (string::size_type i = 0; static_cast<int>(i) < size; ++i) {
    if (i > 0 && original[i] == ' ') {
      stream << "%20";
    } else
      stream << original[i];
  }

  return stream.str();
}
