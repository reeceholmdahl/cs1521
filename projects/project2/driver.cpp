// My ID#: 5727889

#include <iostream>
#include <vector>

#include "ReceiptArrayBag.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

/** Prints all the entries within a bag, gives a separate message if empty. */
template <typename ItemType>
void printBag(const ReceiptArrayBag<ItemType>& bag) {
  vector<ItemType> vec = bag.toVector();

  cout << "\nPrinting bag:" << endl;
  
  if (!vec.size()) {
    cout << "The bag is empty." << endl;
  }
  
  for (unsigned int i(0); i < vec.size(); ++i) {
    cout << "Entry: " << vec[i] << endl;
  }

  cout << endl;
}

template <typename ItemType>
int* fastPut(ReceiptArrayBag<ItemType>& bag, const ItemType array[], int length) {
  int* receipts = new int[length];

  cout << "Adding: ";
  
  for (int i(0); i < length; ++i) {
    cout << array[i] << " ";
    receipts[i] = bag.put(array[i]);
  }

  cout << "to the bag." << endl;

  return receipts;
}

template <typename ItemType>
void testTakeOutItem(ReceiptArrayBag<ItemType>& bag, int receipt, const ItemType& expected) {
  cout << "Expecting to take out item '" << expected
       << "' with receipt " << receipt
       << ", return value: " << bag.takeOut(receipt) << endl;
}

template <typename ItemType>
void testFrequency(const ReceiptArrayBag<ItemType>& bag, const ItemType& check, int expectedNum) {
  cout << "Checking frequency of item '" << check
       << "' (should be " << expectedNum
       << "): " << bag.getFrequencyOf(check) << endl;
}

template <typename ItemType>
void testContains(const ReceiptArrayBag<ItemType>& bag, const ItemType& check, bool expected) {
  cout << "Checking if bag contains '" << check
       << "' (should be " << expected
       << "): " << bag.contains(check) << endl;
}

template <typename ItemType>
void testEmpty(const ReceiptArrayBag<ItemType>& bag, bool expected) {
  cout << "Checking if the bag is empty (should be " << expected
       << "): " << bag.isEmpty() << endl;
}

template <typename ItemType>
void testGetSize(const ReceiptArrayBag<ItemType>& bag, int expectedSize) {
  cout << "Checking current size of bag (should be " << expectedSize
       << "): " << bag.getCurrentSize() << endl;
}

template <typename ItemType>
void testClear(ReceiptArrayBag<ItemType>& bag) {
  cout << "Clearing the bag." << endl;
  bag.clear();
}

template <typename ItemType>
void testPut(ReceiptArrayBag<ItemType>& bag, const ItemType& newItem, bool expectedSuccess) {
  cout << "Attempting to add '" << newItem
       << "' to the bag. (Success should be " << expectedSuccess
       << "): " << (bag.put(newItem) != -1) << endl;
}

int main() {

  /* Begin integer receipt bag tests */
  
  ReceiptArrayBag<int> iBag;

  int iValues[5] = {10, 9, 8, 7, 6};
  
  int* iReceipts = fastPut(iBag, iValues, 5);

  testEmpty(iBag, false);

  printBag(iBag);

  testGetSize(iBag, 5);
  
  testTakeOutItem(iBag, iReceipts[2], 8);

  testGetSize(iBag, 4);

  printBag(iBag);

  testFrequency(iBag, 8, 0);
  testFrequency(iBag, 10, 1);

  testContains(iBag, 6, true);
  testContains(iBag, 8, false);

  cout << endl;
  
  testTakeOutItem(iBag, iReceipts[4], 6);
  testContains(iBag, 6, false);
  testGetSize(iBag, 3);

  printBag(iBag);

  testClear(iBag);
  testContains(iBag, 10, false);
  testGetSize(iBag, 0);

  printBag(iBag);

  testEmpty(iBag, true);
  
  // Free memory from heap
  delete iReceipts;
  iReceipts = nullptr;

  cout << "\nFreed integer receipt bag test memory from heap. Moving on to string tests.\n\n" << endl;

  /* Begin string receipt bag tests */

  ReceiptArrayBag<string> sBag;

  string sValues[6] = {"hello", "goodbye", "bonjour", "adieu", "hola", "adios"};
  
  int* sReceipts = fastPut(sBag, sValues, 6);

  testEmpty(sBag, false);

  printBag(sBag);

  testPut(sBag, string("overflow?"), false);

  testGetSize(sBag, 6);
  
  testTakeOutItem(sBag, sReceipts[5], string("adios"));
  testTakeOutItem(sBag, sReceipts[3], string("adieu"));
  testTakeOutItem(sBag, sReceipts[1], string("goodbye"));

  testGetSize(sBag, 3);

  printBag(sBag);

  testPut(sBag, string("no"), true);
  testPut(sBag, string("hello"), true);

  testGetSize(sBag, 5);

  printBag(sBag);

  testFrequency(sBag, string("goodbye"), 0);
  testFrequency(sBag, string("hello"), 2);

  testContains(sBag, string("hola"), true);
  testContains(sBag, string("adios"), false);

  cout << endl;
  
  testTakeOutItem(sBag, sReceipts[0], string("hello"));
  testContains(sBag, string("hello"), true);
  testGetSize(sBag, 4);

  printBag(sBag);

  testClear(sBag);
  testContains(sBag, string("bonjour"), false);
  testGetSize(sBag, 0);

  printBag(sBag);

  testEmpty(sBag, true);
  
  // Free memory from heap
  delete sReceipts;
  sReceipts = nullptr;

  cout << "\nFreed string receipt array bag test memory from heap. Exiting program, then moving on to error tests." << endl;

  return EXIT_SUCCESS;
}
