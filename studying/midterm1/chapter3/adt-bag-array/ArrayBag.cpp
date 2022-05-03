#include <vector>
#include "ArrayBag.h"

using std::vector;

#ifdef _TESTING_POINTER
template <typename ItemType>
ArrayBag<ItemType>::ArrayBag(int bagSize) : maxItems{bagSize}, items{new ItemType[maxItems]} {
}

template <typename ItemType>
ArrayBag<ItemType>::~ArrayBag() {
  delete items;
  items = nullptr;
}
#endif

template <typename ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& anEntry) const {
  for (int index(0); index < itemCount; ++index) {
    if (items[index] == anEntry) {
      return index;
    }
  }

  return -1;
}

template <typename ItemType>
int ArrayBag<ItemType>::getCurrentSize() const {
  return itemCount;
}

template <typename ItemType>
bool ArrayBag<ItemType>::isEmpty() const {
  return !itemCount;
}

template <typename ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry) {
  bool canAdd = itemCount < maxItems;
  if (canAdd) {
    items[itemCount] = newEntry;
    ++itemCount;
  }

  return canAdd;
}

template <typename ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry) {

  int index;
  bool canRemove = itemCount > 0 && (index = getIndexOf(anEntry)) != -1;
   if (canRemove) {
    --itemCount;
    items[index] = items[itemCount];
  }

  return canRemove;
}

template <typename ItemType>
void ArrayBag<ItemType>::clear() {
  itemCount = 0;
}

template <typename ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
  int amount = 0;
  
  for (int index(0); index < itemCount; ++index) {
    if (items[index] == anEntry) {
      ++amount;
    }
  }

  return amount;
}

template <typename ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const {
  return getIndexOf(anEntry) != -1;
}

template <typename ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const {
  vector<ItemType> vector;

  for (int index(0); index < itemCount; ++index) {
    vector.push_back(items[index]);
  }
  
  return vector;
}
