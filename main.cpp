#include <cstring>
#include <iostream>

#include "src/hello.hpp"

void tests(const char* first, const char* second) {
  int result = strcmp_case_insensitive (first, second);
  std::cout << "The comparison of \"" << first << "\" and \"" << second << "\" returns " << result << "." << std::endl;
}

int main() {
  // diff case, first < second
  tests("String one", "string two");

  // equal ignoring case
  tests("String one", "string one");

  // first > second
  tests("String two", "string one");

  // diff lengths
  tests("map", "mapmaker");

  // 1 empty string
  tests("", "hello");

  //both empty
  tests("", "");

  return 0;
}
