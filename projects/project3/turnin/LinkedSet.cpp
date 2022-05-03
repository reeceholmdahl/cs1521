/** @file
 
    @course CS1521
    @section 9
    @term Spring 2021
 
    Implementation file for the class LinkedSet.
 
    Adapted from pages 139-148 in Carrano 7e.
 
    @author Frank M. Carrano
    @author Timothy Henry
    @author Steve Holtz
    @author Reece Holmdahl (5727889) 
    
    @date 20 Feb 2021
    
    @version 7.0 */

#include <vector>

template <typename ItemType>
LinkedSet<ItemType>::LinkedSet(const LinkedSet<ItemType>& aSet) {

  itemCount = aSet.itemCount;

  // If 'aSet.headPtr' is not pointing at a node:
  if (!aSet.headPtr) { // aSet.headPtr == nullptr (!nullptr == true)
    headPtr = nullptr;
  }
  else {
    NodePtr origChainPtr(aSet.headPtr);

    headPtr = new Node<ItemType>(origChainPtr->getItem() );

    NodePtr newChainPtr(headPtr);

    origChainPtr = origChainPtr->getNext();

    while (origChainPtr) { // while (origChainPtr != nullptr) {
      newChainPtr->setNext(new Node<ItemType>(origChainPtr->getItem()) );

      newChainPtr = newChainPtr->getNext();
      origChainPtr = origChainPtr->getNext();
    }
  }
}

template <typename ItemType>
LinkedSet<ItemType>::~LinkedSet() {

  clear();
}

template <typename ItemType>
int LinkedSet<ItemType>::getCurrentSize() const {

  return itemCount;
}

template <typename ItemType>
bool LinkedSet<ItemType>::isEmpty() const {

  return !itemCount;
}

template <typename ItemType>
bool LinkedSet<ItemType>::add(const ItemType& newEntry) {

  bool canAdd(!contains(newEntry) );

  if (canAdd) {
    headPtr = new Node<ItemType>(newEntry, headPtr);
    ++itemCount;
  }

  return canAdd;
}

template <typename ItemType>
bool LinkedSet<ItemType>::remove(const ItemType& anEntry) {

  NodePtr entryNodePtr(getPointerTo(anEntry) );

  // If 'entryNodePtr' is pointing at a node:
  if (entryNodePtr) { // entryNodePtr != nullptr (nullptr == false)
    entryNodePtr->setItem(headPtr->getItem() );

    NodePtr nodeToDeletePtr(headPtr);

    headPtr = headPtr->getNext();

    delete nodeToDeletePtr;

    --itemCount;
  }

  return static_cast<bool>(entryNodePtr);
}

template <typename ItemType>
Node<ItemType>*
LinkedSet<ItemType>::getPointerTo(const ItemType& target) const {

  NodePtr curPtr(headPtr);

  while (curPtr) { // curPtr != nullptr
    if (curPtr->getItem() == target) {
      return curPtr;
    }

    curPtr = curPtr->getNext();
  }

  return nullptr; // curPtr == nullptr so 'return curPtr;' works.
}

template <typename ItemType>
void LinkedSet<ItemType>::clear() {

  NodePtr nodeToDeletePtr(headPtr);

  while (headPtr) { // headPtr != nullptr
    headPtr = headPtr->getNext();

    delete nodeToDeletePtr;

    nodeToDeletePtr = headPtr;
  }

  // Note that headPtr == nodeToDeletePtr == nullptr
  itemCount = 0;
}

template <typename ItemType>
bool
LinkedSet<ItemType>::contains(const ItemType& anEntry) const {

  return static_cast<bool>(getPointerTo(anEntry) ); // ... != nullptr;
}

template <typename ItemType>
int
LinkedSet<ItemType>::getFrequencyOf(const ItemType& anEntry) const {

  int frequency(0);

  NodePtr curPtr(headPtr);

  while (curPtr) { // != nullptr
    if (curPtr->getItem() == anEntry) {
      ++frequency;
    }

    curPtr = curPtr->getNext();
  }

  return frequency;
}

template <typename ItemType>
std::vector<ItemType> LinkedSet<ItemType>::toVector() const {

  std::vector<ItemType> setContents;

  NodePtr curPtr(headPtr);

  while (curPtr) { // != nullptr
    setContents.push_back(curPtr->getItem() );

    curPtr = curPtr->getNext();
  }

  return setContents;
}

template <typename ItemType>
LinkedSet<ItemType> LinkedSet<ItemType>::difference(const LinkedSet<ItemType>& set2) const {

  LinkedSet<ItemType> difference;
  
  for (NodePtr curPtr(headPtr); curPtr; curPtr = curPtr->getNext() ) {
    ItemType element(curPtr->getItem() );
    if (!set2.contains(element) ) {
      difference.add(element);
    }
  }
  
  return difference;
}
