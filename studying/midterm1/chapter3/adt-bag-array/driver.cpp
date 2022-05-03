//#define _TESTING_SIZE
//#define _TESTING_POINTER

#include <iostream>
#include <vector>

#include <stdlib.h>
#include <time.h>

#include "ArrayBag.h"

using std::cout;
using std::endl;
using std::vector;

template <typename ItemType>
void printBag(const ArrayBag<ItemType>& bag) {
  if (!bag.getCurrentSize()) {
    cout << "Bag is empty." << endl;
    return;
  }
  
  vector<ItemType> v = bag.toVector();
  
  for (int i(0); i < v.size(); ++i) {
    cout << "Index: " << i << ", Value: " << v[i] << endl;
  }
}

template <typename ItemType>
void testBag(ArrayBag<ItemType>& bag, const ItemType& testEntry) {
  printBag(bag);
  
  cout << "Current size: " << bag.getCurrentSize() << endl
       << "Is empty: " << bag.isEmpty() << endl
       << "Adding 1st test entry (success?): " << bag.add(testEntry) << endl
       << "Adding 2nd test entry (success?): " << bag.add(testEntry) << endl
       << "Freq. of test entry (attempted to add 2): " << bag.getFrequencyOf(testEntry) << endl
       << "Contains test entry: " << bag.contains(testEntry) << endl
       << "Removing 1st test entry (success?): " << bag.remove(testEntry) << endl
       << "Removing 2nd test entry (success?): " << bag.remove(testEntry) << endl;

  printBag(bag);
}

int ranNum(int min, int max) {
  return rand() % max + min;
}

int main() {

  srand(time(0));
  for (int i(1); i < 30; ++i) {
    //cout << ranNum(0, i) << endl;
  }

  int max = 100;
  int add = ranNum(2, max) - 1;
  int remove = ranNum(2, max) - 1;

  ArrayBag<int> bag;

  int added[max + 1];
  for (int i(0); i <= max; ++i) {
    added[i] = ranNum(i, 100);
  }
  
  for (int i(0); i < add; ++i) {
    cout << "Able to add (value:  " << added[i] << "): " << bag.add(added[i]) << endl;
  }

  int i = 10;
  testBag(bag, i);

  cout << endl << endl;

  for (int i(0); i < remove; ++i) {
    cout << "Able to remove (value: " << added[i] << "): " << bag.remove(added[i]) << endl;
  }

  testBag(bag, i);
    
  return EXIT_SUCCESS;
}
