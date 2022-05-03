#include <iostream>
#include <vector>

#include "node.hpp"
#include "linked-list.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::string;

template <typename Type>
void printList(const LinkedList<Type>& list) {
  for (int i(0); i < list.getSize(); ++i) {
    cout << "List[" << i << "] == " << list[i] << endl;
  }
}

int main() {

  Node<int>* headPtr = new Node<int>(7);
  headPtr->setNext(new Node<int>(8) );
  headPtr->getNext()->setNext(new Node<int>(9) );
  headPtr->getNext()->getNext()->setNext(new Node<int>(10) );

  Node<int>* curPtr(headPtr);
  int i(0);
  while (curPtr) {
    cout << "Value at " << i << ": " << curPtr->getValue() << endl;
    curPtr = curPtr->getNext();
    ++i;
  }

  /* END NODE TESTS START LIST TESTS */
  cout << endl << endl;

  LinkedList<int> list;

  list.add(10);
  list.add(9);
  list.add(8);
  list.add(7);

  vector<int> contents = list.toVector();
  
  /*for (int i(0); i < contents.size(); ++i) {
    cout << "Value at " << i << ": " << contents[i] << endl;
    }*/

  printList(list);

  list[0] = 105;
  list[1] = list[2];

  printList(list);
  
  return EXIT_SUCCESS;
}
