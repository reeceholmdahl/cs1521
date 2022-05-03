#include <iostream>

#include "grammar.hpp"

using std::cout;
using std::endl;

int main() {

  cout << gram::isInteger("333.") << endl;
  
  return EXIT_SUCCESS;
}
