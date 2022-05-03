/** @file
 
    @course CS1521
    @section 9
    @term Spring 2021
 
    Implementation file for the class ArraySet.
 
    Adapted from pages 101-111 in Carrano 7e.
 
    @author Frank M. Carrano
    @author Timothy Henry
    @author Steve Holtz
    @author Reece Holmdahl (5727889)
 
    @date 13 Feb 2021
   
    @version 7.0 */

#include <vector>

using std::vector;

template <typename ItemType>
int ArraySet<ItemType>::getCurrentSize() const {

  return size;
}

template <typename ItemType>
bool ArraySet<ItemType>::isEmpty() const {

  return !size;
}

template <typename ItemType>
bool ArraySet<ItemType>::add(const ItemType& newElement) {

  bool hasRoomToAdd(size < maxSize);
  bool alreadyContains(contains(newElement) );
  bool canAdd(hasRoomToAdd && !alreadyContains);

  if (canAdd) {
    elements[size] = newElement;
    ++size;
  }

  return canAdd;
}

template <typename ItemType>
bool ArraySet<ItemType>::remove(const ItemType& anElement) {

  int locatedIndex(getIndexOf(anElement) );
  bool canRemoveItem(locatedIndex > -1);

  if (canRemoveItem) {
    --size;
    elements[locatedIndex] = elements[size];
  }

  return canRemoveItem;
}

template <typename ItemType>
void ArraySet<ItemType>::clear() {

  size = 0;
}

template <typename ItemType>
bool ArraySet<ItemType>::contains(const ItemType& anElement) const {

  // Return the frequency of anElement which can either be 1 (true) or 0 (false).
  return getFrequencyOf(anElement);
}

template <typename ItemType>
int ArraySet<ItemType>::getFrequencyOf(const ItemType& anElement) const {

  // A set can only contain 1 entry of an element, so if it finds one, return 1.
  for (int index(0); index < size; ++index) {
    if (elements[index] == anElement) {
      return 1;
    }
  }

  return 0;
}

template <typename ItemType>
vector<ItemType> ArraySet<ItemType>::toVector() const {

  vector<ItemType> setContents;

  for (int index(0); index < size; ++index) {
    setContents.push_back(elements[index]);
  }

  return setContents;
}

template <typename ItemType>
ArraySet<ItemType> ArraySet<ItemType>::difference(const ArraySet<ItemType>& set2) const {

  ArraySet<ItemType> difference;

  vector<ItemType> set1Contents = toVector();

  for (int index(0); index < size; ++index) {
    ItemType item(set1Contents[index]);
    if (!set2.contains(item) ) {
      
      difference.add(item);
    }
  }
  
  return difference;
} // STUB

template <typename ItemType>
int ArraySet<ItemType>::getIndexOf(const ItemType& target) const {

  // Search for target and return its index if found.
  for (int index(0); index < size; ++index) {
    if (elements[index] == target) {
      return index;
    }
  }

  // If it's made it this far, no occurrence of target in this set.
  return -1;
}
