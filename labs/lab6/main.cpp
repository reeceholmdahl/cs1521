#include <iostream>
#include <string>
#include <vector>

#include "isPalindrome.h"

int main() {

   std::vector<std::string> strVec = { "",
                                       "a",
                                       "aba",
                                       "abba",
                                       "deleveled",
                                       "A man, a plan, a canal: Panama",
                                       "ab",
                                       "abbc" };

   // Range-based 'for' loop:
   for (const std::string& currStr : strVec) {
      // Initialize a 'clean' string to empty:
      std::string clean; // A default-constructed std::string is ""
                         // (the empty string).

      // Another, nested range-based 'for' loop.
      // Iterate over the characters in 'currStr' and concatenate all
      // characters, except for space characters, to the string
      // 'clean':
      for (char ch : currStr) {
         // If 'ch' is uppercase, then convert it to lowercase:
         if (ch >= 'A' && ch <= 'Z') {
            ch += 'a' - 'A';
         }
         // Append 'ch' to 'clean' string only if it is alpha:
         if (ch >= 'a' && ch <= 'z') {
            clean += ch;
         }
      }

      // Test and report whether the string 'clean' contains a
      // palindrome:
      if (isPalindrome(clean) ) {
         std::cout << "YES \""
                   << currStr
                   << "\" is a palindrome."
                   << std::endl;
      }
      else {
         std::cout << "NO \""
                   << currStr
                   << "\" is not a palindrome."
                   << std::endl;
      }
   }

   return EXIT_SUCCESS;
}
