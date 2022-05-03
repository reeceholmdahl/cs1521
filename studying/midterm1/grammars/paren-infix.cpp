#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool isLetter(char ch);
bool isOp(char ch);

int endInfix(const string& str, int first, char lastChar) {

  int last = str.length() - 1;

  // Base case A
  if (first > last) {
    return -1;
  }

  char ch = str[first];
  
  if (isLetter(ch) ) {

    // Base case B
    if (lastChar == '(' || isOp(lastChar) ) {
      return first;
    }
    
  } else if (ch == ')' ) {

    return first;
  } else if (isOp(ch) ) {

    return endInfix(str, first + 1, ch);
  } else if (ch == '(' ) {

    int lhs = endInfix(str, first + 1, ch);
    
    if (lhs > -1) {

      int rhs = endInfix(str, lhs + 1, str[lhs]);
      
      if (rhs > -1) {
	int endParen = endInfix(str, rhs + 1, str[rhs]);
	return endParen;
      }
    }
  }
  
  // If it has reached here, return error code;
  return -1;
}

bool isInfix(const string& str) {
  return endInfix(str, 0, ' ') == str.length() - 1;
}

int main() {

  string exp;
  cout << "Enter an infix expression: ";
  cin >> exp;
  int end = endInfix(exp, 0, ' ');
  bool is = isInfix(exp);
  
  cout << endl << "End of infix: " << end << endl;
  cout << "Is infix?: " << is << endl;
  
  return EXIT_SUCCESS;
}

bool isLetter(char ch) {
  return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

bool isOp(char ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// start at 1, pass first character of str
/*int oldEndInfix(const string& str, int first, char lastChar) {

  int last = str.length() - 1;
  
  if (first > last) {
  return -1;
  }

  char ch = str[first];
  cout << "Character here: " << ch << endl;

  int do = -1;
  
  if (isLetter(ch) ) {
  if (
  }

  if (isLetter(ch) ) {
    
  if (isOp(lastChar) || first == 0) {
      
  if (first < last) {
  return endInfix(str, first + 1, ch);
  } else {
  return first;
  }
      
  } else {
   
  return -1;
  }
    
  } else if (isOp(ch) ) {

  if (isLetter(lastChar) ) {
      
  return endInfix(str, first + 1, ch);      
  } else {
      
  return -1;
  }
      
  } else {
    
  return -1;
  }
  }
  }*/

/*bool isInfix(const string& str) {
  return endInfix(str, 0, 0) == str.length() - 1;
  }*/
