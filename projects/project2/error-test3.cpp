// My ID#: 5727889

#include <iostream>

#include "ReceiptArrayBag.h"

using std::cout;
using std::endl;
using std::string;

int main() {

  ReceiptArrayBag<string> bag;
  cout << "Putting 'hello' in bag." << endl;
  int receipt = 10;
  cout << "Attempting to take out item associated with arbitrarily high receipt 10." << endl;
  bag.takeOut(receipt);
}
