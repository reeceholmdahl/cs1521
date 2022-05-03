// My ID: 5727889
#include <string>
#include <cassert>

#include "Infix.h"
#include "StackInterface.h"
#include "LinkedStack.h"
#include "DivisionByZeroExcep.h"

using std::string;

Infix::Infix(const string& exp) : exp(exp) {
}

void Infix::evaluateTop(StackInterface<char>& operatorStack, StackInterface<int>& valueStack) const {
  // Operator stack has at least one item
  assert(!operatorStack.isEmpty() );

  // Peek the operator from the top of the operator stack and pop it
  char op(operatorStack.peek() );
  operatorStack.pop();

  // Value stack has at least one item
  assert(!valueStack.isEmpty() );

  // Peek the operand from the top of the value stack (rhs) and pop it
  int rhs(valueStack.peek() );
  valueStack.pop();

  // Value stack has at least one item (for a total of 2)
  assert(!valueStack.isEmpty() );

  // Peek the operand from the top of the value stack (lhs) and pop it
  int lhs(valueStack.peek() );
  valueStack.pop();

  if (op == '/' && rhs == 0) {
    throw DivisionByZeroExcep("Infinite result - Cannot handle division-by-zero.");
  }

  int result(0);
  switch(op) {
  case '+':
    result = lhs + rhs;
    break;
    
  case '-':
    result = lhs - rhs;
    break;

  case '*':
    result = lhs * rhs;
    break;

  case '/':
    result = lhs / rhs;
    break;
  }

  valueStack.push(result);
}

bool Infix::greaterPrecedence(char op1, char op2) const {
  bool result;

  if (op2 == '(' ) {
    return true;
  }
  
  switch (op1) {    
  case '+':
  case '-':
    result = false;
    break;

  case '*':
  case '/':
    result = op2 != '*' && op2 != '/';
    break;

  default:
    result = false;
    break;
  }

  return result;
}

std::string Infix::getExpression() const {
  return exp;
}

void Infix::setExpression(const string& newExp) {
  exp = newExp;
}

int Infix::evaluate() const {
  // Operator stack
  LinkedStack<char> opStack;

  // Value stack
  LinkedStack<int> valueStack;

  // Conversion from character to digit
  int toDigit = -48;

  for (unsigned int i(0); i < exp.size(); ++i) {
    char ch = exp[i];

    switch(ch) {
    case '(':
      opStack.push(ch);
      break;
      
    case '+':
    case '-':
    case '*':
    case '/':
      if (opStack.isEmpty() || greaterPrecedence(ch, opStack.peek() ) ) {
	opStack.push(ch);
      } else {
	while (!opStack.isEmpty() && !greaterPrecedence(ch, opStack.peek() ) ) {
	  evaluateTop(opStack, valueStack);
	}
	opStack.push(ch);
      }
      break;

    case ')':
      while (opStack.peek() != '(') {
	evaluateTop(opStack, valueStack);
      }

      // Pop left paren
      opStack.pop();
      break;

    default:
      // This is where I'm choosing to handle digit recognition
      if (ch >= '0' && ch <= '9') {
	int digit = ch + toDigit;
	valueStack.push(digit);
      }

      // If it's not a digit, it's not a valid infix expression and nothing needs to happen
      break;
    } // end switch
  } // end for

  // Evaluate top of stacks until the operator stack is empty
  while (!opStack.isEmpty() ) {
    evaluateTop(opStack, valueStack);
  }
  
  // Return top of value stack, which will be the fully evaluated expression
  return valueStack.peek();
}
