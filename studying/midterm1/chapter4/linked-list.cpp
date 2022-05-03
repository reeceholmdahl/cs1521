#include <stdexcept>
#include <sstream>

template <typename Type>
LinkedList<Type>::LinkedList() : head(nullptr), size(0) {
} // Empty bodied

template <typename Type>
LinkedList<Type>::LinkedList(const LinkedList& list) {
} // STUB

template <typename Type>
LinkedList<Type>::~LinkedList() {
} // STUB

template <typename Type>
void LinkedList<Type>::add(const Type& item) {

  // Cache the previous head
  nodePtr prevHead(head);

  head = new Node<Type>(item, prevHead);

  prevHead = nullptr;

  ++size;
}

template <typename Type>
bool LinkedList<Type>::remove(const Type& item) {
  
  nodePtr curPtr(head);
  int counter(0);

  while (counter < size && curPtr) {
    Type curItem(curPtr->getItem() );
    if (item == curItem) {
      curPtr->setItem(head->getItem() );
      nodePtr prevHead(head);
      head = head->getNext();

      delete prevHead;
      prevHead = nullptr;

      --size;

      return true;
    }
  }

  return false;
}

template <typename Type>
int LinkedList<Type>::getSize() const {
  return size;
}

template <typename Type>
Type& LinkedList<Type>::operator [] (int index) const {
  
  nodePtr curPtr(head);
  int counter(0);
  
  while (counter < size && curPtr) {
    if (counter == index) {
      return curPtr->getValue();
    }
    ++counter;
    curPtr = curPtr->getNext();
  }

  // If function has made it this far, throw out of range error
  std::stringstream errorMsg;
  errorMsg << "Error attempting to access index " << index << " of list size " << size;
  
  throw new std::out_of_range(errorMsg.str() );
}

template <typename Type>
vector<Type> LinkedList<Type>::toVector() const {

  vector<Type> contents;
  
  nodePtr curPtr = head;
  
  while (curPtr) {
    contents.push_back(curPtr->getValue() );
    curPtr = curPtr->getNext();
  }

  return contents;
}
