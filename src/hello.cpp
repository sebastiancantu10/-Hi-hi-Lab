#include <string>
#include <cctype>
using namespace std;


// func compares two strings char by char, case-insensitive
// go until chars differ
// or end of string
// returns -1, 0, 1 to mimic strcmp

int strcmp_case_insensitive(const char* first_string, const char* second_string) {
   int i = 0;

   // loop until the end of the string
   while (first_string[i] != '\0' && second_string[i] != '\0') {

      // convert both chars to lowercase to compare
      char c1 = tolower(first_string[i]);
      char c2 = tolower(second_string[i]);
      // first < second
      if (c1 < c2) return -1;
      // first > second
      if (c1 > c2) return 1;

      // next char
      i++;
   }

   // reach the end of one or both strings
   // equal
   if (first_string[i] == '\0' && second_string[i] == '\0') return 0;
   // first ended 1st
   if (first_string[i] == '\0') return -1;
   // second ended 1st
   return 1;
}
