// My ID: 5727889
#ifndef INFIX_
#define INFIX_

#include <string>

#include "StackInterface.h"

using std::string;

class Infix {
 private:

  /** The infix expression in its string form. */
  string exp;

  /** Evaluates the top expression of the two stacks; one operator and two operands.
      @pre 'operatorStack' contains at least one operator, and 'valueStack' contains at least two operands.
      @post 'operatorStack' will have one less item and 'valueStack' will be decremented two items and incremented one. 

      @param[in, out] operatorStack A char stack containing operator characters.
      @param[in, out] valueStack An int stack containing the operands. */
  void evaluateTop(StackInterface<char>& operatorStack, StackInterface<int>& valueStack) const;

  /** Checks if the precedence of 'op1' is greater than 'op2'
      @pre 'op1' and 'op2' are operators.
      @post None.
  
      @param[in] op1 A char operator: + | - | * | /
      @param[in] op2 A char operator.
      @return True if op1 has a higher precedence than op2, false if  op1 has a lower or equal precedence to op2. */
  bool greaterPrecedence(char op1, char op2) const;
public:

  /** Explicit constructor with infix string parameter, also acts as default constructor. */
  explicit Infix(const string& exp = "");

  /** Default virtual destructor. */
  virtual ~Infix() = default;

  /** Gets the expression that this infix object represents in string form.
      @pre None.
      @post None.

      @return An infix expression in string form */
  string getExpression() const;

  // Might want to make this class validate
  /** Sets this object to represent a new expression.
      @pre 'newExp' is a proper infix expression. <!-- this might not be necessary
      @post This class now represents the expression in 'newExp'.
      
      @param[in] newExp The new expression that this infix object will represent. */
  void setExpression(const string& newExp);

  /** Evaluates the expression that this infix object represents.
      @pre This class represents a valid infix expression.
      @post None.

      @return The integer result of the infix expression. */
  int evaluate() const;
};

#endif // INFIX_
