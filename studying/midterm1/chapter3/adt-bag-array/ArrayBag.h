#ifndef _ARRAY_BAG
#define _ARRAY_BAG

#include <vector>
#include "BagInterface.h"

using std::vector;

template <typename ItemType>
class ArrayBag : public BagInterface<ItemType> {
 private:

  #ifdef _TESTING_SIZE
  static const int DEFAULT_CAPACITY = 6; // Should be significantly higher, is low for testing
  #else
  static const int DEFAULT_CAPACITY = 100; // Normal value, testing header guards for changing stuff
  #endif

  #ifdef _TESTING_POINTER
  ItemType* items = nullptr;
  #else
  ItemType items[DEFAULT_CAPACITY];
  #endif
  
  int itemCount = 0;

  int maxItems = DEFAULT_CAPACITY;
  
  virtual int getIndexOf(const ItemType& anEntry) const;
 public:

  ArrayBag() = default;

  #ifdef _TESTING_POINTER
  ArrayBag(int maxItems);
  virtual ~ArrayBag();
  #else
  virtual ~ArrayBag() = default;
  #endif
  
  virtual int getCurrentSize() const;
  
  virtual bool isEmpty() const;
  
  virtual bool add(const ItemType& newEntry);
  
  virtual bool remove(const ItemType& anEntry);
  
  virtual void clear();
  
  virtual int getFrequencyOf(const ItemType& anEntry) const;
  
  virtual bool contains(const ItemType& anEntry) const;
  
  virtual vector<ItemType> toVector() const;
}; // end ArrayBag

#include "ArrayBag.cpp"

#endif
