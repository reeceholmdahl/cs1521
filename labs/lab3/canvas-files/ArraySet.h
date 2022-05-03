/** @file
 
    @course CS1521
    @section 9
    @term Spring 2021
 
    Header file for an array-based implementation of the ADT set.
    
    Adapted from page 100 in Carrano 7e.
 
    @author Frank M. Carrano
    @author Timothy Henry
    @author Steve Holtz
    @author Reece Holmdahl (5727889)
 
    @date 13 Feb 2021
    
    @version 7.0 */

#ifndef ARRAY_SET_
#define ARRAY_SET_

#include <vector>

#include "SetInterface.h"

/** @class ArraySet ArraySet.h "ArraySet.h"
    Specification of an array-based ADT set. */
template <typename ItemType>
class ArraySet : public SetInterface<ItemType> {
private:
  
  /** Maximum capacity of this set. Low number for testing purposes. */
  static const int DEFAULT_CAPACITY = 6;

  /** Element data storage. */
  ItemType elements[DEFAULT_CAPACITY];

  /** Number of elements in this set. */
  int size = 0;

  /** Maximum capacity of this set. */
  int maxSize = DEFAULT_CAPACITY;

  /** Gets the index of target in the array 'elements' in this set.
      @param target The ItemType value to retrieve the index of.
   
      @return The index of 'target' in the array 'elements', or -1 if the array does not contain 'target'. */
  int getIndexOf(const ItemType& target) const;

public:
  
  /** Default constructor. */
  ArraySet() = default;

  /** Virtual destructor, using default. */
  virtual ~ArraySet() = default;

  virtual int getCurrentSize() const;

  virtual bool isEmpty() const;

  virtual bool add(const ItemType& newElement);

  virtual bool remove(const ItemType& anElement);

  virtual void clear();

  virtual int getFrequencyOf(const ItemType& anElement) const;

  virtual bool contains(const ItemType& anElement) const;

  virtual std::vector<ItemType> toVector() const;

  /** Creates a new set containing all of the items in this set that are not in 'set2'.
      @param[in] set2 The ArraySet of the same item type to take the difference with.

      @return The ArraySet of the same item type representing the difference between this set and 'set2'. */
  virtual ArraySet<ItemType> difference(const ArraySet<ItemType>& set2) const;
};

#include "ArraySet.cpp"

#endif // ARRAY_SET_
