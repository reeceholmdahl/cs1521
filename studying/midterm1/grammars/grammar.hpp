#ifndef GRAMMAR_
#define GRAMMAR_

namespace gram {

  // Number recognition
  bool isInteger(const std::string& str, int first, int last);
  bool isInteger(const std::string& str);
  bool isFloat(const std::string& str, int first, int last);
  bool isFloat(const std::string& str);

  // Identifier recognition
  bool is_cpp_identifier(const std::string& str);

  // Algebra recognition
  bool isSymbolicInfix(const std::string& str);
  bool isLiteralInfix(const std::string& str);

}

#include "numbers.cpp"

#endif // GRAMAR_
