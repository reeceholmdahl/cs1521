// My ID: 5727889
#include <iostream>

#include "Infix.h"
#include "LinkedStack.h"
#include "DivisionByZeroExcep.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

  Infix infixExp;

  string exp;
  while (getline(cin, exp) ) {
    infixExp.setExpression(exp);

    cout << exp << " = ";

    try {
      int result = infixExp.evaluate();
      cout << result;
    } catch (const DivisionByZeroExcep& e) {
      std::cerr << e.what();
    }

    cout << endl;
  }
  
return EXIT_SUCCESS;
  }
