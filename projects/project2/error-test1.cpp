// My ID#: 5727889

#include <iostream>

#include "ReceiptArrayBag.h"

using std::cout;
using std::endl;
using std::string;

int main() {

  ReceiptArrayBag<string> bag;
  cout << "Putting 'hello' in bag." << endl;
  int receipt = bag.put("hello");
  cout << "Taking out item associated with receipt (points at 'hello')" << endl;
  bag.takeOut(receipt);
  cout << "Attempting to take out item with the same receipt." << endl;
  bag.takeOut(receipt);
}
