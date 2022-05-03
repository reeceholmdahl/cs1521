template <typename ItemType>
LinkedSet<ItemType>::LinkedSet(const LinkedSet<ItemType>& otherSet) {

  size = otherSet.size;

  if (!otherSet.headPtr) {
    headPtr = nullptr;
  } else {
    NodePtr copyChain(otherSet.headPtr);
    NodePtr thisChain(headPtr = new Node<ItemType>(copyChain->getValue() ) );

    copyChain = copyChain->getNext();

    while (copyChain) {
      thisChain->setNext(new Node<ItemType>(copyChain->getValue() ) );

      copyChain = copyChain->getNext();
      thisChain = thisChain->getNext();
    }
  } 
}

template <typename ItemType>
LinkedSet<ItemType>::~LinkedSet() {
  clear();
}

template <typename ItemType>
int LinkedSet<ItemType>::getCurrentSize() const {
  return size;
}

template <typename ItemType>
bool LinkedSet<ItemType>::isEmpty() const {
  return !size;
}

template <typename ItemType>
bool LinkedSet<ItemType>::add(const ItemType& newElement) {

  bool canAdd(!contains(newElement) );
  
  if (canAdd) {
    headPtr = new Node<ItemType>(newElement, headPtr);
    ++size;
  }
  
  return canAdd;
}

template <typename ItemType>
bool LinkedSet<ItemType>::remove(const ItemType& anElement) {

  NodePtr location = getPointerTo(anElement);

  if (location) {
    prevHead = headPtr;
    location->setValue(headPtr->getValue() );
    headPtr = headPtr->getNext();

    delete prevHead;
    prevHead = nullptr;
  }
  
  return static_cast<bool>(location);
}

template <typename ItemType>
void LinkedSet<ItemType>::clear() {
  size = 0;
  NodePtr toDelete;

  while (headPtr) {
    toDelete = headPtr;
    headPtr = headPtr->getNext();
    delete toDelete;
  }
}

template <typename ItemType>
int LinkedSet<ItemType>::getFrequencyOf(const ItemType& anElement) const {

  if (getPointerTo(anElement) ) {
    return 1;
  }
  
  return 0;
}

template <typename ItemType>
bool LinkedSet<ItemType>::contains(const ItemType& anElement) const {
  return getFrequencyOf(anElement);
}

template <typename ItemType>
std::vector<ItemType> LinkedSet<ItemType>::toVector() const {

  std::vector<ItemType> setContents;

  for (NodePtr curPtr(headPtr); curPtr; curPtr = curPtr->getNext() ) {
    setContents.push_back(curPtr->getValue() );
  }
  
  return setContents;
}

template <typename ItemType>
LinkedSet<ItemType> LinkedSet<ItemType>::difference(const LinkedSet<ItemType>& set2) const {

  LinkedSet<ItemType> difference;
  
  for (NodePtr curPtr(headPtr); curPtr; curPtr = curPtr->getNext() ) {
    ItemType element(curPtr->getValue() );
    if (!set2.contains(element) ) {
      difference.add(element);
    }
  }
  
  return difference;
}

template <typename ItemType>
Node<ItemType>* LinkedSet<ItemType>::getPointerTo(const ItemType& target) const {

  // Traverse linked chain with for loop
  for (NodePtr curPtr(headPtr); curPtr; curPtr = curPtr->getNext() ) {

    // If the current pointer's value is the target, return the pointer
    if (curPtr->getValue() == target) {
      return curPtr;
    }
  }

  // If it has made it this far there is no element 'target' in this set
  return nullptr;
}
