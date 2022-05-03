bool isDigit(char ch);
int endIntegral(const std::string& str, int first, int last, int pos);
int endInteger(const std::string& str, int first, int last);
int endFloat(const std::string& str, int first, int last);

bool gram::isInteger(const std::string& str, int first, int last) {
  int end = endInteger(str, first, last);
  //std::cout << "end: " << end << std::endl;
  return end == last;
}

bool gram::isInteger(const std::string& str) {
  return gram::isInteger(str, 0, str.length() - 1);
}

bool isDigit(char ch) {
  return ch >= '0' && ch <= '9';
}

int endIntegral(const std::string& str, int first, int last, int pos) {
  
  // Base case A
  if (pos > last) {
    return last;
  }

  char ch = str[pos];
  std::cout << ch << " ";

  if (isDigit(ch) ) {
    return endIntegral(str, first, last, pos + 1);
  } else {
    return pos;
  }
}

int endInteger(const std::string& str, int first, int last) {
  int end = endIntegral(str, first, last, first);
  if (end > -1 && str[first] == '0') {
    return -1;
  } else {
    return end;
  }
}

bool gram::isFloat(const std::string& str, int first, int last) {
  return endFloat(str, first, last) == last;
}

bool gram::isFloat(const std::string& str) {
  return isFloat(str, 0, str.length() - 1);
}

int endFloat(const std::string& str, int first, int last) {
  int lhs = endInteger(str, first, last);

  std::cout << "LHS end: " << lhs << std::endl;
  
  if (lhs > 0 && lhs < last) {
    
    int dot = lhs + 1;
    std::cout << "Dot point: " << dot << std::endl;
    if (dot < last && str[dot] == '.') {

      std::cout << "char at Dot point: " << str[dot] << std::endl;
      
      int rhs = endIntegral(str, dot + 1, last, dot + 1);
      return rhs;
    }
  }

  return -1;
}
